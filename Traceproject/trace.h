#ifndef TRACE_H
#define TRACE_H
#define traceme Trace traceObject( __func__ );
#define tracemex( extra ) Trace traceObject( __func__, extra );
#define traceMsg( meddelande ) traceObject.message( meddelande );
#include <string>




class Trace
{

public:
    enum Outputtype {outpout_cout,outpout_qdebug};

    Trace(const std::string& funktionsnamn);
    Trace(const std::string& funktionsnamn, const std::string& extra);
    ~Trace();

    void message(const std::string& str);



private:
    std::string m_funktionsnamn;
    std::string indentering();
    void printline(const std::string& str);

};

#endif // TRACE_H
