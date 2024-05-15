#include <iostream>
#include <fstream>
#include "stok.h"
#include "arrayd.h"
using namespace std;

class Admin{
  public:
    void menu();
    void reset();
    void tokenize();
    void ambildata();
    int sz;
    string tgl, nama;
    int harga, stok;
}ad;

Array1D<Stok> X(5);

int toInt(string x){
	int y;

	stringstream ss;
	ss << x;
	ss >> y;

	return y;
}

void tokenize1(string s, string del = " ", int idx =0){
	string tmp;
	int i = 1;
    int start, end = -1*del.size();
    do {
        start = end + del.size();
        end = s.find(del, start);
        tmp = s.substr(start, end - start);

        if (i == 1)
        {
        	X[idx].tgl = tmp;
        }
        else if (i == 2){
        	X[idx].nama = tmp;
        }
        else if (i == 3){
        	X[idx].harga = toInt(tmp);
        }
        else{
        	X[idx].stok = toInt(tmp);
        }
        i++;

    } while (end != -1);
}

void Admin::ambildata(){
  ifstream ambil;
  ambil.open("data.txt");
  
}

void Admin::menu(){
  awal:
  ofstream tulis;
	tulis.open("data.txt", ios::app);
  system("clear");
  int pil;
  cout << "Anda login sebagai admin" << endl;
  cout << "-------------- MENU ADMIN -------------" << endl;
  cout << "1. Input data barang" << endl;
  cout << "2. Edit data barang" << endl;
  cout << "3. Lihat data barang" << endl;
  cout << "4. Kembali ke menu login" << endl;
  cout << "---------------------------------------" << endl;
  cout << "Anda memilih menu : "; cin >> pil;
  
  if (pil == 1){
    cout << "Masukkan jumlah barang yang ingin diinputkan : "; cin >> sz;
    Array1D<Stok> X(sz);
	  for (int i = 0; i < sz; ++i){
      cout << "Data barang ke-" <<  i + 1 << endl;
		  cout << "tgl   : "; cin >> tgl;
		  cout << "nama  : "; cin >> nama;
      cout << "harga : "; cin >> harga;
		  cout << "stok  : "; cin >> stok;
      cout << "---------------------------------------" << endl;
      tulis << tgl << ";" << nama << ";" << harga << ";" << stok << endl;
      
		  Stok stokN(tgl, nama, harga, stok);
		  X[i] = stokN;
    }
    cout << "Data berhasil disimpan..";
  }
  else if(pil == 3){

  }
  else if (pil == 4){
    goto akhir;
  }
  else{
    cout << "Pilihan yang anda masukkan tidak ada!";
    cout << "Tekan enter untuk memasukkan login kembali" << endl;
    cout << "---------------------------------------" << endl;

  }
  tulis.close();
  cin.ignore();
  getchar();
  goto awal;
  akhir:
  system("clear");
}