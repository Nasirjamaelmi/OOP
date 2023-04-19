#include "mystring.h"
#include <stdlib.h>

Mystring::~Mystring()
{
    m_cstr = nullptr;
    delete []m_cstr;

}

Mystring::Mystring()
{
    char tmp [] {"0"};
    m_cstr = tmp;
    m_size = 0;
}

Mystring::Mystring(const char *cstr)
{
      int size =0;
      if(cstr == nullptr)
      {
          char tmp [] {0};
          m_cstr = tmp;
          m_size = 0;
      }
      else
      {
         for(int i=0; *cstr!=0; i++)
         {
             m_cstr += cstr[i];
             size = i;
         }
         m_size = size;

      }
}

Mystring::Mystring(const Mystring &otherString)
{

        for(int i=0; i<otherString.m_size; i++)
        {
            m_cstr += otherString[i];
        }
        m_size = otherString.m_size;
}

Mystring::Mystring(Mystring &&stringToMove)
{
    m_cstr = stringToMove.m_cstr;
    m_size = stringToMove.m_size;
    stringToMove.m_cstr = nullptr;
}

const Mystring &Mystring::operator=(const Mystring &otherString)
{
    delete m_cstr;
    char tmp [] {0};
    tmp = otherString;

}

const Mystring &Mystring::operator=(Mystring&& stringToMove)
{

}
