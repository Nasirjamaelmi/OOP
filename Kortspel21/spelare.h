#ifndef SPELARE_H
#define SPELARE_H


#include "kort.h"
#include "korthand.h"
class Spelare
{
public:
    Spelare();
    bool villSpela();
    bool villHaKort();
    void tagEmotKort(const Kort &kort);
    void bankenTagKort(const Kort &Kort) const;
    void kortlekenHarBlandats();
    void speletAvslutat(bool spelareVann);

    const Korthand& korthand();

private:
    Korthand m_hand;
};

#endif // SPELARE_H
