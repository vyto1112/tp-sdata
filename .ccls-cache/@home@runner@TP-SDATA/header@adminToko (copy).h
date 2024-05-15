//209

#include <iostream>
#include <fstream>
#include <sstream>
#include "arrayd.h"
#include "binary.h"
using namespace std;

int count = 0;
BinaryTree<string> a,b,c,z,p;

template<class T>
void ct(BinaryTreeNode<T> *t)
{
  count++;
}

//Class Admin Toko
class AdminT
{
  public:
    void menutoko();
    void ambildata();
    void inputbarang();
    void menuedit();
    void tulisdata();
    void dataedit1();
    void dataedit2();
    void dataedit3();
    void dataedit4();
    void datapohon();
    void pohon();
    void tampilpohon();

    string tgl;
    string nama;
    int sz;
    int harga;
    int stok;
    int noedit;
    int idx;
    int idx1;

};

//Deklarasi class AdminT
AdminT t;
AdminT dataAdmin[100];

//Class Stok
class Stok
{
	public :
		Stok(string t="", string n="", int h=0, int s=0)
    {
			tgl = t;
			nama = n;
      harga = h;
			stok = s;
		}

		string tgl;
    string nama;
    int harga;
    int stok;

};

//Fungsi untuk konversi tipe data string ke tipe data integer
int toInt(string x)
{
	int y;

	stringstream ss;
	ss << x;
	ss >> y;

	return y;
  
}

//Deklarasi array dinamis
Array1D<Stok> Y(100);

//Prosedur untuk memisahkan data
void tokenize1(string s, string del = " ", int idx =0)
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
    
  }
  while (end != -1);
  
}

//Method untuk menginputkan data barang
void AdminT::inputbarang()
{
  ofstream tulis;
	tulis.open("data.txt", ios::app);
  
  cout << "Masukkan jumlah barang yang ingin diinputkan : ";
  cin >> sz;
  
	for (int i = 0; i < sz; ++i)
  {
    cout << "Data barang ke-";
    cout <<  i + 1;
    cout << endl;
		cout << "tgl   : ";
    cin >> tgl;
		cout << "nama  : ";
    cin >> nama;
    cout << "harga : ";
    cin >> harga;
		cout << "stok  : ";
    cin >> stok;
    
    for (int n = 0; n < 39; n++)
    {
    	cout << "-";
    }
    cout << endl;
    
    tulis << tgl;
    tulis << ";";
    tulis << nama;
    tulis << ";";
    tulis << harga;
    tulis << ";";
    tulis << stok;
    tulis << endl;
  }
  
  cout << "Data berhasil disimpan..";
  tulis.close();
  
}

