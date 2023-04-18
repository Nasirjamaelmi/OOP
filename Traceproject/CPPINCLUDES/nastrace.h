#ifndef TRACE_H
#define TRACE_H
#define traceme Trace traceObject( __func__ );
#define tracemex( extra ) Trace traceObject( __func__, extra );
#define traceMsg( meddelande ) traceObject.message( meddelande );
#include <string>
#include <iostream>
#include <Qdebug>

#define USING_COUT_TRACE \
int Trace::s_aktuelltDjup = 0; \
Trace::Outputtype Trace::s_utskriftsMetod = Trace::output_cout;

#define USING_QDEBUG_TRACE\
int Trace::s_aktuelltDjup = 0;\
Trace::Outputtype Trace::s_utskrift sMetod = Trace::output_qdebug;




class Trace
{

public:
    enum Outputtype {outpout_cout,outpout_qdebug};
    Trace(const std::string& funktionsnamn);
    Trace(const std::string& funktionsnamn, const std::string &extra);
    ~Trace();

    void message(const std::string& str);


private:
    std::string m_funktionsnamn;
    std::string indentering();
    void printline(const std::string& str);
};


static int s_aktuelltDjup;
static Trace::Outputtype s_utskriftsMetod;


void Trace::printline(const std::string& str)
{
    if (s_utskriftsMetod == outpout_cout)
        std::cout << str << std::endl;
    else
        qDebug() << str.c_str();
}

std::string Trace::indentering()
{
    int depth = s_aktuelltDjup * 3;
    std::string space{};
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
    printline(indentering() + ">>" + funktionsnamn + ">>");
    s_aktuelltDjup += 1;
}

Trace::Trace(const std::string& funktionsnamn, const std::string &extra)
{
    m_funktionsnamn = funktionsnamn;
    printline(indentering() + ">>" + funktionsnamn + " " + extra + ">>");
}

Trace::~Trace()
{
    s_aktuelltDjup -= 1;
    printline(indentering() +"<<" + m_funktionsnamn +"<<");

}

#endif // TRACE_H
