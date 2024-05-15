#include <iostream>
#include <fstream>
#include "ktp.h"
using namespace std;

class Login{
  public:
    void login();
    void datalogin(int no);
    bool islogin();
    bool isAdmin();
  private:
    string nik, nama, alamat;
    bool berhasil_login = false;
    bool isadmin = false;
    
}lo;

void Login::datalogin(int no){
  ofstream log;
  
  log.open("datalogin.txt");
  log << dataKTP[no].NIK << ";" << dataKTP[no].nama << ";" << dataKTP[no].alamat;
  
  log.close();
}

void Login::login(){
  awal:
  system("clear");
  KTP x;
  x.ambildata();
  cout << "-------------- MENU LOGIN -------------" << endl;
  cout << "Masukkan NIK anda  : "; cin >> nik;
  cout << "Masukkan nama anda : "; cin >> nama;
  cout << "---------------------------------------" << endl;

  if(nik == dataKTP[0].NIK && nama == dataKTP[0].nama)
  {
    cout << "Anda login sebagai admin" << endl;
    isadmin = true;
    berhasil_login = true;
  }
  else if(nik == dataKTP[1].NIK && nama == dataKTP[1].nama)
  {
    cout << "Anda login sebagai user" << endl;
    datalogin(1);
    isadmin = false;
    berhasil_login = true;
  }
  else if(nik == dataKTP[2].NIK && nama == dataKTP[2].nama)
  {
    datalogin(2);
    cout << "Anda login sebagai user" << endl;
    isadmin = false;
    berhasil_login = true;
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