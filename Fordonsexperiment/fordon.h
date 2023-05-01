#ifndef FORDON_H
#define FORDON_H


class Fordon
{
public:
    Fordon();
    virtual void pakallaUppmarksamhet();
    virtual void indikeraKommandeSvang();
    virtual void svangvanster();
    virtual void svangHoger();
    virtual void korFrammat(float antalKm);


};

#endif // FORDON_H
