//209

#ifndef Binary_
#define Binary_
int _count;

#include <iostream>
#include "lqueue.h"
#include "btnode2.h"
using namespace std;

template<class E, class K> class BSTree;
template<class E, class K> class DBSTree;

template<class T>
class BinaryTree{
   friend BSTree<T,int>;
   friend DBSTree<T,int>;

   public:
      BinaryTree() {root = 0;};
      ~BinaryTree()
      {
        
      }; 
      int IsEmpty() const
      {
        return ((root) ? 0 : 1);
      }
      int Root(T& x) const;
      void MakeTree(const T& element,
          BinaryTree<T>& left,
          BinaryTree<T>& right);
      void BreakTree(T& element, BinaryTree<T>& left,
          BinaryTree<T>& right);
      void PreOrder(void(*Visit)(BinaryTreeNode<T> *u))
      {
        PreOrder(Visit, root);
      }
      void InOrder(void(*Visit)(BinaryTreeNode<T> *u))
      {
        InOrder(Visit, root);
      }
      void PostOrder(void(*Visit)(BinaryTreeNode<T> *u))
      {
        PostOrder(Visit, root);
      }
      void LevelOrder(void(*Visit)(BinaryTreeNode<T> *u));
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
        _count = 0; PreOrder(Add1, root); return _count;
      }
   
  private:
      BinaryTreeNode<T> *root;
      void PreOrder(void(*Visit)
        (BinaryTreeNode<T> *u), BinaryTreeNode<T> *t);
      void InOrder(void(*Visit)
        (BinaryTreeNode<T> *u), BinaryTreeNode<T> *t);
      void PostOrder(void(*Visit)
        (BinaryTreeNode<T> *u), BinaryTreeNode<T> *t);
      static void Free(BinaryTreeNode<T> *t)
      {
        delete t;
      }
      static void Output(BinaryTreeNode<T> *t)
      {
        cout << t->data << "   ";
      }
      static void Add1(BinaryTreeNode<T> *t)
      {
        _count++;
      }
      int Height(BinaryTreeNode<T> *t) const;
};

template<class T>
int BinaryTree<T>::Root(T& x) const
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
void BinaryTree<T>::MakeTree(const T& element,
          BinaryTree<T>& left, BinaryTree<T>& right)
{
   root = new BinaryTreeNode<T>
   (element, left.root, right.root);
   left.root = right.root = 0;
}

template<class T>
void BinaryTree<T>::BreakTree(T& element,
       BinaryTree<T>& left, BinaryTree<T>& right)
{
   if (!root) throw BadInputBT();

   element = root->data;
   left.root = root->LeftChild;
   right.root = root->RightChild;

   delete root;
   root = 0;
}

template<class T>
void BinaryTree<T>::PreOrder(
           void(*Visit)(BinaryTreeNode<T> *u),
                        BinaryTreeNode<T> *t)
{
    if (t)
    {
      Visit(t);
   	  PreOrder(Visit, t->LeftChild);
   	  PreOrder(Visit, t->RightChild);
    }
  
}

template <class T>
void BinaryTree<T>::InOrder(
           void(*Visit)(BinaryTreeNode<T> *u),
                        BinaryTreeNode<T> *t)
{
  if (t)
  {
    InOrder(Visit, t->LeftChild);
   	Visit(t);
   	InOrder(Visit, t->RightChild);
  }
  
}

template <class T>
void BinaryTree<T>::PostOrder(
           void(*Visit)(BinaryTreeNode<T> *u),
                        BinaryTreeNode<T> *t)
{
    if (t)
    {
      PostOrder(Visit, t->LeftChild);
      PostOrder(Visit, t->RightChild);
      Visit(t);
    }
  
}

template <class T>
void BinaryTree<T>::LevelOrder(
          void(*Visit)(BinaryTreeNode<T> *u))
{
    LinkedQueue<BinaryTreeNode<T>*> Q;
    BinaryTreeNode<T> *t;
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
      catch (OutOfBoundsBT)
      {
        return;
      }
    }
}

template <class T>
int BinaryTree<T>::Height(BinaryTreeNode<T> *t) const
{
   if (!t) return 0;               
   int hl = Height(t->LeftChild);  
   int hr = Height(t->RightChild); 
   if (hl > hr) return ++hl;
   else return ++hr;
  
}

#endif
