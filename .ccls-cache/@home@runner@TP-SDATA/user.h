#include <iostream>
#include <fstream>
#include "datalist.h"
#include "linklist.h"
using namespace std;

//Class User
class User{
  public:
    void menu();
    void tampil();
    void list();
    void pembelian();
    void ambildata();
    void transaksi();
    void ubahstok();
    void proses();
    void invoice();
    int sz, szb;
    string tgl, tglb, nama;
    int harga, stok, idx, beli[100], jumlah[100], total[100], sudahpilih[100], totalsemua, uang, kembali;
    char yn;
    bool sudahlewat, sudahbelanja, sudahtransaksi;
}us, dataUser[100];

struct KTP2{
  string NIK, nama, alamat;
}dataKTP2[100];

//Fungsi untuk konversi tipe data string ke tipe data integer
int toInt1(string x){
	int y;

	stringstream ss;
	ss << x;
	ss >> y;

	return y;
}

//Prosedur untuk memisahkan data dari data.txt
void tokenize2(string s, string del = " ", int idx =0){
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
        dataUser[idx].tgl = tmp;
      }
      else if (i == 2)
      {
        dataUser[idx].nama = tmp;
      }
      else if (i == 3)
      {
        dataUser[idx].harga = toInt1(tmp);
      }
        else
      {
        dataUser[idx].stok = toInt1(tmp);
      }
      i++;
    }while (end != -1);
}

//Prosedur untuk memisahkan data dari datalogin.txt
void tokenize3(string s, string del = " ", int idx =0)
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
        	dataKTP2[idx].NIK = tmp;
        }
        else if (i == 2){
        	dataKTP2[idx].nama = tmp;
        }
        else if (i == 3){
          dataKTP2[idx].alamat = tmp;
        }
        i++;

    } while (end != -1);
}

//Method untuk mengambil data dari file eksternal "data.txt" dan "datalogin.txt"
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

  idx = 0;
  ambil.open("datalogin.txt");
  while(!ambil.eof()){
		ambil >> t;
		tokenize3(t, ";", idx);
		idx++;
  }
  
  ambil.close();
}

//Method untuk menampilkan daftar data yang disimpan
void User::tampil(){
  for (int i = 0; i < szb; i++)
  {
    cout << "Daftar barang ke-" << i + 1 << endl;
    cout << "Nama barang   : " << dataUser[beli[i]].nama << endl;
    cout << "Harga barang  : " << dataUser[beli[i]].harga << endl;
    cout << "Jumlah barang : " << jumlah[beli[i]] << endl;
    cout << "Total harga   : " << total[beli[i]] << endl;
    cout << "---------------------------------------" << endl;
  }
}

//Method untuk menggunakan link list
void User::list(){
  List<Datalist> x;
  
  cout << "Anda berhasil menambahkan : " << endl;
  for(int i = 0; i < szb; i++){
		Datalist t(dataUser[beli[i]].nama, jumlah[beli[i]]);
    x.sisipBelakang(t);
  }
  
  cout << x;
}

//Method untuk mengubah jumlah stok setelah terjadi pembelian
void User::ubahstok(){
  ofstream tulis1;
  tulis1.open("data.txt");
  
  for (int i = 0; i < idx - 1; i++){
    tulis1 << dataUser[i].tgl << ";" << dataUser[i].nama << ";" << dataUser[i].harga << ";" << dataUser[i].stok << endl;
  }
  
  tulis1.close();
}

//Method untuk menu pembelian
void User::pembelian(){
  sudahbelanja = true;
  
  for (int i = 0; i < idx - 1; i++){
  cout << "Data barang ke-" <<  i + 1 << endl;
	cout << "nama  : " << dataUser[i].nama << endl;
  cout << "harga : " << dataUser[i].harga << endl;
	cout << "stok  : " << dataUser[i].stok << endl;
  cout << "---------------------------------------" << endl;
  }
  
  while (true)
  {
    start:
    cout << "Masukkan no barang yang anda beli     : "; cin >> beli[szb];
    beli[szb] -= 1;
    
    if (beli[szb] >= idx - 1)
    {
      cout << "No barang yang anda masukkan tidak ada!" << endl;
      cout << "---------------------------------------" << endl;
      goto start;
    }
    if (sudahlewat = true)
    {
      for (int j = 0; j < szb; j++)
      {
        if (sudahpilih[j] == beli[szb])
        {
          cout << "Tidak dapat memilih barang yang sama!" << endl;
          cout << "---------------------------------------" << endl;
          cout << "Apakah anda ingin membeli lagi? (y/n) : "; cin >> yn;
          cout << "---------------------------------------" << endl;
          goto end;
        }
      } 
    }
    sudahlewat = true;
    sudahpilih[szb] = beli[szb];
    
    cout << "Masukkan jumlah barang yang anda beli : "; cin >> jumlah[beli[szb]];
    cout << "Apakah anda ingin membeli lagi? (y/n) : "; cin >> yn;
    cout << "---------------------------------------" << endl;
    
    proses();
    ubahstok();
    szb++;
  
    end:
    if (yn == 'n' || yn == 'N')
    {
      cout << "Daftar belanjaan anda : " << endl;
      cout << "---------------------------------------" << endl;
      list();
      break;
    }
  }
}

