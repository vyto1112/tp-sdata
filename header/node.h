//209

#ifndef Node_
#define Node_

template <class T> class LinkedStack;
template <class T> class LinkedQueue;

template <class T>
class NodeBT
{
   friend LinkedStack<T>;
   friend LinkedQueue<T>;

   private:
      T data;
      NodeBT<T> *link;
};

#endif
