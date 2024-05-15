#include <iostream>
#include <fstream>
#include "stok.h"
#include "arrayd.h"
#include <sstream>
using namespace std;

//Class Admin
class Admin{
  public:
    void menu();
    void ambildata();
    void inputbarang();
    void menuedit();
    void tulisdata();
    int sz;
    string tgl, nama;
    int harga, stok, noedit, idx;
}ad, dataAdmin[100];

//Fungsi untuk konversi tipe data string ke tipe data integer
int toInt(string x){
	int y;

	stringstream ss;
	ss << x;
	ss >> y;

	return y;
}

//Deklarasi array dinamis
Array1D<Stok> Y(100);

//Prosedur untuk memisahkan data
void tokenize1(string s, string del = " ", int idx =0){
	string tmp;
	int i = 1;
  int start, end = -1*del.size();
  
  do{
    start = end + del.size();
    end = s.find(del, start);
    tmp = s.substr(start, end - start);
    
    if (i == 1)
    {
      dataAdmin[idx].tgl = tmp;
    }
    else if (i == 2)
    {
      dataAdmin[idx].nama = tmp;
    }
    else if (i == 3)
    {
      dataAdmin[idx].harga = toInt(tmp);
    }
    else
    {
      dataAdmin[idx].stok = toInt(tmp);
    }
    i++;
  }while (end != -1);
}

//Method untuk menginputkan data barang
void Admin::inputbarang(){
  ofstream tulis;
	tulis.open("data.txt", ios::app);
  
  cout << "Masukkan jumlah barang yang ingin diinputkan : "; cin >> sz;
	  for (int i = 0; i < sz; ++i)
    {
      cout << "Data barang ke-" <<  i + 1 << endl;
		  cout << "tgl   : "; cin >> tgl;
		  cout << "nama  : "; cin >> nama;
      cout << "harga : "; cin >> harga;
		  cout << "stok  : "; cin >> stok;
      cout << "---------------------------------------" << endl;
      tulis << tgl << ";" << nama << ";" << harga << ";" << stok << endl;
    }
  cout << "Data berhasil disimpan..";
  
  tulis.close();
}

//Method untuk data dari file eksternal "data.txt"
void Admin::ambildata(){
  idx = 0;
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

  for (int i = 0; i < idx; i++)
  {
    tgl = dataAdmin[i].tgl;
    nama = dataAdmin[i].nama;
    harga = dataAdmin[i].harga;
    stok = dataAdmin[i].stok;
    
    Stok stokN(tgl, nama, harga, stok);
		X[i] = stokN;
    }
  
  Y = X;
}

//Method untuk menu edit
void Admin::menuedit(){
  editawal:
  ambildata();
  int pil;
  char yn;
  
  cout << endl << "-------------- MENU EDIT --------------" << endl;
  cout << "1. Edit data" << endl;
  cout << "2. Hapus semua data" << endl;
  cout << "---------------------------------------" << endl;
  cout << "Anda memilih menu : "; cin >> pil;
  cout << "---------------------------------------" << endl;
  
  if (pil == 2)
  {
    cout << "Apakah anda yakin (y/n)? : "; cin >> yn;
    if (yn == 'y' || yn == 'Y')
    {
      ofstream hapus;
      hapus.open("data.txt");
      hapus << "";
      hapus.close();
      cout << "---------------------------------------" << endl;
      cout << "Data berhasil dihapus" << endl;
    }
    else
    {
      cout << "---------------------------------------" << endl;
      cout << "Operasi dibatalkan" << endl;
    }
  }
  else if (pil == 1)
  {
    cout << Y;
    cout << "Masukkan no barang yang ingin anda edit : "; cin >> noedit;
    noedit -= 1;
    cout << "---------------------------------------" << endl;
    cout << endl << "------------- Opsi edit ---------------" << endl;
    cout << "1. Edit tanggal" << endl;
    cout << "2. Edit nama" << endl;
    cout << "3. Edit harga" << endl;
    cout << "4. Edit stok" << endl;
    cout << "5. Hapus data" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Anda memilih opsi : "; cin >> pil;
    cout << "---------------------------------------" << endl;
    switch(pil)
    {
      case 1:
        cout << "Masukkan data tanggal yg baru : "; cin >> tgl;
        dataAdmin[noedit].tgl = tgl;
        tulisdata();
        break;
      
      case 2:
        cout << "Masukkan data nama yg baru : "; cin >> nama;
        dataAdmin[noedit].nama = nama;
        tulisdata();
        break;
      
      case 3:
        cout << "Masukkan data harga yg baru : "; cin >> harga;
        dataAdmin[noedit].harga = harga;
        tulisdata();
        break;
      
      case 4:
        cout << "Masukkan data stok yg baru : "; cin >> stok;
        dataAdmin[noedit].stok = stok;
        tulisdata();
        break;
      
      case 5: 
        cout << "Apakah anda yakin (y/n)? : "; cin >> yn;
        if (yn == 'y' || yn == 'Y')
        {
          ofstream hapus;
          ofstream tulis;
          tulis.open("data.txt");
          for (int i = 0; i < idx - 1; i++)
          {
            if (i != noedit)
            {
              tulis << dataAdmin[i].tgl << ";" << dataAdmin[i].nama << ";" << dataAdmin[i].harga << ";" << dataAdmin[i].stok << endl;
            }
          }
          tulis.close();
          cout << "---------------------------------------" << endl;
          cout << "Data berhasil dihapus" << endl;
          break;
        }
        else
        {
          cout << "---------------------------------------" << endl;
          cout << "Operasi dibatalkan" << endl;
          break;
        }
    }
  }
  else
  {
    cout << "Pilihan yang anda masukkan tidak ada!" << endl;
    cout << "Tekan enter untuk memilih menu kembali" << endl;
    cout << "---------------------------------------" << endl;
  } 
}

//Method untuk menulis ulang data yang telah diedit
void Admin::tulisdata()
{
  ofstream tulis;
  tulis.open("data.txt");
  
  for (int i = 0; i < idx - 1; i++)
  {
    tulis << dataAdmin[i].tgl << ";" << dataAdmin[i].nama << ";" << dataAdmin[i].harga << ";" << dataAdmin[i].stok << endl;
  }
  
  tulis.close();
}

//Method untuk tampilan menu utama sebagai admin
void Admin::menu(){
  awal:
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
  
  if (pil == 1)
  {
    inputbarang();
  }
  else if(pil == 2)
  {
    menuedit();
  }
  else if(pil == 3)
  {
    ambildata();
    cout << Y;
  }
  else if (pil == 4)
  {
    goto akhir;
  }
  else
  {
    cout << "Pilihan yang anda masukkan tidak ada!" << endl;
    cout << "Tekan enter untuk memilih menu kembali" << endl;
    cout << "---------------------------------------" << endl;
  }
  
  cin.ignore();
  getchar();
  goto awal;
  
  akhir:
  system("clear");
}