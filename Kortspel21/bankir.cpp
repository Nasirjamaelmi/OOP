#include "bankir.h"

Bankir::Bankir()
{
  m_pSpelare = nullptr;
}

void Bankir::registreraSpelare(AbstraktSpelare *pSpelare)
{
    m_pSpelare = pSpelare;
}

bool Bankir::harRegistreradeSpelare() const
{
    while(m_pSpelare != nullptr)
    {
        return true;
    }
    return false;
}

void Bankir::spelaEnOmgang()
{
    if(m_pSpelare == nullptr)
        return;

    if(m_kortlek.antalKort()<15)
    {
        m_kortlek.aterstallBlandadKort();
        (*m_pSpelare).kortlekenHarBlandats();
    }

    if((*m_pSpelare).villSpela())
    {
        Kort k = m_kortlek.utplockatKort();
        (*m_pSpelare).tagEmotKort(k);

        while ((*m_pSpelare).korthand().poang()<21 && (*m_pSpelare).villHaKort())
        {
            Kort k = m_kortlek.utplockatKort();
            (*m_pSpelare).tagEmotKort(k);
        }

        const int spelarpoang = (*m_pSpelare).korthand().poang();
        if(spelarpoang > 21)
            (*m_pSpelare).speletAvslutat(false);
        else if (spelarpoang == 21)
            (*m_pSpelare).speletAvslutat(true);
        else
        {
          Korthand bankhand;
          while (bankhand.poang() < 16)
          {
              Kort kort = m_kortlek.utplockatKort();
              bankhand.stoppaInKort(kort);
              (*m_pSpelare).bankenTagKort(kort);
          }
          int bankpoang = bankhand.poang();
          bool spelareVann = bankpoang > 21 || spelarpoang > bankpoang;
          (*m_pSpelare).speletAvslutat(spelareVann);
        }
    }
    else m_pSpelare = nullptr;
}
