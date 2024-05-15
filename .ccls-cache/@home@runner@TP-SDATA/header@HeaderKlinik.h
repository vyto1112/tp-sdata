//209

#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include <new>
using namespace std;

int _countK;

template <class T> class BinaryTreeK;
template<class E, class K> class BSTreeK;
template<class E, class K> class DBSTreeK;

template <class T>
class BinaryTreeNodeK
{
   friend BinaryTreeK<T>;
   friend void PlaceBoosters(BinaryTreeNodeK<T> *);
   friend BSTreeK<T,int>;
   friend DBSTreeK<T,int>;

   public:
      BinaryTreeNodeK()
      {
        LeftChild = RightChild = 0;
      }
      BinaryTreeNodeK(const T& e)
      {
        data = e; LeftChild = RightChild = 0;
      }
      BinaryTreeNodeK(const T& e, BinaryTreeNodeK *l,
                     BinaryTreeNodeK *r)
      {
        data = e; LeftChild = l; RightChild = r;
      }

   private:
      T data;
      BinaryTreeNodeK<T> *LeftChild,  // left subtree
                        *RightChild; // right subtree

};

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

class BadInitializersBTK
{
   public:
      BadInitializersBTK()
      {
  
      }

};

class NoMemBTK
{
   public:
      NoMemBTK()
      {
        
      }

};

void my_new_handlerBTK()
{
   throw NoMemBTK();
  
};

class OutOfBoundsBTK
{
   public:
      OutOfBoundsBTK()
      {
        
      }

};

class SizeMismatchBTK
{
   public:
      SizeMismatchBTK()
      {
        
      }

};

class MustBeZeroBTK
{
   public:
      MustBeZeroBTK()
      {
        
      }

};

class BadInputBTK
{
   public:
      BadInputBTK()
      {
        
      }

};

template<class T>
class LinkedQueueK
{
   public:
      LinkedQueueK()
      {
        front = rear = 0;
      }
      ~LinkedQueueK();
      int IsEmpty() const
      {
        return ((front) ? 0 : 1);
      }
      int IsFull() const;
      T First() const;
      T Last() const;
      LinkedQueueK<T>& Add(const T& x);
      LinkedQueueK<T>& Delete(T& x);

   private:
      NodeBTK<T> *front;
      NodeBTK<T> *rear;
};

template<class T>
LinkedQueueK<T>::~LinkedQueueK()
{
    NodeBTK<T> *next;
    while (front)
    {
      next = front->link; 
      delete front; 
      front = next;
    }
  
}

template<class T>
int LinkedQueueK<T>::IsFull() const
{
   NodeBTK<T> *p;
    try
    {
      p = new NodeBTK<T>;
      delete p;
      return 0;
    }
      
    catch (NoMemBTK)
    {
      return 1;
    }
  
}

template<class T>
T LinkedQueueK<T>::First() const
{
   if (IsEmpty()) throw OutOfBoundsBTK();
   return front->data;
  
}

template<class T>
T LinkedQueueK<T>::Last() const
{
   if (IsEmpty()) throw OutOfBoundsBTK();
   return rear->data;
  
}

template<class T>
LinkedQueueK<T>& LinkedQueueK<T>::Add(const T& x)
{
   NodeBTK<T> *p = new NodeBTK<T>;
   p->data = x;
   p->link = 0;

   if (front) rear->link = p;
   else front = p;             
   rear = p;

   return *this;
  
}

template<class T>
LinkedQueueK<T>& LinkedQueueK<T>::Delete(T& x)
{
   if (IsEmpty()) throw OutOfBoundsBTK();

   x = front->data;

   NodeBTK<T> *p = front;
   front = front->link;
   delete p;

   return *this;
}


template<class E, class K> class BSTree;
template<class E, class K> class DBSTree;

template<class T>
class BinaryTreeK{
   friend BSTree<T,int>;
   friend DBSTree<T,int>;

