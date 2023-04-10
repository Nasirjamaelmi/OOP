#include "spelare.h"

Spelare::Spelare()
{


}

bool Spelare::villSpela()
{
    int res;
    std::cout<<"Want to play: press one to play and zero for no"<<std::endl;
    std::cin >> res;
    if(res == 1)
        return true;
    else return false;

}

bool Spelare::villHaKort()
{
    std::string Card{};
    std::cout<<"Want another card ?"<<std::endl;
    std::cin >> Card;
    if(Card == "Yes" || Card == "yes")
        return true;
    else
        return false;
}

void Spelare::tagEmotKort(const Kort &kort)
{
    m_hand.stoppaInKort(kort);
    std::cout<<"Player recived"<<kort.farg()<<" "<<kort.valor()<<std::endl;
}

void Spelare::bankenTagKort(const Kort &Kort) const
{
    std::cout<<"The bank gave you"<<Kort.farg()<<" "<<Kort.valor()<<std::endl;
}

void Spelare::kortlekenHarBlandats()
{
    std::cout<<"The Cards are being shuffled"<<std::endl;
}

void Spelare::speletAvslutat(bool spelareVann)
{
    std::cout<<"The winner is:"<<spelareVann<<std::endl;

}
const Korthand &Spelare::korthand()
{

}


