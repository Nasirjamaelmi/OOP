#include "kort.h"

Kort::Kort(Farg farg, int valor)
{
    m_farg = farg;
    m_valor = valor;
}

Kort::Farg Kort::farg() const
{
     return m_farg;
}

int Kort::valor() const
{
    int set = 10;
    if (m_valor == 12  || 13 || 14)
        return set;
    else
    return m_valor;
}

std::string Kort::text() const
{
    static const char* valornamn[14]{"finnesej","ess","tva","tre","fyra","fem","sex","sju","atta","nio","tio","knekt","dam","kung"};
    return fargstrang() + " " + valornamn[m_valor];
}

std::string Kort::fargstrang() const
{
    static const char* valorfarg[4]{"klover","ruter","hjarter","spader"};
    return valorfarg[m_farg];

}
