#include "trace.h"
#include <iostream>
#include <Qdebug>

using namespace std;

static Trace::Outputtype UTSKRIFTSMETOD = Trace::outpout_qdebug;
static int AKTUELLT_DJUP = 0;

void Trace::printline(const std::string& str)
{
    if (UTSKRIFTSMETOD == outpout_cout)
        cout << str << endl;
    else
        qDebug() << str.c_str();
}

string Trace::indentering()
{
    int depth = AKTUELLT_DJUP * 3;
    string space{};
    for(int i=0; i<depth; i++)
    {
       space += " ";
    }
    return space;
}

void Trace::message(const std::string& str)
{
    printline(indentering() + "trace:" + str);
}

Trace::Trace(const std::string& funktionsnamn)
{
    m_funktionsnamn = funktionsnamn;
    printline(indentering() + ">>" + __func__ + ">>");
    AKTUELLT_DJUP += 1;
}

Trace::Trace(const std::string& funktionsnamn, const::string& extra)
{
    m_funktionsnamn = funktionsnamn;
    printline(indentering() + ">>" + funktionsnamn + " " + extra + ">>");
}

Trace::~Trace()
{
    AKTUELLT_DJUP -= 1;
    printline(indentering() +"<<" + m_funktionsnamn +"<<");

}
