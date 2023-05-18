#ifndef VY_H
#define VY_H

#include <vector>

struct VMFarg{
    VMFarg(unsigned char r,unsigned char g,unsigned char b,unsigned char o =255)
        :m_r(r), m_g(g),m_b(b),m_opacity(o){}
    unsigned char m_r,m_g,m_b,m_opacity;
};

struct VMFig{
    enum Typ{ rektangel, ellips};

    Typ m_typ;
    int m_left,m_top,m_width,m_height;
    VMFarg m_fyllfarg;
    int m_konturtjocklek;
    VMFarg m_konturfarg;

    VMFig(Typ typ, int left, int top, int width, int height,
          VMFarg fyllfarg,int konturtjocklek=0, VMFarg konturfarg=VMFarg(0,0,0))
        : m_typ(typ),
          m_left(left),m_top(top),m_width(width), m_height(height),
          m_fyllfarg(fyllfarg), m_konturtjocklek(konturtjocklek), m_konturfarg(konturfarg) {}
};

struct VyModell {
    std::vector<VMFig> m_vector;
};

class Vy{
public:
    virtual void visaVymodell(const VyModell &vymodell) = 0;
};

#endif // VY_H
