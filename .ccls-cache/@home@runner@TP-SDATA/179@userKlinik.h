//179

#include <iostream>
#include <fstream>
#include <sstream>
#include "../header/linklist.h"
#include "../header/queue.h"
using namespace std;

//Class User Klinik
class UserK
{
  public:
    void menuklinik();
    void tampil();
    void list();
    void pembelian();
    void ambildata();
    void transaksi();
    void pemasukan();
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

//Deklarasi kelas UserK
UserK uk;
UserK dataUserk[100];

//Class data link list
class Datalist1
{
	public :
		Datalist1(string n="", int h=0)
    {
			nama = n;
			harga = h;
		}

		string nama;
    int harga;

};

//Struct data KTP3
struct KTP3
{
  string NIK;
  string nama;
  string alamat;
  string ttl;

};

//Deklarasi struct KTP3
KTP3 dataKTP3;

//Class dataAntriU
class dataAntriU
{
  public:
    string nama;
    string NIK;

};

//Deklarasi class dataAntriU
dataAntriU qU[100];

//Fungsi untuk konversi tipe data string ke tipe data integer
int toInt3(string x)
{
	int y;

	stringstream ss;
	ss << x;
	ss >> y;

	return y;
  
}

//Prosedur untuk memisahkan data dari data.txt
void tokenize5(string s, string del = " ", int idx =0)
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
      dataUserk[idx].nama = tmp;
    }
      
    else if (i == 2)
    {
      dataUserk[idx].harga = toInt3(tmp);
    }
    i++;
    
    }
    while (end != -1);
  
}

//Prosedur untuk memisahkan data dari datalogin.txt
void tokenize6(string s, string del = " ")
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
      dataKTP3.NIK = tmp;
    }
      
    else if (i == 2)
    {
      dataKTP3.nama = tmp;
    }
      
    else if (i == 3)
    {
      dataKTP3.alamat = tmp;
    }
      
    else if (i == 4)
    {
      dataKTP3.ttl = tmp;
    }
    i++;

    }
    while (end != -1);
  
}

//Prosedur untuk memisahkan data
void tokenize11(string s, string del = " ", int idx =0)
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
      qU[idx].nama = tmp;
    }
      
    else if (i == 2)
    {
      qU[idx].NIK = tmp;
    }    
    i++;
    
  }
  while (end != -1);
  
}

//Method untuk mengambil data dari file eksternal "data.txt" dan "datalogin.txt"
void UserK::ambildata()
{
  string t;
  idx = 0;
  idx1 = 0;
  ifstream ambil;
  
  ambil.open("data_layanan.txt");
  
	while(!ambil.eof())
  {
		ambil >> t;
		tokenize5(t, ";", idx);
		idx++;
	}
  
	ambil.close();
  ambil.open("datalogin.txt");
  
  while(!ambil.eof())
  {
		ambil >> t;
		tokenize6(t, ";");
  }
  
  ambil.close();

  ifstream catat;
  catat.open("antrian.txt");
  
	while(!catat.eof()){
		catat >> t;
		tokenize11(t, ";", idx1);
		idx1++;
	}
  
	catat.close();
  
}

//Method untuk menampilkan daftar data yang disimpan
void UserK::tampil()
{
  for (int i = 0; i < szb; i++)
  {
    cout << "Daftar layanan ke-";
    cout << i + 1;
    cout << endl;
    cout << "Nama layanan   : ";
    cout << dataUserk[beli[i]].nama;
    cout << endl;
    cout << "Harga layanan  : ";  
    cout << dataUserk[beli[i]].harga;
    cout << endl;
      
    for (int n = 0; n < 39; n++)
    {
    	cout << "-";
    }
    cout << endl;
  }
  
}

//Method untuk menggunakan linklist
void UserK::list()
{
  ListK<Datalist1> x;
  
  cout << "Anda berhasil menambahkan : ";
  cout << endl;
  
  for(int i = 0; i < szb; i++)
  {
		Datalist1 t(dataUserk[beli[i]].nama, dataUserk[beli[i]].harga);
    x.sisipBelakang(t);
  }
  cout << x;
  
}

