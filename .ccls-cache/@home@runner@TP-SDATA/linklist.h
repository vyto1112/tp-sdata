#include <iostream>
using namespace std;

template <class T>
class List;


template <class T>
class Node
{
    friend class List<T>;

    template <class U>
    friend ostream &operator<<(ostream &, const List<U> &);

public:
    Node(T &t, Node<T> *p) : info(t), berikut(p) {}

protected:
    T info;
    Node *berikut;
};


template <class T>
class List
{
    template <class U>
    friend ostream &operator<<(ostream &, const List<U> &);

public:
    List() : kepala(0) {}
    ~List();
    void sisip(T t);
    void sisipBelakang(T t);
    int hapus(T &t);
    int kosong() { return (kepala == 0); }
    void cetak();

protected:
    Node<T> *kepala, *ekor;
    Node<T> *nodeBaru(T &t, Node<T> *p)
    {
        Node<T> *q = new Node<T>(t, p);
        return q;
    }
};



template <class T>
void  List<T>::sisipBelakang(T t){
    if (!kepala)
    {
        sisip(t);
        ekor = kepala;
    }
    else{
        Node<T> *p = nodeBaru(t, NULL);
        ekor->berikut = p;
        ekor = p;
    }
}


template <class T>
ostream &operator<<(ostream &out, const List<T> &k)
{
    for (Node<T> *p = k.kepala; p; p = p->berikut)
        out << "("<< p->info.nama <<" sejumlah "<< p->info.jumlah <<" buah " << ") -> ";
    out << "*\n\n";
    return out;
}
template <class T>
List<T>::~List()
{
    Node<T> *temp;
    for (Node<T> *p = kepala; p;)
    {
        temp = p;
        p = p->berikut;
        delete temp;
    }
}
template <class T>
void List<T>::sisip(T t)
{
    Node<T> *p = nodeBaru(t, kepala);
    kepala = p;
}
template <class T>
int List<T>::hapus(T &t)
{
    if (kosong())
        return 0; // penghapusan gagal
    t = kepala->info;
    Node<T> *p = kepala;
    kepala = kepala->berikut;
    delete p;
    return 1; // penghapusan sukses
}
template <class T>
void List<T>::cetak()
{
    for (Node<T> *p = kepala; p; p = p->berikut)
        cout << p->info << " -> ";
    cout << "*\n";
}