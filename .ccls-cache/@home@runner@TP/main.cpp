#include "login.h"
#include "admin.h"
#include "user.h"
using namespace std;

int main() {
  awal:
  lo.login();
  if(lo.islogin() == true){
    if(lo.isAdmin()== true){
      ad.menu();
      goto awal;
    }
    else{
      us.menu();
      goto awal;
    }
  }
}