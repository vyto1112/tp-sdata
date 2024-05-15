//214

#include <iostream>
using namespace std;

class dataStack
{
  public:
    string nama;
    int harga;
    int jumlah;
    int total;

};

dataStack ds[100];

class Stack
{
  public :
    bool isFull();
    bool isEmpty();
    void pushStack(string nama, int harga, int total);
    void popArray();
    void display();

    int top = 0;
    int maksimal = 100;
    int totalsemua;
};

Stack stk;

bool Stack::isFull()
{
  if(top == maksimal)
  {
    return true;
  }
    
  else
  {
    return false;
  }
  
}

bool Stack::isEmpty()
{
  if(top == 0)
  {
    return true;
  }
    
  else
  {
    return false;
  }
  
}

void Stack::pushStack(string nama, int harga, int jumlah){
  if(isFull())
  {
    cout << "Data penuh";
    cout << endl;
  }

  else
  {
    ds[top].nama = nama;
    ds[top].harga = harga;
    ds[top].jumlah = jumlah;
    ds[top].total = jumlah * harga;
    top++;
  }
  
}

void Stack::popArray()
{
  if(isEmpty())
  {
    cout << "Data kosong!!";
    cout << endl;
  }
    
  else
  {
    ds[top-1].nama = "";
    ds[top-1].harga = 0;
    ds[top-1].jumlah = 0;
    ds[top-1].total = 0;
    top--;
  }
  
}

void Stack::display(){
  if(isEmpty() )
  {
    cout << "Data kosong!!";
    cout << endl;
  }
  
  else
  {
    totalsemua = 0;
    
    cout << "Data pesanan : ";
    cout << endl;
    
    for (int n = 0; n < 39; n++)
    {
      cout << "-";
    }
    
    cout << endl;
    for(int i = maksimal - 1; i >= 0; i--)
    {
      if(ds[i].nama != "" )
      {
        cout << "Nama : ";
        cout << ds[i].nama;
        cout << endl;
        cout << "Harga  : ";
        cout << ds[i].harga;
        cout << endl;
        cout << "Jumlah : ";
        cout << ds[i].jumlah;
        cout << endl;
        cout << "Total bayar : ";
        cout << ds[i].total;
        cout << endl;
        
        for (int n = 0; n < 39; n++)
        {
        	cout << "-";
        }
        
        cout << endl;
        totalsemua += ds[i].total;
        
      }
 
    }
    cout << "Total bayar semua = ";
    cout << totalsemua;
    cout << endl;
    
    for (int n = 0; n < 39; n++)
    {
      cout << "-";
    }
    cout << endl;
    
  }
}
