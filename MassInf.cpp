#include "MassInf.h"
#include "RandomNumberGenerator.h"
#include <cassert>
#include <cmath>

namespace Imaging
{

using namespace std;
using namespace DNest3;

MassInf::MassInf(int maxNumObjects, double xMin, double xMax,
				double yMin, double yMax)
:maxNumObjects(maxNumObjects)
,xMin(xMin)
,xMax(xMax)
,yMin(yMin)
,yMax(yMax)
,xRange(xMax - xMin)
,yRange(yMax - yMin)
{
	assert(maxNumObjects >= 0);
	assert(xMax > xMin);
	assert(yMax > yMin);
}

void MassInf::fromPrior()
{
	numObjects = randInt(maxNumObjects + 1);
	x.resize(numObjects);
	y.resize(numObjects);
	mass.resize(numObjects);

	for(int i=0; i<numObjects; i++)
	{
		x[i] = xMin + xRange*randomU();
		y[i] = yMin + yRange*randomU();
		mass[i] = generateMass();
	}
}

double MassInf::generateMass()
{
	return massInverseCDF(randomU());
}

double MassInf::massCDF(double x)
{
	double result = 0.;
	if(x > 0.)
		result = 1. - exp(-x);
	return result;
}

double MassInf::massInverseCDF(double x)
{
	assert(x >= 0. && x <= 1.);
	return -log(1. - x);
}

} // namespace Imaging

