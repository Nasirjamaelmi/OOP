#include <intervall.h>
#include <iostream>

using namespace std;
void provaIntervall()
{
    cout <<"Loopar några varv"<<endl;

    Intervall talomrade(10,20);
    for(Intervall::iterator ite = talomrade.begin(); ite!=talomrade.end(); ++ite)
        cout <<*ite<<endl;

    cout <<"Loopar igen"<<endl;

    for(Intervall::iterator ite = begin(talomrade); ite!=end(talomrade); ++ite)
        cout <<*ite<<endl;

    cout <<"Loopar lite mera"<<endl;

    for(int tal : talomrade)
        cout <<tal <<endl;


    cout <<"Loopar ännu lite mera" <<endl;

    for(int tal: Intervall(10,20))
        cout <<tal<<endl;
}

