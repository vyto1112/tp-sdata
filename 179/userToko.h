//179

#include <iostream>
#include <fstream>
#include <sstream>
#include "../header/userToko+.h"
using namespace std;

//Class User Toko
class UserT
{
  public:
    void menutoko();
    void tampil();
    void list();
    void pembelian();
    void ambildata();
    void transaksi();
    void pemasukan();
    void ubahstok();
    void proses();
    void invoice();

    int sz;
    int szb;
    int harga;
    int stok;
    int idx;
    int idx1;
    int beli[100];
    int jumlah[100];
    int total[100];
    int sudahpilih[100];
    int totalsemua;
    int uang;
    int kembali;
    char yn;
    string tgl;
    string tglb;
    string nama;
    bool sudahlewat;
    bool sudahbelanja;
    bool sudahtransaksi;
    bool prioritas;

};

//Deklarasi class UserT
UserT ut;
UserT dataUsert[100];

//Class data link list
class Datalist
{
	public :
		Datalist(string n="", int j=0)
    {
			nama = n;
			jumlah = j;
		}

		string nama;
    int jumlah;

};

//Struct data KTP2
struct KTP2
{
  string NIK;
  string nama;
  string alamat;
  string ttl;

};

//Deklarasi struct KTP2
KTP2 dataKTP2;

//Class dataAntriUT
class dataAntriUT
{
  public:
    string nama;
    string NIK;

};

//Deklarasi class dataAntriUT
dataAntriUT qUT[100];

//Fungsi untuk konversi tipe data string ke tipe data integer
int toInt1(string x)
{
	int y;

	stringstream ss;
	ss << x;
	ss >> y;

	return y;
  
}

//Prosedur untuk memisahkan data dari data.txt
void tokenize41(string s, string del = " ", int idx =0)
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
      qUT[idx].nama = tmp;
    }
      
    else if (i == 2)
    {
      qUT[idx].NIK = tmp;
    }
    
    i++;
    
    }
    while (end != -1);
  
  }

//Prosedur untuk memisahkan data dari data.txt
void tokenize2(string s, string del = " ", int idx =0)
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
      dataUsert[idx].tgl = tmp;
    }
      
    else if (i == 2)
    {
      dataUsert[idx].nama = tmp;
    }
      
    else if (i == 3)
    {
      dataUsert[idx].harga = toInt1(tmp);
    }
      
    else
    {
      dataUsert[idx].stok = toInt1(tmp);
    }
    i++;
    
    }
    while (end != -1);
  
}

//Prosedur untuk memisahkan data dari datalogin.txt
void tokenize3(string s, string del = " ")
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
      dataKTP2.NIK = tmp;
    }
      
    else if (i == 2)
    {
      dataKTP2.nama = tmp;
    }
      
    else if (i == 3)
    {
      dataKTP2.alamat = tmp;
    }
      
    else if (i == 4)
    {
      dataKTP2.ttl = tmp;
    }
    i++;

    }
    while (end != -1);
  
}

//Method untuk mengambil data dari file eksternal "data.txt" dan "datalogin.txt"
void UserT::ambildata()
{
  string t;
  idx = 0;
  idx1 = 0;
  ifstream ambil;
  
  ambil.open("data.txt");
  
	while(!ambil.eof())
  {
		ambil >> t;
		tokenize2(t, ";", idx);
		idx++;
	}
  
	ambil.close();
  ambil.open("datalogin.txt");
  
  while(!ambil.eof())
  {
		ambil >> t;
		tokenize3(t, ";");
  }
  
  ambil.close();
  ambil.open("antrian_toko.txt");
  
  while(!ambil.eof())
  {
		ambil >> t;
		tokenize41(t, ";", idx1);
    idx1++;
  }
  
  ambil.close();
  
}

//Method untuk menampilkan daftar data yang disimpan
void UserT::tampil()
{
  for (int i = 0; i < szb; i++)
  {
    cout << "Daftar barang ke-";
    cout << i + 1;
    cout << endl;
    cout << "Nama barang   : ";
    cout << dataUsert[beli[i]].nama;
    cout << endl;
    cout << "Harga barang  : ";  
    cout << dataUsert[beli[i]].harga;
    cout << endl;
    cout << "Jumlah barang : ";
    cout << jumlah[beli[i]];
    cout << endl;
    cout << "Total harga   : ";
    cout << total[beli[i]];
    cout << endl;
    
    for (int n = 0; n < 39; n++)
    {
    	cout << "-";
    }
    cout << endl;
  }
  
}

