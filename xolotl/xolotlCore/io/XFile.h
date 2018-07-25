#ifndef XCORE_XFILE_H
#define XCORE_XFILE_H

#include <string>
#include <vector>
#include <tuple>
#include "xolotlCore/io/HDF5File.h"
#include "xolotlCore/io/HDF5Exception.h"


namespace xolotlCore {


// Class for reading and writing an HDF5 file with Xolotl data.
// Note: the class stores 1D data as an attribute on a group instead
// of as a dataset.
// TODO Why?  because it is an attribute, every process must have same
// data to write.  As opposed to dataset, where can use independent file 
// access to let one process write. (?)
class XFile : public HDF5File {
public:

    // A group with info about a specific time step.
    class ConcentrationGroup;
    class TimestepGroup : public HDF5File::Group {
    private:

        // Prefix to use when constructing group names.
        static const std::string groupNamePrefix;

        // Names of time-related attributes.
        static const std::string absTimeAttrName;
        static const std::string prevTimeAttrName;
        static const std::string deltaTimeAttrName;

        // Names of surface position attributes.
        static const std::string surfacePosDataName;

        // Names of interstitial attributes.
        static const std::string nIntersAttrName;
        static const std::string prevIFluxAttrName;

        // Names of Helium attributes.
        static const std::string nHeAttrName;
        static const std::string prevHeFluxAttrName;

        // Names of Deuterium attributes.
        static const std::string nDAttrName;
        static const std::string prevDFluxAttrName;

        // Names of Tritium attributes.
        static const std::string nTAttrName;
        static const std::string prevTFluxAttrName;


        /**
         * Construct the group name for the given time step.
         *
         * @param concGroup The parent concentration group.
         * @param timeStep The time step the group will represent.
         * @return A string to use for the name of the time step group for
         *          the given time step.
         */
        static std::string makeGroupName(const ConcentrationGroup& concGroup,
                                            int timeStep);

    public:
        // Concise name for surface representations.
        using Surface1DType = int;
        using Surface2DType = std::vector<Surface1DType>;
        using Surface3DType = std::vector<Surface2DType>;

        // Concise name for data representations.
        using Data1DType = double;
        using Data2DType = std::vector<Data1DType>;
        using Data3DType = std::vector<Data2DType>;

        /**
         * Construct a TimestepGroup.
         * Default and copy constructors explicitly disallowed.
         */
        TimestepGroup(void) = delete;
        TimestepGroup(const TimestepGroup& other) = delete;

        /**
         * Create and populate a Timestep group within the given 
         * concentration group.
         *
         * @param timeStep The number of the time step
         * @param time The physical time at this time step
         * @param previousTime The physical time at the previous time step
         * @param deltaTime The physical length of the time step
         */
        TimestepGroup(const ConcentrationGroup& concGroup,
                            int timeStep,
                            double time,
                            double previousTime,
                            double deltaTime);

        /**
         * Open a TimestepGroup within the given concentration group.
         *
         * @param timeStep The time step of the desired group.
         */
        TimestepGroup(const ConcentrationGroup& concGroup, int timeStep);


        /**
         * Save the surface positions to our timestep group.
         *
         * @param iSurface The index of the surface position
         * @param nInter The quantity of interstitial at each surface position
         * @param previousFlux The previous I flux at each surface position
         */
        void writeSurface1D(Surface1DType iSurface,
                            Data1DType nInter,
                            Data1DType previousFlux) const;

        /**
         * Save the surface positions to our timestep group.
         *
         * @param iSurface The indices of the surface position
         * @param nInter The quantity of interstitial at each surface position
         * @param previousFlux The previous I flux at each surface position
         */
        void writeSurface2D(const Surface2DType& iSurface,
                            const Data2DType& nInter,
                            const Data2DType& previousFlux) const;

        /**
         * Save the surface positions to our timestep group.
         *
         * @param iSurface The indices of the surface position
         * @param nInter The quantity of interstitial at each surface position
         * @param previousFlux The previous I flux at each surface position
         */
        void writeSurface3D(const Surface3DType& iSurface,
                            const Data3DType& nInter,
                            const Data3DType& previousFlux) const;

        /**
         * Save the bottom informations to our timestep group.
         *
         * @param nHe The quantity of helium at the bottom
         * @param previousHeFlux The previous He flux
         * @param nD The quantity of deuterium at the bottom
         * @param previousDFlux The previous D flux
         * @param nT The quantity of tritium at the bottom
         * @param previousTFlux The previous T flux
         */
        void writeBottom1D(Data1DType nHe, Data1DType previousHeFlux,
                Data1DType nD, Data1DType previousDFlux,
                Data1DType nT, Data1DType previousTFlux);

        /**
         * Save the bottom informations to our timestep group.
         *
         * @param nHe The quantity of helium at the bottom
         * @param previousHeFlux The previous He flux
         * @param nD The quantity of deuterium at the bottom
         * @param previousDFlux The previous D flux
         * @param nT The quantity of tritium at the bottom
         * @param previousTFlux The previous T flux
         */
        void writeBottom2D(const Data2DType& nHe,
                            const Data2DType& previousHeFlux,
                            const Data2DType& nD,
                            const Data2DType& previousDFlux,
                            const Data2DType& nT,
                            const Data2DType& previousTFlux);


