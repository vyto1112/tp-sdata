#include "179.h"
#include "209.h"
#include "214/login.h"

void mulai(){
  awal:

  lo.login();
  if(lo.islogin() == true)
  {
    if(lo.isAdmin()== true)
    {
      ad.menu();
      goto awal;
    }
    else
    {
      us.menu();
      goto awal;
    }
  }
}
