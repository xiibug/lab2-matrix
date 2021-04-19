#pragma once
#ifndef _MATRIX_H_
#define _MATRIX_H_

#include "MyVector.h"

using namespace std;

template<class T>
class TMatrix : public Vector<Vector<T>> 
{
public:
	TMatrix(int _size = 0);
	TMatrix(int _size, const T& value);
	TMatrix(const TMatrix<T>& A);
	~TMatrix();
	int Length() const;
	bool operator==(const TMatrix& A) const;
	TMatrix& operator=(const TMatrix& A);
	TMatrix operator+(const TMatrix& A);
	TMatrix operator-(const TMatrix& A);
	TMatrix operator*(const TMatrix& A);
	TMatrix operator*(const double& d);
	Vector<T> operator*(const Vector<T>& v);
	friend istream& operator>>(istream& in, TMatrix& mt)
	{
		for (int i = 0; i < mt.length; i++)
			in >> mt.x[i];
		return in;
	}
	friend ostream& operator<<(ostream& out, const TMatrix& mt)
	{
		for (int i = 0; i < mt.length; i++)
			out << mt.x[i] << endl;
		return out;
	}

};
template<class T>
inline int TMatrix<T>::Length() const {
	return x->Length();
}
template<class T>
inline TMatrix<T>::TMatrix(int _size) : Vector<Vector<T>>(_size)
{
	if (_size < 0)
		throw new exception;
	for (int i = 0; i < _size; i++)
		this->x[i] = Vector<T>(_size - i, 0);
}
template<class T>
inline TMatrix<T>::TMatrix(int _size, const T& value) : Vector<Vector<T>>(_size, value)
{
}
template<class T>
inline TMatrix<T>::TMatrix(const TMatrix<T>& A) : Vector<Vector<T>>(A)
{
	//length = A.length;
	//x = new Vector<T>[length];
	//for (int i = 0; i < length; i++) {
	//	x[i] = A.x[i];
	//}
}

template<class T>
inline TMatrix<T>::~TMatrix()
{
}

template<class T>
inline  bool TMatrix<T>::operator==(const TMatrix& A) const
{
	 if (length != A.length) return false;
	 for (int i = 0; i < length; i++) {
		 if (x[i] != A.x[i])return false;
	 }
	 return true;
}
template<class T>
inline TMatrix<T>& TMatrix<T>::operator=(const TMatrix& A)
{
	if (this != &A)
	{
		if (this->length != A.length)
		{
			if (this->x != NULL)
				delete[] this->x;
			this->length = A.length;
			this->x = new Vector<T>[A.length];
			for (int i = 0; i < this->length; i++)
				this->x[i] = A.x[i];
		}
		for (int i = 0; i < this->length; i++)
			this->x[i] = A.x[i];
	}
	return *this;
}
template<class T>
inline TMatrix<T> TMatrix<T>::operator+(const TMatrix& A)
{
	if (length != A.length) throw - 1; 
	TMatrix<T> tmp(*this);
	for (int i = 0; i < tmp.Length(); i++)
		tmp[i] += A[i];
	return tmp;
}
template<class T>
inline TMatrix<T> TMatrix<T>::operator-(const TMatrix& A)
{
	if (length != A.length) throw - 1;
	TMatrix<T> tmp = *this;
	for (int i = 0; i < tmp.Length(); i++)
		tmp[i] -= A[i];
	return tmp;
}
template<class T>
inline TMatrix<T> TMatrix<T>::operator*(const TMatrix& A)
{
	TMatrix<T> tmp(*this);
	if (length != A.Length())
		throw new exception();
	for (int i = 0; i < this->length; i++)
		tmp.x[i] = tmp.x[i] * A.x[i];
	return tmp;
}
template<class T>
inline TMatrix<T> TMatrix<T>::operator*(const double& d)
{
	TMatrix<T> tmp(*this);
	for (int i = 0; i < length; i++)
		for (int j = 0; j < x[i].Length(); j++)
			tmp[i] *= d;
	return tmp;
}
template<class T>
inline Vector<T> TMatrix<T>::operator*(const Vector<T>& v)
{
	Vector<T> tmp(length, 0);
	for (int i = 0; i < length; i++)
		for (int j = i; j < length; j++)
			tmp[i] += x[i][j - i] * v[j];
	return tmp;
}
#endif