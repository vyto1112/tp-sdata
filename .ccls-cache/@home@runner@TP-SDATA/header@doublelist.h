#include <iostream>
using namespace std;

template <class T>
class Noded
{
  public:
    Noded(T& t, Noded<T>* p) : info(t), next(p) {}
    T info;
    Noded *next;
    Noded *prev;
};

template <class T>
class Listd
{
  template <class A>
  friend ostream& operator<<(ostream&, const Listd<A>&);
public :
  Listd() : kepala(0) {}
  ~Listd();
  void sisip(T t);
  void hapus(T& t);
  int kosong()
  {
    return (kepala == NULL);  
  }
  void cetak();
  Noded<T>* kepala;
  Noded<T>* nodeBaru(T& t, Noded<T>* p)
  { 
    Noded<T>* q = new Noded<T>(t, p); return q;
  }
};

template <class T>
ostream& operator<<(ostream& out, const Listd<T>& k)
{
  for (Noded<T>* p = k.kepala; p; p = p->next) 
  out << p->info << " -> ";
  out << "*\n";
  return out;
}

template <class T>
Listd<T>::~Listd()
{
  Noded<T>* temp;
  for (Noded<T>* p = kepala; p;)
  {
    temp = p;
    p = p->next;
    delete temp;
  }
}

template <class T>
void Listd<T>::sisip(T t)
{
  Noded<T> *tambah = nodeBaru(t, kepala);
  tambah->next = NULL;
  tambah->prev = NULL;

  if(kepala == NULL)
  {
    kepala = tambah;
  }
  else
  {
    Noded<T> *akhir = kepala;
    while (akhir->next != NULL)
    {
      akhir = akhir->next;
    }

    tambah->prev = akhir;
    akhir->next = tambah;
  }
}

template <class T>
void Listd<T>::hapus(T& t)
{
  if (kosong()) return;
  if(kepala->next == NULL)
  {
    kepala = NULL;
  }
  else
  {
    Noded<T> *akhir = kepala;
    while (akhir->next->next != NULL)
    {
      akhir = akhir->next;
    }

    Noded<T> *hapus = akhir->next;
    akhir->next = NULL;
    delete hapus;
  }
}

template <class T>
void Listd<T>::cetak()
{
  for (Noded<T>  p = kepala; p; p = p->next) cout << p->info << " -> ";
  cout << "*\n"; 
}