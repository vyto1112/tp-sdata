//209

#include <iostream>
#include <fstream>
#include "209/adminToko.h"
#include "209/adminKlinik.h"
#include "214/adminSuplier.h"
#include <sstream>
using namespace std;

//Class Admin
class Admin
{
  public:
    void menu();
};

Admin ad;

void Admin::menu()
{
  awal:
  system("clear");
  int pil;

  cout << "-------------- MENU ADMIN -------------";
  cout << endl;
  cout << "1. Menu TOKO";
  cout << endl;
  cout << "2. Menu KLINIK";
  cout << endl;
  cout << "3. Menu SUPLIER";
  cout << endl;
  cout << "4. Kembali ke menu login";
  cout << endl;
  cout << "---------------------------------------";
  cout << endl;
  cout << "Anda memilih menu : ";
  cin >> pil;
  cout << "---------------------------------------";
  cout << endl;
  
  if (pil == 1)
  {
    t.menutoko();
  }
    
  else if (pil == 2)
  {
    k.menuklinik();
  }

  else if (pil == 3)
  {
    s.menusuplier();
  }
    
  else if (pil == 4)
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
