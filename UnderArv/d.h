#ifndef D_H
#define D_H
#include "c.h"

class D : public C
{
public:
    double m_arrD[5];
    std::string classname() {return "D";}
};

#endif // D_H
