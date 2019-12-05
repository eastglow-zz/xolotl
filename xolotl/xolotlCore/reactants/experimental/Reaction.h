#pragma once

#include <Kokkos_Core.hpp>

#include <plsm/detail/KokkosExtension.h>
#include <plsm/Utility.h>

namespace xolotlCore
{
namespace experimental
{
template <typename TImpl>
template <typename TDerived>
class ReactionNetwork<TImpl>::Reaction
{
public:
    using NetworkType = ReactionNetwork<TImpl>;
    using Cluster = typename NetworkType::Cluster;
    using ConcentrationsView = Kokkos::View<double*, Kokkos::MemoryUnmanaged>;
    using FluxesView = Kokkos::View<double*, Kokkos::MemoryUnmanaged>;

    enum class Type
    {
        production,
        dissociation
    };

    struct ClusterAssoc
    {
        Type reactionType{};
        std::size_t cluster0 {invalid};
        std::size_t cluster1 {invalid};
        std::size_t cluster2 {invalid};
        std::size_t cluster3 {invalid};

        ClusterAssoc() = default;

        ClusterAssoc(Type rType, std::size_t cl0, std::size_t cl1,
                std::size_t cl2 = invalid, std::size_t cl3 = invalid)
            :
            reactionType{rType},
            cluster0{cl0},
            cluster1{cl1},
            cluster2{cl2},
            cluster3{cl3}
        {
        }
    };

    Reaction() = default;

    Reaction(NetworkType& network, std::size_t reactionId, Type reactionType,
        std::size_t cluster0, std::size_t cluster1,
        std::size_t cluster2 = invalid, std::size_t cluster3 = invalid);

    Type
    getType() const noexcept
    {
        return _type;
    }

    void
    updateRates();

    void
    productionConnectivity(ConnectivityView connectivity);

    void
    dissociationConnectivity(ConnectivityView connectivity);

    void
    contributeConnectivity(ConnectivityView connectivity)
    {
        ((*this).*(_connectFn))(connectivity);
    }

    void
    productionFlux(ConcentrationsView concentrations, FluxesView fluxes,
        std::size_t gridIndex);

    void
    dissociationFlux(ConcentrationsView concentrations, FluxesView fluxes,
        std::size_t gridIndex);

    void
    contributeFlux(ConcentrationsView concentrations, FluxesView fluxes,
        std::size_t gridIndex)
    {
        ((*this).*(_fluxFn))(concentrations, fluxes, gridIndex);
    }

    void
    productionPartialDerivatives(ConcentrationsView concentrations,
        Kokkos::View<double*> values,
        std::size_t gridIndex);

    void
    dissociationPartialDerivatives(ConcentrationsView concentrations,
        Kokkos::View<double*> values,
        std::size_t gridIndex);

    void
    contributePartialDerivatives(ConcentrationsView concentrations,
        Kokkos::View<double*> values,
        std::size_t gridIndex)
    {
        ((*this).*(_partialsFn))(concentrations, values, gridIndex);
    }

private:
    TDerived*
    asDerived()
    {
        return static_cast<TDerived*>(this);
    }

    AmountType
    computeOverlap(const Region& singleCl, const Region& pairCl1,
        const Region& pairCl2);

    void
    computeProductionCoefficients();

    void
    computeDissociationCoefficients();

    void
    copyMomentIds(std::size_t clusterId,
        Kokkos::Array<std::size_t, 4>& momentIds)
    {
        if (clusterId == invalid) {
            momentIds = {invalid, invalid, invalid, invalid};
            return;
        }

        const auto& mIds = _network->getCluster(clusterId).getMomentIds();
        for (std::size_t i = 0; i < 4; ++i) {
            momentIds[i] = mIds[i];
        }
    }

    double
    computeProductionRate(std::size_t gridIndex);

    double
    computeDissociationRate(std::size_t gridIndex);

    void
    computeProductionRates()
    {
        for (std::size_t i = 0; i < _rate.extent(0); ++i) {
            _rate(i) = asDerived()->computeProductionRate(i);
        }
    }

    void
    computeDissociationRates()
    {
        for (std::size_t i = 0; i < _rate.extent(0); ++i) {
            _rate(i) = asDerived()->computeDissociationRate(i);
        }
    }

    void
    addConnectivity(std::size_t rowId, std::size_t columnId, ConnectivityView connectivity)
    {
        // Check if the columnId is already present
        std::size_t i = 0;
        for (i = 0; i < connectivity.extent(1); ++i) {
            if (connectivity(rowId, i) == columnId) {
                // It is already present, don't do anything
                return;
            }
            if (connectivity(rowId, i) == invalid) {
                // We reached the end of the list and it was not present
                break;
            }
        }
        // Add the value
        connectivity(rowId, i) = columnId;
    }

protected:
    NetworkType* _network {nullptr};

    Type _type {};

    using ConnectFn =
        void (Reaction::*)(ConnectivityView);
    ConnectFn _connectFn {nullptr};

    using FluxFn =
        void (Reaction::*)(ConcentrationsView, FluxesView, std::size_t);
    FluxFn _fluxFn {nullptr};

    using PartialsFn =
        void (Reaction::*)(ConcentrationsView,
            Kokkos::View<double*>, std::size_t);
    PartialsFn _partialsFn {nullptr};

    //Cluster indices for LHS and RHS of the reaction
    //Dissociation reactions always have 1 input and 2 outputs
    //Production reactions always have 2 inputs, but may have 0, 1, or 2 outputs
    Kokkos::Array<std::size_t, 2> _reactants {invalid, invalid};
    Kokkos::Array<std::size_t, 2> _products {invalid, invalid};

    //TODO: This '4' be numSpeciesNoI?
    static constexpr auto nMomentIds = NetworkType::getNumberOfSpeciesNoI();
    Kokkos::Array<Kokkos::Array<std::size_t, nMomentIds>, 2> _reactantMomentIds;
    Kokkos::Array<Kokkos::Array<std::size_t, nMomentIds>, 2> _productMomentIds;

    //! Reaction rate (k)
    Kokkos::View<double*> _rate;

    //! Flux coefficients
    Kokkos::View<double****> _coefs;
};
}
}

#include <experimental/Reaction.inl>