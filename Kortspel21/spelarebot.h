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
    void rensaKorthand() override;
    int money() override;
    int insats() override;
private:
    int m_antalPartierAttSpela = 0;
    int m_antalSpeladeSpel = 0;
    float m_totalvinst = 0;
    int m_insats = 0;
    //Korthand m_korthand;


};

#endif // SPELAREBOT_H
