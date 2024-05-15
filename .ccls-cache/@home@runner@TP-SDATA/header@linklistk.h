

#include <iostream>
using namespace std;

template <class T>
class ListK;

template <class T>
class NodeK
{
    friend class ListK<T>;

    template <class U>
    friend ostream &operator<<(ostream &, const ListK<U> &);

public:
    NodeK(T &t, NodeK<T> *p) : info(t), berikut(p) {}

protected:
    T info;
    NodeK *berikut;

};

template <class T>
class ListK
{
    template <class U>
    friend ostream &operator<<(ostream &, const ListK<U> &);

public:
    ListK() : kepala(0){}
    ~ListK();
    void sisip(T t);
    void sisipBelakang(T t);
    int hapus(T &t);

    int kosong()
    {
      return (kepala == 0);
    }
    void cetak();

protected:
    NodeK<T> *kepala, *ekor;

    NodeK<T> *nodeBaru(T &t, NodeK<T> *p)
    {
        NodeK<T> *q = new NodeK<T>(t, p);
        return q;
    }

};

template <class T>
void  ListK<T>::sisipBelakang(T t)
{
    if (!kepala)
    {
        sisip(t);
        ekor = kepala;
    }
    else
    {
        NodeK<T> *p = nodeBaru(t, NULL);
        ekor->berikut = p;
        ekor = p;
    }
  
}

template <class T>
ostream &operator<<(ostream &out, const ListK<T> &k)
{
    for (NodeK<T> *p = k.kepala; p; p = p->berikut)
    {
      out << "(";
      out << p->info.nama;
      out << " seharga Rp.";
      out << p->info.harga;
      out << ") -> ";
    }
        
    out << "*\n\n";
    return out;
  
}

template <class T>
ListK<T>::~ListK()
{
    NodeK<T> *temp;
    for (NodeK<T> *p = kepala; p;)
    {
        temp = p;
        p = p->berikut;
        delete temp;
    }
  
}

template <class T>
void ListK<T>::sisip(T t)
{
    NodeK<T> *p = nodeBaru(t, kepala);
    kepala = p;
  
}

template <class T>
int ListK<T>::hapus(T &t)
{
    if (kosong())
    {
      return 0;
    }
  
    t = kepala->info;
    NodeK<T> *p = kepala;
    kepala = kepala->berikut;
    delete p;
  
    return 1;
  
}

template <class T>
void ListK<T>::cetak()
{
    for (NodeK<T> *p = kepala; p; p = p->berikut)
    {
      cout << p->info;
      cout << " -> ";
    }

    cout << "*\n";
  
}