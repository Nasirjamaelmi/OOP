#ifndef GRAFIKYTA_H
#define GRAFIKYTA_H

#include "mushanterare.h"
#include "vy.h"
#include <QWidget>

class Grafikyta : public QWidget, public Vy
{
    Q_OBJECT

    Mushanterare *m_pMushanterare = nullptr;
    VyModell m_vymodell;


public:
   explicit  Grafikyta(QWidget *parent = nullptr);

    void pluggaInMushanterare(Mushanterare *pMushanterare);

    void visaVymodell(const VyModell& vymodell) override;

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;


private:
    void ritaVMFig(QPainter  &painter, const VMFig &fig);
};

#endif // GRAFIKYTA_H
