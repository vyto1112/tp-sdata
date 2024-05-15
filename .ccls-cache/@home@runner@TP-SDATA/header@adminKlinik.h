//209

#include <iostream>
#include <fstream>
#include <sstream>
#include "adminKlinik+.h"
using namespace std;

int count1 = 0;
BinaryTreeK<string> a1,b1,c1,z1,p1;

template<class T>
void ct1(BinaryTreeNodeK<T> *t)
{
  count1++;
}

#include <iostream>
using namespace std;

//Class Admin Klinik
class AdminK
{
  public:
    void menuklinik();
    void ambildata();
    void inputdata();
    void menuedit();
    void menuantrian();
    void tulisdata();
    void dataedit1();
    void dataedit2();
    void dataedit3();
    void dataedit4();
    void datapohon();
    void pohon();
    void tampilpohon();

    string nama;
    int harga;
    int noedit;
    int idx;
    int idx1;
    int sz;

};

//Deklarasi class AdminK
AdminK k;
AdminK dataAdmink[100];

//Class Layanan
class Layanan
{
	public :
		Layanan(string n="", int h=0)
    {
			nama = n;
			harga = h;
		}

		string nama;
    int harga;

};

//Deklarasi array dinamis
Array1DK<Layanan> A(100);

//Class dataAntriA
class dataAntriA
{
  public:
    string nama;
    string NIK;

};

//Deklarasi class dataAntriA
dataAntriA qA[100];

//Prosedur untuk memisahkan data
int toInt2(string x)
{
	int y;

	stringstream ss;
	ss << x;
	ss >> y;

	return y; 
  
}

//Prosedur untuk memisahkan data
void tokenize4(string s, string del = " ", int idx =0)
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
      dataAdmink[idx].nama = tmp;
    }
      
    else if (i == 2)
    {
      dataAdmink[idx].harga = toInt2(tmp);
    }    
    i++;
    
  }
  while (end != -1);
  
}

//Prosedur untuk memisahkan data
void tokenize10(string s, string del = " ", int idx =0)
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
      qA[idx].nama = tmp;
    }
      
    else if (i == 2)
    {
      qA[idx].NIK = tmp;
    }    
    i++;
    
  }
  while (end != -1);
  
}

//Deklarasi class Layanan
Layanan dataLayanan[100];

//Method untuk mengambil data dari txt
void AdminK::ambildata()
{
  idx = 0;
  idx1 = 0;
  string t;
  
  ifstream ambil;
  ambil.open("data_layanan.txt");
  
	while(!ambil.eof()){
		ambil >> t;
		tokenize4(t, ";", idx);
		idx++;
	}
  
	ambil.close();

  Array1DK<Layanan> B(idx);
  
  for (int i = 0; i < idx; i++)
  {
    nama = dataAdmink[i].nama;
    harga = dataAdmink[i].harga;
    
    Layanan layananN(nama, harga);
		B[i] = layananN;
  }
  
  A = B;

  ifstream catat;
  catat.open("antrian.txt");
  
	while(!catat.eof()){
		catat >> t;
		tokenize10(t, ";", idx1);
		idx1++;
	}
  
	catat.close();
  
}

//Method untuk menginput data ke txt
void AdminK::inputdata()
{
  ofstream tulis;
	tulis.open("data_layanan.txt", ios::app);
  
  cout << "Masukkan jumlah layanan yang ingin diinputkan : ";
  cin >> sz;
  
	for (int i = 0; i < sz; ++i)
  {
    cout << "Data layanan ke-";
    cout <<  i + 1;
    cout << endl;
		cout << "nama layanan   : ";
    cin >> nama;
		cout << "harga layanan  : ";
    cin >> harga;
    
    for (int n = 0; n < 39; n++)
    {
	    cout << "-";
    }
    cout << endl;
    
    tulis << nama;
    tulis << ";";
    tulis << harga;
    tulis << endl;
  }
  
  cout << "Data berhasil disimpan..";
  tulis.close();
  
}


