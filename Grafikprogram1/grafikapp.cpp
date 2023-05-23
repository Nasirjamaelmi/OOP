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

    m_pKlickadFigur = m_dokument.pFigurFranPunkt(x,y);

}

void Grafikapp::musUpp(int x, int y)
{
   m_pKlickadFigur = nullptr;
}

void Grafikapp::musFlytt(int x, int y)
{
   if(m_pKlickadFigur != nullptr)
   {
       m_pKlickadFigur->m_left=x;
       m_pKlickadFigur->m_top=y;
       uppdateraVyn();
   }
}

