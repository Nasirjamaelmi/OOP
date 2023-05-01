#ifndef FORDON_H
#define FORDON_H


class Fordon
{
public:
    Fordon(int antalhjul);
    virtual void pakallaUppmarksamhet() = 0;
    virtual void indikeraKommandeSvang() = 0;
    virtual void svangvanster() = 0;
    virtual void svangHoger() = 0;
    virtual void korFrammat(float antalKm) = 0;
    virtual void SkrivUtInfo();
    friend int getprivateint(const Fordon& obj);

protected:
    int m_antalhjul;
};

#endif // FORDON_H
