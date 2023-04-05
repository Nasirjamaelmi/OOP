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
    int temp = 0;

    for(int i=0; i < m_korten.size(); i++)
    {
        if(sum + m_korten[i].valor() > 22)
        {
            break;
        }
        else if(m_korten[i].valor() == 1)
        {

            std::cout<<"One or fourteen"<<std::endl;
            std::cin >> temp;
            sum += temp;
        }
        else{
             sum+=m_korten[i].valor();
        }
    }

  return sum;

}
