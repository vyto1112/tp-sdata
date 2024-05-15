#include <iostream>
#include <fstream>
#include "header/doublelist.h"
using namespace std;

//Class login
class Login
{
  public:
    void login();
    void datalogin(int no);
    void tampil();
    bool islogin();
    bool isAdmin();

  private:
    int pil;
    int nolog;
    string status;
    string nik;
    string nama;
    string alamat;
    bool berhasil_login = false;
    bool isadmin = false;  

}lo;

//Class KTP
class KTP
{
	public :
		string NIK;
		string nama;
		string alamat;
		int umur;
    void ambildata();
    int idx;
};

KTP x;
KTP dataKTP[5];

//Prosedur untuk memisahkan data
void tokenize(string s, string del = " ", int idx =0)
{
	string tmp;
	int i = 1;
  int start, end = -1*del.size();
  
  do
  {
    start = end + del.size();
    end = s.find(del, start);
    tmp = s.substr(start, end - start);
    
    if (i == 1)
    {
      dataKTP[idx].status = tmp;
    }
    else if (i == 2)
    {
      dataKTP[idx].NIK = tmp;
    }
    else if (i == 3){
      dataKTP[idx].nama = tmp;
    }
    else if (i == 4){
      dataKTP[idx].alamat = tmp;
    }
    i++;
    }while (end != -1);
}

//Method untuk mengambil data dari ktp.txt
void KTP::ambildata()
{
  ifstream baca;
  string t;
  baca.open("ktp.txt");

  idx = 0;
	while(!baca.eof())
  {
		baca >> t;
		tokenize(t, ";", idx);
		idx++;
	}
  
	baca.close();
}

//Method untuk menyimpan data siapa yang login
void Login::datalogin(int no)
{
  ofstream log;
  ofstream hislog;
  
  log.open("datalogin.txt");
  log << dataKTP[no].NIK << ";" << dataKTP[no].nama << ";" << dataKTP[no].alamat << endl;

  log.close();
  
  hislog.open("history_login.txt", ios::app);
  hislog << "NIK    : " << dataKTP[no].NIK << endl;
  hislog << "Nama   : " << dataKTP[no].nama << endl;
  hislog << "Alamat : " << dataKTP[no].alamat << endl;
  if (isadmin == true){
    hislog << "Status : " << "Admin" << endl;
  }
  else{
    hislog << "Status : " << "User" << endl;
  }
  hislog << "---------------------------------------" << endl;
  
  hislog.close();
}

//Method untuk menampilkan data ktp yang tersedia
void Login::tampil()
{
  for (int i = 0; i < x.idx - 1; i++){
    cout << "Data ktp ke-" << i + 1 << " : " << endl;
    cout << "NIK    : " << dataKTP[i].NIK << endl;
    cout << "Nama   : " << dataKTP[i].nama << endl;
    cout << "Alamat : " << dataKTP[i].alamat << endl;
    cout << "---------------------------------------" << endl;
  }
}

//Method untuk menu utama login
void Login::login()
{
  awal:
  system("clear");
  x.ambildata();
  
  cout << "-------------- MENU LOGIN -------------" << endl;
  cout << "1. Login dari data ktp" << endl;
  cout << "2. Login dengan input keyboard" << endl;
  cout << "3. Buat akun baru dengan data ktp" << endl;
  cout << "---------------------------------------" << endl;
  cout << "Anda memilih menu : "; cin >> pil;
  cout << "---------------------------------------" << endl;
  
  if (pil == 1)
  {
    tampil();
    cout << "Masukkan no data yang ingin anda pakai : "; cin >> nolog;
    if(nolog == 1)
    {
      cout << "Anda login sebagai admin" << endl;
      isadmin = true;
      berhasil_login = true;
      datalogin(0);
    }
    else if(nolog == 2)
    {
      cout << "Anda login sebagai user" << endl;
      isadmin = false;
      berhasil_login = true;
      datalogin(1);
    }
    else if(nolog == 3)
    {
      cout << "Anda login sebagai user" << endl;
      isadmin = false;
      berhasil_login = true;
      datalogin(2);
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
  }
  else if (pil == 2)
  {
    cout << endl << "-------------- MENU LOGIN -------------" << endl;
    cout << "Masukkan NIK anda  : "; cin >> nik;
    cout << "Masukkan nama anda : "; cin >> nama;
    cout << "---------------------------------------" << endl;
    if(nik == dataKTP[0].NIK && nama == dataKTP[0].nama)
    {
      cout << "Anda login sebagai admin" << endl;
      isadmin = true;
      berhasil_login = true;
      datalogin(0);
    }
    else if(nik == dataKTP[1].NIK && nama == dataKTP[1].nama)
    {
      cout << "Anda login sebagai user" << endl;
      isadmin = false;
      berhasil_login = true;
      datalogin(1);
    }
    else if(nik == dataKTP[2].NIK && nama == dataKTP[2].nama)
    {
      cout << "Anda login sebagai user" << endl;
      isadmin = false;
      berhasil_login = true;
      datalogin(2);
    }
    else
    {
      berhasil_login = false;
      cout << "Data yang anda masukkan tidak terdaftar!" << endl;
      cout << "Tekan enter untuk login kembali" << endl;
      cout << "---------------------------------------" << endl;
      cin.ignore();
  	  getchar();
  	  goto awal;
    }
  }
  else if (pil == 3)
  {
    
  }
  else
  {
    cout << "Pilihan yang anda masukkan tidak ada!" << endl;
    cout << "Tekan enter untuk kembali lagi" << endl;
  }
  cin.ignore();
	getchar(); 
}

//Method untuk status login
bool Login:: islogin ()
{ 
   return berhasil_login;
}

//Method untuk status admin
bool Login:: isAdmin ()
{
   return isadmin;
}