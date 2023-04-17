#include "spelare.h"

Spelare::Spelare()
{


}

bool Spelare::villSpela()
{
    std::string want{};
    std::cout<<"vill du spela, ja eller nej"<<std::endl;
    std::cin >> want;
    if(want == "Ja" || "ja")
        return true;
    else return false;

}

bool Spelare::villHaKort()
{
    std::string Card{};
    std::cout<<"vill du ha ett kort ?"<<std::endl;
    std::cin >> Card;
    if(Card == "Ja" || Card == "ja")
        return true;
    else
        return false;
}

void Spelare::tagEmotKort(const Kort &kort)
{
    m_hand.stoppaInKort(kort);
    std::cout<<"Spelare fick "<<kort.text()<<std::endl;
}

void Spelare::bankenTagKort(const Kort &Kort) const
{
    std::cout<<"Bankir gav "<<Kort.text()<<std::endl;
}

void Spelare::kortlekenHarBlandats()
{
    std::cout<<"Kortlekten blandas"<<std::endl;
}

void Spelare::speletAvslutat(bool spelareVann)
{
    std::cout<<"Vinnaren är :"<<spelareVann<<std::endl;

}
const Korthand &Spelare::korthand()
{
    return m_hand;
}