//Method untuk menu edit
void AdminK::menuedit()
{
  editawal:
  ambildata();
  int pil;
  char yn;
  
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
      hapus.open("data_layanan.txt");
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
    cout << A;
    cout << "Masukkan no layanan yang ingin anda edit : ";
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
      cout << "1. Edit nama layanan";
      cout << endl;
      cout << "2. Edit harga layanan";
      cout << endl;
      cout << "3. Hapus data";
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
          cout << "Masukkan data nama yg baru : ";
          cin >> nama;
          dataAdmink[noedit].nama = nama;
          
          tulisdata();
          dataedit2();
          break;
        
        case 2:
          dataedit1();
          cout << "Masukkan data harga yg baru : ";
          cin >> harga;
          dataAdmink[noedit].harga = harga;
          
          tulisdata();
          dataedit2();
          break;
        
        case 3: 
          cout << "Apakah anda yakin (y/n)? : ";
          cin >> yn;
          
          if (yn == 'y' || yn == 'Y')
          {
            dataedit1();
            ofstream hapus;
            ofstream tulis;
            tulis.open("data_layanan.txt");
            
            for (int i = 0; i < idx - 1; i++)
            {
              if (i != noedit)
              {
                tulis << dataAdmink[i].nama;
                tulis << ";";
                tulis << dataAdmink[i].harga;
                tulis << ";";
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
void AdminK::tulisdata()
{
  ofstream tulis;
  tulis.open("data_layanan.txt");
  
  for (int i = 0; i < idx - 1; i++)
  {
    tulis << dataAdmink[i].nama;
    tulis << ";";
    tulis << dataAdmink[i].harga;
    tulis << ";";
    tulis << endl;
  }
  
  tulis.close();
  
}

//Method untuk menulis data yang belum diedit ke dalam file "history-edit.txt"
void AdminK::dataedit1()
{
  ofstream tulis;
  tulis.open("history_edit.txt", ios::app);
  
  tulis << "Data awal : ";
  tulis << endl;
  tulis << "Nama layanan  : ";
  tulis << dataAdmink[noedit].nama;
  tulis << endl;
  tulis << "Harga layanan : ";
  tulis << dataAdmink[noedit].harga;
  tulis<< endl;

  tulis.close();
  
}

//Method untuk menulis data yang sudah diedit ke dalam file "history-edit.txt"
void AdminK::dataedit2()
{
  ofstream tulis;
  tulis.open("history_edit.txt", ios::app);
  
  tulis << "Data awal : ";
  tulis << endl;
  tulis << "Nama layanan  : ";
  tulis << dataAdmink[noedit].nama;
  tulis << endl;
  tulis << "Harga layanan : ";
  tulis << dataAdmink[noedit].harga;
  tulis << endl;
  
  for (int n = 0; n < 39; n++)
  {
	  tulis << "-";
  }
  tulis << endl;
  
  tulis.close();
  
}

//Method untuk menulis data yang sudah diedit ke dalam file "history-edit.txt"
void AdminK::dataedit3()
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

//Method untuk menulis data yang sudah diedit ke dalam file "history-edit.txt"
void AdminK::dataedit4()
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

//Method untuk menu antrian
void AdminK::menuantrian(){  
  ambildata();
  for (int i = 0; i < idx1-1; i++)
  {
    enqueueLinkedListA(qA[i].nama, qA[i].NIK);
  }
  
  int pil;
  int hitung;
  hitung = 0;
  pil = 0;
  
  awal:
  system("clear");
  
  for (int n = 0; n < 13; n++)
  {
  	cout << "-";
  }
  
  cout << " ";
  cout << "MENU ANTRIAN";
  cout << " ";

  for (int n = 0; n < 12; n++)
  {
  	cout << "-";
  }
  
  cout << endl;
  cout << "1. Lihat antrian saat ini";
  cout << endl;
  cout << "2. Layani antrian";
  cout << endl;
  cout << "3. Hapus semua antrian";
  cout << endl;
  cout << "4. Kembali ke menu klinik";
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
    displayLinkedListA();
  }
    
  else if (pil == 2){
    hitung++;
    dequeueLinkedListA();

    ofstream catat;
    catat.open("antrian.txt");

    for (int i = hitung; i < idx1-1; i++)
    {
      catat << qA[i].nama;
      catat << ";";
      catat << qA[i].NIK;
      catat << endl;
    }
    
    catat.close();
  }

  else if(pil == 3)
  {
    clearLinkedListA();

    ofstream catat;
    catat.open("antrian.txt");
    catat << " ";
    
    catat.close();
  }
    
  else if (pil == 4){
    goto akhir;
  }

  cin.ignore();
  getchar();
  goto awal;
  
  akhir:
  int g;
}

//Struct pohonT
struct pohonK
{
  string pegawai;
};

//Deklarasi struct pohon
pohonK pk[100];

void AdminK::datapohon()
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
      pk[idx1].pegawai = t;
      idx1++;
    }
  }

  ambil.close();

}

