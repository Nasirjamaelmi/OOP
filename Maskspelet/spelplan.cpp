#include "spelplan.h"
#include <QTimer>
#include <QPainter>
#include <QKeyEvent>
#include <QPaintEvent>
#include <chrono>
#include <thread>
#include <cassert>

using namespace std;

Spelplan::Spelplan(QWidget *parent) : QWidget{parent}
{
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Spelplan::uppdateraMasken);
    timer->start(60);

    setFocus();
    m_rkHuvud = RK(50,50);
    m_rkRiktning = RK(0,0);
    srand(time(0));
    newFood(true);

}

void Spelplan::newFood(bool eaten)
{
    if(eaten == true)
    {
        int randK = rand() % (rect().width()/m_cellstorlek) + 1;
        int randR = rand() % (rect().height()/m_cellstorlek) + 1;
        m_mat = RK(randR,randK);

         m_eaten = false;
    }
}

void Spelplan::uppdateraMasken()
{

    if(m_gameOver == true)                  // gameover
    {

        return;

    }

    if(m_eaten)
    {
        newFood(m_eaten);
    }

    if(m_rkHuvud.m_r == m_mat.m_r && m_rkHuvud.m_k == m_mat.m_k)
    {
        for(int i = 0; i < 5; i++)
        m_masken.push_back(m_mat);
        m_eaten = true;

    }

    m_rkHuvud.m_r += m_rkRiktning.m_r;   ///riktningen för huvudet
    m_rkHuvud.m_k += m_rkRiktning.m_k;



    if(m_rkHuvud.m_r >= 0 && m_rkHuvud.m_r <= (rect().height()/m_cellstorlek) && m_rkHuvud.m_k == 0)
    {
        m_rkHuvud.m_k = (rect().width()/m_cellstorlek);
    }

    else if(m_rkHuvud.m_r >= 0 && m_rkHuvud.m_r <= (rect().height()/m_cellstorlek) && m_rkHuvud.m_k == (rect().width()/m_cellstorlek))
    {
        m_rkHuvud.m_k = 0;
    }


    else if(m_rkHuvud.m_k >= 0 && m_rkHuvud.m_k <= (rect().width()/m_cellstorlek) && m_rkHuvud.m_r == 0)
    {
        m_rkHuvud.m_r = (rect().height()/m_cellstorlek);
    }

    else if(m_rkHuvud.m_k >= 0 && m_rkHuvud.m_k <= (rect().width()/m_cellstorlek) && m_rkHuvud.m_r == (rect().height()/m_cellstorlek))
    {
        m_rkHuvud.m_r = 0;
    }


    for(unsigned int i=0; i<m_masken.size(); i++)      /// loppar för vilkoret
    {

        RK rk = m_masken[i];
        if(m_rkHuvud.m_r == rk.m_r && m_rkHuvud.m_k == rk.m_k  && (m_rkRiktning.m_r != 0 || m_rkRiktning.m_k != 0))
        {
            m_gameOver = true;

        }

    }


    m_masken.push_front(m_rkHuvud);           ///stoppar in huvudet och tar bort ett om masken är större än 100
    if(m_masken.size())
        m_masken.pop_back();
    update();
}

void Spelplan::keyPressEvent(QKeyEvent *event)
{
    int k = event->key();

    if(k==Qt::Key_Down) m_rkRiktning = RK(1,0);
    if(k==Qt::Key_Up) m_rkRiktning = RK(-1,0);
    if(k==Qt::Key_Left) m_rkRiktning = RK(0,-1);
    if(k==Qt::Key_Right) m_rkRiktning = RK(0,1);


}

void Spelplan::paintEvent(QPaintEvent *event)
{


    QPainter painter(this);
    painter.fillRect(rect(),Qt::white);
    painter.fillRect(m_rkHuvud.m_k*m_cellstorlek,
                     m_rkHuvud.m_r*m_cellstorlek,
                     m_cellstorlek,
                     m_cellstorlek,
                     Qt::blue);

    if(!m_eaten)
    {
         painter.fillRect(m_mat.m_k*m_cellstorlek,
                     m_mat.m_r*m_cellstorlek,
                     m_cellstorlek,
                     m_cellstorlek,
                     Qt::red);
    }


    if(m_gameOver == true)
    {
        for(unsigned int i=0; i<m_masken.size(); i++)
        {

            painter.drawText(QPoint(rect().center().x(),rect().center().y()*0.5), "Game Over");
            RK rk = m_masken[i];
            painter.fillRect(rk.m_k*m_cellstorlek,
                             rk.m_r*m_cellstorlek,
                             m_cellstorlek,
                             m_cellstorlek,
                             Qt::red);

            painter.fillRect(m_rkHuvud.m_k*m_cellstorlek,
                             m_rkHuvud.m_r*m_cellstorlek,
                             m_cellstorlek,
                             m_cellstorlek,
                             Qt::red);

        }
    }
    else
        for(unsigned int i=0; i<m_masken.size(); i++)
        {
            RK rk = m_masken[i];
            painter.fillRect(rk.m_k*m_cellstorlek,
                             rk.m_r*m_cellstorlek,
                             m_cellstorlek,
                             m_cellstorlek,
                             Qt::blue);
        }

}
