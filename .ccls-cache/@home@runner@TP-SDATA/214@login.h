#include <iostream>
#include <fstream>
using namespace std;

//Class login
class Login
{
  public:
    void login();
    void datalogin(int no);
    void tampil();
    void daftar(string s);
    void daftarambil();
    bool islogin();
    bool isAdmin();

  private:
    int pil;
    int nolog;
    int idx;
    string status;
    string namafile;
    string nik;
    string nama;
    string alamat;
    string ttl;
    char yn;
    bool berhasil_login;
    bool isadmin;

};

Login lo;

//Class KTP
class KTP
{
	public :
    string status;
		string NIK;
		string nama;
		string alamat;
    string ttl;
		int umur;
    void ambildata();
    int idx;
    int idx1;

};

//Deklarasi kelas KTP
KTP x;
KTP dataKTP[100];
KTP dataKTPbaru[100];

//Prosedur untuk memisahkan data
void tokenize(string s, string del = " ", int idx =0)
{
	string tmp;
	int i;
  i = 1;
  int start;
  int end;
  end = -1 * del.size();
  
  do
  {
    start = end + del.size();
    end = s.find(del, start);
    tmp = s.substr(start, end - start);
    
    if (i == 1)
    {
      dataKTP[idx].status = tmp;
    }
      
    else if (i == 2)
    {
      dataKTP[idx].NIK = tmp;
    }
      
    else if (i == 3)
    {
      dataKTP[idx].nama = tmp;
    }
      
    else if (i == 4)
    {
      dataKTP[idx].alamat = tmp;
    }
      
    else if (i == 5)
    {
      dataKTP[idx].ttl = tmp;
    }
    i++;
    
  }    
  while (end != -1);
  
}

//Prosedur untuk memisahkan data
void tokenizeb(string s, string del = " ", int idx =0)
{
	string tmp;
	int i;
  i = 1;
  int start;
  int end;
  end = -1 * del.size();
  
  do
  {
    start = end + del.size();
    end = s.find(del, start);
    tmp = s.substr(start, end - start);
    
    if (i == 1)
    {
      dataKTPbaru[idx].status = tmp;
    }
      
    else if (i == 2)
    {
      dataKTPbaru[idx].NIK = tmp;
    }
      
    else if (i == 3)
    {
      dataKTPbaru[idx].nama = tmp;
    }
      
    else if (i == 4)
    {
      dataKTPbaru[idx].alamat = tmp;
    }
      
    else if (i == 5)
    {
      dataKTPbaru[idx].ttl = tmp;
    }
    i++;
    
  } 
  while (end != -1);
  
}

//Method untuk mengambil data dari ktp.txt
void KTP::ambildata()
{
  ifstream baca;
  string t;
  baca.open("ktp.txt");

  idx = 0;
	while(!baca.eof())
  {
		baca >> t;
		tokenize(t, ";", idx);
		idx++;
	}
  
	baca.close();
  
}


//Method untuk menyimpan data siapa yang login
void Login::datalogin(int no)
{
  ofstream log;
  ofstream hislog;
  
  log.open("datalogin.txt");
  log << dataKTP[no].NIK;
  log << ";";
  log << dataKTP[no].nama;
  log << ";";
  log << dataKTP[no].alamat;
  log << ";";
  log << dataKTP[no].ttl;
  log << endl;

  log.close();
  
  hislog.open("history_login.txt", ios::app);
  hislog << "NIK       : ";
  hislog << dataKTP[no].NIK;
  hislog << endl;
  hislog << "Nama      : ";
  hislog << dataKTP[no].nama;
  hislog << endl;
  hislog << "Alamat    : ";
  hislog << dataKTP[no].alamat;
  hislog << endl;
  hislog << "Tgl lahir : ";
  hislog << dataKTP[no].ttl;
  hislog << endl;
  
  if (isadmin == true)
  {
    hislog << "Status    : ";
    hislog << "Admin";
    hislog << endl;
  }
    
  else
  {
    hislog << "Status    : ";
    hislog << "User";
    hislog << endl;
  }
  
  for (int n = 0; n < 39; n++)
  {
	  hislog << "-";
  }
  
  hislog << endl;
  
  hislog.close();
  
}

//Method untuk menampilkan data ktp yang tersedia
void Login::tampil()
{
  for (int i = 0; i < x.idx - 1; i++)
  {
    cout << "Data ktp ke-";
    cout << i + 1;
    cout << " : ";
    cout << endl;
    cout << "Status    : ";
    cout << dataKTP[i].status;
    cout << endl;
    cout << "NIK       : ";
    cout << dataKTP[i].NIK;
    cout << endl;
    cout << "Nama      : ";
    cout << dataKTP[i].nama;
    cout << endl;
    cout << "Alamat    : ";
    cout << dataKTP[i].alamat;
    cout << endl;
    cout << "Tgl lahir : ";
    cout << dataKTP[i].ttl;
    cout << endl;
    
    for (int n = 0; n < 39; n++)
    {
	    cout << "-";
    }
    cout << endl;
  }
  
}

