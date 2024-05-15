//214

#include <iostream>
#include "xceptk.h"
using namespace std;

template <class T>
class Array1DK
{
  template <class U>
  friend ostream &operator<<(ostream &, const Array1DK<U> &);

  public:
      Array1DK(int size = 0);
      Array1DK(const Array1DK<T> &v);
      ~Array1DK() { delete[] element; }
      T &operator[](int i) const;
      int Size() { return size; }
      Array1DK<T> &operator=(const Array1DK<T> &v);
      Array1DK<T> operator+() const;
      Array1DK<T> operator+(const Array1DK<T> &v) const;
      Array1DK<T> operator-() const;
      Array1DK<T> operator-(const Array1DK<T> &v) const;
      Array1DK<T> operator*(const Array1DK<T> &v) const;
      Array1DK<T> &operator+=(const T &x);
      Array1DK<T> &ReSize(int sz);
      Array1DK<T> tambahAKhir(const Array1DK<T> &v);
  
  private:
      int size;
      T *element;

};

template<class T>
Array1DK<T> Array1DK<T>::tambahAKhir(const Array1DK<T> &v)
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
Array1DK<T>::Array1DK(int sz)
{ 
  if (sz < 0)
  {
    throw BadInitializersK();
  } 
  
  size = sz;
  element = new T[sz];
  
}

template <class T>
Array1DK<T>::Array1DK(const Array1DK<T> &v)
{
  size = v.size;
  element = new T[size];
  
  for (int i = 0; i < size; i++)
  {
    element[i] = v.element[i];
  }
  
}

template <class T>
T &Array1DK<T>::operator[](int i) const
{
  if (i < 0 || i >= size)
  {
    throw OutOfBoundsK();
  }
  
  return element[i];
  
}

template <class T>
Array1DK<T> &Array1DK<T>::operator=(const Array1DK<T> &v)
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
Array1DK<T> Array1DK<T>::operator+(const Array1DK<T> &v) const
{
    if (size != v.size)
    {
      throw SizeMismatchK();
    }
  
    Array1DK<T> w(size);
  
    for (int i = 0; i < size; i++)
    {
      w.element[i] = element[i] + v.element[i];
    }
  
    return w;
  
}

template <class T>
Array1DK<T> Array1DK<T>::operator-(const Array1DK<T> &v) const
{
    if (size != v.size)
    {
      throw SizeMismatchK();
    }
        
    Array1DK<T> w(size);
  
    for (int i = 0; i < size; i++)
    {
      w.element[i] = element[i] - v.element[i];
    }
        
    return w;
  
}

template <class T>
Array1DK<T> Array1DK<T>::operator-() const
{
    Array1DK<T> w(size);
  
    for (int i = 0; i < size; i++)
    {
      w.element[i] = -element[i];
    }
        
    return w;
  
}

template <class T>
Array1DK<T> Array1DK<T>::operator*(const Array1DK<T> &v) const
{
    if (size != v.size)
    {
      throw SizeMismatchK();
    }
        
    Array1DK<T> w(size);
  
    for (int i = 0; i < size; i++)
    {
      w.element[i] = element[i] * v.element[i];
    }
        
    return w;
  
}

template <class T>
Array1DK<T> &Array1DK<T>::operator+=(const T &x)
{
    for (int i = 0; i < size; i++)
    {
      element[i] += x;
    }
        
    return *this;
  
}

template <class T>
ostream &operator<<(ostream &out, const Array1DK<T> &x)
{
    for (int i = 0; i < x.size-1; i++)
    {
      out << "Data layanan ke-";
      out <<  i + 1;
      out << endl;
		  out << "Nama layanan  : ";
      out << x.element[i].nama;
      out << endl;
		  out << "Harga layanan : ";
      out << x.element[i].harga;
      out << endl;
      out << "---------------------------------------";
      out << endl;
    }
  
    return out;
  
}

template <class T>
Array1DK<T> &Array1DK<T>::ReSize(int sz)
{
    if (sz < 0)
    {
      throw BadInitializersK();
    }
        
    delete[] element;
    size = sz;
    element = new T[size];
    return *this;
  
}