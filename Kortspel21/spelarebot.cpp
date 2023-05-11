#include "spelarebot.h"


Spelarebot::Spelarebot(int antalPartierAttSpela)
{

}

bool Spelarebot::villSpela()
{
    return false;
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

int Spelarebot::money()
{
    return 0;
}