//Method untuk menampilkan pohon dengan grafik
void AdminK::tampilpohon(){
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
  cout << pk[0].pegawai;
  
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
	cout << pk[1].pegawai;
	
	for (int n = 0; n < 13; n++)
	{
		cout << " ";
	}
  
	cout << " ";
  cout << pk[4].pegawai;
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
  cout << pk[2].pegawai;
  cout << " ";
	cout << " ";
  cout << pk[3].pegawai;
  cout << " ";
	
	for (int n = 0; n < 13; n++)
	{
		cout << " ";
	}
	
	cout << "  ";
  cout << pk[5].pegawai;
  cout << "  ";
  cout << "  ";
	cout << pk[6].pegawai;
	cout << endl;
  cout << endl;
  cout << endl;
  
}

//Method untuk menu pohon
void AdminK::pohon()
{
  datapohon();
  
  c1.MakeTree(pk[2].pegawai,a1,a1);
  z1.MakeTree(pk[3].pegawai,a1,a1);
  p1.MakeTree(pk[1].pegawai,c1,z1);
  z1.MakeTree(pk[6].pegawai,a1,a1);
  b1.MakeTree(pk[5].pegawai,a1,z1);
  z1.MakeTree(pk[4].pegawai,a1,b1);
  c1.MakeTree(pk[0].pegawai,p1,z1);

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
    c1.PreOutput();
    
    for (int n = 0; n < 39; n++)
    {
    	cout << "-";
    }
    cout << endl;
    
  }
    
  else if(pil == 2)
  {
    cout << "Secara inorder    : ";
    c1.InOutput();
    for (int n = 0; n < 39; n++)
    {
    	cout << "-";
    }
    cout << endl;
    
  }
    
  else if(pil == 3)
  {
    cout << "Secara postorder  : ";
    c1.PostOutput();
    
    for (int n = 0; n < 39; n++)
    {
    	cout << "-";
    }
    cout << endl;
    
  }

  else if(pil == 4)
  {
    cout << "Secara levelorder : ";
    c1.LevelOutput();
  
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

//Method untuk tampilan utama menu klinik
void AdminK::menuklinik()
{
  awal:
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
  cout << "1. Tambah layanan";
  cout << endl;
  cout << "2. Edit layanan";
  cout << endl;
  cout << "3. Lihat data layanan";
  cout << endl;
  cout << "4. Selesaikan layanan";
  cout << endl;
  cout << "5. Lihat hierarki kepegawaian";
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
    inputdata();
  }
    
  else if (pil == 2)
  {
    menuedit();
  }
    
  else if (pil == 3)
  {
    ambildata();
    cout << A;
  }

  else if (pil == 4)
  {
    menuantrian();
  }

  else if (pil == 5)
  {
    pohon();
  }
    
  else if (pil == 6)
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