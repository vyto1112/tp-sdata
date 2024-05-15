//179

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
    List() : kepala(0){}
    ~List();
    void sisip(T t);
    void sisipBelakang(T t);
    int hapus(T &t);

    int kosong()
    {
      return (kepala == 0);
    }
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
void  List<T>::sisipBelakang(T t)
{
    if (!kepala)
    {
        sisip(t);
        ekor = kepala;
    }
    else
    {
        Node<T> *p = nodeBaru(t, NULL);
        ekor->berikut = p;
        ekor = p;
    }
  
}

template <class T>
ostream &operator<<(ostream &out, const List<T> &k)
{
    for (Node<T> *p = k.kepala; p; p = p->berikut)
    {
      out << "(";
      out << p->info.nama;
      out << " sejumlah ";
      out << p->info.jumlah;
      out <<" buah";
      out << ") -> ";
    }
        
    out << "*";
    out << endl;
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
    {
      return 0;
    }
  
    t = kepala->info;
    Node<T> *p = kepala;
    kepala = kepala->berikut;
    delete p;
  
    return 1;
  
}

template <class T>
void List<T>::cetak()
{
    for (Node<T> *p = kepala; p; p = p->berikut)
    {
      cout << p->info;
      cout << " -> ";
    }

    cout << "*";
    cout << endl;
  
}

// array Antrian
int maksimalAntrianArrayUT = 100, frontUT = 0, backUT = 0;
// ruang antrian array
string antrianUserUT[100];

// isFull / cek data antrian penuh atau tidak
bool isFullArrayUT()
{
  if(backUT == maksimalAntrianArrayUT)
  {
    return true;
  }
    
  else
  {
    return false;
  }
}

// isEmpty
bool isEmptyArrayUT()
{
  if( backUT == 0 )
  {
    return true;
  }
    
  else
  {
    return false;
  }
}

// enqueue / penambahan data antrian
void enqueueArrayUT(string data){

  if(isFullArrayUT())
  {
    cout << "Antrian penuh!!" << endl;
  }
    
  else
  {
    // cek apakah datanya kosong atau tidak
    if(isEmptyArrayUT())
    {
      // kalau antrian kosong
      antrianUserUT[0] = data;
      frontUT++;
      backUT++;
    }
      
    else
    {
      // kalo gak kosong
      antrianUserUT[backUT] = data;
      backUT++;
    }
  }

}

// dequeue / penghapusan data depan
void dequeueArrayUT()
{
  if( isEmptyArrayUT())
  {
    cout << "Antrian kosong!!" << endl;
  }
  else
  {
    for( int i = 0; i < backUT; i++ )
    {
      antrianUserUT[i] = antrianUserUT[i+1];
    }
    backUT--;
  }
}

// countArrayUT / menghitung banyak data yg ngantri
int countArrayUT()
{

  if( isEmptyArrayUT() )
  {
    return 0;
  }
    
  else if( isFullArrayUT() )
  {
    return maksimalAntrianArrayUT;
  }
    
  else
  {
    return backUT;
  }

}

// destroy / clear
void destroyArrayUT()
{
  if(isEmptyArrayUT())
  {
    cout << "Antrian kosong!!" << endl;
  }
  
  else
  {
    for(int i = 0; i < maksimalAntrianArrayUT; i++)
    {
      
      if( backUT > 1 )
      {
        antrianUserUT[backUT - 1] = "";
        backUT--;
      }
      else if( backUT == 1 )
      {
        antrianUserUT[backUT - 1] = "";
        backUT = 0;
        frontUT = 0;
      }

    }
  }
}