   public:
      BinaryTreeK() {root = 0;};
      ~BinaryTreeK()
      {
        
      }; 
      int IsEmpty() const
      {
        return ((root) ? 0 : 1);
      }
      int Root(T& x) const;
      void MakeTree(const T& element,
          BinaryTreeK<T>& left,
          BinaryTreeK<T>& right);
      void BreakTree(T& element, BinaryTreeK<T>& left,
          BinaryTreeK<T>& right);
      void PreOrder(void(*Visit)(BinaryTreeNodeK<T> *u))
      {
        PreOrder(Visit, root);
      }
      void InOrder(void(*Visit)(BinaryTreeNodeK<T> *u))
      {
        InOrder(Visit, root);
      }
      void PostOrder(void(*Visit)(BinaryTreeNodeK<T> *u))
      {
        PostOrder(Visit, root);
      }
      void LevelOrder(void(*Visit)(BinaryTreeNodeK<T> *u));
      void PreOutput()
      {
        PreOrder(Output, root); cout << endl;
      }
      void InOutput()
      {
        InOrder(Output, root); cout << endl;
      }
      void PostOutput()
      {
        PostOrder(Output, root); cout << endl;
      }
      void LevelOutput()
      {
        LevelOrder(Output); cout << endl;
      }
      void Delete()
      {
        PostOrder(Free, root); root = 0;
      }
      int Height() const
      {
        return Height(root);
      }
      int Size()
      {
        _countK = 0; PreOrder(Add1, root); return _countK;
      }
   
  private:
      BinaryTreeNodeK<T> *root;
      void PreOrder(void(*Visit)
        (BinaryTreeNodeK<T> *u), BinaryTreeNodeK<T> *t);
      void InOrder(void(*Visit)
        (BinaryTreeNodeK<T> *u), BinaryTreeNodeK<T> *t);
      void PostOrder(void(*Visit)
        (BinaryTreeNodeK<T> *u), BinaryTreeNodeK<T> *t);
      static void Free(BinaryTreeNodeK<T> *t)
      {
        delete t;
      }
      static void Output(BinaryTreeNodeK<T> *t)
      {
        cout << t->data << "   ";
      }
      static void Add1(BinaryTreeNodeK<T> *t)
      {
        _countK++;
      }
      int Height(BinaryTreeNodeK<T> *t) const;
};

template<class T>
int BinaryTreeK<T>::Root(T& x) const
{
    if (root)
    {
      x = root->data;
      return 1;
    }
    else
    {
      return 0;
    } 
  
}

template<class T>
void BinaryTreeK<T>::MakeTree(const T& element,
          BinaryTreeK<T>& left, BinaryTreeK<T>& right)
{
   root = new BinaryTreeNodeK<T>
   (element, left.root, right.root);
   left.root = right.root = 0;
}

template<class T>
void BinaryTreeK<T>::BreakTree(T& element,
       BinaryTreeK<T>& left, BinaryTreeK<T>& right)
{
   if (!root) throw BadInputBTK();

   element = root->data;
   left.root = root->LeftChild;
   right.root = root->RightChild;

   delete root;
   root = 0;
}

template<class T>
void BinaryTreeK<T>::PreOrder(
           void(*Visit)(BinaryTreeNodeK<T> *u),
                        BinaryTreeNodeK<T> *t)
{
    if (t)
    {
      Visit(t);
   	  PreOrder(Visit, t->LeftChild);
   	  PreOrder(Visit, t->RightChild);
    }
  
}

template <class T>
void BinaryTreeK<T>::InOrder(
           void(*Visit)(BinaryTreeNodeK<T> *u),
                        BinaryTreeNodeK<T> *t)
{
  if (t)
  {
    InOrder(Visit, t->LeftChild);
   	Visit(t);
   	InOrder(Visit, t->RightChild);
  }
  
}

template <class T>
void BinaryTreeK<T>::PostOrder(
           void(*Visit)(BinaryTreeNodeK<T> *u),
                        BinaryTreeNodeK<T> *t)
{
    if (t)
    {
      PostOrder(Visit, t->LeftChild);
      PostOrder(Visit, t->RightChild);
      Visit(t);
    }
  
}

