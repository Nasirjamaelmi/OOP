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
    int check = 0;


    for(int i=0; i < antalkort(); i++)
    {

        if (m_korten[i].valor() == 1)
        {
            check++;
            sum += 14;

        }
        else
        sum += m_korten[i].valor();
    }
    while(sum > 21 && check !=0)
    {
        sum -= 13;
        check--;
    }
    if(antalkort() == 5 && sum < 21)
        return 21;
    return sum;

}
