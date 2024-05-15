#ifndef LinkedList_H
#define LinkedList_H

#include <iostream>
#include "datastruct.h"

using namespace std;

template <class T>
class Node {
    //friend class List<T>;
    //friend ostream& operator<<(ostream&, const List<T>&); 
  public:
    Node(T& t, Node<T>* p) : info(t), next(p) { }
  //protected :
    T info;
    Node *next;
    Node *prev;
};

template <class T>
class List {
  template <class A>
  friend ostream& operator<<(ostream&, const List<A>&);
public :
  List() : kepala(0) { }
  ~List();
  void sisip(T t);
  void hapus(T& t);
  int kosong() { return (kepala == NULL); }
  void cetak();
//protected:
  Node<T>* kepala;
  Node<T>* nodeBaru(T& t, Node<T>* p)
  { Node<T>* q = new Node<T>(t, p); return q; }
};

template <class T>
ostream& operator<<(ostream& out, const List<T>& k) {
  for (Node<T>* p = k.kepala; p; p = p->next) 
  out << p->info << " -> ";
  out << "*\n";
  return out;
}

template <class T>
List<T>::~List() {
  Node<T>* temp;
  for (Node<T>* p = kepala; p;) {
    temp = p;
    p = p->next;
    delete temp;
  }
}

/*
template <class T>
void List<T>::sisip(T t) {
  //cout << t << " masuk list : ";
  Node<T> *p = nodeBaru(t,kepala);
  kepala = p;
}
*/

template <class T>
void List<T>::sisip(T t) {
  //cout << t << " masuk list : ";
  Node<T> *tambah = nodeBaru(t, kepala);
  tambah->next = NULL;
  tambah->prev = NULL;

  if(kepala == NULL) { //Jika kosong maka langsung tambah
    kepala = tambah;
  } else { //Jika tidak kosong maka tambah ke belakang
    Node<T> *akhir = kepala;
    while (akhir->next != NULL) {
      akhir = akhir->next;
    }

    tambah->prev = akhir;
    akhir->next = tambah;
  }
}

template <class T>
void List<T>::hapus(T& t) {
  /*
  if (kosong()) return 0;
  t = kepala->info;
  Node<T>* p = kepala;
  kepala = kepala->next;
  delete p;
  return 1;
  */
  if (kosong()) return; //Jika kosong, maka berhenti
  if(kepala->next == NULL) { //Jika hanya terdapat 1 data, maka langsung hapus
    kepala = NULL;
  } else { //Jika lebih dari 1 data, maka hapus dari belakang
    Node<T> *akhir = kepala;
    while (akhir->next->next != NULL) {
      akhir = akhir->next;
    }

    Node<T> *hapus = akhir->next;
    akhir->next = NULL;
    delete hapus;
  }
}

template <class T>
void List<T>::cetak() {
  for (Node<T>  p = kepala; p; p = p->next) cout << p->info << " -> ";
  cout << "*\n"; 
}

#endif