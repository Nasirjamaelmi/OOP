#include <nastrace.h>
using namespace std;
USING_COUT_TRACE;


int fakultet(int n)
{
    tracemex(to_string(n));
    if(n<=1)
    {
        traceMsg("basvilkkoret returnerar 1");
        return 1;
    }
    int resultat = n*fakultet(n-1);
    traceMsg(string("returnerar ") + to_string(resultat));
    return resultat;
}

void funcB()
{
    traceme(__func__);
    traceMsg("Hello, world");
}

void funcA()
{
    traceme(__func__);
    funcB();
    cout <<"Fakultet av 4 är "<< fakultet(4) <<endl;

}


int main()
{
    traceme(__func__);
    funcA();

}
