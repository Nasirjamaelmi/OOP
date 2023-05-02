#include "bil.h"
#include <iostream>

Bil::Bil() : Fordon(4)
{

}

void Bil::pakallaUppmarksamhet()
{
    std::cout<<"tut tut"<<std::endl;
}

void Bil::indikeraKommandeSvang()
{
        std::cout<<"Blinkar"<<std::endl;
}

void Bil::svangvanster()
{
    std::cout<<"Vrider ratten åt vänster"<<std::endl;
}

void Bil::svangHoger()
{
    std::cout<<"Vrider ratten åt höger"<<std::endl;
}

void Bil::korFrammat(float antalKm)
{
  std::cout<<"Gasar på "<<antalKm<<" Km"<<std::endl;
}
void Bil::SkrivUtInfo()
{
    std::cout << "Fordonet är en Bil."<<std::endl;
    Fordon::SkrivUtInfo();

}