// Display / View
void viewArrayUT()
{
  cout << "Jumlah data yg ngantri : ";
  cout << countArrayUT();
  cout << "data.";
  cout << endl;
  cout << "Data Antrian Layanan : ";
  cout << endl;
  
  if( isEmptyArrayUT() )
  {
    cout << "Antrian kosong!!";
    cout << endl;
  }
    
  else
  {
    for( int i = 0; i < maksimalAntrianArrayUT; i++ )
    {
      // cek apakah ruang kosong atau tidak
      if( antrianUserUT[i] != "" )
      {
        // kalau ruang tidak kosong
        cout << i+1;
        cout << ". ";
        cout << antrianUserUT[i];
        cout << endl;
      }
        
      else
      {
        // kalo kosong
        cout << i+1;
        cout << ". (kosong)";
        cout << endl;
      }
    }
  }
  cout << endl;
  cout << endl;
}

// siapin ruang antrian
struct antrianUserTLL
{
  // data / member
  string nama;
  string id;

  // pointer next
  antrianUserTLL *next;
};

int maksimalAntrianLinkedListUT = 100;
antrianUserTLL *headUT, *tailUT, *curUT, *delUT, *newNodeUT;

// count Linked List
int countLinkedListUT()
{
  if( headUT == NULL )
  {
    return 0;
  }
    
  else
  {
    int banyak = 0;
    curUT = headUT;
    while( curUT != NULL )
    {
      curUT = curUT->next;
      banyak++;
    }
    return banyak;
  }
}

// isFull Linked List
bool isFullLinkedListUT()
{
  if( countLinkedListUT() == maksimalAntrianLinkedListUT )
  {
    return true;
  }
    
  else
  {
    return false;
  }
}

// isEmpty Linked List
bool isEmptyLinkedListUT()
{
  if( countLinkedListUT() == 0 )
  {
    return true;
  }
    
  else
  {
    return false;
  }
}

// enqueue / penambahan
void enqueueLinkedListUT( string nama, string id )
{

  if( isFullLinkedListUT() )
  {
    cout << "Antrian Penuh!!!";
    cout << endl;
  }
    
  else
  {
    
    if( isEmptyLinkedListUT() )
    {
      headUT = new antrianUserTLL();
      headUT->nama = nama;
      headUT->id = id;
      headUT->next = NULL;
      tailUT = headUT;
    }
      
    else
    {
      newNodeUT = new antrianUserTLL();
      newNodeUT->nama = nama;
      newNodeUT->id = id;
      newNodeUT->next = NULL;
      tailUT->next = newNodeUT;
      tailUT = newNodeUT;
    }

  }

}

// dequeue Linked List
void dequeueLinkedListUT()
{
  if( isEmptyLinkedListUT() )
  {
    cout << "Data Antrian Kosong!!";
    cout << endl;
  }
    
  else
  {
    delUT = headUT;
    headUT = headUT->next;
    delUT->next = NULL;
    delete delUT;
  }
}

// destroy / clear
void clearLinkedListUT()
{
  if( isEmptyLinkedListUT() )
  {
    cout << "Data Antrian Kosong!!";
    cout << endl;
  }
    
  else
  {
    curUT = headUT;
    while( curUT != NULL )
    {
      delUT = curUT;
      curUT = curUT->next;
      delUT->next = NULL;
      delete delUT;
    }
    headUT = NULL;
    tailUT = NULL;
  }
}

// display Linked List
void displayLinkedListUT()
{
  cout << "Data Antrian : ";
  cout << endl;
  
  if( isEmptyLinkedListUT() )
  {
    cout << "Data Antrian Kosong!!";
    cout << endl;
  }
    
  else
  {
    cout << "Banyak data antrian : ";
    cout << countLinkedListUT();
    cout << endl;
    
    curUT = headUT;
    int nomor = 1;
    while( nomor <= maksimalAntrianLinkedListUT ){
      
      if( curUT != NULL )
      {
        cout << nomor;
        cout << ". ";
        cout << curUT->nama;
        cout << " \t";
        cout << curUT->id;
        cout << ".";
        cout << endl;
        curUT = curUT->next;
      }

      nomor++;
    }

  }

  cout << endl;
  cout << endl;

}
