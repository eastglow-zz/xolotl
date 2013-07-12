#ifndef HEINTERSTITIALCLUSTER_H
#define HEINTERSTITIALCLUSTER_H

// Includes
#include "PSICluster.h"
#include <string>
#include <map>

namespace xolotlCore {

/**
 *  A cluster composed of helium and vacancies
 */
class HeInterstitialCluster : public PSICluster {

private:

	//! The number of helium atoms in this cluster.
	int numHe;

	//! The number of interstitial defects in this cluster.
	int numI;

	/**
	 * The default constructor is private because PSIClusters must always be
	 * initialized with a size.
	 */
	HeInterstitialCluster():PSICluster(1) {}

public:

	/**
	 * The constructor. All HeInterstitialClusters must be initialized with a map
	 * that describes the species of which the cluster is composed. The map
	 * should contain as its keys the names of the species and the sizes of the
	 * species as its values. The names of the species must be one of
	 * {He,I}.
	 */
	HeInterstitialCluster(const std::map<std::string,int> speciesMap);

	//! Destructor
	~HeInterstitialCluster();

	/**
	 * This operation returns the total generation rate due to emission for
	 * this cluster.
	 */
	double getGenByEm();

	/**
	 * This operation returns the total annihilation rate due to emission for
	 * this cluster.
	 */
	double getAnnByEm();

	/**
	 * This operation returns the number of a given "species" within this
	 * cluster by passing one of {He,I} as an input argument.
	 */
	int getSpeciesSize(const std::string speciesName);

	/**
	 * This operation overrides getConnectivity() from the base class to
	 * provide the proper connectivity for a mixed-species cluster.
	 * @return The connectivity array
	 */
    virtual std::vector<int> getConnectivity();

};
//end class HeInterstitialCluster

} /* end namespace xolotlCore */
#endif