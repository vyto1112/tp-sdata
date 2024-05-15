template <class T> class LinkedStackK;
template <class T> class LinkedQueueK;

template <class T>
class NodeBTK
{
   friend LinkedStackK<T>;
   friend LinkedQueueK<T>;

   private:
      T data;
      NodeBTK<T> *link;
};
