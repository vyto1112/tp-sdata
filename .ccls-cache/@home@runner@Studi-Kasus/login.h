#include <iostream>
#include "ktp.h"
#include "admin.h"
using namespace std;

class Login{
  public:
    void login();
  private:
    string nik, nama;
}lo;

void Login::login(){
  awal:
  system("clear");
  KTP x;
  x.ambildata();
  // cout << "-----------------------------" << endl;
  // for (int i = 0; i < 2; i++){
  //   cout << "NIK  : " << dataKTP[i].NIK << endl;
  //   cout << "Nama : " << dataKTP[i].nama << endl;
  //   cout << "-----------------------------" << endl;
  // }
  cout << "-------------- MENU LOGIN -------------" << endl;
  cout << "Masukkan NIK anda  : "; cin >> nik;
  cout << "Masukkan nama anda : "; cin >> nama;
  cout << "---------------------------------------" << endl;

  if(nik == dataKTP[0].NIK && nama == dataKTP[0].nama){
    ad.menu();
    cin.ignore();
		getchar();
		goto awal;
  }
  else if(nik == dataKTP[1].NIK && nama == dataKTP[1].nama){
    cout << "Anda login sebagai user" << endl;
  }
  else{
    cout << "Data yang anda masukkan tidak terdaftar!" << endl;
    cout << "Tekan enter untuk login kembali" << endl;
    cout << "---------------------------------------" << endl;
    cin.ignore();
		getchar();
		goto awal;
  }
}