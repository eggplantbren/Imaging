#ifndef _Array_
#define _Array_

#include <vector>

namespace Imaging
{

template<class Type>
class Array
{
	protected:
		int ni, nj, size;
		std::vector< std::vector<Type> > pixels;

	public:
		Array();
		Array(int ni, int nj);

		// Resize (destructive)
		void resize(int ni, int j);

		// Set all pixels to given value
		void set(const Type& value);
		void increment(const Type& value);
		void decrement(const Type& value);

		// Operator versions of the above
		Array& operator  = (const Type& value) { set(value); return *this; }
		Array& operator += (const Type& value) { increment(value); return *this; }
		Array& operator -= (const Type& value) { decrement(value); return *this; }

		// Const and non-const getter
		Type operator()  (int i, int j) const { return pixels[i][j]; }
		Type& operator() (int i, int j)       { return pixels[i][j]; }

};

}

#include "ArrayImpl.h"

#endif

