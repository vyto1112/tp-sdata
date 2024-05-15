#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class KTP {
	public :
		string NIK;
		string nama;
		string alamat;
		int umur;
    void ambildata();
  private :
    int idx;
};

KTP dataKTP[5];

void tokenize(string s, string del = " ", int idx =0)
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
        	dataKTP[idx].NIK = tmp;
        }
        else if (i == 2){
        	dataKTP[idx].nama = tmp;
        }
        else if (i == 3){
          dataKTP[idx].alamat = tmp;
        }
        i++;

    } while (end != -1);
}

void KTP::ambildata(){
  ifstream baca;
  string t;
  
  baca.open("ktp.txt");
	while(!baca.eof()){
		baca >> t;
		tokenize(t, ";", idx);
		idx++;
	}
	baca.close();
}