//214

#include <iostream>
#include <fstream>
#include <sstream>
#include "stack.h"
using namespace std;

//Class AdminS
class AdminS
{
  public:
    void ambildata();
    void tampil();
    void tampilsuplier();
    void daftarsuplier();
    void pesanbarang();
    void menusuplier();
    void pembelian();

    string nama;
    string tgl;
    int pil;
    int stok;
    int harga;
    int idx;
    int idx1;
    int uang;
    bool sudahpesan;
    bool sudahtransaksi;

};

//Deklarasi class AdminS
AdminS s;
AdminS dataSuplier[100];

//Struct suplier
struct suplier
{
  string nama;
  string barang;
  int harga;

};

//Deklarasi struct suplier
suplier sp[100];

//Fungsi untuk mengubah string ke int
int toInt4(string x)
{
	int y;

	stringstream ss;
	ss << x;
	ss >> y;

	return y;
  
}

//Prosedur untuk memisahkan data
void tokenize7(string s, string del = " ", int idx =0)
{
	string tmp;
	int i;
  int start;
  int end;

  i = 1;
  end = -1 * del.size();
  
  do
  {
    start = end + del.size();
    end = s.find(del, start);
    tmp = s.substr(start, end - start);
    
    if (i == 1)
    {
      dataSuplier[idx].tgl = tmp;
    }
      
    else if (i == 2)
    {
      dataSuplier[idx].nama = tmp;
    }
      
    else if (i == 3)
    {
      dataSuplier[idx].harga = toInt4(tmp);
    }
      
    else
    {
      dataSuplier[idx].stok = toInt4(tmp);
    }
    i++;
    
  }
  while (end != -1);
  
}

//Prosedur untuk memisahkan data
void tokenize8(string s, string del = " ", int idx =0)
{
	string tmp;
	int i;
  int start;
  int end;

  i = 1;
  end = -1 * del.size();
  
  do
  {
    start = end + del.size();
    end = s.find(del, start);
    tmp = s.substr(start, end - start);
    
    if (i == 1)
    {
      sp[idx].nama = tmp;
    }
      
    else if (i == 2)
    {
      sp[idx].barang = tmp;
    }
      
    else if (i == 3)
    {
      sp[idx].harga = toInt4(tmp);
    }
      
    i++;
    
  }
  while (end != -1);
  
}

//Method untuk menampilkan daftar barang
void AdminS::tampil()
{
  for (int i = 0; i < idx-1; i++)
  {
    cout << "Daftar barang ke-";
    cout << i + 1;
    cout << endl;
    cout << "Nama barang   : ";
    cout << dataSuplier[i].nama;
    cout << endl;
    cout << "Stok barang : ";
    cout << dataSuplier[i].stok;
    cout << endl;
    
    for (int n = 0; n < 39; n++)
    {
    	cout << "-";
    }
    cout << endl;
  }
  
}

//Method untuk mengambil data dari txt
void AdminS::ambildata()
{
  string t;
  idx = 0;
  ifstream ambil;
  
  ambil.open("data.txt");
  
	while(!ambil.eof())
  {
		ambil >> t;
		tokenize7(t, ";", idx);
		idx++;
	}

  ambil.close();
  
  idx1 = 0;
  ambil.open("data_suplier.txt");
  
  while(!ambil.eof())
  {
		ambil >> t;
		tokenize8(t, ";", idx1);
		idx1++;
  }

  ambil.close();
  
}

