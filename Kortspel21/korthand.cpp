#include "korthand.h"
#include "kort.h"

Korthand::Korthand()
{

}

void Korthand::rensa()
{
    m_korten.clear();
}

int Korthand::antalkort() const
{
    return m_korten.size();
}

Kort Korthand::kort(int nr) const
{
    return m_korten[nr];
}

void Korthand::stoppaInKort(const Kort &kort)
{
    m_korten.push_back(kort);
}

int Korthand::poang() const
{
   int sum = 0;
   for(int i=0; i< m_korten.size(); i++)
   {
       if(m_korten[i].valor() == 1 && sum > 7)
       {
            sum += 1;
       }
       if(m_korten[i].valor() == 1 && sum <= 7)
       {
           sum += 14;
       }
       else if(m_korten[i].valor() != 1)
       {
           sum += m_korten[i].valor();
       }
   }
       return sum;
}