//Method untuk data dari file eksternal "data.txt"
void AdminT::ambildata()
{
  idx = 0;
  string t;
  
  ifstream ambil;
  ambil.open("data.txt");
  
	while(!ambil.eof())
  {
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
void AdminT::menuedit()
{
  editawal:
  ambildata();
  int pil;
  char yn;
  pil = 0;
  
  cout << endl;
  for (int n = 0; n < 14; n++)
  {
  	cout << "-";
  }
  
  cout << " ";
  cout << "MENU EDIT";
  cout << " ";
  
  for (int n = 0; n < 14; n++)
  {
  	cout << "-";
  }
  
  cout << endl;
  cout << "1. Edit data";
  cout << endl;
  cout << "2. Hapus semua data";
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
  
  if (pil == 2)
  {
    cout << "Apakah anda yakin (y/n)? : ";
    cin >> yn;
    
    if (yn == 'y' || yn == 'Y')
    {
      ofstream hapus;
      hapus.open("data.txt");
      hapus << "";
      hapus.close();
      
      for (int n = 0; n < 39; n++)
      {
      	cout << "-";
      }
      cout << endl;
      cout << "Data berhasil dihapus";
      cout << endl;
      dataedit4();
    }
      
    else
    {
      for (int n = 0; n < 39; n++)
      {
      	cout << "-";
      }
      
      cout << endl;
      cout << "Operasi dibatalkan";
      cout << endl;
    }
    
  }
    
  else if (pil == 1)
  {
    cout << Y;
    cout << "Masukkan no barang yang ingin anda edit : ";
    cin >> noedit;
    noedit -= 1;
    
    if (noedit < idx - 1)
    {
      for (int n = 0; n < 39; n++)
      {
      	cout << "-";
      }
      
      cout << endl;
      cout << endl;
      for (int n = 0; n < 14; n++)
      {
      	cout << "-";
      }
      
      cout << " ";
      cout << "OPSI EDIT";
      cout << " ";
      
      for (int n = 0; n < 14; n++)
      {
      	cout << "-";
      }
      
      cout << endl;
      cout << "1. Edit tanggal";
      cout << endl;
      cout << "2. Edit nama";
      cout << endl;
      cout << "3. Edit harga";
      cout << endl;
      cout << "4. Edit stok";
      cout << endl;
      cout << "5. Hapus data";
      cout << endl;
      
      for (int n = 0; n < 39; n++)
      {
      	cout << "-";
      }
      cout << endl;
      cout << "Anda memilih opsi : ";
      cin >> pil;
      
      for (int n = 0; n < 39; n++)
      {
      	cout << "-";
      }
      cout << endl;
      
      switch(pil)
      {
        case 1:
          
          dataedit1();
          cout << "Masukkan data tanggal yg baru : ";
          cin >> tgl;
          dataAdmin[noedit].tgl = tgl;
          tulisdata();
          dataedit2();
          break;
        
        case 2:
          
          dataedit1();
          cout << "Masukkan data nama yg baru : ";
          cin >> nama;
          dataAdmin[noedit].nama = nama;
          tulisdata();
          dataedit2();
          break;
        
        case 3:
          
          dataedit1();
          cout << "Masukkan data harga yg baru : ";
          cin >> harga;
          dataAdmin[noedit].harga = harga;
          tulisdata();
          dataedit2();
          break;
        
        case 4:
          
          dataedit1();
          cout << "Masukkan data stok yg baru : ";
          cin >> stok;
          dataAdmin[noedit].stok = stok;
          tulisdata();
          dataedit2();
          break;
        
        case 5: 
          
          cout << "Apakah anda yakin (y/n)? : ";
          cin >> yn;
          
          if (yn == 'y' || yn == 'Y')
          {
            dataedit1();
            ofstream hapus;
            ofstream tulis;
            tulis.open("data.txt");
            
            for (int i = 0; i < idx - 1; i++)
            {
              if (i != noedit)
              {
                tulis << dataAdmin[i].tgl;
                tulis << ";";
                tulis << dataAdmin[i].nama;
                tulis << ";";
                tulis << dataAdmin[i].harga;
                tulis << ";";
                tulis << dataAdmin[i].stok;
                tulis << endl;
                
              }
            }
            tulis.close();
            
            for (int n = 0; n < 39; n++)
            {
            	cout << "-";
            }
            
            cout << endl;
            cout << "Data berhasil dihapus";
            cout << endl;
            dataedit3();
            break;
            
          }
            
          else
          {
            for (int n = 0; n < 39; n++)
            {
            	cout << "-";
            }
            
            cout << endl;
            cout << "Operasi dibatalkan";
            cout << endl;
            break;
            
          }
        
        default:
          
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
    }
      
    else
    {
      cout << "Data yang anda masukkan tidak ada!";
      cout << endl;
      cout << "Tekan enter untuk memilih menu kembali";
      cout << endl;
      
      for (int n = 0; n < 39; n++)
      {
      	cout << "-";
      }
      cout << endl;
      
    }
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
}

//Method untuk menulis ulang data yang telah diedit
void AdminT::tulisdata()
{
  ofstream tulis;
  tulis.open("data.txt");
  
  for (int i = 0; i < idx - 1; i++)
  {
    tulis << dataAdmin[i].tgl;
    tulis << ";";
    tulis << dataAdmin[i].nama;
    tulis << ";";
    tulis << dataAdmin[i].harga;
    tulis << ";";
    tulis << dataAdmin[i].stok;
    tulis << endl;
  }
  tulis.close();
  
}

//Method untuk menulis data yang belum diedit ke dalam file "history-edit.txt"
void AdminT::dataedit1()
{
  ofstream tulis;
  tulis.open("history_edit.txt", ios::app);
  
  tulis << "Data awal : ";
  tulis << endl;
  tulis << "Tgl   : ";
  tulis << dataAdmin[noedit].tgl;
  tulis << endl;
  tulis << "Nama  : ";
  tulis << dataAdmin[noedit].nama;
  tulis << endl;
  tulis << "Harga : ";
  tulis << dataAdmin[noedit].harga;
  tulis << endl;
  tulis << "Stok  : ";
  tulis << dataAdmin[noedit].stok;
  tulis << endl;
  tulis.close();
  
}

//Method untuk menulis data yang sudah diedit ke dalam file "history-edit.txt"
void AdminT::dataedit2()
{
  ofstream tulis;
  tulis.open("history_edit.txt", ios::app);
  
  tulis << endl;
  tulis << "Diedit menjadi : ";
  tulis << endl;
  tulis << "Tgl   : ";
  tulis << dataAdmin[noedit].tgl;
  tulis << endl;
  tulis << "Nama  : ";
  tulis << dataAdmin[noedit].nama;
  tulis << endl;
  tulis << "Harga : ";
  tulis << dataAdmin[noedit].harga;
  tulis << endl;
  tulis << "Stok  : ";
  tulis << dataAdmin[noedit].stok;
  tulis << endl;
  
  for (int n = 0; n < 39; n++)
  {
	  tulis << "-";
  }
  tulis << endl;
  
  tulis.close();
  
}

//Method untuk menulis data yang sudah diedit ke dalam file "history-edit.txt"
void AdminT::dataedit3()
{
  ofstream tulis;
  tulis.open("history_edit.txt", ios::app);

  tulis << endl;
  tulis << "Diedit menjadi : ";
  tulis << endl;
  tulis << " - ";
  tulis << endl;
  tulis << "(Data dihapus)";
  tulis << endl;
  
  for (int n = 0; n < 39; n++)
  {
	  tulis << "-";
  }
  tulis << endl;
  
  tulis.close();
  
}

//Method untuk menulis data yang sudah diedit ke dalam file "history_edit.txt"
void AdminT::dataedit4()
{
  ofstream tulis;
  tulis.open("history_edit.txt", ios::app);

  tulis << endl;
  tulis << "Semua data dihapus";
  tulis << endl;
  tulis << endl;
  
  for (int n = 0; n < 39; n++)
  {
	  tulis << "-";
  }
  tulis << endl;
  
  tulis.close();
}

//Struct pohonT
struct pohonT
{
  string pegawai;
};

//Deklarasi struct pohon
pohonT pt[100];

void AdminT::datapohon()
{
  idx1 = 0;
  ifstream ambil;
  string t;
  
  ambil.open("pegawai.txt");
  
  while(!ambil.eof())
  {
		ambil >> t;
    
    if (t != "-")
    {
      pt[idx1].pegawai = t;
      idx1++;
    }
  }

  ambil.close();

}

//Method untuk menampilkan pohon dengan grafik
void AdminT::tampilpohon(){
  cout << endl;
  cout << endl;
  
  for (int n = 0; n < 14; n++)
	{
		cout << " ";
	}
	
	for (int n = 0; n < 14; n++)
	{
		cout << " ";
	}
  
	for (int n = 0; n < 5; n++)
	{
		cout << " ";
  }
  cout << pt[0].pegawai;
  
  for (int n = 0; n < 5; n++)
	{
		cout << " ";
  }
  cout << endl;
	
	for (int n = 0; n < 14; n++)
	{
		cout << " ";
	}
	
	cout << "      == == ==";
	cout << " == ==|== == ";
	cout << "== == ==      ";
  cout << endl;
	
	for (int n = 0; n < 14; n++)
	{
		cout << " ";
	}
	cout << "      ||      ";
	
	for (int n = 0; n < 13; n++)
	{
		cout << " ";
	}
	cout << "      ||      " << endl;
	
	for (int n = 0; n < 14; n++)
	{
		cout << " ";
	}
	cout << pt[1].pegawai;
	
	for (int n = 0; n < 13; n++)
	{
		cout << " ";
	}
  
	cout << " ";
  cout << pt[4].pegawai;
  cout << " ";
  cout << endl;
	
	for (int n = 0; n < 14; n++)
	{
		cout << " ";
	}
	cout << "      ||      ";
	
	for (int n = 0; n < 13; n++)
	{
		cout << " ";
	} 
	cout << "      ||      " << endl;
	
	cout << "      -- -- --";
	cout << "-- -- --      ";
	
	for (int n = 0; n < 13; n++)
	{
		cout << " ";
	}
	cout << "      -- -- --";
	
	cout << "-- -- --";
	cout << endl;
	cout << "      ||      ";
	cout << "      ||      ";
	
	for (int n = 0; n < 13; n++)
	{
		cout << " ";
	}
	cout << "      ||      ";
	
	cout << "      ||";
	cout << endl;
	cout << " ";
  cout << pt[2].pegawai;
  cout << " ";
	cout << " ";
  cout << pt[3].pegawai;
  cout << " ";
	
	for (int n = 0; n < 13; n++)
	{
		cout << " ";
	}
	
	cout << "  ";
  cout << pt[5].pegawai;
  cout << "  ";
  cout << "  ";
	cout << pt[6].pegawai;
	cout << endl;
  cout << endl;
  cout << endl;
  
}

//Method untuk menu pohon
void AdminT::pohon()
{
  datapohon();
  
  c.MakeTree(pt[2].pegawai,a,a);
  z.MakeTree(pt[3].pegawai,a,a);
  p.MakeTree(pt[1].pegawai,c,z);
  z.MakeTree(pt[6].pegawai,a,a);
  b.MakeTree(pt[5].pegawai,a,z);
  z.MakeTree(pt[4].pegawai,a,b);
  c.MakeTree(pt[0].pegawai,p,z);

  pohon:
  system("clear");
  tampilpohon();
  int pil;
  pil = 0;
  
  for (int n = 0; n < 14; n++)
  {
  	cout << "-";
  }
  
  cout << " ";
  cout << "MENU POHON";
  cout << " ";
  
  for (int n = 0; n < 13; n++)
  {
  	cout << "-";
  }

  cout << endl;
  cout << "1. Lihat secara preorder";
  cout << endl;
  cout << "2. Lihat secara inorder";
  cout << endl;
  cout << "3. Lihat secara postorder";
  cout << endl;
  cout << "4. Lihat secara levelorder";
  cout << endl;
  cout << "5. Edit data";
  cout << endl;
  cout << "6. Kembali ke menu admin";
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
    cout << "Secara preorder   : ";
    c.PreOutput();
    
    for (int n = 0; n < 39; n++)
    {
    	cout << "-";
    }
    cout << endl;
    
  }
    
  else if(pil == 2)
  {
    cout << "Secara inorder    : ";
    c.InOutput();
    for (int n = 0; n < 39; n++)
    {
    	cout << "-";
    }
    cout << endl;
    
  }
    
  else if(pil == 3)
  {
    cout << "Secara postorder  : ";
    c.PostOutput();
    
    for (int n = 0; n < 39; n++)
    {
    	cout << "-";
    }
    cout << endl;
    
  }

  else if(pil == 4)
  {
    cout << "Secara levelorder : ";
    c.LevelOutput();
  
    for (int n = 0; n < 39; n++)
    {
    	cout << "-";
    }
    cout << endl;
    
  }

  else if (pil == 5)
  {
    
  }
    
  else if (pil == 6)
  {
    goto pohonakhir;
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
  goto pohon;

  pohonakhir:
  int g;
  
}

//Method untuk tampilan menu utama sebagai admin
void AdminT::menutoko()
{
  awal:
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
  cout << "1. Input data barang";
  cout << endl;
  cout << "2. Edit data barang";
  cout << endl;
  cout << "3. Lihat data barang";
  cout << endl;
  cout << "4. Lihat hierarki kepegawaian";
  cout << endl;
  cout << "5. Kembali ke menu admin";
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

  else if(pil == 4)
  {
    pohon();
  }
    
  else if (pil == 5)
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