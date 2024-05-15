//179

#ifndef LLqueue
#define LLqueue_

#include <iostream>
using namespace std;

// array Antrian
int maksimalAntrianArray = 100, front = 0, back = 0;
// ruang antrian array
string antrianUser[100];

// isFull / cek data antrian penuh atau tidak
bool isFullArray()
{
  if(back == maksimalAntrianArray)
  {
    return true;
  }
    
  else
  {
    return false;
  }
}

// isEmpty
bool isEmptyArray()
{
  if( back == 0 )
  {
    return true;
  }
    
  else
  {
    return false;
  }
}

// enqueue / penambahan data antrian
void enqueueArray(string data){

  if(isFullArray())
  {
    cout << "Antrian penuh!!";
    cout << endl;
  }
    
  else
  {
    // cek apakah datanya kosong atau tidak
    if(isEmptyArray())
    {
      // kalau antrian kosong
      antrianUser[0] = data;
      front++;
      back++;
    }
      
    else
    {
      // kalo gak kosong
      antrianUser[back] = data;
      back++;
    }
  }

}

// dequeue / penghapusan data depan
void dequeueArray()
{
  if( isEmptyArray())
  {
    cout << "Antrian kosong!!";
    cout << endl;
  }
    
  else
  {
    for( int i = 0; i < back; i++ )
    {
      antrianUser[i] = antrianUser[i+1];
    }
    back--;
  }
}

// countArray / menghitung banyak data yg ngantri
int countArray()
{

  if( isEmptyArray() )
  {
    return 0;
  }
    
  else if( isFullArray() )
  {
    return maksimalAntrianArray;
  }
    
  else
  {
    return back;
  }

}

// destroy / clear
void destroyArray()
{
  if(isEmptyArray())
  {
    cout << "Antrian kosong!!";
    cout << endl;
  }
  
  else
  {
    for(int i = 0; i < maksimalAntrianArray; i++)
    {
      
      if( back > 1 )
      {
        antrianUser[back - 1] = "";
        back--;
      }
        
      else if( back == 1 )
      {
        antrianUser[back - 1] = "";
        back = 0;
        front = 0;
      }

    }
  }
}


// Display / View
void viewArray()
{
  cout << "Jumlah data yg ngantri : ";
  cout << countArray();
  cout << "data.";
  cout << endl;
  cout << "Data Antrian Layanan : ";
  cout << endl;
  
  if( isEmptyArray() )
  {
    cout << "Antrian kosong!!";
    cout << endl;
  }
    
  else
  {
    for( int i = 0; i < maksimalAntrianArray; i++ )
    {
      // cek apakah ruang kosong atau tidak
      if( antrianUser[i] != "" )
      {
        // kalau ruang tidak kosong
        cout << i+1;
        cout << ". ";
        cout << antrianUser[i];
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
struct antrianUserLL
{
  // data / member
  string nama;
  string id;

  // pointer next
  antrianUserLL *next;
};

int maksimalAntrianLinkedList = 100;
antrianUserLL *head, *tail, *cur, *del, *newNode;

// count Linked List
int countLinkedList()
{
  if( head == NULL )
  {
    return 0;
  }
    
  else
  {
    int banyak = 0;
    cur = head;
    while( cur != NULL )
    {
      cur = cur->next;
      banyak++;
    }
    return banyak;
  }
}

// isFull Linked List
bool isFullLinkedList()
{
  if( countLinkedList() == maksimalAntrianLinkedList )
  {
    return true;
  }
  else
  {
    return false;
  }
}

// isEmpty Linked List
bool isEmptyLinkedList()
{
  if( countLinkedList() == 0 )
  {
    return true;
  }
  else
  {
    return false;
  }
}

// enqueue / penambahan
void enqueueLinkedList( string nama, string id )
{

  if( isFullLinkedList() )
  {
    cout << "Antrian Penuh!!!";
    cout << endl;
  }
    
  else
  {
    
    if( isEmptyLinkedList() )
    {
      head = new antrianUserLL();
      head->nama = nama;
      head->id = id;
      head->next = NULL;
      tail = head;
    }
      
    else
    {
      newNode = new antrianUserLL();
      newNode->nama = nama;
      newNode->id = id;
      newNode->next = NULL;
      tail->next = newNode;
      tail = newNode;
    }

  }

}

// dequeue Linked List
void dequeueLinkedList()
{
  if( isEmptyLinkedList() )
  {
    cout << "Data Antrian Kosong!!";
    cout << endl;
  }
    
  else
  {
    del = head;
    head = head->next;
    del->next = NULL;
    delete del;
  }
}

// destroy / clear
void clearLinkedList()
{
  if( isEmptyLinkedList() )
  {
    cout << "Data Antrian Kosong!!";
    cout << endl;
  }
    
  else
  {
    cur = head;
    while( cur != NULL )
    {
      del = cur;
      cur = cur->next;
      del->next = NULL;
      delete del;
    }
    head = NULL;
    tail = NULL;
  }
}

// display Linked List
void displayLinkedList()
{
  cout << "Data Antrian : ";
  cout << endl;
  if( isEmptyLinkedList() )
  {
    cout << "Data Antrian Kosong!!";
    cout << endl;
  }
    
  else
  {
    cout << "Banyak data antrian : ";
    cout << countLinkedList();
    cout << endl;
    
    cur = head;
    int nomor = 1;
    while( nomor <= maksimalAntrianLinkedList ){
      
      if( cur != NULL )
      {
        cout << nomor;
        cout << ". ";
        cout << cur->nama;
        cout << " \t";
        cout << cur->id;
        cout << ".";
        cout << endl;
        cur = cur->next;
      }

      nomor++;
    }

  }

  cout << endl;
  cout << endl;

}

#endif