template <class T>
void BinaryTreeK<T>::LevelOrder(
          void(*Visit)(BinaryTreeNodeK<T> *u))
{
    LinkedQueueK<BinaryTreeNodeK<T>*> Q;
    BinaryTreeNodeK<T> *t;
    t = root;
    while (t)
    {
      Visit(t);
      if (t->LeftChild) Q.Add(t->LeftChild);
      if (t->RightChild) Q.Add(t->RightChild);
      
      try
      {
        Q.Delete(t);
      }
      catch (OutOfBoundsBTK)
      {
        return;
      }
    }
}

template <class T>
int BinaryTreeK<T>::Height(BinaryTreeNodeK<T> *t) const
{
   if (!t) return 0;               
   int hl = Height(t->LeftChild);  
   int hr = Height(t->RightChild); 
   if (hl > hr) return ++hl;
   else return ++hr;
  
}

// array Antrian
int maksimalAntrianArrayA = 100, frontA = 0, backA = 0;
// ruang antrian array
string antrianAdmin[100];

// isFull / cek data antrian penuh atau tidak
bool isFullArrayA()
{
  if(backA == maksimalAntrianArrayA)
  {
    return true;
  }
    
  else
  {
    return false;
  }
}

// isEmpty
bool isEmptyArrayA()
{
  if( backA == 0 )
  {
    return true;
  }
    
  else
  {
    return false;
  }
}

// enqueue / penambahan data antrian
void enqueueArrayA(string data){

  if(isFullArrayA())
  {
    cout << "Antrian penuh!!" << endl;
  }
    
  else
  {
    // cek apakah datanya kosong atau tidak
    if(isEmptyArrayA())
    {
      // kalau antrian kosong
      antrianAdmin[0] = data;
      frontA++;
      backA++;
    }
      
    else
    {
      // kalo gak kosong
      antrianAdmin[backA] = data;
      backA++;
    }
  }

}

// dequeue / penghapusan data depan
void dequeueArrayA()
{
  if( isEmptyArrayA())
  {
    cout << "Antrian kosong!!" << endl;
  }
  else
  {
    for( int i = 0; i < backA; i++ )
    {
      antrianAdmin[i] = antrianAdmin[i+1];
    }
    backA--;
  }
}

// countKArray / menghitung banyak data yg ngantri
int countArrayA()
{

  if( isEmptyArrayA() )
  {
    return 0;
  }
    
  else if( isFullArrayA() )
  {
    return maksimalAntrianArrayA;
  }
    
  else
  {
    return backA;
  }

}

// destroy / clear
void destroyArrayA()
{
  if(isEmptyArrayA())
  {
    cout << "Antrian kosong!!" << endl;
  }
  
  else
  {
    for(int i = 0; i < maksimalAntrianArrayA; i++)
    {
      
      if( backA > 1 )
      {
        antrianAdmin[backA - 1] = "";
        backA--;
      }
      else if( backA == 1 )
      {
        antrianAdmin[backA - 1] = "";
        backA = 0;
        frontA = 0;
      }

    }
  }
}

// Display / View
void viewArrayA()
{
  cout << "Jumlah data yg ngantri : " << countArray() << "data." << endl;
  cout << "Data Antrian Layanan : " << endl;
  if( isEmptyArrayA() )
  {
    cout << "Antrian kosong!!" << endl;
  }else
  {
    for( int i = 0; i < maksimalAntrianArrayA; i++ )
    {
      // cek apakah ruang kosong atau tidak
      if( antrianAdmin[i] != "" )
      {
        // kalau ruang tidak kosong
        cout << i+1 << ". " << antrianAdmin[i] << endl;
      }
        
      else
      {
        // kalo kosong
        cout << i+1 << ". (kosong)" << endl;
      }
    }
  }
  cout << "\n" << endl;
}

// siapin ruang antrian
struct antrianAdminLL
{
  // data / member
  string nama;
  string id;

