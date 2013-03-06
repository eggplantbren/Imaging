#include <iostream>
#include "Array.h"

using namespace Imaging;

int main()
{
	Array<double> a(100, 100);
	a = 5.;
	cout<<a(5, 12)<<endl;
	return 0;
}

