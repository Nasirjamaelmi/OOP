#ifndef CYKEL_H
#define CYKEL_H
#include "fordon.h"

class Cykel : public Fordon
{
public:
    Cykel();

    // Fordon interface
public:
    void pakallaUppmarksamhet() override;
    void indikeraKommandeSvang() override;
    void svangvanster() override;
    void svangHoger() override;
    void korFrammat(float antalKm) override;
    void SkrivUtInfo() override;


};

#endif // CYKEL_H
