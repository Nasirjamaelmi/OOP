#include "cykel.h"
#include <iostream>
Cykel::Cykel() : Fordon(2)
{

}

void Cykel::pakallaUppmarksamhet()
{
  std::cout<<"pling pling"<<std::endl;
}

void Cykel::indikeraKommandeSvang()
{
  std::cout<<"Sträcker ut arm"<<std::endl;
}

void Cykel::svangvanster()
{
  std::cout<<"vickar åt vänster och vrider styrstången"<<std::endl;
}

void Cykel::svangHoger()
{
  std::cout<<"vickar åt höger och vrider styrstången"<<std::endl;
}

void Cykel::korFrammat(float antalKm)
{
    std::cout<<"Trampar vidare "<<antalKm<<" Km"<<std::endl;
}

void Cykel::SkrivUtInfo()
{
    std::cout << "Fordonet är en cykel."<<std::endl;
    Fordon::SkrivUtInfo();

}
