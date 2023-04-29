#include "mystring.h"
#include "nastrace.h"
#include <stdlib.h>

Mystring::~Mystring()
{
    traceme;
    delete []m_cstr;
    m_cstr = nullptr;
}
Mystring::Mystring()
{
    traceme;
    char *p_string = new char[1];
    *p_string = 0;
    m_cstr = p_string;
    m_size = 0;
}

Mystring::Mystring(const char *cstr)
{
    tracemex("typkonv");
    int size = 0;
    if (cstr == nullptr)
    {
        char *p_string = new char[1];
        *p_string = 0;
        m_cstr = p_string;
        m_size = 0;
    }
    else
    {
        for(int i=0; cstr[i] !=0; i++)
            size++;


        char *p_string = new char[size+1];
        for (int x = 0; x <= size; ++x)
        {
           p_string[x] = cstr[x];
        }
        m_cstr = p_string;
        m_size = size;
    }
}

Mystring::Mystring(const Mystring &otherString) : Mystring(otherString.m_cstr)
{
   tracemex("copy");
}

Mystring::Mystring(Mystring &&stringToMove)
{
    tracemex("move-tilldelning");
    m_size = stringToMove.m_size;
    m_cstr = stringToMove.m_cstr;
    stringToMove.m_cstr = nullptr;
}

const Mystring &Mystring::operator=(const Mystring &otherString)
{
    tracemex(" vanlig tilldelning");
    if(this == &otherString)
        return *this;

    delete [] m_cstr;

    m_size = otherString.m_size;

    m_cstr = new char[m_size + 1];

    for(int i = 0; i <= otherString.m_size; i++)
        m_cstr[i] = otherString[i];

    m_cstr[m_size] = 0;

    return *this;
}

const Mystring &Mystring::operator=(Mystring&& stringToMove)
{
    tracemex("move-tilldelning")    ;
    delete [] m_cstr;
    m_size = stringToMove.m_size;
    m_cstr = new char[m_size+1];
    m_cstr = stringToMove.m_cstr;
    stringToMove.m_cstr = nullptr;
    return *this;
}

const Mystring& Mystring::operator+=(const Mystring& otherString)
{
    tracemex("+= operator");
    int totSum = m_size + otherString.m_size + 1;
    char *p_string = new char [totSum];
    for(int i=0; m_cstr[i] != 0; i++)
    {
        p_string[i] = m_cstr[i];
    }
    for(int x = 0; otherString.m_cstr[x]!=0; x++)
    {
        p_string[m_size+x] = otherString.m_cstr[x];
    }

    delete [] m_cstr;
    m_size = m_size + otherString.m_size;
    m_cstr = p_string;
    p_string[m_size] = 0;
    return *this;
}

bool Mystring::operator==(const Mystring& otherString) const
{
    tracemex("== operator");
    if(m_size != otherString.m_size)
        return false;

    for(int i=0; i < m_size; i++)
    {
        if(m_cstr[i] != otherString.m_cstr[i])
        {
            return false;
        }
    }
    return true;
}

char& Mystring::operator[](int ix)
{
    tracemex("open[] ej const ");
    return m_cstr[ix];
}

char Mystring::operator[](int ix) const
{
    tracemex("open[]  const ");
    return m_cstr[ix];
}

int Mystring::size() const
{
        tracemex("storlek");
       return m_size;
}

const char *Mystring::c_str() const
{
        tracemex("skriv c-sträng");
        return m_cstr;
}


bool operator !=(const Mystring& a, const Mystring& b)
{
        traceme;
        return !(a == b);
}


std::ostream& operator<<(std::ostream& out, const Mystring& str)
{
      tracemex("std operator");
      out << str.c_str();
      return out;
}