//Method untuk menu pembelian
void UserK::pembelian()
{
  sudahbelanja = true;
  
  for (int i = 0; i < idx - 1; i++)
  {
    cout << "Data layanan ke-";
    cout <<  i + 1;
    cout << endl;
  	cout << "nama layanan  : ";
    cout << dataUserk[i].nama;
    cout << endl;
    cout << "harga layanan : ";
    cout << dataUserk[i].harga;
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
    cout << "Masukkan no layanan yang anda pesan     : ";
    cin >> beli[szb];
    beli[szb] -= 1;
    
    if (beli[szb] >= idx - 1)
    {
      cout << "No layanan yang anda masukkan tidak ada!";
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
          cout << "Tidak dapat memilih layanan yang sama!";
          cout << endl;
          
          for (int n = 0; n < 39; n++)
          {
          	cout << "-";
          }
          
          cout << endl;
          cout << "Apakah anda ingin memesan lagi? (y/n) : ";
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
    
    cout << "Apakah anda ingin memesan lagi? (y/n) : ";
    cin >> yn;
    
    for (int n = 0; n < 39; n++)
    {
    	cout << "-";
    }
    cout << endl;
    
    proses();
    szb++;
  
    end:
    
    if (yn == 'n' || yn == 'N')
    {
      cout << "Daftar pesanan anda : ";
      cout << endl;
      
      for (int n = 0; n < 39; n++)
      {
      	cout << "-";
      }
      cout << endl;
      list();
      
      for (int n = 0; n < 39; n++)
      {
      	cout << "-";
      }
      
      break;
    }
    
  }
  
}

//Method untuk menu transaksi
void UserK::transaksi()
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
  cout << "Daftar pesanan layanan anda : ";
  cout << endl;
  
  for (int n = 0; n < 39; n++)
  {
  	cout << "-";
  }
  cout << endl;
  
  tampil();
  
  cout << "Total yang harus dibayar : ";
  cout << totalsemua;
  cout << endl;
  cout << "Apakah anda sudah yakin dengan pesanan anda (y/n) : ";
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
        enqueueLinkedList(dataKTP3.nama, dataKTP3.NIK);
        for (int i = 0; i < idx1-1; i++)
        {
          enqueueLinkedList(qU[i].nama, qU[i].NIK);
        }
      }
        
      else
      {
        for (int i = 0; i < idx1-1; i++)
        {
          enqueueLinkedList(qU[i].nama, qU[i].NIK);
        }
        enqueueLinkedList(dataKTP3.nama, dataKTP3.NIK);
      }
      
      ofstream antri;
      antri.open("antrian.txt");

      if (prioritas == true){
        cout << "Nomor antrian anda adalah : 1";
        cout << endl;
      }
        
      else
      {
        cout << "Nomor antrian anda adalah : ";
        cout << countLinkedList();   
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
      cout << "Terima kasih sudah menggunakan layanan kami :)";
      cout << endl;

      if (prioritas == true)
      {
        antri << dataKTP3.nama;
        antri << ";";
        antri << dataKTP3.NIK;
        antri << endl;
        
        for (int i = 0; i < idx1-1; i++)
        {
          antri << qU[i].nama;
          antri << ";";
          antri << qU[i].NIK;
          antri << endl;
        }
      }
        
      else
      {
        for (int i = 0; i < idx1-1; i++)
        {
          antri << qU[i].nama;
          antri << ";";
          antri << qU[i].NIK;
          antri << endl;
        }
        antri << dataKTP3.nama;
        antri << ";";
        antri << dataKTP3.NIK;
        antri << endl;
      }
      antri.close();
      
      invoice();
      sudahtransaksi = true;
    }
  
  }
  
}

//Method untuk mencetak invoice dalam bentuk "invoice.txt" dan mencatat data transaksi pada "history_transaksi.txt"
void UserK::invoice()
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
  struk << dataKTP3.NIK;
  struk << endl;
  struk << "Nama      : ";
  struk << dataKTP3.nama;
  struk << endl;
  struk << "Alamat    : ";
  struk << dataKTP3.alamat;
  struk << endl;
  struk << "Tgl lahir : ";
  struk << dataKTP3.ttl;
  struk << endl;
  
  for (int n = 0; n < 51; n++)
  {
	  struk << "-";
  }
  struk << endl;
  
  for (int i = 0; i < szb; i++)
  {
    struk << dataUserk[beli[i]].nama;
    struk << "   ";
    struk << " = Rp.";
    struk << dataUserk[beli[i]].harga;
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
  catat << dataKTP3.nama;
  catat << endl;
  catat << "NIK       : ";
  catat << dataKTP3.NIK;
  catat << endl;
  catat << "Alamat    : ";
  catat << dataKTP3.alamat;
  catat << endl;
  catat << "Tgl lahir : ";
  catat << dataKTP3.ttl;
  catat << endl;
  
  for (int n = 0; n < 51; n++)
  {
	  catat << "-";
  }
  catat << endl;
  
  for (int i = 0; i < szb; i++)
  {
    catat << dataUserk[beli[i]].nama;
    catat << "   ";
    catat << " = Rp.";
    catat << dataUserk[beli[i]].harga;
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
void UserK::proses()
{
  totalsemua += dataUserk[beli[szb]].harga;
  
}

//Method untuk menu utama sebagai user
void UserK::menuklinik()
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
  
  for (int n = 0; n < 13; n++)
  {
  	cout << "-";
  }
  
  cout << " ";
  cout << "MENU KLINIK";
  cout << " ";
  
  for (int n = 0; n < 13; n++)
  {
  	cout << "-";
  }
  
  cout << endl;
  cout << "1. Pesan layanan";
  cout << endl;
  cout << "2. Lihat Layanan yang dipesan";
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
      cout << "Anda belum memilih apapun!";
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
      cout << "Anda belum memilih apapun!";
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