#include "dokument.h"


Figur::Figur(Typ typ, int left, int top, int width, int height, VMFarg fyllfarg, int konturtjocklek, VMFarg konturfarg)
    : VMFig(typ,left,top,width,height,fyllfarg,konturtjocklek,konturfarg)
{

}

Rectangel::Rectangel(int left, int top, int width, int height, VMFarg fyllfarg, int konturtjocklek, VMFarg kotnurfarg)
    : Figur(rektangel,left,top,width,height,fyllfarg,konturtjocklek,m_konturfarg)
{

}

Ellips::Ellips(int left, int top, int width, int height, VMFarg fyllfarg, int konturtjocklek, VMFarg konturfarg)
    : Figur(ellips,left,top,width,height,fyllfarg,konturtjocklek,konturfarg)
{

}
float square(float x)
{
    return x*x;
}

bool Rectangel::innehallerPunkt(int x, int y)
{
       const float abs = square(m_top) + square(m_height);
       const float abscord = square(x) + square(y);
       return (abs == abscord);
}



bool Ellips::innehallerPunkt(int x, int y)
{
    const float cy = m_top + m_height/2;
    const float cx = m_left + m_width /2;
    const float v = square((x-cx)/m_width) + square((y-cy)/m_height);
    return v <= 1.0/4;
}

Dokument::~Dokument()
{

}

void Dokument::rensaDokument()
{
    for (unsigned int i = 0; i< m_pFigurer.size(); ++i)
    {
        delete m_pFigurer[i];

    }
        m_pFigurer.clear();
}

void Dokument::skapaStandardansikte()
{

        int headWidth = 200;
        int headHeight = 200;
        int xHeadCenter = 150;
        int yHeadCenter = 150;

        int xLeftEyeCenter =  75;
        int xRightEyeCenter = 75;
        int eyeDiameter = 50 ;


        VMFarg vit(255,255,255);
        VMFarg svart(0,0,0);
        VMFarg gul(255,255,0);
        VMFarg rod(255,0,0);

        Figur *pHead = new Ellips(xHeadCenter-headWidth/2,
                                  yHeadCenter - headHeight/2,
                                  headWidth,
                                  headHeight,
                                  gul,
                                  2,
                                  svart);

        Figur *pLeftEye = new Ellips(xLeftEyeCenter- eyeDiameter/2,
                                     xLeftEyeCenter,
                                     xLeftEyeCenter,
                                     xLeftEyeCenter,
                                     vit,
                                     5,
                                     svart);

        Figur *pRightEye = new Ellips(xRightEyeCenter- eyeDiameter/2,
                                     xRightEyeCenter,
                                     xRightEyeCenter,
                                     xRightEyeCenter,
                                     vit,
                                     1,
                                     svart);

        rensaDokument();

        m_pFigurer.push_back(pHead);
        m_pFigurer.push_back(pLeftEye);
        m_pFigurer.push_back(pRightEye);







}

Figur *Dokument::pFigurFranPunkt(int x, int y)
{

    for(int i =m_pFigurer.size() -1; 0<=i; --i)
        if(m_pFigurer[i]->innehallerPunkt(x,y))
            return m_pFigurer[i];
        return nullptr;

}
