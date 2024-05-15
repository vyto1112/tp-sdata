

#include <iostream>
#include "xcepts.h"
using namespace std;

template <class T>
class Array1DS
{
  template <class U>
  friend ostream &operator<<(ostream &, const Array1DS<U> &);

  public:
      Array1DS(int size = 0);
      Array1DS(const Array1DS<T> &v);
      ~Array1DS()
      {
        delete[] element;
      }
      T &operator[](int i) const;
      int Size()
      { 
        return size;
      }
      Array1DS<T> &operator=(const Array1DS<T> &v);
      Array1DS<T> operator+() const;
      Array1DS<T> operator+(const Array1DS<T> &v) const;
      Array1DS<T> operator-() const;
      Array1DS<T> operator-(const Array1DS<T> &v) const;
      Array1DS<T> operator*(const Array1DS<T> &v) const;
      Array1DS<T> &operator+=(const T &x);
      Array1DS<T> &ReSize(int sz);
      Array1DS<T> tambahAKhir(const Array1DS<T> &v);
  
  private:
      int size;
      T *element;

};

template<class T>
Array1DS<T> Array1DS<T>::tambahAKhir(const Array1DS<T> &v)
{
    if (this != &v)
    {
        delete[] element;
        element = new T[size];
        for (int i = 0; i < v.size; i++)
        {
          element[i] = v.element[i];
        }
    }
  
    return *this;
  
}

template <class T>
Array1DS<T>::Array1DS(int sz)
{ 
  if (sz < 0)
  {
    throw BadInitializersS();
  } 
  
  size = sz;
  element = new T[sz];
  
}

template <class T>
Array1DS<T>::Array1DS(const Array1DS<T> &v)
{
  size = v.size;
  element = new T[size];
  
  for (int i = 0; i < size; i++)
  {
    element[i] = v.element[i];
  }
  
}

template <class T>
T &Array1DS<T>::operator[](int i) const
{
  if (i < 0 || i >= size)
  {
    throw OutOfBoundsS();
  }
  
  return element[i];
  
}

template <class T>
Array1DS<T> &Array1DS<T>::operator=(const Array1DS<T> &v)
{
    if (this != &v)
    {
      size = v.size;
      delete[] element;
      element = new T[size];
      
      for (int i = 0; i < size; i++)
      {
        element[i] = v.element[i];
      }
      
    }
  
    return *this;
  
}

template <class T>
Array1DS<T> Array1DS<T>::operator+(const Array1DS<T> &v) const
{
    if (size != v.size)
    {
      throw SizeMismatchS();
    }
  
    Array1DS<T> w(size);
  
    for (int i = 0; i < size; i++)
    {
      w.element[i] = element[i] + v.element[i];
    }
  
    return w;
  
}

template <class T>
Array1DS<T> Array1DS<T>::operator-(const Array1DS<T> &v) const
{
    if (size != v.size)
    {
      throw SizeMismatchS();
    }
        
    Array1DS<T> w(size);
  
    for (int i = 0; i < size; i++)
    {
      w.element[i] = element[i] - v.element[i];
    }
        
    return w;
  
}

template <class T>
Array1DS<T> Array1DS<T>::operator-() const
{
    Array1DS<T> w(size);
  
    for (int i = 0; i < size; i++)
    {
      w.element[i] = -element[i];
    }
        
    return w;
  
}

template <class T>
Array1DS<T> Array1DS<T>::operator*(const Array1DS<T> &v) const
{
    if (size != v.size)
    {
      throw SizeMismatchS();
    }
        
    Array1DS<T> w(size);
  
    for (int i = 0; i < size; i++)
    {
      w.element[i] = element[i] * v.element[i];
    }
        
    return w;
  
}

template <class T>
Array1DS<T> &Array1DS<T>::operator+=(const T &x)
{
    for (int i = 0; i < size; i++)
    {
      element[i] += x;
    }
        
    return *this;
  
}

template <class T>
Array1DS<T> &Array1DS<T>::ReSize(int sz)
{
    if (sz < 0)
    {
      throw BadInitializersS();
    }
        
    delete[] element;
    size = sz;
    element = new T[size];
    return *this;
  
}