//Method untuk menampilkan daftar suplier
void AdminS::daftarsuplier()
{
  cout << endl;
  for (int n = 0; n < 39; n++)
  {
  	cout << "-";
  }
  cout << endl;
  cout << "Nama suplier : Mustika_Ratu";
  cout << endl;
  cout << "Daftar Barang : ";
  cout << endl;
  
  for (int n = 0; n < 39; n++)
  {
  	cout << "-";
  }
  cout << endl;
  
  for (int i = 0; i < idx1-1; i++)
  {
    if (sp[i].nama == "Mustika_Ratu")
    {
      cout << "Nama barang   : ";
      cout << sp[i].barang;
      cout << endl;
      cout << "Harga barang : ";
      cout << sp[i].harga;
      cout << endl;
      
      for (int n = 0; n < 39; n++)
      {
      	cout << "-";
      }
      cout << endl;
    }
    
  }

  cout << endl;
  for (int n = 0; n < 39; n++)
  {
    cout << "-";
  }
  
  cout << endl;
  cout << "Nama suplier : Wardah";
  cout << endl;
  cout << "Daftar Barang : ";
  cout << endl;
  
  for (int n = 0; n < 39; n++)
  {
    cout << "-";
  }
  cout << endl;

  for (int i = 0; i < idx1-1; i++)
  {
    if (sp[i].nama == "Wardah")
    {
      cout << "Nama barang   : ";
      cout << sp[i].barang;
      cout << endl;
      cout << "Harga barang : ";
      cout << sp[i].harga;
      cout << endl;
      
      for (int n = 0; n < 39; n++)
      {
        cout << "-";
      }
      cout << endl;
    }
    
  }

  cout << endl;
  for (int n = 0; n < 39; n++)
  {
    cout << "-";
  }
  
  cout << endl;
  cout << "Nama suplier : Lomira";
  cout << endl;
  cout << "Daftar Barang : ";
  cout << endl;
  
  for (int n = 0; n < 39; n++)
  {
    cout << "-";
  }
  cout << endl;

  for (int i = 0; i < idx1-1; i++)
  {
    if (sp[i].nama == "Lomira")
    {
      cout << "Nama barang   : ";
      cout << sp[i].barang;
      cout << endl;
      cout << "Harga barang : ";
      cout << sp[i].harga;
      cout << endl;
      
      for (int n = 0; n < 39; n++)
      {
        cout << "-";
      }
      cout << endl;
    }
    
  }

  cout << endl;
  for (int n = 0; n < 39; n++)
  {
    cout << "-";
  }
  
  cout << endl;
  cout << "Nama suplier : Miranda";
  cout << endl;
  cout << "Daftar Barang : ";
  cout << endl;
  
  for (int n = 0; n < 39; n++)
  {
    cout << "-";
  }
  cout << endl;

  for (int i = 0; i < idx1-1; i++)
  {
    if (sp[i].nama == "Miranda")
    {
      cout << "Nama barang   : ";
      cout << sp[i].barang;
      cout << endl;
      cout << "Harga barang : ";
      cout << sp[i].harga;
      cout << endl;
      
      for (int n = 0; n < 39; n++)
      {
        cout << "-";
      }
      cout << endl;
    }
    
  }

  cout << endl;
  for (int n = 0; n < 39; n++)
  {
    cout << "-";
  }
  
  cout << endl;
  cout << "Nama suplier : Ponds";
  cout << endl;
  cout << "Daftar Barang : ";
  cout << endl;
  
  for (int n = 0; n < 39; n++)
  {
	  cout << "-";
  }
  cout << endl;

  for (int i = 0; i < idx1-1; i++)
  {
    if (sp[i].nama == "Ponds")
    {
      cout << "Nama barang   : ";
      cout << sp[i].barang;
      cout << endl;
      cout << "Harga barang : ";
      cout << sp[i].harga;
      cout << endl;
      
      for (int n = 0; n < 39; n++)
      {
	      cout << "-";
      }
      cout << endl;
    }
    
  }

  cout << endl;
  for (int n = 0; n < 39; n++)
  {
	  cout << "-";
  }
  
  cout << endl;
  cout << "Nama suplier : Rexona";
  cout << endl;
  cout << "Daftar Barang : ";
  cout << endl;
  
  for (int n = 0; n < 39; n++)
  {
	  cout << "-";
  }
  cout << endl;

  for (int i = 0; i < idx1-1; i++)
  {
    if (sp[i].nama == "Rexona")
    {
      cout << "Nama barang   : ";
      cout << sp[i].barang;
      cout << endl;
      cout << "Harga barang : ";
      cout << sp[i].harga;
      cout << endl;
      
      for (int n = 0; n < 39; n++)
      {
	      cout << "-";
      }
      cout << endl;
    }
    
  }

  cout << endl;
  for (int n = 0; n < 39; n++)
  {
	  cout << "-";
  }
  
  cout << endl;
  cout << "Nama suplier : Kahf";
  cout << endl;
  cout << "Daftar Barang : ";
  cout << endl;
  
  for (int n = 0; n < 39; n++)
  {
	  cout << "-";
  }
  cout << endl;

  for (int i = 0; i < idx1-1; i++)
  {
    if (sp[i].nama == "Kahf")
    {
      cout << "Nama barang   : ";
      cout << sp[i].barang;
      cout << endl;
      cout << "Harga barang : ";
      cout << sp[i].harga;
      cout << endl;
      
      for (int n = 0; n < 39; n++)
      {
	      cout << "-";
      }
      cout << endl;
    }
    
  }

  cout << endl;
  for (int n = 0; n < 39; n++)
  {
	  cout << "-";
  }
  
  cout << endl;
  cout << "Nama suplier : Garnier";
  cout << endl;
  cout << "Daftar Barang : ";
  cout << endl;
  
  for (int n = 0; n < 39; n++)
  {
	  cout << "-";
  }
  cout << endl;

  for (int i = 0; i < idx1-1; i++)
  {
    if (sp[i].nama == "Garnier")
    {
      cout << "Nama barang   : ";
      cout << sp[i].barang;
      cout << endl;
      cout << "Harga barang : ";
      cout << sp[i].harga;
      cout << endl;
      
      for (int n = 0; n < 39; n++)
      {
      	cout << "-";
      }
      cout << endl;
    }
    
  }
}

