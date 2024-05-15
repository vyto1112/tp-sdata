#include <iostream>
#include <fstream>
#include "stok.h"
#include "arrayd.h"
#include <sstream>
using namespace std;

class Admin{
  public:
    void menu();
    void ambildata();
    int sz;
    string tgl, nama;
    int harga, stok;
}ad, dataAdmin[100];

int toInt(string x){
	int y;

	stringstream ss;
	ss << x;
	ss >> y;

	return y;
}

Array1D<Stok> Y(100);

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
        	dataAdmin[idx].tgl = tmp;
        }
        else if (i == 2){
        	dataAdmin[idx].nama = tmp;
        }
        else if (i == 3){
        	dataAdmin[idx].harga = toInt(tmp);
        }
        else{
        	dataAdmin[idx].stok = toInt(tmp);
        }
        i++;

    } while (end != -1);
}

void Admin::ambildata(){
  int idx = 0;
  string t;
  ifstream ambil;
  ambil.open("data.txt");
	while(!ambil.eof()){
		ambil >> t;
		tokenize1(t, ";", idx);
		idx++;
	}
	ambil.close();
  Array1D<Stok> X(idx);

  for (int i = 0; i < idx; i++){
    tgl = dataAdmin[i].tgl;
    nama = dataAdmin[i].nama;
    harga = dataAdmin[i].harga;
    stok = dataAdmin[i].stok;
    
    Stok stokN(tgl, nama, harga, stok);
		X[i] = stokN;
  }

  Y = X;
}

void Admin::menu(){
  awal:
  ofstream tulis;
	tulis.open("data.txt", ios::app);
  system("clear");
  int pil;
  cout << "-------------- MENU ADMIN -------------" << endl;
  cout << "1. Input data barang" << endl;
  cout << "2. Edit data barang" << endl;
  cout << "3. Lihat data barang" << endl;
  cout << "4. Kembali ke menu login" << endl;
  cout << "---------------------------------------" << endl;
  cout << "Anda memilih menu : "; cin >> pil;
  cout << "---------------------------------------" << endl;
  
  if (pil == 1){
    cout << "Masukkan jumlah barang yang ingin diinputkan : "; cin >> sz;
	  for (int i = 0; i < sz; ++i){
      cout << "Data barang ke-" <<  i + 1 << endl;
		  cout << "tgl   : "; cin >> tgl;
		  cout << "nama  : "; cin >> nama;
      cout << "harga : "; cin >> harga;
		  cout << "stok  : "; cin >> stok;
      cout << "---------------------------------------" << endl;
      tulis << tgl << ";" << nama << ";" << harga << ";" << stok << endl;
    }
    cout << "Data berhasil disimpan..";
  }
  else if(pil == 3){
    ambildata();
    cout << Y;
  }
  else if (pil == 4){
    goto akhir;
  }
  else{
    cout << "Pilihan yang anda masukkan tidak ada!" << endl;
    cout << "Tekan enter untuk memilih menu kembali" << endl;
    cout << "---------------------------------------" << endl;
  }
  tulis.close();
  cin.ignore();
  getchar();
  goto awal;
  akhir:
  system("clear");
}