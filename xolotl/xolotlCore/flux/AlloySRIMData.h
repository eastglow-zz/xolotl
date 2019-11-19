#ifndef ALLOYSRIMDATA_H
#define ALLOYSRIMDATA_H

namespace xolotlCore {

// begin class Cascade
class Cascade {
private:
public:
	std::vector<std::vector<double> > clusterFraction;
	const std::vector<int> clusterSizes;
	std::vector<double> cascadeEfficiency;
	const double perfectFraction;

	Cascade() :
			clusterSizes( { 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31,
					30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14,
                13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, -1, -2, -3, -4, -5, -6, -7,
                -8, -9, -10, -11, -12, -13, -14, -15, -16, -17, -18, -19, -20, -21,
                -22, -23, -24, -25, -26, -27, -28, -29, -30, -31, -32, -33, -34, -35,
                -36, -37, -38, -39, -40, -41, -42, -43, -44, -45
            }), perfectFraction(
					0.8) {
		return;
	}

	void setBulk() {
		cascadeEfficiency =
		{ 0.15 };
		clusterFraction = { {0.000}, {0.000}, {0.019}, {0.021}, {0.001}, {0.006}, {0.003},
	    {0.002}, {0.003}, {0.000}, {0.003}, {0.002}, {0.010}, {0.003}, {0.013}, {0.003},
	    {0.003}, {0.010}, {0.001}, {0.002}, {0.002}, {0.005}, {0.003}, {0.006}, {0.003},
	    {0.006}, {0.002}, {0.003}, {0.013}, {0.003}, {0.005}, {0.016}, {0.008}, {0.014},
	    {0.011}, {0.032}, {0.016}, {0.016}, {0.019}, {0.039}, {0.035}, {0.066}, {0.120},
	    {0.100}, {0.350}, {0.350}, {0.100}, {0.120}, {0.066}, {0.035}, {0.039}, {0.019},
	    {0.016}, {0.016}, {0.032}, {0.011}, {0.014}, {0.008}, {0.016}, {0.005}, {0.003},
	    {0.013}, {0.003}, {0.002}, {0.006}, {0.003}, {0.006}, {0.003}, {0.005}, {0.002},
	    {0.002}, {0.001}, {0.010}, {0.003}, {0.003}, {0.013}, {0.003}, {0.010}, {0.002},
	    {0.003}, {0.000}, {0.003}, {0.002}, {0.003}, {0.006}, {0.001}, {0.021}, {0.019},
	    {0.000}, {0.000}
        };}

