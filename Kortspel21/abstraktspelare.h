#ifndef ABSTRAKTSPELARE_H
#define ABSTRAKTSPELARE_H
#include "kort.h"
#include "korthand.h"
class AbstraktSpelare
{
public:
    AbstraktSpelare();
    virtual bool villSpela() = 0 ;
    virtual bool villHaKort() = 0;
    virtual void tagEmotKort(const Kort &kort) = 0;
    virtual void bankenTagKort(const Kort &Kort) const = 0;
    virtual void kortlekenHarBlandats() = 0;
    virtual void speletAvslutat(bool spelareVann) = 0;
    virtual void vinst(int summa) = 0;
    virtual void forlust(int summa) = 0;
    virtual const Korthand& korthand() = 0;
    virtual int money() = 0;

protected:
    Korthand m_hand;
};


#endif // ABSTRAKTSPELARE_H