        /**
         * Add a concentration dataset at a specific grid point.
         *
         * @param size The size of the dataset to create
         * @param concArray The array of concentration at a grid point
         * @param i The index of the position on the grid on the x direction
         * @param j The index of the position on the grid on the y direction
         * @param k The index of the position on the grid on the z direction
         */
        void writeConcentrationDataset(int size,
                                        double concArray[][2],
                                        int i, int j = -1, int k = -1);

        /**
         * Read the times from our timestep group.
         *
         * @return pair(time, deltaTime) containing the physical time to 
         *          be changed and the time step length to be changed.
         */
        std::pair<double, double> readTimes(void) const;


        /**
         * Read the previous time from our concentration group.
         *
         * @return The physical time at the previous timestep
         */
        double readPreviousTime(void) const;

        /**
         * Read the surface position from our concentration group in
         * the case of a 1D grid (one surface position).
         *
         * @return The index of the surface position
         */
        Surface1DType readSurface1D(void) const;

        /**
         * Read the surface position from our concentration group in
         * the case of a 2D grid (a vector of surface positions).
         *
         * @return The vector of indices of the surface position
         */
        Surface2DType readSurface2D(void) const;

        /**
         * Read the surface position from our concentration group in
         * the case of a 3D grid (a vector of vector of surface positions).
         *
         * @return The vector of vector of indices of the surface position
         */
        Surface3DType readSurface3D(void) const;

        /**
         * Read some data from our concentration
         * group in the case of a 1D grid (one float).
         *
         * @param dataName The name of the data we want
         * @return The value of the data
         */
        Data1DType readData1D(const std::string& dataName) const;

        /**
         * Read some data from our concentration group in
         * the case of a 2D grid (a vector).
         *
         * @param dataName The name of the data we want
         * @return The vector of the data
         */
        Data2DType readData2D(const std::string& dataName) const;

        /**
         * Read some data from our concentration group file in
         * the case of a 3D grid (a vector of vector).
         *
         * @param dataName The name of the data we want
         * @return The vector of vector of data
         */
        Data3DType readData3D(const std::string& dataName) const;

        /**
         * Read our (i,j,k)-th grid point concentrations.
         *
         * @param i The index of the grid point on the x axis
         * @param j The index of the grid point on the y axis
         * @param k The index of the grid point on the z axis
         * @return The vector of concentrations
         */
        Data3DType readGridPoint(int i, int j = -1, int k = -1) const;
    };


    // Our concentrations group.
    class ConcentrationGroup : public HDF5File::Group {
    private:
        // Name of our last timestep attribute.
        static const std::string lastTimestepAttrName;

    public:
        // Path of the concentrations group within the file.
        static const fs::path path;

        // Create or open the concentrationsGroup.
        ConcentrationGroup(void) = delete;
        ConcentrationGroup(const ConcentrationGroup& other) = delete;
        ConcentrationGroup(const XFile& file, bool create = false);

        /**
         * Add a concentration timestep group for the given time step.
         *
         * @param timeStep The number of the time step
         * @param time The physical time at this time step
         * @param previousTime The physical time at the previous time step
         * @param deltaTime The physical length of the time step
         */
        std::unique_ptr<TimestepGroup> addTimestepGroup(int timeStep,
                                                    double time,
                                                    double previousTime,
                                                    double deltaTime) const;

        /**
         * Obtain the last timestep known to our group.
         *
         * @return Time step of last TimestepGroup written to our group.
         */
        int getLastTimeStep(void) const;


        /**
         * Determine if we have any TimestepGroups.
         *
         * @return True iff any TimestepGroups have been written.
         */
        bool hasTimesteps(void) const { return getLastTimeStep() >= 0; }

        /**
         * Access the TimestepGroup associated with the given time step.
         *
         * @param ts Time step of the desired TimestepGroup.
         * @return TimestepGroup associated with the given time step.  Empty
         *          pointer if the given time step is not known to us.
         */
        std::unique_ptr<TimestepGroup> getTimestepGroup(int timeStep) const;


        /**
         * Access the TimestepGroup associated with the last known time step.
         *
         * @return TimestepGroup associated with the last known time step.
         *          Empty pointer if we do not yet have any time steps.
         */
        std::unique_ptr<TimestepGroup> getLastTimestepGroup(void) const;
    };


    // Our header group.
    class HeaderGroup : public HDF5File::Group {
    public:
        // Concise name for type of network compositions 
        // in HDF5 class method parameters.
        using NetworkCompsType = std::vector<std::vector<int>>;

    private:
        // Name of network composition dataset within our group.
        static const std::string netCompsDatasetName;

        // Names of grid-specification attributes.
        static const std::string nxAttrName;
        static const std::string hxAttrName;
        static const std::string nyAttrName;
        static const std::string hyAttrName;
        static const std::string nzAttrName;
        static const std::string hzAttrName;