	void setOverlap() {
		cascadeEfficiency =
		{ 0.15 };
        clusterFraction = { {0.000}, {0.000}, {0.019}, {0.021}, {0.001}, {0.006}, {0.003},
            {0.002}, {0.003}, {0.000}, {0.003}, {0.002}, {0.010}, {0.003}, {0.013}, {0.003},
	    {0.003}, {0.010}, {0.001}, {0.002}, {0.002}, {0.005}, {0.003}, {0.006}, {0.003},
	    {0.006}, {0.002}, {0.003}, {0.013}, {0.003}, {0.005}, {0.016}, {0.008}, {0.014},
	    {0.011}, {0.032}, {0.016}, {0.016}, {0.019}, {0.039}, {0.035}, {0.066}, {0.120},
	    {0.100}, {0.350}, {0.350}, {0.100}, {0.120}, {0.066}, {0.035}, {0.039}, {0.019},
	    {0.016}, {0.016}, {0.032}, {0.011}, {0.014}, {0.008}, {0.016}, {0.005}, {0.003},
	    {0.013}, {0.003}, {0.002}, {0.006}, {0.003}, {0.006}, {0.003}, {0.005}, {0.002},
	    {0.002}, {0.001}, {0.010}, {0.003}, {0.003}, {0.013}, {0.003}, {0.010}, {0.002},
	    {0.003}, {0.000}, {0.003}, {0.002}, {0.003}, {0.006}, {0.001}, {0.021}, {0.019},
	    {0.000}, {0.000}
        };}
};
// end class Cascade

class SRIMData {
protected:
	std::vector<double> depth;
	std::vector<std::vector<double> > damage;
	std::vector<double> implantation;
public:
	SRIMData() {
		return;
	}
	std::vector<double> getDepth() {
		return depth;
	}
	std::vector<std::vector<double> > getDamage() {
		return damage;
	}
	std::vector<double> getImplantation() {
		return implantation;
	}
	void setInSitu() {
		depth =
		{	10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160,
			170, 180, 190, 200, 210, 220, 230, 240, 250, 260, 270, 280, 290, 300,
			310, 320, 330, 340, 350, 360, 370, 380, 390, 400, 410, 420, 430, 440,
			450, 460, 470, 480, 490, 500, 510, 520, 530, 540, 550};
		damage =
		{	{	0.989951, 1.12413, 1.05185, 9.24095},
			{	1.07173, 1.20697, 1.13084, 9.82103},
			{	1.10253, 1.25748, 1.17203, 10.2216},
			{	1.14176, 1.30553, 1.24145, 10.5252},
			{	1.18783, 1.36207, 1.27287, 10.6713},
			{	1.22959, 1.42007, 1.34888, 11.1115},
			{	1.27548, 1.48213, 1.41754, 11.3377},
			{	1.32009, 1.56411, 1.46843, 11.6518},
			{	1.3591, 1.60631, 1.53331, 12.0082},
			{	1.40554, 1.67004, 1.55905, 12.144},
			{	1.4505, 1.72672, 1.64081, 12.281},
			{	1.49526, 1.78127, 1.70252, 12.5266},
			{	1.54246, 1.85934, 1.78801, 12.7381},
			{	1.57722, 1.89112, 1.81832, 12.8325},
			{	1.60336, 1.93527, 1.87448, 12.7261},
			{	1.62848, 1.98116, 1.88077, 12.5582},
			{	1.64243, 2.00864, 1.91759, 12.491},
			{	1.66256, 2.0403, 1.94385, 12.2427},
			{	1.65517, 2.04298, 1.93514, 11.9928},
			{	1.6395, 2.01447, 1.93511, 11.6899},
			{	1.60955, 1.98671, 1.89988, 11.0849},
			{	1.57854, 1.93925, 1.85491, 10.7857},
			{	1.53209, 1.88592, 1.81087, 10.0685},
			{	1.45592, 1.8032, 1.73988, 9.3749},
			{	1.38467, 1.71331, 1.63133, 8.60395},
			{	1.29988, 1.61522, 1.54271, 7.99702},
			{	1.20527, 1.48536, 1.42954, 7.03046},
			{	1.10948, 1.38457, 1.28553, 6.27128},
			{	0.993709, 1.23881, 1.16539, 5.39555},
			{	0.880955, 1.0885, 1.02545, 4.76185},
			{	0.784851, 0.974278, 0.916095, 3.99001},
			{	0.68391, 0.853514, 0.794634, 3.34665},
			{	0.578624, 0.70784, 0.663107, 2.82839},
			{	0.485876, 0.601163, 0.565777, 2.26214},
			{	0.401816, 0.489428, 0.470619, 1.78098},
			{	0.32581, 0.395406, 0.366279, 1.39933},
			{	0.260004, 0.319967, 0.299005, 1.116},
			{	0.203472, 0.252726, 0.23789, 0.808684},
			{	0.154129, 0.188876, 0.173798, 0.605839},
			{	0.115232, 0.139769, 0.127419, 0.438295},
			{	0.085828, 0.100144, 0.098823, 0.300228},
			{	0.062848, 0.07526, 0.065442, 0.2072},
			{	0.043048, 0.050146, 0.044712, 0.139193},
			{	0.030835, 0.039912, 0.029841, 0.098319},
			{	0.019071, 0.025462, 0.020913, 0.052365},
			{	0.012395, 0.016556, 0.011996, 0.03929},
			{	0.007989, 0.009955, 0.008984, 0.020821},
			{	0.004741, 0.005594, 0.005747, 0.01566},
			{	0.003316, 0.003524, 0.003409, 0.007423},
			{	0.001806, 0.002373, 0.002065, 0.003454},
			{	0.000972, 0.001386, 0.001748, 0.002218},
			{	0.000804, 0.000733, 0.000546, 0.001833},
			{	0.000316, 0.00058, 0.000445, 0.000849},
			{	0.000184, 0.000234, 0.000148, 0.000214},
			{	4.9e-05, 6.6e-05, 0, 0}};
		implantation =
		{	1.9e-05, 6.3e-05, 0.000129, 0.000204, 0.000329, 0.00048, 0.000589,
			0.00077, 0.000925, 0.001097, 0.001327, 0.001591, 0.001911, 0.002122,
			0.002317, 0.00265, 0.003025, 0.003322, 0.003629, 0.003816, 0.004143,
			0.004342, 0.004611, 0.004679, 0.004683, 0.004796, 0.004641, 0.004553,
			0.004344, 0.004022, 0.003776, 0.003531, 0.003123, 0.002714, 0.00237,
			0.002035, 0.001664, 0.001434, 0.001133, 0.000826, 0.000677, 0.000464,
			0.000361, 0.000263, 0.000177, 0.000119, 7.5e-05, 4.9e-05, 2.8e-05,
			1.5e-05, 1.5e-05, 1.1e-05, 2e-06, 2e-06, 2e-06};
		return;
	}
	void setBulk ()
	{
		depth =
		{	10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160,
			170, 180, 190, 200, 210, 220, 230, 240, 250, 260, 270, 280, 290, 300,
			310, 320, 330, 340, 350, 360, 370, 380, 390, 400, 410, 420, 430, 440,
			450, 460, 470, 480, 490, 500, 510, 520, 530, 540, 550, 560, 570, 580,
			590, 600, 610, 620, 630, 640, 650, 660, 670, 680, 690, 700, 710, 720,
			730, 740, 750, 760, 770, 780, 790, 800, 810, 820, 830, 840, 850, 860,
			870, 880, 890, 900, 910, 920, 930, 940, 950, 960, 970, 980, 990, 1000,
			1010, 1020, 1030, 1040, 1050, 1060, 1070, 1080, 1090, 1100, 1110,
			1120, 1130, 1140, 1150, 1160, 1170, 1180, 1190, 1200, 1210, 1220,
			1230, 1240, 1250, 1260, 1270, 1280, 1290, 1300, 1310, 1320, 1330,
			1340, 1350, 1360, 1370, 1380, 1390, 1400, 1410, 1420, 1430, 1440,
			1450, 1460, 1470, 1480, 1490, 1500, 1510 ,1520, 1530, 1540, 1550,
			1560, 1570, 1580, 1590, 1600, 1610, 1620, 1630, 1640, 1650, 1660,
			1670, 1680, 1690, 1700, 1710, 1720, 1730, 1740, 1750, 1760, 1770,
			1780, 1790, 1800, 1810, 1820, 1830, 1840, 1850, 1860, 1870, 1880,
			1890, 1900, 1910, 1920, 1930};
		damage =
		{	{ 8.57E+01, 0.0}};
		implantation =
		{	1.000E-06, 1.000E-06, 1.000E-06, 1.000E-06, 2.000E-06, 2.000E-06,
			3.000E-06, 3.000E-06, 1.000E-06, 2.000E-06, 2.000E-06, 1.000E-06,
			4.000E-06, 3.000E-06, 1.000E-05, 2.000E-06, 6.000E-06, 3.000E-06,
			5.000E-06, 6.000E-06, 7.000E-06, 3.000E-06, 8.000E-06, 9.000E-06,
			7.000E-06, 1.000E-05, 1.300E-05, 9.000E-06, 1.600E-05, 1.200E-05,
			1.000E-05, 1.100E-05, 1.400E-05, 1.400E-05, 1.600E-05, 1.300E-05,
			1.800E-05, 1.400E-05, 1.100E-05, 1.200E-05, 2.100E-05, 1.700E-05,
			1.500E-05, 2.000E-05, 3.300E-05, 2.700E-05, 3.200E-05, 2.600E-05,
			4.000E-05, 2.500E-05, 1.700E-05, 3.500E-05, 3.700E-05, 3.700E-05,
			3.300E-05, 3.200E-05, 4.800E-05, 4.300E-05, 5.000E-05, 4.900E-05,
			5.200E-05, 3.500E-05, 6.400E-05, 5.800E-05, 7.400E-05, 6.000E-05,
			7.600E-05, 8.700E-05, 7.100E-05, 7.800E-05, 9.700E-05, 9.000E-05,
			1.060E-04, 1.000E-04, 1.070E-04, 1.260E-04, 1.210E-04, 1.160E-04,
			1.250E-04, 1.290E-04, 1.730E-04, 1.400E-04, 1.590E-04, 1.760E-04,
			1.840E-04, 1.700E-04, 1.970E-04, 2.260E-04, 2.490E-04, 2.430E-04,
			2.290E-04, 2.570E-04, 2.870E-04, 3.140E-04, 2.990E-04, 3.330E-04,
			3.520E-04, 3.620E-04, 3.810E-04, 4.450E-04, 4.550E-04, 4.970E-04,
			4.950E-04, 4.810E-04, 5.390E-04, 5.780E-04, 6.270E-04, 6.390E-04,
			6.500E-04, 7.000E-04, 7.160E-04, 7.700E-04, 8.160E-04, 8.590E-04,
			9.000E-04, 9.100E-04, 9.820E-04, 1.047E-03, 1.056E-03, 1.104E-03,
			1.184E-03, 1.232E-03, 1.322E-03, 1.327E-03, 1.470E-03, 1.483E-03,
			1.542E-03, 1.563E-03, 1.615E-03, 1.729E-03, 1.673E-03, 1.830E-03,
			1.830E-03, 1.865E-03, 1.928E-03, 1.978E-03, 2.008E-03, 2.114E-03,
			1.996E-03, 1.991E-03, 2.056E-03, 2.132E-03, 2.079E-03, 2.069E-03,
			2.076E-03, 2.008E-03, 1.981E-03, 1.997E-03, 1.950E-03, 1.899E-03,
			1.897E-03, 1.729E-03, 1.776E-03, 1.668E-03, 1.654E-03, 1.535E-03,
			1.387E-03, 1.289E-03, 1.182E-03, 1.149E-03, 1.007E-03, 9.740E-04,
			8.950E-04, 7.440E-04, 6.490E-04, 5.890E-04, 5.510E-04, 4.640E-04,
			4.110E-04, 3.470E-04, 2.890E-04, 2.500E-04, 1.870E-04, 1.670E-04,
			1.200E-04, 1.030E-04, 8.100E-05, 5.800E-05, 6.200E-05, 4.300E-05,
			3.200E-05, 2.400E-05, 1.700E-05, 1.900E-05, 9.000E-06, 4.000E-06,
			4.000E-06, 5.000E-06, 4.000E-06, 1.000E-06, 1.000E-06, 1.000E-06,
			1.000E-06};
		return;
	}
	void setOverlap() {
		depth =
		{	0};
		damage =
		{	{	8.57E+01, 0.0}};
		implantation =
		{	0.0};
		return;
	}
};
/*
 // begin class InSituIon
 class InSituIon : public SRIMData {
 private:
 public:
 InSituIon () {return;}
 void set ()
 {
 depth =
 { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160,
 170, 180, 190, 200, 210, 220, 230, 240, 250, 260, 270, 280, 290, 300,
 310, 320, 330, 340, 350, 360, 370, 380, 390, 400, 410, 420, 430, 440,
 450, 460, 470, 480, 490, 500, 510, 520, 530, 540, 550 };
 damage =
 { { 0.989951, 1.12413, 1.05185, 9.24095 },
 { 1.07173, 1.20697, 1.13084, 9.82103 },
 { 1.10253, 1.25748, 1.17203, 10.2216 },
 { 1.14176, 1.30553, 1.24145, 10.5252 },
 { 1.18783, 1.36207, 1.27287, 10.6713 },
 { 1.22959, 1.42007, 1.34888, 11.1115 },
 { 1.27548, 1.48213, 1.41754, 11.3377 },
 { 1.32009, 1.56411, 1.46843, 11.6518 },
 { 1.3591, 1.60631, 1.53331, 12.0082 },
 { 1.40554, 1.67004, 1.55905, 12.144 },
 { 1.4505, 1.72672, 1.64081, 12.281 },
 { 1.49526, 1.78127, 1.70252, 12.5266 },
 { 1.54246, 1.85934, 1.78801, 12.7381 },
 { 1.57722, 1.89112, 1.81832, 12.8325 },
 { 1.60336, 1.93527, 1.87448, 12.7261 },
 { 1.62848, 1.98116, 1.88077, 12.5582 },
 { 1.64243, 2.00864, 1.91759, 12.491 },
 { 1.66256, 2.0403, 1.94385, 12.2427 },
 { 1.65517, 2.04298, 1.93514, 11.9928 },
 { 1.6395, 2.01447, 1.93511, 11.6899 },
 { 1.60955, 1.98671, 1.89988, 11.0849 },
 { 1.57854, 1.93925, 1.85491, 10.7857 },
 { 1.53209, 1.88592, 1.81087, 10.0685 },
 { 1.45592, 1.8032, 1.73988, 9.3749 },
 { 1.38467, 1.71331, 1.63133, 8.60395 },
 { 1.29988, 1.61522, 1.54271, 7.99702 },
 { 1.20527, 1.48536, 1.42954, 7.03046 },
 { 1.10948, 1.38457, 1.28553, 6.27128 },
 { 0.993709, 1.23881, 1.16539, 5.39555 },
 { 0.880955, 1.0885, 1.02545, 4.76185 },
 { 0.784851, 0.974278, 0.916095, 3.99001 },
 { 0.68391, 0.853514, 0.794634, 3.34665 },
 { 0.578624, 0.70784, 0.663107, 2.82839 },
 { 0.485876, 0.601163, 0.565777, 2.26214 },
 { 0.401816, 0.489428, 0.470619, 1.78098 },
 { 0.32581, 0.395406, 0.366279, 1.39933 },
 { 0.260004, 0.319967, 0.299005, 1.116 },
 { 0.203472, 0.252726, 0.23789, 0.808684 },
 { 0.154129, 0.188876, 0.173798, 0.605839 },
 { 0.115232, 0.139769, 0.127419, 0.438295 },
 { 0.085828, 0.100144, 0.098823, 0.300228 },
 { 0.062848, 0.07526, 0.065442, 0.2072 },
 { 0.043048, 0.050146, 0.044712, 0.139193 },
 { 0.030835, 0.039912, 0.029841, 0.098319 },
 { 0.019071, 0.025462, 0.020913, 0.052365 },
 { 0.012395, 0.016556, 0.011996, 0.03929 },
 { 0.007989, 0.009955, 0.008984, 0.020821 },
 { 0.004741, 0.005594, 0.005747, 0.01566 },
 { 0.003316, 0.003524, 0.003409, 0.007423 },
 { 0.001806, 0.002373, 0.002065, 0.003454 },
 { 0.000972, 0.001386, 0.001748, 0.002218 },
 { 0.000804, 0.000733, 0.000546, 0.001833 },
 { 0.000316, 0.00058, 0.000445, 0.000849 },
 { 0.000184, 0.000234, 0.000148, 0.000214 },
 { 4.9e-05, 6.6e-05, 0, 0 } };
 implantation =
 { 1.9e-05, 6.3e-05, 0.000129, 0.000204, 0.000329, 0.00048, 0.000589,
 0.00077, 0.000925, 0.001097, 0.001327, 0.001591, 0.001911, 0.002122,
 0.002317, 0.00265, 0.003025, 0.003322, 0.003629, 0.003816, 0.004143,
 0.004342, 0.004611, 0.004679, 0.004683, 0.004796, 0.004641, 0.004553,
 0.004344, 0.004022, 0.003776, 0.003531, 0.003123, 0.002714, 0.00237,
 0.002035, 0.001664, 0.001434, 0.001133, 0.000826, 0.000677, 0.000464,
 0.000361, 0.000263, 0.000177, 0.000119, 7.5e-05, 4.9e-05, 2.8e-05,
 1.5e-05, 1.5e-05, 1.1e-05, 2e-06, 2e-06, 2e-06 };
 return;
 }
 };
 // end class InSituIon

 // begin class BulkIon
 class BulkIon : public SRIMData {
 private:
 public:
 BulkIon () {return;}
 void set ()
 {
 depth =
 { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160,
 170, 180, 190, 200, 210, 220, 230, 240, 250, 260, 270, 280, 290, 300,
 310, 320, 330, 340, 350, 360, 370, 380, 390, 400, 410, 420, 430, 440,
 450, 460, 470, 480, 490, 500, 510, 520, 530, 540, 550, 560, 570, 580,
 590, 600, 610, 620, 630, 640, 650, 660, 670, 680, 690, 700, 710, 720,
 730, 740, 750, 760, 770, 780, 790, 800, 810, 820, 830, 840, 850, 860,
 870, 880, 890, 900, 910, 920, 930, 940, 950, 960, 970, 980, 990, 1000,
 1010, 1020, 1030, 1040, 1050, 1060, 1070, 1080, 1090, 1100, 1110,
 1120, 1130, 1140, 1150, 1160, 1170, 1180, 1190, 1200, 1210, 1220,
 1230, 1240, 1250, 1260, 1270, 1280, 1290, 1300, 1310, 1320, 1330,
 1340, 1350, 1360, 1370, 1380, 1390, 1400, 1410, 1420, 1430, 1440,
 1450, 1460, 1470, 1480, 1490, 1500, 1510 ,1520, 1530, 1540, 1550,
 1560, 1570, 1580, 1590, 1600, 1610, 1620, 1630, 1640, 1650, 1660,
 1670, 1680, 1690, 1700, 1710, 1720, 1730, 1740, 1750, 1760, 1770,
 1780, 1790, 1800, 1810, 1820, 1830, 1840, 1850, 1860, 1870, 1880,
 1890, 1900, 1910, 1920, 1930 };
 damage =
 { { 0.271542, 0.200304, 0.15497, 1.05477 },
 { 0.308535, 0.227273, 0.175254, 1.2167 },
 { 0.313186, 0.228889, 0.176485, 1.22415 },
 { 0.313976, 0.230839, 0.180637, 1.22845 },
 { 0.316711, 0.232956, 0.185423, 1.31091 },
 { 0.31923, 0.238938, 0.182036, 1.33319 },
 { 0.322641, 0.236294, 0.189074, 1.27171 },
 { 0.322583, 0.242254, 0.18536, 1.42532 },
 { 0.325382, 0.237198, 0.187236, 1.4006 },
 { 0.3279, 0.24536, 0.191383, 1.32588 },
 { 0.331271, 0.246947, 0.183649, 1.39913 },
 { 0.333967, 0.247791, 0.190035, 1.48317 },
 { 0.339535, 0.252277, 0.193684, 1.38152 },
 { 0.339247, 0.253732, 0.195976, 1.44453 },
 { 0.344277, 0.258417, 0.197942, 1.52424 },
 { 0.345131, 0.256587, 0.198708, 1.4731 },
 { 0.346128, 0.258416, 0.204506, 1.45124 },
 { 0.349744, 0.265473, 0.205441, 1.55873 },
 { 0.354676, 0.262585, 0.204402, 1.52726 },
 { 0.355892, 0.266649, 0.209379, 1.58067 },
 { 0.358503, 0.274799, 0.216807, 1.64 },
 { 0.36195, 0.272287, 0.216512, 1.53508 },
 { 0.363489, 0.274062, 0.214242, 1.59797 },
 { 0.368892, 0.277106, 0.223721, 1.65227 },
 { 0.370983, 0.282585, 0.220528, 1.52918 },
 { 0.37113, 0.285635, 0.223678, 1.73649 },
 { 0.378636, 0.285204, 0.226825, 1.67444 },
 { 0.379017, 0.293226, 0.219868, 1.59167 },
 { 0.382543, 0.29157, 0.236709, 1.68085 },
 { 0.384638, 0.293908, 0.236073, 1.72216 },
 { 0.388989, 0.299659, 0.237299, 1.74993 },
 { 0.392169, 0.307392, 0.234026, 1.78978 },
 { 0.392953, 0.301044, 0.241205, 1.74326 },
 { 0.399036, 0.307131, 0.235749, 1.78594 },
 { 0.402971, 0.309731, 0.247778, 1.84412 },
 { 0.406056, 0.31041, 0.24701, 1.85957 },
 { 0.407457, 0.311099, 0.245753, 1.94592 },
 { 0.412759, 0.320674, 0.248154, 1.87077 },
 { 0.415427, 0.318267, 0.258701, 1.91052 },
 { 0.418997, 0.319928, 0.265583, 1.95735 },
 { 0.421976, 0.333949, 0.255045, 2.018 },
 { 0.429893, 0.330961, 0.260994, 2.00642 },
 { 0.430243, 0.3384, 0.26555, 2.01716 },
 { 0.435444, 0.343825, 0.275771, 2.08169 },
 { 0.439977, 0.347026, 0.278855, 2.18397 },
 { 0.441723, 0.346736, 0.287894, 1.988 },
 { 0.446155, 0.355251, 0.280912, 2.06344 },
 { 0.452276, 0.352173, 0.289389, 2.06639 },
 { 0.454641, 0.355359, 0.291266, 2.15768 },
 { 0.458926, 0.365162, 0.290609, 2.19066 },
 { 0.463985, 0.367106, 0.296867, 2.2319 },
 { 0.468968, 0.367147, 0.301035, 2.23369 },
 { 0.469916, 0.376197, 0.304183, 2.33112 },
 { 0.475779, 0.379309, 0.310031, 2.27661 },
 { 0.482441, 0.388498, 0.305269, 2.26104 },
 { 0.486144, 0.391025, 0.316509, 2.35575 },
 { 0.493252, 0.391624, 0.327218, 2.34856 },
 { 0.496328, 0.402682, 0.331662, 2.25123 },
 { 0.500091, 0.405808, 0.334722, 2.46985 },
 { 0.505993, 0.414894, 0.326732, 2.47988 },
 { 0.513089, 0.417427, 0.338518, 2.53694 },
 { 0.518201, 0.416796, 0.337374, 2.62188 },
 { 0.523506, 0.428362, 0.348137, 2.55835 },
 { 0.527804, 0.431308, 0.350659, 2.62657 },
 { 0.535058, 0.435404, 0.354886, 2.67037 },
 { 0.538959, 0.449026, 0.358151, 2.72607 },
 { 0.542647, 0.448471, 0.376197, 2.72163 },
 { 0.55044, 0.454195, 0.380088, 2.66093 },
 { 0.554669, 0.457142, 0.377086, 2.84762 },
 { 0.559456, 0.470885, 0.376428, 2.85066 },
 { 0.568408, 0.472975, 0.392917, 2.83421 },
 { 0.571709, 0.479644, 0.388523, 2.863 },
 { 0.5799, 0.485007, 0.397669, 2.974 },
 { 0.588853, 0.491037, 0.415315, 3.04993 },
 { 0.587539, 0.500913, 0.411884, 3.06522 },
 { 0.595642, 0.51053, 0.424472, 3.1309 },
 { 0.601653, 0.519852, 0.429073, 3.18052 },
 { 0.599336, 0.522751, 0.435563, 3.15522 },
 { 0.608205, 0.530199, 0.451304, 3.24409 },
 { 0.614477, 0.542187, 0.450003, 3.37267 },
 { 0.62307, 0.54901, 0.462192, 3.43177 },
 { 0.625501, 0.563057, 0.457105, 3.41073 },
 { 0.631809, 0.572881, 0.481554, 3.48684 },
 { 0.6345, 0.5795, 0.476084, 3.67413 },
 { 0.637833, 0.593492, 0.503027, 3.74298 },
 { 0.644778, 0.598994, 0.50646, 3.5994 },
 { 0.653143, 0.609963, 0.531303, 3.80663 },
 { 0.655333, 0.622208, 0.531883, 3.80684 },
 { 0.664436, 0.639954, 0.532095, 3.85805 },
 { 0.671113, 0.640401, 0.556287, 3.83263 },
 { 0.677298, 0.648467, 0.537795, 4.02621 },
 { 0.687061, 0.662392, 0.566079, 4.01542 },
 { 0.696162, 0.672784, 0.57056, 4.10639 },
 { 0.705498, 0.684059, 0.574729, 4.18461 },
 { 0.715644, 0.696285, 0.592495, 4.34835 },
 { 0.725883, 0.706214, 0.601393, 4.30578 },
 { 0.731022, 0.724806, 0.624863, 4.24048 },
 { 0.744127, 0.727851, 0.635187, 4.4681 },
 { 0.754965, 0.740065, 0.643695, 4.61189 },
 { 0.770187, 0.758152, 0.65665, 4.71497 },
 { 0.777844, 0.775026, 0.672827, 4.59334 },
 { 0.794051, 0.792237, 0.697228, 4.83242 },
 { 0.795312, 0.802649, 0.679003, 4.67016 },
 { 0.800602, 0.806831, 0.697019, 4.8243 },
 { 0.814962, 0.823537, 0.713271, 4.8608 },
 { 0.824558, 0.839092, 0.732816, 4.79872 },
 { 0.844119, 0.850955, 0.734862, 4.96035 },
 { 0.846441, 0.868982, 0.752019, 4.9611 },
 { 0.852767, 0.868297, 0.779787, 5.04044 },
 { 0.872952, 0.880533, 0.784897, 5.33257 },
 { 0.870717, 0.898393, 0.776986, 5.30854 },
 { 0.887479, 0.907731, 0.788749, 5.21942 },
 { 0.898905, 0.936669, 0.814825, 5.33997 },
 { 0.906132, 0.955856, 0.829126, 5.28971 },
 { 0.912545, 0.951197, 0.827521, 5.43007 },
 { 0.921995, 0.964912, 0.861425, 5.41668 },
 { 0.922455, 0.975831, 0.846479, 5.45765 },
 { 0.944688, 0.991121, 0.859583, 5.4679 },
 { 0.944589, 0.992061, 0.875821, 5.35226 },
 { 0.946809, 1.01714, 0.881817, 5.52679 },
 { 0.960412, 1.02547, 0.892385, 5.51695 },
 { 0.965203, 1.02946, 0.934559, 5.58448 },
 { 0.970955, 1.04035, 0.925605, 5.46525 },
 { 0.971033, 1.04475, 0.938264, 5.65051 },
 { 0.984639, 1.0571, 0.93468, 5.57807 },
 { 0.97022, 1.0502, 0.918006, 5.52562 },
 { 0.974984, 1.05728, 0.919044, 5.45641 },
 { 0.965211, 1.04983, 0.948436, 5.33933 },
 { 0.964672, 1.06105, 0.936792, 5.33444 },
 { 0.965347, 1.05603, 0.929828, 5.31593 },
 { 0.94978, 1.04333, 0.942429, 5.19343 },
 { 0.95606, 1.05091, 0.949122, 5.26059 },
 { 0.947585, 1.02826, 0.921454, 5.01191 },
 { 0.938561, 1.03778, 0.925863, 4.97379 },
 { 0.920623, 1.02622, 0.934905, 4.95296 },
 { 0.911316, 1.01291, 0.904997, 4.80502 },
 { 0.891897, 0.993385, 0.90447, 4.66055 },
 { 0.8762, 0.981436, 0.876256, 4.47585 },
 { 0.848555, 0.950943, 0.859665, 4.35362 },
 { 0.826712, 0.93969, 0.838342, 4.1583 },
 { 0.806415, 0.907578, 0.813487, 3.9889 },
 { 0.789645, 0.884159, 0.801792, 3.87666 },
 { 0.759151, 0.855199, 0.776007, 3.62472 },
 { 0.733674, 0.823123, 0.721558, 3.53772 },
 { 0.705088, 0.798423, 0.706897, 3.39019 },
 { 0.679877, 0.7713, 0.702242, 3.23269 },
 { 0.649874, 0.731216, 0.661454, 3.06687 },
 { 0.620984, 0.703714, 0.636271, 2.75286 },
 { 0.588438, 0.670568, 0.613563, 2.72576 },
 { 0.554895, 0.631872, 0.561318, 2.48595 },
 { 0.522873, 0.597299, 0.531624, 2.2805 },
 { 0.490022, 0.557314, 0.491865, 2.04874 },
 { 0.463686, 0.522778, 0.473301, 2.00216 },
 { 0.434771, 0.491061, 0.443965, 1.79728 },
 { 0.394353, 0.456812, 0.403567, 1.55772 },
 { 0.359475, 0.409572, 0.373983, 1.51334 },
 { 0.325385, 0.372275, 0.338881, 1.3057 },
 { 0.296104, 0.342085, 0.297841, 1.17063 },
 { 0.261911, 0.303725, 0.270736, 1.03295 },
 { 0.238341, 0.273314, 0.244838, 0.936314 },
 { 0.214178, 0.243782, 0.222912, 0.804239 },
 { 0.191837, 0.222813, 0.196813, 0.729621 },
 { 0.169229, 0.197253, 0.17134, 0.613707 },
 { 0.146726, 0.164737, 0.154348, 0.516673 },
 { 0.12616, 0.145243, 0.12828, 0.451344 },
 { 0.107745, 0.121266, 0.105669, 0.357452 },
 { 0.092945, 0.107799, 0.092883, 0.32246 },
 { 0.077129, 0.090986, 0.07765, 0.248499 },
 { 0.068384, 0.0782, 0.066849, 0.209601 },
 { 0.054643, 0.061093, 0.05594, 0.170629 },
 { 0.045049, 0.051037, 0.042248, 0.153446 },
 { 0.036338, 0.039304, 0.037849, 0.122317 },
 { 0.0279, 0.033139, 0.030312, 0.083532 },
 { 0.022893, 0.026852, 0.022568, 0.073876 },
 { 0.018838, 0.020666, 0.019024, 0.056223 },
 { 0.014185, 0.016855, 0.012869, 0.038462 },
 { 0.011851, 0.014966, 0.011993, 0.031008 },
 { 0.009141, 0.009639, 0.009087, 0.025379 },
 { 0.007278, 0.008947, 0.007556, 0.01951 },
 { 0.006562, 0.006487, 0.004561, 0.013385 },
 { 0.004253, 0.004069, 0.004016, 0.00893 },
 { 0.003352, 0.003378, 0.002861, 0.008705 },
 { 0.002222, 0.002852, 0.002863, 0.003808 },
 { 0.001612, 0.00145, 0.001906, 0.004042 },
 { 0.000875, 0.001203, 0.00056, 0.001154 },
 { 0.000564, 0.000717, 0.000683, 0.00155 },
 { 0.000799, 0.00086, 0.000533, 0.002091 },
 { 0.000445, 0.000533, 0.000683, 0.001342 },
 { 0.000429, 0.000598, 0.000486, 0.000637 },
 { 0.0001, 0.000214, 6.4e-05, 0.000282 },
 { 7.3e-05, 5e-05, 0, 0.000181 },
 { 4e-05, 0, 7.2e-05, 0 },
 { 3.9e-05, 4.2e-05, 0, 0 },
 { 2.4e-05, 2.8e-05, 0.000139, 0.000135 },
 { 8.6e-05, 9.1e-05, 0, 0 },
 { 5.3e-05, 9.7e-05, 8.1e-05, 0.000133 },
 { 2.1e-05, 2.3e-05, 0, 0 } };
 implantation =
 { 1.000E-06, 1.000E-06, 1.000E-06, 1.000E-06, 2.000E-06, 2.000E-06,
 3.000E-06, 3.000E-06, 1.000E-06, 2.000E-06, 2.000E-06, 1.000E-06,
 4.000E-06, 3.000E-06, 1.000E-05, 2.000E-06, 6.000E-06, 3.000E-06,
 5.000E-06, 6.000E-06, 7.000E-06, 3.000E-06, 8.000E-06, 9.000E-06,
 7.000E-06, 1.000E-05, 1.300E-05, 9.000E-06, 1.600E-05, 1.200E-05,
 1.000E-05, 1.100E-05, 1.400E-05, 1.400E-05, 1.600E-05, 1.300E-05,
 1.800E-05, 1.400E-05, 1.100E-05, 1.200E-05, 2.100E-05, 1.700E-05,
 1.500E-05, 2.000E-05, 3.300E-05, 2.700E-05, 3.200E-05, 2.600E-05,
 4.000E-05, 2.500E-05, 1.700E-05, 3.500E-05, 3.700E-05, 3.700E-05,
 3.300E-05, 3.200E-05, 4.800E-05, 4.300E-05, 5.000E-05, 4.900E-05,
 5.200E-05, 3.500E-05, 6.400E-05, 5.800E-05, 7.400E-05, 6.000E-05,
 7.600E-05, 8.700E-05, 7.100E-05, 7.800E-05, 9.700E-05, 9.000E-05,
 1.060E-04, 1.000E-04, 1.070E-04, 1.260E-04, 1.210E-04, 1.160E-04,
 1.250E-04, 1.290E-04, 1.730E-04, 1.400E-04, 1.590E-04, 1.760E-04,
 1.840E-04, 1.700E-04, 1.970E-04, 2.260E-04, 2.490E-04, 2.430E-04,
 2.290E-04, 2.570E-04, 2.870E-04, 3.140E-04, 2.990E-04, 3.330E-04,
 3.520E-04, 3.620E-04, 3.810E-04, 4.450E-04, 4.550E-04, 4.970E-04,
 4.950E-04, 4.810E-04, 5.390E-04, 5.780E-04, 6.270E-04, 6.390E-04,
 6.500E-04, 7.000E-04, 7.160E-04, 7.700E-04, 8.160E-04, 8.590E-04,
 9.000E-04, 9.100E-04, 9.820E-04, 1.047E-03, 1.056E-03, 1.104E-03,
 1.184E-03, 1.232E-03, 1.322E-03, 1.327E-03, 1.470E-03, 1.483E-03,
 1.542E-03, 1.563E-03, 1.615E-03, 1.729E-03, 1.673E-03, 1.830E-03,
 1.830E-03, 1.865E-03, 1.928E-03, 1.978E-03, 2.008E-03, 2.114E-03,
 1.996E-03, 1.991E-03, 2.056E-03, 2.132E-03, 2.079E-03, 2.069E-03,
 2.076E-03, 2.008E-03, 1.981E-03, 1.997E-03, 1.950E-03, 1.899E-03,
 1.897E-03, 1.729E-03, 1.776E-03, 1.668E-03, 1.654E-03, 1.535E-03,
 1.387E-03, 1.289E-03, 1.182E-03, 1.149E-03, 1.007E-03, 9.740E-04,
 8.950E-04, 7.440E-04, 6.490E-04, 5.890E-04, 5.510E-04, 4.640E-04,
 4.110E-04, 3.470E-04, 2.890E-04, 2.500E-04, 1.870E-04, 1.670E-04,
 1.200E-04, 1.030E-04, 8.100E-05, 5.800E-05, 6.200E-05, 4.300E-05,
 3.200E-05, 2.400E-05, 1.700E-05, 1.900E-05, 9.000E-06, 4.000E-06,
 4.000E-06, 5.000E-06, 4.000E-06, 1.000E-06, 1.000E-06, 1.000E-06,
 1.000E-06 };
 return;
 }
 };
 // end class BulkIon
 */
}

#endif
