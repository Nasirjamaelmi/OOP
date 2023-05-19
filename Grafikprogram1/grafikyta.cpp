#include "grafikyta.h"
#include <QPaintEvent>
#include <QPainter>
#include <QColor>
#include <Qpen>
#include <QRect>
#include <QPoint>

Grafikyta::Grafikyta(QWidget *funkar)
{

}

void Grafikyta::visaVymodell(const VyModell &vymodell)
{
    m_vymodell = vymodell;
    update();
}


void Grafikyta::pluggaInMushanterare(Mushanterare *pMushanterare)
{
   m_pMushanterare = pMushanterare;
}


void Grafikyta::mousePressEvent(QMouseEvent *event)
{
    m_pMushanterare->musNed(event->pos().x(), event->pos().y());
}
void Grafikyta::mouseReleaseEvent(QMouseEvent *event)
{
    m_pMushanterare->musUpp(event->pos().x(),event->pos().y());
}

void Grafikyta::mouseMoveEvent(QMouseEvent *event)
{
    m_pMushanterare->musFlytt(event->pos().x(),event->pos().y());
}

QColor qcolor(const VMFarg& farg)
{
    return QColor(farg.m_r,farg.m_g,farg.m_b,farg.m_opacity);
}
void Grafikyta::ritaVMFig(QPainter &painter, const VMFig &fig)
{
    QBrush brush(qcolor(fig.m_fyllfarg));
    QPen pen(qcolor(fig.m_konturfarg), fig.m_konturtjocklek);
    QRect rect(fig.m_left,fig.m_top,fig.m_width,fig.m_height);

    painter.setBrush(brush);
    painter.setPen(pen);

    if(fig.m_typ == VMFig::ellips)
        painter.drawEllipse(rect);
    else if(fig.m_typ==VMFig::rektangel)
        painter.drawRect(rect);
    else assert(false);
}
/*void Grafikyta::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    QColor farg1 = Qt::red;
    QColor farg2 = QColor( rand()%256, rand()%256, rand()%256);
    QColor farg3 = QColor(255,255,0, 200);

    painter.fillRect(rect(), Qt::white);

    QRect litenKvadrat(0,20,100,100);
    painter.fillRect(litenKvadrat, farg1);

    QPen pen(Qt::blue, 5);
    painter.setPen(pen);
    painter.setBrush(farg2);
    painter.drawEllipse(200,10,50,300);

    painter.setPen(Qt::black);
    painter.setBrush(farg3);
    painter.drawEllipse(50,50,300,100);
}*/

/*void Grafikyta::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    ritaAnsikte(painter,rect());
}*/

void Grafikyta::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(rect(),Qt::white);

    for(auto &fig : m_vymodell.m_vector)
    {
        ritaVMFig(painter,fig);
    }
}



