#include "spelarebot.h"


Spelarebot::Spelarebot(int antalPartierAttSpela)
{
    m_antalPartierAttSpela = antalPartierAttSpela;

}

bool Spelarebot::villSpela()
{
    if(m_antalPartierAttSpela == )
    {

    }


    return true;
}

bool Spelarebot::villHaKort()
{
    return false;
}

void Spelarebot::tagEmotKort(const Kort &kort)
{

}

void Spelarebot::bankenTagKort(const Kort &Kort) const
{

}

void Spelarebot::kortlekenHarBlandats()
{

}

void Spelarebot::speletAvslutat(bool spelareVann)
{

    m_antalSpeladeSpel++;
    if(spelareVann)
    {
       m_totalvinst
    }

}

void Spelarebot::vinst(int summa)
{

}

void Spelarebot::forlust(int summa)
{

}


const Korthand &Spelarebot::korthand()
{
    return m_hand;
}

void Spelarebot::rensaKorthand()
{
    
}

int Spelarebot::money()
{
    return m_Money;
}

int Spelarebot::insats()
{

}
