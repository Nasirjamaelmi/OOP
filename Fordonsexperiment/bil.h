#ifndef BIL_H
#define BIL_H
#include "fordon.h"

class Bil : public Fordon
{
public:
    Bil();
    // Fordon interface
public:
    void pakallaUppmarksamhet() override;
    void indikeraKommandeSvang() override;
    void svangvanster() override;
    void svangHoger() override;
    void korFrammat(float antalKm) override;
    void SkrivUtInfo() override;

};

#endif // BIL_H
