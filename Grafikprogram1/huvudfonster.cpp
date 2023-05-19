#include "huvudfonster.h"
#include "ui_huvudfonster.h"

Huvudfonster::Huvudfonster(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Huvudfonster)
{
    ui->setupUi(this);
    m_grafikapp.pluggaInVy(ui->m_pYtan);
    ui->m_pYtan->pluggaInMushanterare(&m_grafikapp);
    m_grafikapp.skapaEttAnsikte();
}

Huvudfonster::~Huvudfonster()
{
    delete ui;
}

