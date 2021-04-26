#ifndef _MY_VECTOR_
#define _MY_VECTOR_

#include <iostream>
#include <fstream>

using namespace std;

template <class T>
class Vector
{
protected:
  int length;
  T* x;
public:
  Vector<T>* vec;
  Vector(int rowsCount=0, T _v=NULL);
  Vector(const Vector<T>& _v);
  virtual ~Vector();
  void Resize(int size);
  Vector<T> operator +(Vector<T>& _v);
  Vector<T> operator -(Vector<T>& _v);
  Vector<T> operator *(Vector<T>& _v);
  Vector<T> operator /(Vector<T>& _v);
  Vector<T>& operator =(const Vector<T>& _v);
  bool operator==(const Vector<T>& _v) const;
  bool operator!=(const Vector<T>& _v) const;
  T& operator[] (const int index)const;

  Vector<T>& operator ++();
  Vector<T>& operator --();
  Vector<T>& operator +=(Vector<T>& _v);
  Vector<T>& operator -=(Vector<T>& _v);
    
    friend ostream& operator<< (ostream& ostr, const Vector &A) {
      for (int i = 0; i < A.length; i++) {
        ostr << A.x[i]<<' ';
      }
      return ostr;
    }

    friend istream& operator >> (istream& istr, Vector &A) {
      for (int i = 0; i < A.length; i++) {
        istr >> A.x[i];
      }
      return istr;
    }

  friend ifstream& operator>>(ifstream& in, Vector& mt)
  {
      int size;
      in >> size;
      mt.Resize(size);
      for (int i = 0; i < mt.length; i++)
          in >> mt.x[i];
      return in;
  }
  friend ofstream& operator<<(ofstream& out, const Vector& mt)
  {
      out << mt.Length() << endl;
      for (int i = 0; i < mt.length; i++)
          out << mt.x[i]<<' ';
      return out;
  }

  int Length() const;
};


#define MIN(a,b)(a>b?b:a)
#define MAX(a,b)(a>b?a:b)
template <class T>
void Vector<T>::Resize(int size) {
    Vector<T> tmp(size);
    for (int i = 0; i < MIN(length, size); i++) {
        tmp[i] = x[i];
    }
    *this = tmp;
}

template <class T>
Vector<T>::Vector(int rowsCount, T _v)
{
  length = rowsCount;
  x = new T [length];
  for (int i = 0; i < length; i++)
    x[i] = _v;
}
template <class T>
Vector<T>::Vector(const Vector<T>& _v)
{
  length = _v.length;
  x = new T [length];
  for (int i = 0; i < length;i = i + 1)
    x[i] = _v.x[i];
}
template <class T>
Vector<T>::~Vector()
{
  length = 0;
  if (x != 0)
    delete[] x;
  x = 0;
}
template <class T>
Vector<T> Vector<T>::operator +(Vector<T>& _v)
{
  Vector<T> res;
  res.length = MIN(length, _v.length);
  res.x = new T [res.length];
  for (int i = 0; i < res.length; i++)
  {
    res.x[i] = x[i] + _v.x[i];
  }
  return res;
}
template <class T>
Vector<T> Vector<T>::operator -(Vector<T>& _v)
{
  Vector<T> res;
  res.length = MIN(length, _v.length);
  res.x = new T [res.length];
  for (int i = 0; i < res.length; i++)
  {
    res.x[i] = x[i] - _v.x[i];
  }
  return res;
}
template <class T>
Vector<T> Vector<T>::operator *(Vector<T>& _v)
{
  Vector<T> res;
  res.length = MIN(length, _v.length);
  res.x = new T [res.length];
  for (int i = 0; i < res.length; i++)
  {
    res.x[i] = x[i] * _v.x[i];
  }
  return res;
}
template <class T>
Vector<T> Vector<T>::operator /(Vector<T>& _v)

{
  Vector<T> res;
  res.length = MIN(length, _v.length);
  res.x = new T [res.length];
  for (int i = 0; i < res.length; i++)
  {
    res.x[i] = x[i] / _v.x[i];
  }
  return res;
}
template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& _v)
{
  if (this == &_v)
    return *this;
  length = _v.length;
  x = new T [length];
  for (int i = 0; i < length; i++)
    x[i] = _v.x[i];
  return *this;
}
template<class T>
bool Vector<T>::operator==(const Vector<T>& _v) const
{
    if (length != _v.length) return false;
    for (int i = 0; i < length; i++) {
        if (x[i] != _v.x[i])return false;
    }
    return true;
}
template<class T>
inline bool Vector<T>::operator!=(const Vector<T>& _v) const
{
    return (!(*this == _v));
}
template <class T>
T& Vector<T>::operator[] (const int index) const
{
  if ((index >= 0) && (index < length))
    return x[index];
  throw new exception();
}

template <class T>
Vector<T>& Vector<T>::operator ++()
{
  for (int i = 0; i < length; i++)
    x[i]++;
  return *this;
}
template <class T>
Vector<T>& Vector<T>::operator --()
{
  for (int i = 0; i < length; i++)
    x[i]--;
  return *this;
}
template <class T>
Vector<T>& Vector<T>::operator +=(Vector<T>& _v)
{
  length = MIN(length, _v.length);
  for (int i = 0; i < length; i++)
  {
    x[i] += _v.x[i];
  }
  return *this;
}
template <class T>
Vector<T>& Vector<T>::operator -=(Vector<T>& _v)
{
  length = MIN(length, _v.length);
  for (int i = 0; i < length; i++)
  {
    x[i] -= _v.x[i];
  }
  return *this;
}
template <class T>
int Vector<T>::Length() const
{
  return length;
}


#endif

