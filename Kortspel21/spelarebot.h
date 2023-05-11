#ifndef SPELAREBOT_H
#define SPELAREBOT_H
#include "abstraktspelare.h"

class Spelarebot : public AbstraktSpelare
{
public:
    Spelarebot(int antalPartierAttSpela);
    // AbstraktSpelare interface
    bool villSpela() override;
    bool villHaKort() override;
    void tagEmotKort(const Kort &kort) override;
    void bankenTagKort(const Kort &Kort) const override;
    void kortlekenHarBlandats() override;
    void speletAvslutat(bool spelareVann) override;
    void vinst(int summa) override;
    void forlust(int summa) override;
    const Korthand &korthand() override;
    int money() override;
private:
    int m_antalPartierAttSpela;
    int m_antalSpeladeSpel;
    float m_totalvinst;
    //Korthand m_korthand;



};

#endif // SPELAREBOT_H
