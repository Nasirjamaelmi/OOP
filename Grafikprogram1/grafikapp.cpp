#include "grafikapp.h"

Grafikapp::Grafikapp()
{

}

void Grafikapp::pluggaInVy(Vy *pVy)
{
    m_pVy = pVy;
}

void Grafikapp::skapaEttAnsikte()
{
    m_dokument.skapaStandardansikte();
    uppdateraVyn();
}
void Grafikapp::uppdateraVyn()
{
    VyModell vymodell;
    for(unsigned int i=0; i<m_dokument.m_pFigurer.size(); ++i)
    {
        vymodell.m_vector.push_back(*m_dokument.m_pFigurer[i]);
    }

        assert(m_pVy != nullptr);
            m_pVy->visaVymodell(vymodell);
}

void Grafikapp::musNed(int x, int y)
{

    m_pGrafik = this;

}

void Grafikapp::musUpp(int x, int y)
{

}

void Grafikapp::musFlytt(int x, int y)
{

}

