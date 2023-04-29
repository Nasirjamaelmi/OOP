#include <iostream>
#include "korthand.h"
#include "kortlek.h"
#include "kort.h"
#include "bankir.h"
#include "spelare.h"
using namespace std;

void skrevheltal()
{
    static int staticvariabel = 5;
    staticvariabel +=11;
    cout<<staticvariabel<<endl;
}
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
  /*Kort k1{Kort::ruter,1};
  Kort k2{Kort::ruter,4};
  Kort k3{Kort::ruter,6};

  Korthand b = Korthand();

  b.stoppaInKort(k1);
  b.stoppaInKort(k2);
  b.stoppaInKort(k3);

  int sum = b.poang();
  cout<<sum<<endl;*/

    /*cout<< "Kortspelet 21!" <<endl;
    Bankir bank;
    Spelare spelare;
    bank.registreraSpelare(&spelare);

    while (bank.harRegistreradeSpelare())
        bank.spelaEnOmgang();
    return 0;
    */
    skrevheltal();
    skrevheltal();

}