//Method untuk proses pembelian barang
void AdminS::pembelian(){
  for (int i = 0; i < idx; i++)
  {
    for (int j = 0; j < stk.maksimal; j++)
    {
        if (dataSuplier[i].nama == ds[j].nama)  
        {
          dataSuplier[i].stok += ds[j].jumlah;
        }
    }
  }

  ofstream tambah;
  tambah.open("data.txt");

  for (int i = 0; i < idx - 1; i++)
  {
    tambah << dataSuplier[i].tgl;
    tambah << ";";
    tambah << dataSuplier[i].nama;
    tambah << ";";
    tambah << dataSuplier[i].harga;
    tambah << ";";
    tambah << dataSuplier[i].stok;
    tambah << endl;
    
  }

  tambah.close();
}

//Method untuk menu pemesanan barang
void AdminS::pesanbarang(){
  bool ketemu;
  string temp;
  int pesan;

  awal:
  ketemu = false;
  system("clear");
  daftarsuplier();

  cout << endl;
  for (int n = 0; n < 13; n++)
  {
  	cout << "-";
  }
  
  cout << " ";
  cout << "MENU PESANAN";
  cout << " ";
  
  for (int n = 0; n < 12; n++)
  {
	  cout << "-";
  }
  
  cout << endl;
  cout << "1. Tambah Barang ke tumpukan pesanan";
  cout << endl;
  cout << "2. Hapus barang dari tumpukan peesanan";
  cout << endl;
  cout << "3. Lihat tumpukan pesanan";
  cout << endl;
  cout << "4. Selesaikan pesanan";
  cout << endl;
  cout << "5. Kembali ke menu suplier";
  cout << endl;
  
  for (int n = 0; n < 39; n++)
  {
	  cout << "-";
  }
  
  cout << endl;
  cout << "Anda memilih menu : ";
  cin >> pil;
  
  for (int n = 0; n < 39; n++)
  {
	  cout << "-";
  }
  cout << endl;

  if (pil == 1)
  {
    cout << "Masukkan nama barang : "; 
    cin >> temp;

    for (int i = 0; i < idx1-1; i++){
      if (temp == sp[i].barang){
        cout << "Barang ditemukan!";
        cout << endl;
        
        for (int n = 0; n < 39; n++)
        {
        	cout << "-";
        }
        
        cout << endl;
        cout << "Nama suplier   : ";
        cout << sp[i].nama;
        cout << endl;
        cout << "Nama barang   : ";
        cout << sp[i].barang;
        cout << endl;
        cout << "Harga barang : ";
        cout << sp[i].harga;
        cout << endl;
        
        for (int n = 0; n < 39; n++)
        {
        	cout << "-";
        }
        
        cout << endl;
        cout << "Masukkan jumlah barang yang ingin anda pesan : ";
        cin >> pesan;
        
        stk.pushStack(sp[i].barang, sp[i].harga, pesan);
        ketemu = true;
        sudahpesan = true;
        
      }
    }

    if (ketemu == false)
    {
      cout << "Barang yang anda cari tidak ada!";
      cout << endl;
      
    }
  }
    
  else if (pil == 2)
  {
    stk.popArray();
    
  }
    
  else if (pil == 3)
  {
    stk.display();
    
  }

  else if (pil == 4)
  {
    
    if (sudahpesan == false)
    {
      cout << "Anda belum memesan apapun!";
      cout << endl;
      
    }

    else
    {
      char yn;
      stk.display();

      cout << endl;
      cout << "Apakah anda sudah yakin dengan pesanan ini? (y/n) : ";
      cin >> yn;
      
      uang:
      if (yn == 'y' || yn == 'Y')
      {
        cout << "Masukkan jumlah uang anda : ";
        cin >> uang;
        
        if(uang < stk.totalsemua)
        {
          cout << "Uang anda tidak cukup!!";
          cout << endl;
          
          for (int n = 0; n < 39; n++)
          {
          	cout << "-";
          }
          cout << endl;
          goto uang;
        }
          
        else
        {
          pembelian();
          cout << "Pesanan berhasil diproses..";
          cout << endl;
          sudahtransaksi = true;
          goto akhir;
          
        }
      }
    
    }
  } 
    
  else if (pil == 5){
    goto akhir;
  }
  
  cin.ignore();
  getchar();
  goto awal;

  akhir:
  int g;
}

