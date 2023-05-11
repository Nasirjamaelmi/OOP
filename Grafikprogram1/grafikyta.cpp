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

void Grafikyta::mousePressEvent(QMouseEvent *event)
{

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

void Grafikyta::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    ritaAnsikte(painter,rect());
}

void Grafikyta::ritaAnsikte(QPainter &painter, QRect rektangle)
{
    painter.setPen(Qt::black);
    painter.setBrush(Qt::yellow);

    painter.drawEllipse(rektangle);

    int yEyeCenter = rektangle.center().y();
    int xEyeCenter = rektangle.center().x();
    int xLeftEyeCenter = rektangle.width() * 0.3;
    int xRightEyeCenter = rektangle.width() * 0.7;
    int eyewidthandheight = rektangle.width() * 0.1;

    int smalleyes = rektangle.width() * 0.05;



    painter.setBrush(Qt::red);
    painter.drawEllipse(xEyeCenter * 0.77, yEyeCenter * 1.33,eyewidthandheight * 3,eyewidthandheight);

    painter.setBrush(Qt::white);
    painter.drawEllipse(xLeftEyeCenter,yEyeCenter * 0.5,eyewidthandheight,eyewidthandheight);
    painter.drawEllipse(xRightEyeCenter,yEyeCenter * 0.5,eyewidthandheight,eyewidthandheight);

    painter.setBrush(Qt::black);
    painter.drawEllipse(xLeftEyeCenter + eyewidthandheight * 0.25, yEyeCenter * 0.5 + eyewidthandheight * 0.33, smalleyes, smalleyes);
    painter.drawEllipse(xRightEyeCenter + eyewidthandheight * 0.25,yEyeCenter * 0.5 + eyewidthandheight * 0.33,  smalleyes, smalleyes);



}
