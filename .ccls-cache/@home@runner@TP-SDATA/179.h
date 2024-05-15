//179

#include <iostream>
#include <fstream>
#include "179/userToko.h"
#include "179/userKlinik.h"
using namespace std;

//Class User
class User
{
  public:
    void menu();
};

User us;

//Method untuk menu utama sebagai user
void User::menu()
{
  awal:
  system("clear");
  int pil;
  
  cout << "-------------- MENU USER --------------";
  cout << endl;
  cout << "1. Menu TOKO";
  cout << endl;
  cout << "2. Menu KLINIK";
  cout << endl;
  cout << "3. Kembali ke menu login";
  cout << endl;
  cout << "---------------------------------------";
  cout << endl;
  cout << "Anda memilih menu : ";
  cin >> pil;
  cout << "---------------------------------------";
  cout << endl;
  
  
  if (pil == 1)
  {
    ut.menutoko();
  }
    
  else if (pil == 2)
  {
    uk.menuklinik();
  }
    
  else if (pil == 3)
  {
    goto akhir;
  }
    
  else
  {
    cout << "Pilihan yang anda masukkan tidak ada!";
    cout << endl;
    cout << "Tekan enter untuk memilih menu kembali";
    cout << endl;
    cout << "---------------------------------------";
    cout << endl;
  }
  
  cin.ignore();
  getchar();
  goto awal;
  
  akhir:
  system("clear");
  
}
