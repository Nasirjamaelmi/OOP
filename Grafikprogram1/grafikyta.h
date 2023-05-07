#ifndef GRAFIKYTA_H
#define GRAFIKYTA_H

#include <QWidget>

class Grafikyta : public QWidget
{
    Q_OBJECT
public:
    Grafikyta(QWidget *funkar);

    // QWidget interface
protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;
    void ritaAnsikte(QPainter &painter, QRect rektangle);
};

#endif // GRAFIKYTA_H