//Method untuk mendaftar akun sendiri
void Login::daftar(string s)
{
  cout << "Masukkan NIK anda             : ";
  cin >> nik;
  cout << "Masukkan nama anda            : ";
  cin >> nama;
  cout << "Masukkan alamat anda          : ";
  cin >> alamat;
  cout << "Masukkan tgl lahir anda       : ";
  cin >> ttl;
  
  for (int n = 0; n < 39; n++)
  {
	  cout << "-";
  }
  cout << endl;
  ofstream daftar1;
  
  daftar1.open("ktp.txt", ios::app);
  daftar1 << s;
  daftar1 << ";";
  daftar1 << nik;
  daftar1 << ";";
  daftar1 << nama;
  daftar1 << ";";
  daftar1 << alamat;
  daftar1 << ";";
  daftar1 << ttl;
  daftar1 << endl;

  cout << "Data anda berhasil didaftarkan";
  cout << " silahkan kembali ke menu login";
  
}

//Method untuk daftar akun dengan data ktp yang sudah ada
void Login::daftarambil()
{
  ifstream bacabaru;
  string t;
  bacabaru.open(namafile);

  idx = 0;
	while(!bacabaru.eof())
  {
		bacabaru >> t;
		tokenizeb(t, ";", idx);
		idx++;
	}
  
	bacabaru.close();

  cout << "Data yang terbaca : ";
  cout << endl;
  
  for (int i = 0; i < idx - 1; i++)
  {
    cout << "Data ktp ke-";
    cout << i + 1;
    cout << " : ";
    cout << endl;
    cout << "Status    : ";
    cout << dataKTPbaru[i].status;
    cout << endl;
    cout << "NIK       : ";
    cout << dataKTPbaru[i].NIK;
    cout << endl;
    cout << "Nama      : ";
    cout << dataKTPbaru[i].nama;
    cout << endl;
    cout << "Alamat    : ";
    cout << dataKTPbaru[i].alamat;
    cout << endl;
    cout << "Tgl lahir : ";
    cout << dataKTPbaru[i].ttl;
    cout << endl;
    
    for (int n = 0; n < 39; n++)
    {
	    cout << "-";
    }
    cout << endl;
  }
  
  cout << "Apakah data tersebut sudah benar? (y/n) : ";
  cin >> yn;
  
  if (yn == 'y' || yn == 'Y')
  {
    ofstream tulisbaru;
    
    tulisbaru.open("ktp.txt", ios::app);
    for (int i = 0; i < idx - 1; i++)
    {
      tulisbaru << dataKTPbaru[i].status;
      tulisbaru << ";";
      tulisbaru << dataKTPbaru[i].NIK;
      tulisbaru << ";";
      tulisbaru << dataKTPbaru[i].nama;
      tulisbaru << ";";
      tulisbaru << dataKTPbaru[i].alamat;
      tulisbaru << ";";
      tulisbaru << dataKTPbaru[i].ttl;
      tulisbaru << endl;
    }

    tulisbaru.close();
    
    for (int n = 0; n < 39; n++)
    {
	    cout << "-";
    }
    cout << endl;
    cout << "Data anda berhasil didaftarkan, silahkan kembali ke menu login";
  }
  
}

//Method untuk status login
bool Login:: islogin ()
{ 
   return berhasil_login;
  
}

//Method untuk status admin
bool Login:: isAdmin ()
{
   return isadmin;
  
}

