#include "fordon.h"
#include <iostream>

Fordon::Fordon(int antalhjul)
{
    m_antalhjul = antalhjul;
}

void Fordon::SkrivUtInfo()
{
    std::cout << "Ett fordon med " << m_antalhjul << " hjul." << std::endl;
}
int getprivateint(const Fordon& obj)
{
  return obj.m_antalhjul;
}

