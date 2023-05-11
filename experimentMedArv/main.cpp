#include <iostream>
#include <typeinfo>
#include <iostream>

using namespace std;

class Bas
{
public:
    void iv() { cout << "Bas iv() anropades. "<<endl;}
    virtual void v() {cout <<"Base v() anropades. "<<endl;}
    virtual ~Bas() {cout<<"Bas destruktor"<<endl;}
};

class Sub : public Bas
{
public:
    void iv() { cout << "Sub iv() anropades. "<<endl;}
    virtual void v() {cout <<"Sub v() anropades. "<<endl;}
    virtual ~Sub() {cout<<"Sub destruktor"<<endl;}
};

void experimentMedVirtual()
{
  cout <<endl<< "Testa1, anrop via sub"<<endl;
  Sub sub;
  sub.iv();  // får ut sub
  sub.v();   // får ut sub

  cout <<endl<< "Testa2, anrop via bas1"<<endl;
  Bas bas1 = sub;
  bas1.iv();  // får ut bas
  bas1.v();   // får ut bas

  cout <<endl<< "Testa3, anrop via bas-pekare"<<endl;
  Bas *pB = &sub;
  pB->iv(); // får ut bas
  pB->v(); // får ut sub
  (*pB).iv(); // får ut bas
  (*pB).v();  // får ut sub


  cout <<endl<< "Testa4, anrop via basreferens"<<endl;
  Bas &bas2 = sub;
  bas2.iv(); // får ut bas
  bas2.v();  // får ut sub
  cout << endl <<"testaVirtual avslutas" <<endl;

}
void experimentMedDestruktor()
{
    cout <<endl << "Testar destruktor" <<endl;

    Bas* pBase = new Sub;

    delete pBase;
}
void provaDownCasting(Bas *pBas)
{
    Sub *pSub = dynamic_cast<Sub*>(pBas);
    if (pSub !=nullptr)
        cout <<"Yes, Vi har fått en pekare till ett subklassobjekt!" <<endl;
    else cout <<"Nope, typomvandlingen gick ej"<<endl;
}

void experimentMedDynamicDownCasting()
{
    cout <<"experiment med dynamic down casting" <<endl;
    Bas *pX = new Bas; // allokerar minne för en bas
    Bas *pY = new Sub; // allokerar minne för sub gör att vi kan tilldela all information correct

    provaDownCasting( pX );
    provaDownCasting( pY );

    delete pX;
    delete pY;

}

int main()
{
    cout << "Hello World!" << endl;
    //experimentMedVirtual();
    //experimentMedDestruktor();
    //experimentMedDynamicDownCasting();
    return 0;
}
