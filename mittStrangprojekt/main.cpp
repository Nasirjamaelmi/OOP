#include <iostream>
#include <cassert>
#include "mystring.h"
#include <nastrace.h>

USING_COUT_TRACE;

using namespace std;

Mystring mittNamn(){
    return "Nasir";
}
void anropByValue(Mystring str)
{
    cout << str << endl;
}
void anropByRef(const Mystring &str)
{
    cout << str << endl;
}
bool arVersaler(const Mystring &str)
{
    for (int i=0; i<str.size(); ++i)
    if (str[i] != toupper(str[i]))
    return false;
    return true;
}
void konverteraTillVersaler(Mystring &str)
{
    for (int i=0; i<str.size(); ++i)
    str[i] = toupper(str[i]);
}

Mystring versalstrang(const Mystring &str)
{
    Mystring kopia = str;
    konverteraTillVersaler( kopia );
    return kopia;
}
void stringQuizz()
{
    traceme
    Mystring s1("Hello");
    Mystring s2("hej");
    s1 += s2;

}



void testaStrang()
{
    Mystring str1;
    assert( str1 == "");
    Mystring str2 = "Hej";
    assert( str2.size() == 3 );
    str2 = "Sol";
    assert( str2.size() == 3 );
    assert( str2[1] == 'o');
    str2 += "sken!";
    assert( str2.size() == 8 );
    assert( str2 == "Solsken!");
    Mystring str3 = mittNamn();
    anropByValue(str3);
    anropByRef(str3);
    assert( !arVersaler(str2) );
    konverteraTillVersaler(str2);
    assert( arVersaler(str2) );
    Mystring str4 = versalstrang( "hej" );
    assert( arVersaler(str4) );
    cout << "testaStrang lyckades" << endl;
}


int main()
{

    stringQuizz();
    return 0;
}
