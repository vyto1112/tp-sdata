#include <iostream>
#include <fstream>
#include "linklist.h"
using namespace std;

class User{
  public:
    void menu();
    void tampil();
    void ambildata();
    void transaksi();
    void proses();
    int sz;
    string tgl, nama;
    int harga, stok, idx, beli, jumlah[100], total[100];
    char yn;
}us, dataUser[100];

int toInt1(string x){
	int y;

	stringstream ss;
	ss << x;
	ss >> y;

	return y;
}

void tokenize2(string s, string del = " ", int idx =0){
	string tmp;
	int i = 1;
    int start, end = -1*del.size();
    do {
        start = end + del.size();
        end = s.find(del, start);
        tmp = s.substr(start, end - start);

        if (i == 1)
        {
        	dataUser[idx].tgl = tmp;
        }
        else if (i == 2){
        	dataUser[idx].nama = tmp;
        }
        else if (i == 3){
        	dataUser[idx].harga = toInt1(tmp);
        }
        else{
        	dataUser[idx].stok = toInt1(tmp);
        }
        i++;

    } while (end != -1);
}

void User::ambildata(){
  string t;
  idx = 0;
  ifstream ambil;
  ambil.open("data.txt");
	while(!ambil.eof()){
		ambil >> t;
		tokenize2(t, ";", idx);
		idx++;
	}
	ambil.close();
}

void User::tampil(){
  for (int i = 0; i < idx - 1; i++){
    cout << "Data barang ke-" <<  i + 1 << endl;
		cout << "nama  : " << dataUser[i].nama << endl;
    cout << "harga : " << dataUser[i].harga << endl;
		cout << "stok  : " << dataUser[i].stok << endl;
    cout << "---------------------------------------" << endl;
  }
}

void User::menu(){
  awal:
  ambildata();
  system("clear");
  int pil;
  cout << "-------------- MENU USER --------------" << endl;
  cout << "1. Lihat daftar barang" << endl;
  cout << "2. Beli barang" << endl;
  cout << "3. Kembali ke menu login" << endl;
  cout << "---------------------------------------" << endl;
  cout << "Anda memilih menu : "; cin >> pil;
  cout << "---------------------------------------" << endl;
  
  if (pil == 1){
    tampil();
  }
  else if(pil == 2){
    tampil();
    while (true){
      cout << "Masukkan no barang yang anda beli     : "; cin >> beli;
      beli -= 1;
      cout << "Masukkan jumlah barang yang anda beli : "; cin >> jumlah[beli];
      cout << "Apakah anda ingin membeli lagi? (y/n) : "; cin >> yn;
      if (yn == 'n' || yn == 'N'){
        break;
      }
      cout << "---------------------------------------" << endl;
    }
  }
  else if(pil == 3){
    goto akhir;
  }
  else{
    cout << "Pilihan yang anda masukkan tidak ada!" << endl;
    cout << "Tekan enter untuk memasukkan login kembali" << endl;
    cout << "---------------------------------------" << endl;
  }
  cin.ignore();
  getchar();
  goto awal;
  akhir:
  system("clear");
}

void User::proses(){
  
}