//Method untuk menggunakan link list
void UserT::list()
{
  List<Datalist> x;
  
  cout << "Anda berhasil menambahkan : ";
  cout << endl;
  
  for(int i = 0; i < szb; i++)
  {
		Datalist t(dataUsert[beli[i]].nama, jumlah[beli[i]]);
    x.sisipBelakang(t);
  }
  
  cout << x;
  
}

//Method untuk mengubah jumlah stok setelah terjadi pembelian
void UserT::ubahstok()
{
  ofstream tulis;
  tulis.open("data.txt");
  
  for (int i = 0; i < idx - 1; i++)
  {
    tulis << dataUsert[i].tgl;
    tulis << ";";
    tulis << dataUsert[i].nama;
    tulis << ";";
    tulis << dataUsert[i].harga;
    tulis << ";";
    tulis << dataUsert[i].stok;
    tulis << endl;
  }
  
  tulis.close();
  
}

//Method untuk menu pembelian
void UserT::pembelian()
{
  sudahbelanja = true;
  
  for (int i = 0; i < idx - 1; i++)
  {
    cout << "Data barang ke-";
    cout <<  i + 1;
    cout << endl;
  	cout << "nama  : ";
    cout << dataUsert[i].nama;
    cout << endl;
    cout << "harga : ";
    cout << dataUsert[i].harga;
    cout << endl;
  	cout << "stok  : ";
    cout << dataUsert[i].stok;
    cout << endl;
    
    for (int n = 0; n < 39; n++)
    {
    	cout << "-";
    }
    cout << endl;
  }
  
  while (true)
  {
    start:
    cout << "Masukkan no barang yang anda beli     : ";
    cin >> beli[szb];
    beli[szb] -= 1;
    
    if (beli[szb] >= idx - 1)
    {
      cout << "No barang yang anda masukkan tidak ada!";
      cout << endl;
      
      for (int n = 0; n < 39; n++)
      {
      	cout << "-";
      }
      
      cout << endl;
      goto start;
    }
    
    if (sudahlewat == true)
    {
      
      for (int j = 0; j < szb; j++)
      {
        
        if (sudahpilih[j] == beli[szb])
        {
          cout << "Tidak dapat memilih barang yang sama!";
          cout << endl;
          
          for (int n = 0; n < 39; n++)
          {
          	cout << "-";
          }

          cout << endl;
          cout << "Apakah anda ingin membeli lagi? (y/n) : ";
          cin >> yn;
          
          for (int n = 0; n < 39; n++)
          {
          	cout << "-";
          }
          
          cout << endl;
          goto end;
        }
        
      } 
      
    }
    
    sudahlewat = true;
    sudahpilih[szb] = beli[szb];

    ulang:
    cout << "Masukkan jumlah barang yang anda beli : ";
    cin >> jumlah[beli[szb]];
    
    if (jumlah[beli[szb]] > dataUsert[beli[szb]].stok)
    {
      cout << "Tidak dapat membeli melebihi jumlah stok!";
      cout << endl;
      goto ulang;
    }
    
    cout << "Apakah anda ingin membeli lagi? (y/n) : ";
    cin >> yn;
    
    for (int n = 0; n < 39; n++)
    {
    	cout << "-";
    }
    cout << endl;
    
    proses();
    ubahstok();
    szb++;
  
    end:
    
    if (yn == 'n' || yn == 'N')
    {
      cout << "Daftar belanjaan anda : ";
      cout << endl;
      
      for (int n = 0; n < 39; n++)
      {
      	cout << "-";
      }
      
      cout << endl;
      list();
      break;
    }
    
  }
  
}

