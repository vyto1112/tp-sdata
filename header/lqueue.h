//209

#ifndef LinkedQueue_
#define LinkedQueue_
#include "node.h"

#include <exception>
#include <new>

class BadInitializersBT
{
   public:
      BadInitializersBT()
      {
  
      }

};

class NoMemBT
{
   public:
      NoMemBT()
      {
        
      }

};

void my_new_handlerBT()
{
   throw NoMemBT();
  
};

class OutOfBoundsBT
{
   public:
      OutOfBoundsBT()
      {
        
      }

};

class SizeMismatchBT
{
   public:
      SizeMismatchBT()
      {
        
      }

};

class MustBeZeroBT
{
   public:
      MustBeZeroBT()
      {
        
      }

};

class BadInputBT
{
   public:
      BadInputBT()
      {
        
      }

};

template<class T>
class LinkedQueue
{
   public:
      LinkedQueue()
      {
        front = rear = 0;
      }
      ~LinkedQueue();
      int IsEmpty() const
      {
        return ((front) ? 0 : 1);
      }
      int IsFull() const;
      T First() const;
      T Last() const;
      LinkedQueue<T>& Add(const T& x);
      LinkedQueue<T>& Delete(T& x);

   private:
      NodeBT<T> *front;
      NodeBT<T> *rear;
};

template<class T>
LinkedQueue<T>::~LinkedQueue()
{
    NodeBT<T> *next;
    while (front)
    {
      next = front->link; 
      delete front; 
      front = next;
    }
  
}

template<class T>
int LinkedQueue<T>::IsFull() const
{
   NodeBT<T> *p;
    try
    {
      p = new NodeBT<T>;
      delete p;
      return 0;
    }
      
    catch (NoMemBT)
    {
      return 1;
    }
  
}

template<class T>
T LinkedQueue<T>::First() const
{
   if (IsEmpty()) throw OutOfBoundsBT();
   return front->data;
  
}

template<class T>
T LinkedQueue<T>::Last() const
{
   if (IsEmpty()) throw OutOfBoundsBT();
   return rear->data;
  
}

template<class T>
LinkedQueue<T>& LinkedQueue<T>::Add(const T& x)
{
   NodeBT<T> *p = new NodeBT<T>;
   p->data = x;
   p->link = 0;

   if (front) rear->link = p;
   else front = p;             
   rear = p;

   return *this;
  
}

template<class T>
LinkedQueue<T>& LinkedQueue<T>::Delete(T& x)
{
   if (IsEmpty()) throw OutOfBoundsBT();

   x = front->data;

   NodeBT<T> *p = front;
   front = front->link;
   delete p;

   return *this;
}

#endif
