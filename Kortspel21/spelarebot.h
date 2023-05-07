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
    const Korthand &korthand() override;
private:
    int m_antalPartierAttSpela;
    int m_antalSpeladeSpel;
    float m_totalvinst;


    // AbstraktSpelare interface


};

#endif // SPELAREBOT_H
