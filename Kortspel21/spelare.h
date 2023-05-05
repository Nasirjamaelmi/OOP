#ifndef SPELARE_H
#define SPELARE_H

#include "abstraktspelare.h"
#include "kort.h"
#include "korthand.h"
class Spelare : public AbstraktSpelare
{
public:
    Spelare();
    int money = 100;
    bool villSpela() override;
    bool villHaKort() override;
    void tagEmotKort(const Kort &kort) override;
    void bankenTagKort(const Kort &Kort) const override;
    void kortlekenHarBlandats() override;
    void speletAvslutat(bool spelareVann) override;

    const Korthand& korthand() override;

private:
    Korthand m_hand;

};

#endif // SPELARE_H