//Method untuk tampilan utama menu suplier
void AdminS::menusuplier()
{
  sudahtransaksi = false;
  sudahpesan = false;
  ambildata();
  awal:
  system("clear");

  for (int n = 0; n < 13; n++)
  {
	  cout << "-";
  }
  
  cout << " ";
  cout << "MENU SUPLIER";
  cout << " ";
  
  for (int n = 0; n < 12; n++)
  {
  	cout << "-";
  }
  cout << endl;
  cout << "1. Daftar suplier";
  cout << endl;
  cout << "2. Daftar barang";
  cout << endl;
  cout << "3. Pesan barang";
  cout << endl;
  cout << "4. Kembali ke menu admin";
  cout << endl;
  
  for (int n = 0; n < 39; n++)
  {
	  cout << "-";
  }
  cout << endl;
  cout << "Anda memilih menu : "; cin >> pil;
  
  for (int n = 0; n < 39; n++)
  {
	  cout << "-";
  }
  cout << endl;

  if (pil == 1)
  {
    daftarsuplier();
  }
    
  else if (pil == 2){
    tampil();
  }
    
  else if (pil == 3){
    if(sudahtransaksi == false)
    {
      pesanbarang();
    }
    else
    {
      cout << "Anda tidak bisa melakukan transaksi lagi";
      cout << endl;
    }
  }
    
  else if (pil == 4)
  {
    goto akhir;
  }
    
  else
  {
    cout << "Pilihan yang anda masukkan tidak ada!";
    cout << endl;
    cout << "Tekan enter untuk memilih menu kembali";
    cout << endl;
    
    for (int n = 0; n < 39; n++)
    {
    	cout << "-";
    }
    cout << endl;
  }
  
  cin.ignore();
  getchar();
  goto awal;
  
  akhir:
  int g;
  
}