        /**
         * Initialize the list of cluster compositions.
         *
         * @param compVec The vector of composition
         */
        void initNetworkComps(const NetworkCompsType& compVec) const;

    public:
        // Path of the header group within the file.
        static const fs::path path;

        /**
         * Create the header group.
         * Default and copy constructors explicitly disallowed.
         */
        HeaderGroup(void) = delete;
        HeaderGroup(const HeaderGroup& other) = delete;

        /**
         * Create and initialize the header group with the number of 
         * points and step size in each direction.
         *
         * @param file The file in which the header should be added.
         * @param grid The grid points in the x direction (depth)
         * @param ny The number of grid points in the y direction
         * @param hy The step size in the y direction
         * @param nz The number of grid points in the z direction
         * @param hz The step size in the z direction
         */
        HeaderGroup(const XFile& file,
                const std::vector<double>& grid,
                int ny, double hy,
                int nz, double hz,
                const NetworkCompsType& compVec);

        /**
         * Open an existing header group.
         */
        HeaderGroup(const XFile& file);

        /**
         * Read our file header.
         *
         * @param nx The number of grid points in the x direction (depth)
         * @param hx The step size in the x direction
         * @param ny The number of grid points in the y direction
         * @param hy The step size in the y direction
         * @param nz The number of grid points in the z direction
         * @param hz The step size in the z direction
         */
        void read(int &nx, double &hx, int &ny,
                double &hy, int &nz, double &hz) const;

        /**
         * Read our network compositions.
         *
         * @return The compositions of our network.
         */
        NetworkCompsType readNetworkComps(void) const;
    };


    // A group describing a network within our HDF5 file.
    class NetworkGroup : public HDF5File::Group {
    public:
        // Concise name for type of network
        // in HDF5 class method parameters.
        using NetworkType = std::vector<std::vector<double>>;

        // Path to the network group within our HDF5 file.
        static const fs::path path;

        // Name of network dataset.
        static const std::string netDatasetName;


        NetworkGroup(void) = delete;
        NetworkGroup(const NetworkGroup& other) = delete;

        /**
         * Open an existing network group.
         *
         * @param file The file whose network group to open.
         */
        NetworkGroup(const XFile& file);


        /**
         * Read the network from our group.
         * 
         * @return The vector of vector which contain the network dataset.
         */
        NetworkType readNetwork(void) const;

        
        /**
         * Copy ourself to the given file.
         * A NetworkGroup must not already exist in the file.
         *
         * @param target The file to copy ourself to.
         */
        void copyTo(const XFile& target) const;
    };

private:

    /**
     * Pass through only Create* access modes.
     *
     * @param mode The access mode to check.
     * @return The given access mode if it is a Create* mode.  Otherwise, 
     *          throws an exception.
     */
    static AccessMode EnsureCreateAccessMode(AccessMode mode);

    /**
     * Pass through only Open* access modes.
     *
     * @param mode The access mode to check.
     * @return The given access mode if it is a Open* mode.  Otherwise, 
     *          throws an exception.
     */
    static AccessMode EnsureOpenAccessMode(AccessMode mode);


public:
    /**
     * Create and initialize a checkpoint file.
     *
     * @param path Path of file to create.
     * @param grid The grid points in the x direction (depth)
     * @param compVec The composition vector.
     * @param networkFilePath Path to file from which the network will 
     *          be copied.  No network will be copied if networkFilePath 
     *          is empty.
     * @param ny The number of grid points in the y direction
     * @param hy The step size in the y direction
     * @param nz The number of grid points in the z direction
     * @param hz The step size in the z direction
     * @param mode Access mode for file.  Only HDF5File Create* modes 
     *              are supported.
     */
    XFile(fs::path path,
            const std::vector<double>& grid,
            const HeaderGroup::NetworkCompsType& compVec,
            fs::path networkFilePath,
            int ny = 0,
            double hy = 0.0,
            int nz = 0,
            double hz = 0.0,
            AccessMode mode = AccessMode::CreateOrTruncateIfExists);


    /**
     * Open an existing checkpoint or network file.
     *
     * @param path Path of file to open.
     * @param mode Access mode for file.  Only HDFFile Open* modes 
     *              are supported.
     */
    XFile(fs::path path, AccessMode mode = AccessMode::OpenReadOnly);


    /**
     * Check whether we have one of our top-level Groups.
     *
     * @return True iff we have the desired group.
     */
    template<typename T>
    bool hasGroup(void) const {

        return HDF5File::hasGroup(T::path);
    }


    /**
     * Access one of our top-level Groups within our file.
     *
     * @return The group object if we can open the group, else an empty pointer.
     */
    template<typename T>
    std::unique_ptr<T> getGroup(void) const {
        
        std::unique_ptr<T> group;

        std::cout << "checking for group" << std::endl;
        if(hasGroup<T>()) {
            std::cout << "opening group" << std::endl;
            // Open the group within our file.
            group.reset(new T(*this));
        }
        std::cout << "returning group" << std::endl;
        return std::move(group);
    }
};

} /* namespace xolotlCore */

#endif // XCORE_XFILE_H

