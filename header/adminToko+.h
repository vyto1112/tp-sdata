//209

#include <iostream>
using namespace std;

// array Antrian
int maksimalAntrianArrayAT = 100, frontAT = 0, backAT = 0;
// ruang antrian array
string antrianUserAT[100];

// isFull / cek data antrian penuh atau tidak
bool isFullArrayAT()
{
  if(backAT == maksimalAntrianArrayAT)
  {
    return true;
  }
    
  else
  {
    return false;
  }
}

// isEmpty
bool isEmptyArrayAT()
{
  if( backAT == 0 )
  {
    return true;
  }
    
  else
  {
    return false;
  }
}

// enqueue / penambahan data antrian
void enqueueArrayAT(string data){

  if(isFullArrayAT())
  {
    cout << "Antrian penuh!!" << endl;
  }
    
  else
  {
    // cek apakah datanya kosong atau tidak
    if(isEmptyArrayAT())
    {
      // kalau antrian kosong
      antrianUserAT[0] = data;
      frontAT++;
      backAT++;
    }
      
    else
    {
      // kalo gak kosong
      antrianUserAT[backAT] = data;
      backAT++;
    }
  }

}

// dequeue / penghapusan data depan
void dequeueArrayAT()
{
  if( isEmptyArrayAT())
  {
    cout << "Antrian kosong!!" << endl;
  }
  else
  {
    for( int i = 0; i < backAT; i++ )
    {
      antrianUserAT[i] = antrianUserAT[i+1];
    }
    backAT--;
  }
}

// countArray / menghitung banyak data yg ngantri
int countArrayAT()
{

  if( isEmptyArrayAT() )
  {
    return 0;
  }
    
  else if( isFullArrayAT() )
  {
    return maksimalAntrianArrayAT;
  }
    
  else
  {
    return backAT;
  }

}

// destroy / clear
void destroyArrayAT()
{
  if(isEmptyArrayAT())
  {
    cout << "Antrian kosong!!" << endl;
  }
  
  else
  {
    for(int i = 0; i < maksimalAntrianArrayAT; i++)
    {
      
      if( backAT > 1 )
      {
        antrianUserAT[backAT - 1] = "";
        backAT--;
      }
      else if( backAT == 1 )
      {
        antrianUserAT[backAT - 1] = "";
        backAT = 0;
        frontAT = 0;
      }

    }
  }
}


// Display / View
void viewArrayAT()
{
  cout << "Jumlah data yg ngantri : " << countArrayAT() << "data." << endl;
  cout << "Data Antrian Layanan : " << endl;
  if( isEmptyArrayAT() )
  {
    cout << "Antrian kosong!!" << endl;
  }else
  {
    for( int i = 0; i < maksimalAntrianArrayAT; i++ )
    {
      // cek apakah ruang kosong atau tidak
      if( antrianUserAT[i] != "" )
      {
        // kalau ruang tidak kosong
        cout << i+1 << ". " << antrianUserAT[i] << endl;
      }else
      {
        // kalo kosong
        cout << i+1 << ". (kosong)" << endl;
      }
    }
  }
  cout << "\n" << endl;
}

// siapin ruang antrian
struct antrianUserLLAT
{
  // data / member
  string nama;
  string id;

  // pointer next
  antrianUserLLAT *next;
};

int maksimalAntrianLinkedListAT = 100;
antrianUserLLAT *headAT, *tailAT, *curAT, *delAT, *newNodeAT;

// count Linked List
int countLinkedListAT()
{
  if( headAT == NULL )
  {
    return 0;
  }
    
  else
  {
    int banyak = 0;
    curAT = headAT;
    while( curAT != NULL )
    {
      curAT = curAT->next;
      banyak++;
    }
    return banyak;
  }
}

// isFull Linked List
bool isFullLinkedListAT()
{
  if( countLinkedListAT() == maksimalAntrianLinkedListAT )
  {
    return true;
  }
  else
  {
    return false;
  }
}

// isEmpty Linked List
bool isEmptyLinkedListAT()
{
  if( countLinkedListAT() == 0 )
  {
    return true;
  }
  else
  {
    return false;
  }
}

// enqueue / penambahan
void enqueueLinkedListAT( string nama, string id )
{

  if( isFullLinkedListAT() )
  {
    cout << "Antrian Penuh!!!" << endl;
  }
    
  else
  {
    
    if( isEmptyLinkedListAT() )
    {
      headAT = new antrianUserLLAT();
      headAT->nama = nama;
      headAT->id = id;
      headAT->next = NULL;
      tailAT = headAT;
    }
      
    else
    {
      newNodeAT = new antrianUserLLAT();
      newNodeAT->nama = nama;
      newNodeAT->id = id;
      newNodeAT->next = NULL;
      tailAT->next = newNodeAT;
      tailAT = newNodeAT;
    }

  }

}

// dequeue Linked List
void dequeueLinkedListAT()
{
  if( isEmptyLinkedListAT() )
  {
    cout << "Data Antrian Kosong!!" << endl;
  }
    
  else
  {
    delAT = headAT;
    headAT = headAT->next;
    delAT->next = NULL;
    delete delAT;
  }
}

// destroy / clear
void clearLinkedListAT()
{
  if( isEmptyLinkedListAT() )
  {
    cout << "Data Antrian Kosong!!" << endl;
  }
    
  else
  {
    curAT = headAT;
    while( curAT != NULL )
    {
      delAT = curAT;
      curAT = curAT->next;
      delAT->next = NULL;
      delete delAT;
    }
    headAT = NULL;
    tailAT = NULL;
  }
}

// display Linked List
void displayLinkedListAT()
{
  cout << "Data Antrian : " << endl;
  if( isEmptyLinkedListAT() )
  {
    cout << "Data Antrian Kosong!!" << endl;
  }
    
  else
  {
    cout << "Banyak data antrian : " << countLinkedListAT() << endl;
    curAT = headAT;
    int nomor = 1;
    while( nomor <= maksimalAntrianLinkedListAT ){
      
      if( curAT != NULL )
      {
        cout << nomor << ". " << curAT->nama << " \t" << curAT->id << "." << endl;
        curAT = curAT->next;
      }

      nomor++;
    }

  }

  cout << "\n" << endl;

}