//Method untuk menu transaksi
void UserT::transaksi()
{
  system("clear");
  char pil;
  char pil1;
  prioritas = false;

  pil = '0';
  pil1 = '0';
  
  cout << endl;
  for (int n = 0; n < 12; n++)
  {
  	cout << "-";
  }
  
  cout << " ";
  cout << "MENU TRANSAKSI";
  cout << " ";
  
  for (int n = 0; n < 11; n++)
  {
  	cout << "-";
  }
  
  cout << endl;
  cout << "Daftar barang belanjaan anda : ";
  cout << endl;
  
  for (int n = 0; n < 39; n++)
  {
  	cout << "-";
  }
  cout << endl;
  
  tampil();
  
  cout << "Total belanjaan : ";
  cout << totalsemua;
  cout << endl;
  cout << "Apakah anda sudah yakin dengan belanjaan anda (y/n) : ";
  cin >> pil;

  if(pil != 'n')
  {
    cout << "Apakah anda ingin menggunakan antrian prioritas? (y/n) : ";
    cin >> pil1;
  }

  for (int n = 0; n < 39; n++)
  {
  	cout << "-";
  }

  cout << endl;
  if (pil1 == 'y' || pil1 == 'Y'){
    cout << "Tagihan prioritas Rp.25.000 ditambahkan";
    cout << endl;
    totalsemua += 25000;
    prioritas = true;

    for (int n = 0; n < 39; n++)
    {
    	cout << "-";
    }
    cout << endl;
    
    cout << "Total yang harus dibayar menjadi : ";
    cout << totalsemua;
    cout << endl;

    for (int n = 0; n < 39; n++)
    {
    	cout << "-";
    }
    cout << endl;
    
  }
  
  uang:
  if (pil == 'y' || pil == 'Y')
  {
  
    cout << "Masukkan jumlah uang anda : ";
    cin >> uang;
    
    if(uang < totalsemua)
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
      if (prioritas == true)
      {
        enqueueLinkedListUT(dataKTP2.nama, dataKTP2.NIK);
        for (int i = 0; i < idx1-1; i++)
        {
          enqueueLinkedListUT(qUT[i].nama, qUT[i].NIK);
        }
      }
        
      else
      {
        for (int i = 0; i < idx1-1; i++)
        {
          enqueueLinkedListUT(qUT[i].nama, qUT[i].NIK);
        }
        enqueueLinkedListUT(dataKTP2.nama, dataKTP2.NIK);
      }
      
      ofstream antri;
      antri.open("antrian_toko.txt");

      if (prioritas == true){
        cout << "Nomor antrian anda adalah : 1";
        cout << endl;
      }
        
      else
      {
        cout << "Nomor antrian anda adalah : ";
        cout << countLinkedListUT();   
        cout << endl;
      }
      
      cout << "Masukkan tanggal transaksi : ";
      cin >> tglb;
      
      for (int n = 0; n < 39; n++)
      {
      	cout << "-";
      }
      
      cout << endl;
      cout << "Invoice berhasil dicetak..";
      cout << endl;
      cout << "Terima kasih sudah berbelanja :)";
      cout << endl;
      
      if (prioritas == true)
      {
        antri << dataKTP2.nama;
        antri << ";";
        antri << dataKTP2.NIK;
        antri << endl;
        
        for (int i = 0; i < idx1-1; i++)
        {
          antri << qUT[i].nama;
          antri << ";";
          antri << qUT[i].NIK;
          antri << endl;
        }
      }
        
      else
      {
        for (int i = 0; i < idx1-1; i++)
        {
          antri << qUT[i].nama;
          antri << ";";
          antri << qUT[i].NIK;
          antri << endl;
        }
        antri << dataKTP2.nama;
        antri << ";";
        antri << dataKTP2.NIK;
        antri << endl;
      }
      antri.close();
      
      invoice();
      sudahtransaksi = true;
    }
    
  }
  
}

