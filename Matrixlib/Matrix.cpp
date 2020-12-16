#include "Matrix.h"


template<class T>
TMatrix<T>::TMatrix(int _size) : Vector<Vector<T> >(_size)
{

}

template<class T>
TMatrix<T>::TMatrix(const TMatrix<T>& A) : Vector<Vector<T> >(A)
{
}

template<class T>
TMatrix<T>::~TMatrix()
{
}
