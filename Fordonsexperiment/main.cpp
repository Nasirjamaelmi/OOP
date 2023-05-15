#include <iostream>
#include "bil.h"
#include "cykel.h"
#include "fordon.h"
using namespace std;
void akEnRunda(Fordon &fordon)
{
    cout << "åker en runda -------" <<endl;
    fordon.korFrammat(2);
    fordon.indikeraKommandeSvang();
    fordon.svangHoger();
    fordon.korFrammat(1.5);
    fordon.pakallaUppmarksamhet();
    fordon.korFrammat(0.5);
    fordon.svangvanster();
    fordon.korFrammat(0.1);
    fordon.SkrivUtInfo();
    cout <<"Avslutar åk. "<<endl;
}
void ingangTillTestaFordon()
{
    Cykel cykel;
    Bil Bil;
    Fordon& refTillCykel = cykel;
    akEnRunda(refTillCykel);
    akEnRunda(cykel);
    akEnRunda(Bil);
}
int main()
{
    cout << "Hello World!" << endl;
    ingangTillTestaFordon();
    return 0;
}