//Method untuk mencetak invoice dalam bentuk "invoice.txt" dan mencatat data transaksi pada "history_transaksi.txt"
void UserT::invoice()
{
  kembali = uang - totalsemua;
  ofstream struk;
  struk.open("invoice.txt");
  
  for (int n = 0; n < 18; n++)
  {
  	struk << "=";
  }
  
  struk << " ";
  struk << "STRUK BELANJA";
  struk << " ";
  
  for (int n = 0; n < 18; n++)
  {
  	struk << "=";
  }
  
  struk << endl;
  struk << "NIK       : ";
  struk << dataKTP2.NIK;
  struk << endl;
  struk << "Nama      : ";
  struk << dataKTP2.nama;
  struk << endl;
  struk << "Alamat    : ";
  struk << dataKTP2.alamat;
  struk << endl;
  struk << "Tgl lahir : ";
  struk << dataKTP2.ttl;
  struk << endl;
  
  for (int n = 0; n < 51; n++)
  {
	  struk << "-";
  }
  struk << endl;
  
  for (int i = 0; i < szb; i++)
  {
    struk << dataUsert[beli[i]].nama;
    struk << "   ";
    struk << " = Rp.";
    struk <<  dataUsert[beli[i]].harga;
    struk << " x ";
    struk << jumlah[beli[i]];
    struk << " = ";
    struk << total[beli[i]];
    struk << endl;
  }
  
  for (int n = 0; n < 51; n++)
  {
	  struk << "-";
  }
  
  struk << endl;
  struk << "Total belanjaan : Rp.";
  struk << totalsemua;
  struk << endl;
  struk << "Uang dibayarkan : Rp.";
  struk << uang;
  struk << endl;
  
  for (int n = 0; n < 51; n++)
  {
	  struk << "-";
  }
  
  struk << endl;
  struk << "Kembalian       : Rp.";
  struk << kembali;
  struk << endl;
  
  for (int n = 0; n < 51; n++)
  {
	  struk << "=";
  }
  struk << endl;
  
  struk.close();
  
  ofstream catat;
  catat.open("history_transaksi.txt", ios::app);
  
  catat << "Transaksi pada tanggal ";
  catat << tglb;
  catat << " atas nama ";
  catat << dataKTP2.nama;
  catat << endl;
  catat << "NIK       : ";
  catat << dataKTP2.NIK;
  catat << endl;
  catat << "Alamat    : ";
  catat << dataKTP2.alamat;
  catat << endl;
  catat << "Tgl lahir : ";
  catat << dataKTP2.ttl;
  catat << endl;
  
  for (int n = 0; n < 51; n++)
  {
	  catat << "-";
  }
  catat << endl;
  
  for (int i = 0; i < szb; i++)
  {
    catat << dataUsert[beli[i]].nama;
    catat << "   ";
    catat << " = Rp.";
    catat <<  dataUsert[beli[i]].harga;
    catat << " x ";
    catat << jumlah[beli[i]];
    catat << " = ";
    catat << total[beli[i]];
    catat << endl;
  }
  
  for (int n = 0; n < 51; n++)
  {
	  catat << "-";
  }
  
  catat << endl;
  catat << "Total belanjaan : Rp.";
  catat << totalsemua;
  catat << endl;
  catat << endl;
  
  catat.close();
  
}

//Method untuk menghitung total harga barang dan total semua barang
void UserT::proses()
{
  total[beli[szb]] = jumlah[beli[szb]] * dataUsert[beli[szb]].harga;
  
  totalsemua += total[beli[szb]];
  
  dataUsert[beli[szb]].stok -= jumlah[beli[szb]];
  
}

//Method untuk menu utama sebagai user
void UserT::menutoko()
{
  sudahlewat = false;
  sudahbelanja = false;
  sudahtransaksi = false;
  totalsemua = 0;
  szb = 0;
  
  awal:
  ambildata();
  system("clear");
  int pil;
  pil = 0;
  
  for (int n = 0; n < 14; n++)
  {
  	cout << "-";
  }
  
  cout << " ";
  cout << "MENU TOKO";
  cout << " ";
  
  for (int n = 0; n < 14; n++)
  {
  	cout << "-";
  }
  
  cout << endl;
  cout << "1. Beli barang";
  cout << endl;
  cout << "2. Lihat belanjaan";
  cout << endl;
  cout << "3. Transaksi";
  cout << endl;
  cout << "4. Kembali ke menu user";
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
      cout << "Anda belum belanja apapun!";
      cout << endl;
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
      cout << "Anda belum belanja apapun!";
      cout << endl;
    }
    
  }
    
  else if(pil == 4)
  {
    goto akhir;
  }
    
  else
  {
    cout << "Pilihan yang anda masukkan tidak ada!";
    cout << endl;
    cout << "Tekan enter untuk memasukkan login kembali";
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