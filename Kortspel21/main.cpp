#include <iostream>
#include "korthand.h"
#include "kortlek.h"
#include "kort.h"
using namespace std;

int main()
{
  /*Kortlek lek;
  lek.aterstallKortlek();
  lek.blanda();
  while(lek.antalKort() > 0)
  {
      Kort k = lek.utplockatKort();
      cout<<k.text()<<endl;
  }
  */
  Kort k1{Kort::ruter,1};
  Kort k2{Kort::ruter,4};
  Kort k3{Kort::ruter,6};

  Korthand b = Korthand();

  b.stoppaInKort(k1);
  b.stoppaInKort(k2);
  b.stoppaInKort(k3);

  int sum = b.poang();
  cout<<sum<<endl;
   //Hampe

}