//Method untuk menu utama login
void Login::login()
{
  awal:
  berhasil_login = false;
  isadmin = false;
  system("clear");
  x.ambildata();

  for (int n = 0; n < 14; n++)
  {
    cout << "-";
  }
  cout << " ";
  cout << "MENU LOGIN";
  cout << " ";

  for (int n = 0; n < 13; n++)
  {
    cout << "-";
  }
  
  cout << endl;
  cout << "1. Login dari data ktp";
  cout << endl;
  cout << "2. Login dengan input keyboard";
  cout << endl;
  cout << "3. Buat akun baru dengan data ktp";
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
    tampil();
    cout << "Masukkan no data yang ingin anda pakai : ";
    cin >> nolog;
    
    if(nolog < x.idx)
    {
      nolog -= 1;
      
      if (dataKTP[nolog].status == "admin")
      {
        cout << "Anda login sebagai admin";
        cout << endl;
        
        isadmin = true;
        berhasil_login = true;
        datalogin(nolog);
        
        goto akhir;
      }
        
      else
      {
        cout << "Anda login sebagai user";
        cout << endl;
        
        isadmin = false;
        berhasil_login = true;
        datalogin(nolog);
        
        goto akhir;
      }
      
    }
      
    else
    {
      berhasil_login = false;
      cout << "Data yang anda masukkan tidak terdaftar!";
      cout << endl;
      cout << "Tekan enter untuk login kembali";
      cout << endl;
      
      for (int n = 0; n < 39; n++)
      {
	      cout << "-";
      }
      cout << endl;
      
      cin.ignore();
  	  getchar();
      
  	  goto awal;
      
    }
    
  }
    
  else if (pil == 2)
  {
    cout << endl;
    
    for (int n = 0; n < 14; n++)
    {
      cout << "-";
    }
    
    cout << " ";
    cout << "MENU LOGIN";
    cout << " ";

    for (int n = 0; n < 13; n++)
    {
      cout << "-";
    }
    cout << endl;
    
    cout << "Masukkan NIK anda  : ";
    cin >> nik;
    cout << "Masukkan nama anda : ";
    cin >> nama;
    
    for (int n = 0; n < 39; n++)
    {
	    cout << "-";
    }
    cout << endl;
    
    for (int i = 0; i < x.idx; i++)
    {
      
      if (nik == dataKTP[i].NIK && nama == dataKTP[i].nama)
      {
        
        if (dataKTP[i].status == "admin")
        {
          cout << "Anda login sebagai admin";
          cout << endl;
          
          isadmin = true;
          berhasil_login = true;
          datalogin(i);
          
          goto akhir;
        }
          
        else
        {
          cout << "Anda login sebagai user";
          cout << endl;
          
          isadmin = false;
          berhasil_login = true;
          datalogin(i);
          
          goto akhir;
        }
        
      }
      
    }
    berhasil_login = false;
    cout << "Data yang anda masukkan tidak terdaftar!";
    cout << endl;
    cout << "Tekan enter untuk login kembali";
    cout << endl;
    
    for (int n = 0; n < 39; n++)
    {
	    cout << "-";
    }
    cout << endl;
    
    cin.ignore();
    getchar();
    
    goto awal;
    
  }
    
  else if (pil == 3)
  {
    cout << endl;
    for (int n = 0; n < 13; n++)
    {
      cout << "-";
    }
    
    cout << " ";
    cout << "MENU DAFTAR";
    cout << " ";

    for (int n = 0; n < 13; n++)
    {
      cout << "-";
    }
    
    cout << endl;
    cout << "1. Daftar dengan input sendiri";
    cout << endl;
    cout << "2. Daftar dengan data ktp yang sudah ada";
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
      cout << "1. Admin";
      cout << endl;
      cout << "2. User";
      cout << endl;
      
      for (int n = 0; n < 39; n++)
      {
      	cout << "-";
      }
      
      cout << endl;
      cout << "Masukkan pilihan status akun anda : ";
      cin >> pil;
      
      if (pil == 1)
      {
        status = "admin";
        daftar(status);
      }
        
      else if (pil == 2)
      {
        status = "user";
        daftar(status);
      }
        
      else
      {
        cout << "Pilihan yang anda masukkan tidak ada!";
        cout << endl;
        cout << "Tekan enter untuk kembali lagi";
        cout << endl;
      }
      
    }
      
    else if (pil == 2)
    {
      cout << "Masukkan nama file ktp anda dengan format .txt!";
      cout << endl;
      cout << "Format data ktp adalah ";
      cout << "(status_akun;nik;nama;alamat;tgl lahir)";
      cout << endl;
      
      for (int n = 0; n < 39; n++)
      {
	      cout << "-";
      }
      
      cout << endl;
      cout << "Nama file : ";
      cin >> namafile;
      
      for (int n = 0; n < 39; n++)
      {
	      cout << "-";
      }
      
      cout << endl;
      daftarambil();
      
    }
      
    else
    {
      cout << "Pilihan yang anda masukkan tidak ada!";
      cout << endl;
      cout << "Tekan enter untuk kembali lagi";
      cout << endl;
    }
    
  }
    
  else
  {
    cout << "Pilihan yang anda masukkan tidak ada!";
    cout << endl;
    cout << "Tekan enter untuk kembali lagi";
    cout << endl;
  }
  
  cin.ignore();
	getchar(); 
  goto awal;
  
  akhir:
  cin.ignore();
	getchar(); 
  
}
