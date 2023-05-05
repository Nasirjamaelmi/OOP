#include <iostream>
#include "korthand.h"
#include "kortlek.h"
#include "kort.h"
#include "bankir.h"
#include "spelare.h"
#include "abstraktspelare.h"
using namespace std;

void skrevheltal()
{
    static int staticvariabel = 5;
    staticvariabel +=11;
    cout<<staticvariabel<<endl;
}

int main()
{

/*
  Kort k1{Kort::ruter,4};
  Kort k2{Kort::ruter,3};
  Kort k3{Kort::ruter,3};
  Kort k4{Kort::ruter,2};
  Kort k5{Kort::ruter,3};



  Korthand b = Korthand();


  b.stoppaInKort(k1);
  b.stoppaInKort(k2);
  b.stoppaInKort(k3);
  b.stoppaInKort(k4);
  b.stoppaInKort(k5);



  int sum = b.poang();
  cout<<sum<<endl;
*/
   cout<< "Kortspelet 21!" <<endl;
    Bankir bank;
    Spelare spelare;
    int bet = 0;
    bank.registreraSpelare(&spelare);

    while (bank.harRegistreradeSpelare() && spelare.money > 0)
    {
        cout<<"How much you wanna bet ?       Money:"<<spelare.money<<endl;
        cin >>bet;
        if(bet > spelare.money)
            cin >> bet;
        while(spelare.money > 1
            spelare.money = spelare.money - bet;
            bank.spelaEnOmgang();
        }
    }

    return 0;


}


