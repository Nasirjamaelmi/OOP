#include <iostream>
#include <string>
#include <optional>
using namespace std;



std::optional<int> intFranString(const std::string str)
{
   const char *pC = &str[0];
   char *pSluttecken;

   long int tal = strtol(pC, &pSluttecken, 10);

   if(*pSluttecken == 0)
   {
       return tal;
   }
   else
   {

       return {};
   }
}

void provaHeltal()
{
    string tal = "";
    optional <int> Heltal = 0;
    cout<<"Skriv heltalssträngar, avsluta med ordet avsluta!"<<endl;
    cout<<"helstalssträng:";
    cin >> tal;
    while(tal != "avsluta" && tal != "Avsluta")
    {
        Heltal = intFranString(tal);
        if(Heltal.has_value())
        {
            cout<<"Heltal är"<<Heltal.value()<<endl;
        }
        else
        cout<<"ogiltig int"<<endl;

        cout<<"heltalsträng:";
        cin>>tal;
    }
}

void ingangTillHeltal()
{

    provaHeltal();
}

