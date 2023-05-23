#include <iostream>
#include <string>
#include <optional>
#include <vector>
using namespace std;


vector <string> nameList  = {"Newton","Euklides"};


bool hittadeFodelsearFranNamn(const string namn, int *pFodelsear)
{
    int year [] = {1642,-325,0};
    cout<<nameList.size()<<endl;
    for(int i=0; i<nameList.size(); i++)
    {
        if(namn == nameList[i])
        {
            *pFodelsear = year[i];
            return true;
        }

    }
    return false;
}
/*
void testfall()
{
    string euklides = "Euklides";
    int fodelsear = 0;
    bool hittadefodelsear = hittadeFodelsearFranNamn(euklides,&fodelsear);
    cout<<fodelsear<<endl;

}*/
void provaHittadeFodelsear()
{
    string hitta = "";
    int fodelsear = 0;
    cout<< "Skriv namn på personer, avsluta med ordet avsluta!"<<endl;
    cout<<"namn: ";
    cin >> hitta;
    while(hitta != "avsluta" && hitta != "Avsluta")
    {
        bool hittadefodelsear = hittadeFodelsearFranNamn(hitta,&fodelsear);
        if(hittadefodelsear)
        {
            cout<<hitta<< " föddes "<<fodelsear<<endl;

        }
        else
            cout<<hitta<<" är en okänd person."<<endl;

        cout<<"namn: ";
        cin >> hitta;

    }


}
std::optional<int> fodelsearFranNamn(const string namn)
{
    int year = 0;
    bool hittadefodelsear = hittadeFodelsearFranNamn(namn,&year);
    if(hittadefodelsear)
    {
        return year;
    }
    else return {};
}
void provaFodelsear()
{
    string hitta = "";
    optional <int> fodelsear = 0;
    cout<< "Skriv namn på personer, avsluta med ordet avsluta!"<<endl;
    cout<<"namn: ";
    cin >> hitta;
    while(hitta != "avsluta" && hitta != "Avsluta")
    {
        fodelsear=fodelsearFranNamn(hitta);
        if(fodelsear.has_value())
        {
            cout<<hitta<<" föddes "<<fodelsear.value()<<endl;
        }
        else
        cout<<hitta<<" är en okänd person."<<endl;

        cout<<"namn: ";
        cin>>hitta;
    }
}

void ingangTillFodelsear()
{
    provaHittadeFodelsear();
    //provaFodelsear();
}
