#ifndef DOKUMENT_H
#define DOKUMENT_H
#include "vy.h"

class Figur : public VMFig{
public:
    virtual ~Figur() {}
    Figur(Typ typ, int left, int top, int width, int height,
          VMFarg fyllfarg, int konturtjocklek=0, VMFarg konturfarg=VMFarg(0,0,0));
    virtual bool innehallerPunkt(int x,int y) = 0;
};

class Rectangel : public Figur {
public:
    Rectangel(int left, int top, int width, int height,
              VMFarg fyllfarg, int konturtjocklek=0, VMFarg kotnurfarg=VMFarg(0,0,0));
    bool innehallerPunkt(int x, int y)override;
};

class Ellips : public Figur
{
public:
    Ellips(int left, int top, int width, int height,
           VMFarg fyllfarg, int konturtjocklek=0, VMFarg konturfarg=VMFarg(0,0,0));
    bool innehallerPunkt(int x, int y) override;
};

class Dokument
{
public:
    std::vector<Figur*> m_pFigurer;
    ~Dokument();
    void rensaDokument();

    void skapaStandardansikte();
    Figur* pFigurFranPunkt(int x, int y);

};

#endif // DOKUMENT_H
