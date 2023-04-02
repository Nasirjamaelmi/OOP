#include "minafunktioner.h"
#include <iostream>

using namespace std;


bool boolFranAnvandare(const std::string &txt)
{
    cout<<txt<<endl;
    string test;
    cin >> test;

    if (test == "ja"|| "Ja")
        return true;
    else if (test == "nej" || "Nej")
        return false;
    else return false;
}

