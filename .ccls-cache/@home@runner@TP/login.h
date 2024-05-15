#include <iostream>
#include "ktp.h"
// #include "admin.h"
// #include "user.h"
using namespace std;

class Login{
  public:
    void login();
    bool islogin();
    bool isAdmin();
  private:
    string nik, nama;
    bool berhasil_login = false;
    bool isadmin = false;
    
}lo;

void Login::login(){
  awal:
  system("clear");
  KTP x;
  x.ambildata();
  cout << "-------------- MENU LOGIN -------------" << endl;
  cout << "Masukkan NIK anda  : "; cin >> nik;
  cout << "Masukkan nama anda : "; cin >> nama;
  cout << "---------------------------------------" << endl;

  if(nik == dataKTP[0].NIK && nama == dataKTP[0].nama){
    cout << "Anda login sebagai admin" << endl;
    isadmin = true;
    berhasil_login = true;
    // ad.menu();
  }
  else if(nik == dataKTP[1].NIK && nama == dataKTP[1].nama){
    cout << "Anda login sebagai user" << endl;
    isadmin = false;
    berhasil_login = true;
    // us.menu();
  }
  else{
    berhasil_login = false;
    cout << "Data yang anda masukkan tidak terdaftar!" << endl;
    
    cout << "Tekan enter untuk login kembali" << endl;
    cout << "---------------------------------------" << endl;
    cin.ignore();
	  getchar();
	  goto awal;
  }
  cin.ignore();
	getchar();
}
 bool Login:: islogin (){ 
   return berhasil_login;
 }
bool Login:: isAdmin (){
   return isadmin;
 }