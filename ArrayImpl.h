namespace Imaging
{

using namespace std;

template<class Type>
Array<Type>::Array()
:ni(0), nj(0)
,size(0)
{

}

template<class Type>
Array<Type>::Array(int ni, int nj)
:ni(ni), nj(nj)
,size(ni*nj)
,pixels(ni, vector<Type>(nj))
{

}

template<class Type>
void Array<Type>::resize(int ni, int nj)
{
	this->ni = ni; this->nj = nj;
	size = ni*nj;
	pixels.resize(ni, vector<Type>(nj));
}

template<class Type>
void Array<Type>::set(const Type& value)
{
	for(int i=0; i<ni; i++)
		for(int j=0; j<nj; j++)
			pixels[i][j] = value;
}

template<class Type>
void Array<Type>::increment(const Type& value)
{
	for(int i=0; i<ni; i++)
		for(int j=0; j<nj; j++)
			pixels[i][j] += value;
}

template<class Type>
void Array<Type>::decrement(const Type& value)
{
	for(int i=0; i<ni; i++)
		for(int j=0; j<nj; j++)
			pixels[i][j] -= value;
}

} // namespace Imaging

