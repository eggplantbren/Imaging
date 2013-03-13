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
		mass[i] = -log(randomU());
	}
}

} // namespace Imaging

