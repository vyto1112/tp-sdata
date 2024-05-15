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