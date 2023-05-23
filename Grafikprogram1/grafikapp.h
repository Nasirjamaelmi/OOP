#ifndef GRAFIKAPP_H
#define GRAFIKAPP_H
#include "dokument.h"
#include "mushanterare.h"
#include "vy.h"
#include "cassert"
#include "grafikyta.h"

class Grafikapp : public Mushanterare
{
    Vy *m_pVy = nullptr;
    Dokument m_dokument;

public:
    Grafikapp();

    void pluggaInVy(Vy *pVy);

    void skapaEttAnsikte();



    // Mushanterare interface
    void musNed(int x, int y) override;
    void musUpp(int x, int y) override;
    void musFlytt(int x, int y) override;
private:
    void uppdateraVyn();
    Grafikyta *m_pGrafik = nullptr;
    Figur* m_pKlickadFigur = nullptr;
};

#endif // GRAFIKAPP_H
