#include "bankir.h"
using namespace  std;

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

        string question {};
        int bet =0;
        cout<<"How much you wanna bet from 1 to your maxmoney?       Money:"<<m_pSpelare->money()<<endl;
        cin >> bet;
        while(cin.fail() || bet > m_pSpelare->money())
        {
            cout<<"Bet sum wrong, write again under maxmoney"<<endl;
            cin >> bet;

        }
        Kort k = m_kortlek.utplockatKort();
        (*m_pSpelare).tagEmotKort(k);
        cout<<"Do you wanna double, Yes or No"<<endl;
        cin >> question;
        if(question == "Yes")
        {
            bet += bet;
        }
         (*m_pSpelare).forlust(bet);

        while ((*m_pSpelare).korthand().poang()<21 && (*m_pSpelare).villHaKort())
        {
            Kort k = m_kortlek.utplockatKort();
            (*m_pSpelare).tagEmotKort(k);
        }

        const int spelarpoang = (*m_pSpelare).korthand().poang();
        if(spelarpoang > 21)
        {
            (*m_pSpelare).speletAvslutat(false);
            if(m_pSpelare->money() <= 0)
            {

                m_pSpelare = nullptr;
            }

        }
        else if (spelarpoang == 21)
        {
            (*m_pSpelare).speletAvslutat(true);
            (*m_pSpelare).vinst(bet);
        }

        // spelarenskorthand ska ha 5 kort och poängen ska understiga 21;
        else if (spelarpoang < 21 && m_pSpelare->korthand().antalkort() == 5)
        {
            (*m_pSpelare).speletAvslutat(true);
            (*m_pSpelare).vinst(bet);

        }
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
          if(spelareVann)
          {
            (*m_pSpelare).vinst(bet);
          }

        }

    }
    else m_pSpelare = nullptr;
}
