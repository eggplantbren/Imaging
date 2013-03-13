#ifndef _MassInf_
#define _MassInf_

#include <iostream>
#include <vector>

namespace Imaging
{

// This class defines a "MassInf" type model
// with unknown number of point masses appearing
// in a 2D rectangle with a uniform prior on
// the positions and (by default) an exponential(1)
// prior on the fluxes.

class MassInf
{
	protected:
		int maxNumObjects;
		double xMin, xMax, yMin, yMax;
		double xRange, yRange;

		int numObjects;
		std::vector<double> x, y, mass;

		// Mass distribution properties
		virtual double massCDF(double x);
		virtual double massInverseCDF(double x);

		double generateMass();

	public:
		MassInf(int maxNumObjects, double xMin, double xMax,
				double yMin, double yMax);

		void fromPrior();
};

} // namespace Imaging

#endif

