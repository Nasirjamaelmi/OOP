#include "komplex.h"
#include <cmath>
#include <string>
#include <cassert>
# define M_PI  3.14159265358979323846

Komplex::Komplex(float re, float im)
{
    m_re = re;
    m_im = im;
}

Komplex Komplex::fromAbsArg(float a, float grader)
{
    float i = cos(grader) * a;
    float x = sin(grader) * a;
    Komplex Abs (i,x);
    return Abs;
}

float Komplex::re() const
{
    return m_re;
}

float Komplex::im() const
{
   return m_im;
}

float Komplex::abs() const
{
   return sqrt(m_re+m_im);
}

float Komplex::argRadians() const
{
    return atan2(m_im,m_re);
}

float Komplex::argDegrees() const
{
    return argRadians() * M_PI;
}

Komplex Komplex::konjugat() const
{
    return Komplex(m_re, -m_im);
}

Komplex::operator std::string()
{
    std::string re = std::to_string(m_re);
    std::string im = std::to_string(m_im);
    std::string komplex = "("+re+"-"+im+"i).";
    return komplex;
}

const Komplex &Komplex::operator+=(const Komplex &h)
{
    *this = *this + h;
    return *this;
}

const Komplex &Komplex::operator-=(const Komplex &h)
{
    *this = *this - h;
    return *this;
}

const Komplex &Komplex::operator*=(const Komplex &h)
{
    *this = *this * h;
    return *this;
}

const Komplex &Komplex::operator/=(const Komplex &h)
{
    *this = *this / h;
    return *this;
}

Komplex operator "" _i(long double d)
{
    return Komplex (0,d);
}

Komplex operator "" _i(unsigned long long i)
{
    return Komplex(0,i);
}

Komplex operator+(const Komplex& v, const Komplex& h)
{
    return Komplex(v.re()+h.re() ,   v.im()+h.im());
}
Komplex operator-(const Komplex& v, const Komplex& h)
{
    return Komplex(v.re()-h.re()  ,   v.im()-h.im());
}
Komplex operator-(const Komplex& c)
{
    return Komplex(-c.re(),-c.im());
}
Komplex operator*(const Komplex& v, const Komplex& h)
{
    return Komplex(v.re()*h.re()-v.im()*h.im(),   v.re()*h.im()+v.im()*h.re());
}
Komplex operator/(const Komplex& v, const Komplex& h)
{
    Komplex taljare = v * h.konjugat();
    Komplex namnare = h * h.konjugat();
    assert( abs(namnare.im()) < 0.0001);
    return Komplex( taljare.re()/namnare.re(), taljare.im()/namnare.re());
}
std::ostream& operator<<(std::ostream& out, Komplex c)
{
    out << std::string(c);
    return out;
}



