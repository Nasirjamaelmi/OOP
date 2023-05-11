#ifndef SPELARE_H
#define SPELARE_H

#include "abstraktspelare.h"
#include "kort.h"
#include "korthand.h"
class Spelare : public AbstraktSpelare
{
public:
    Spelare();

    bool villSpela() override;
    bool villHaKort() override;
    void tagEmotKort(const Kort &kort) override;
    void bankenTagKort(const Kort &Kort) const override;
    void kortlekenHarBlandats() override;
    void speletAvslutat(bool spelareVann) override;
    void vinst(int summa) override;
    void forlust(int summa) override;
    const Korthand& korthand() override;
    int money() override;

private:
    Korthand m_hand;
    int m_Money = 100;

};

#endif // SPELARE_H
