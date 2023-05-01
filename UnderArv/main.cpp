#include <iostream>
#include "cassert"

using namespace std;

class C
{
public:
    double m_arrC[10];
    std::string classname() {return "C";};
};

class D : public C
{
public:
    double m_arrD[5];
    std::string classname() {return "D";}
};
class VC
{
    public:
    double m_arrVC[10];
    virtual std::string classname() { return "VC"; }
    virtual std::string f2();
    virtual std::string f3();
};
class VD : public VC
{
    public:
    double m_arrVD[10];
    std::string classname() override { return "VD"; }
    virtual int f4();
    virtual int f5();
};


void skrivStorlekar1()
{
    C c1,c2;
    D d1,d2;

    assert(sizeof(c1)==sizeof(c2) && sizeof(d1) == sizeof(d2));
    cout << "c1 och c2 rymmer " <<sizeof(c1)
         << "oktetter (Byte), emedan d1 och d2 rymmer "
         <<sizeof(d1) <<"."<<endl;
}


void skrivKlassnamn(VC& vc)
{
    cout << vc.classname() << endl;
}

int main()
{
    cout << "Hello World!" << endl;
    //skrivStorlekar1();
    //skrivUtOffset1();
    VD d;
    skrivKlassnamn(d);
    return 0;
}