//Method untuk menu transaksi
void User::transaksi(){
  char pil;
  
  cout << endl << "------------ MENU TRANSAKSI -----------" << endl;
  cout << "Daftar barang belanjaan anda : " << endl;
  cout << "---------------------------------------" << endl;
  
  tampil();
  
  cout << "Total belanjaan : " << totalsemua << endl;
  cout << "Apakah anda sudah yakin dengan belanjaan anda (y/n) : "; cin >> pil;
  
  uang:
  if (pil == 'y' || pil == 'Y'){
    cout << "Masukkan jumlah uang anda : "; cin >> uang;
    if(uang < totalsemua)
    {
      cout << "Uang anda tidak cukup!!" << endl;
      cout << "---------------------------------------" << endl;
      goto uang;
    }
    else
    {
      cout << "Masukkan tanggal transaksi : "; cin >> tglb;
      cout << "---------------------------------------" << endl;
      cout << "Invoice berhasil dicetak.." << endl;
      cout << "Terima kasih sudah berbelanja :)" << endl;
      
      invoice();
      sudahtransaksi = true;
      cin.ignore();
      getchar();
    }
  }
}

//Method untuk mencetak invoice dalam bentuk "invoice.txt"
void User::invoice(){
  kembali = uang - totalsemua;
  ofstream struk;
  struk.open("invoice.txt");
  
  struk << "================== STRUK BELANJA ==================" << endl;
  
  for (int i = 0; i < szb; i++)
  {
    struk << dataUser[beli[i]].nama << "   " << " = Rp." <<  dataUser[beli[i]].harga << " x " << jumlah[beli[i]] << " = " << total[beli[i]] << endl;
  }
  
  struk << "---------------------------------------------------" << endl;
  struk << "Total belanjaan : Rp." << totalsemua << endl;
  struk << "Uang dibayarkan : Rp." << uang << endl;
  struk << "---------------------------------------------------" << endl;
  struk << "Kembalian       : Rp." << kembali << endl;
  struk << "===================================================" << endl;
  
  struk.close();
  
  ofstream catat;
  catat.open("data_transaksi.txt", ios::app);
  
  catat << "Transaksi pada tanggal " << tglb << endl;
  catat << "---------------------------------------------------" << endl;
  
  for (int i = 0; i < szb; i++){
    catat << dataUser[beli[i]].nama << "   " << " = Rp." <<  dataUser[beli[i]].harga << " x " << jumlah[beli[i]] << " = " << total[beli[i]] << endl;
  }
  
  catat << "---------------------------------------------------" << endl;
  catat << "Total belanjaan : Rp." << totalsemua << endl;
  catat << endl;
  
  catat.close();
}

//Method untuk menu utama sebagai user
void User::menu(){
  sudahlewat = false;
  sudahbelanja = false;
  sudahtransaksi = false;
  totalsemua = 0;
  szb = 0;
  awal:
  ambildata();
  system("clear");
  int pil;
  
  cout << "-------------- MENU USER --------------" << endl;
  cout << "1. Beli barang" << endl;
  cout << "2. Lihat belanjaan" << endl;
  cout << "3. Transaksi" << endl;
  cout << "4. Kembali ke menu login" << endl;
  cout << "---------------------------------------" << endl;
  cout << "Anda memilih menu : "; cin >> pil;
  cout << "---------------------------------------" << endl;
  
  if(pil == 1)
  {
    pembelian();
  }
  else if(pil == 2)
  {
    if (sudahbelanja == true)
    {
      tampil();
    }
    else
    {
      cout << "Anda belum belanja apapun!" << endl;
    }
  }
  else if(pil == 3)
  {
    if (sudahbelanja == true)
    {
      transaksi();
      if (sudahtransaksi == true)
      {
        goto akhir;
      }
    }
    else
    {
      cout << "Anda belum belanja apapun!" << endl;
    }
  }
  else if(pil == 4)
  {
    goto akhir;
  }
  else
  {
    cout << dataKTP2[0].NIK << " " << cout << dataKTP2[0].nama << " " << cout << dataKTP2[0].alamat << endl;
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
  total[beli[szb]] = jumlah[beli[szb]] * dataUser[beli[szb]].harga;
  dataUser[beli[szb]].stok -= jumlah[beli[szb]];
  totalsemua += total[beli[szb]];
}