  // pointer next
  antrianAdminLL *next;
};

int maksimalAntrianLinkedListA = 100;
antrianAdminLL *headA, *tailA, *curA, *delA, *newNodeA;

// count Linked List
int countLinkedListA()
{
  if( headA == NULL )
  {
    return 0;
  }
    
  else
  {
    int banyak = 0;
    curA = headA;
    while( curA != NULL )
    {
      curA = curA->next;
      banyak++;
    }
    return banyak;
  }
}

// isFull Linked List
bool isFullLinkedListA()
{
  if( countLinkedListA() == maksimalAntrianLinkedListA )
  {
    return true;
  }
  else
  {
    return false;
  }
}

// isEmpty Linked List
bool isEmptyLinkedListA()
{
  if( countLinkedListA() == 0 )
  {
    return true;
  }
  else
  {
    return false;
  }
}

// enqueue / penambahan
void enqueueLinkedListA( string nama, string id )
{

  if( isFullLinkedListA() )
  {
    cout << "Antrian Penuh!!!" << endl;
  }
    
  else
  {
    
    if( isEmptyLinkedListA() )
    {
      headA = new antrianAdminLL();
      headA->nama = nama;
      headA->id = id;
      headA->next = NULL;
      tailA = headA;
    }
      
    else
    {
      newNodeA = new antrianAdminLL();
      newNodeA->nama = nama;
      newNodeA->id = id;
      newNodeA->next = NULL;
      tailA->next = newNodeA;
      tailA = newNodeA;
    }

  }

}

// dequeue Linked List
void dequeueLinkedListA()
{
  if( isEmptyLinkedListA() )
  {
    cout << "Data Antrian Kosong!!" << endl;
  }
    
  else
  {
    delA = headA;
    headA = headA->next;
    delA->next = NULL;
    delete delA;
  }
}

// destroy / clear
void clearLinkedListA()
{
  if( isEmptyLinkedListA() )
  {
    cout << "Data Antrian Kosong!!" << endl;
  }
    
  else
  {
    curA = headA;
    while( curA != NULL )
    {
      delA = curA;
      curA = curA->next;
      delA->next = NULL;
      delete delA;
    }
    headA = NULL;
    tailA = NULL;
  }
}

// display Linked List
void displayLinkedListA()
{
  cout << "Data Antrian : " << endl;
  if( isEmptyLinkedListA() )
  {
    cout << "Data Antrian Kosong!!" << endl;
  }
    
  else
  {
    cout << "Banyak data antrian : " << countLinkedListA() << endl;
    curA = headA;
    int nomor = 1;
    while( nomor <= maksimalAntrianLinkedListA ){
      
      if( curA != NULL )
      {
        cout << nomor << ". " << curA->nama << " \t" << curA->id << "." << endl;
        curA = curA->next;
      }
        
      else
      {
        cout << nomor << ". " << "(kosong)" << endl;
      }

      nomor++;
    }

  }

  cout << "\n";
  cout << endl;

}

class BadInitializersK
{
   public:
      BadInitializersK()
      {
  
      }

};

class NoMemK
{
   public:
      NoMemK()
      {
        
      }

};

void my_new_handlerK()
{
   throw NoMemK();
  
};

class OutOfBoundsK
{
   public:
      OutOfBoundsK()
      {
        
      }

};

class SizeMismatchK
{
   public:
      SizeMismatchK()
      {
        
      }

};

class MustBeZeroK
{
   public:
      MustBeZeroK()
      {
        
      }

};

class BadInputK
{
   public:
      BadInputK()
      {
        
      }

};

template <class T>
class Array1DK
{
  template <class U>
  friend ostream &operator<<(ostream &, const Array1DK<U> &);

  public:
      Array1DK(int size = 0);
      Array1DK(const Array1DK<T> &v);
      ~Array1DK(){
        delete[] element;
      }
      T &operator[](int i) const;
      int Size()
      {
        return size;
      }
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