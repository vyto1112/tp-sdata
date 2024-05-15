#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class KTP {
	public :
		string NIK;
		string nama;
		string alamat;
		int umur;
    void ambildata();
  private :
    int idx;
};

KTP dataKTP[5];

void tokenize(string s, string del = " ", int idx =0)
{
	string tmp;
	int i = 1;
    int start, end = -1*del.size();
    do {
        start = end + del.size();
        end = s.find(del, start);
        tmp = s.substr(start, end - start);

        if (i == 1)
        {
        	dataKTP[idx].NIK = tmp;
        }
        else if (i == 2){
        	dataKTP[idx].nama = tmp;
        }
        else if (i == 3){
          dataKTP[idx].alamat = tmp;
        }
        i++;

    } while (end != -1);
}

void KTP::ambildata(){
  ifstream baca;
  string t;
  
  baca.open("ktp.txt");
	while(!baca.eof()){
		baca >> t;
		tokenize(t, ";", idx);
		idx++;
	}
	baca.close();
}



void datalogin(){
  ofstream log;
  log.open("datalogin.txt");
  
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
    isadmin = false;
    berhasil_login = true;
  }
  else if(nik == dataKTP[2].NIK && nama == dataKTP[2].nama)
  {
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