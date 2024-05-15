//179

#include <iostream>
using namespace std;

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
  cout << "Jumlah data yg ngantri : " << countArrayUT() << "data." << endl;
  cout << "Data Antrian Layanan : " << endl;
  if( isEmptyArrayUT() )
  {
    cout << "Antrian kosong!!" << endl;
  }else
  {
    for( int i = 0; i < maksimalAntrianArrayUT; i++ )
    {
      // cek apakah ruang kosong atau tidak
      if( antrianUserUT[i] != "" )
      {
        // kalau ruang tidak kosong
        cout << i+1 << ". " << antrianUserUT[i] << endl;
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
    cout << "Antrian Penuh!!!" << endl;
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
    cout << "Data Antrian Kosong!!" << endl;
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
    cout << "Data Antrian Kosong!!" << endl;
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
  cout << "Data Antrian : " << endl;
  if( isEmptyLinkedListUT() )
  {
    cout << "Data Antrian Kosong!!" << endl;
  }
    
  else
  {
    cout << "Banyak data antrian : " << countLinkedListUT() << endl;
    curUT = headUT;
    int nomor = 1;
    while( nomor <= maksimalAntrianLinkedListUT ){
      
      if( curUT != NULL )
      {
        cout << nomor << ". " << curUT->nama << " \t" << curUT->id << "." << endl;
        curUT = curUT->next;
      }

      nomor++;
    }

  }

  cout << "\n" << endl;

}
