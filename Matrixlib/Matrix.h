#pragma once
#ifndef _MATRIX_H_
#define _MATRIX_H_

#include "MyVector.h"

using namespace std;

template<class T>
class TMatrix : public Vector<Vector<T> > 
{
public:
	TMatrix(int _size = 0);
	TMatrix(const TMatrix<T>& A);
	~TMatrix();
};

#endif