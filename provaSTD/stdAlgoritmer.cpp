#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <string>


using namespace std;

template <typename Containter> void skrivHorisontellt(const string &message, Containter &container)
{
    cout <<message<< ":";
    for(const auto &x : container)
        cout << x <<" ";
    cout <<endl;
}

void provaTransorm1()
{
    vector<int> vec{3,7,4,9,3,1,2,4,9,5};

    skrivHorisontellt("originalvektorn:", vec);

    auto adderaTio =[](int i) {return 10+i;};
    transform(begin(vec),end(vec),begin(vec), adderaTio);

    skrivHorisontellt("efter transform:", vec);
}

void provaTransorm2()
{
    vector<int> vec1{3,7,4,9,3,1,2,4,9,5};
    vector<int> vec2(vec1.size());
    vector<int> vec3;

    skrivHorisontellt("originalvektorn:",vec1);
    auto multiTre = [](int i) {return i*3;};
    transform(begin(vec1),end(vec1),begin(vec2), multiTre);
    skrivHorisontellt("efter transform:", vec2);

    skrivHorisontellt("originalvektorn:",vec1);
    auto ite3 = back_inserter(vec3);
    auto multiFem = [] (int i) { return i*5;};
    transform(begin(vec1),end(vec1),(*ite3++), multiFem);
    skrivHorisontellt("efter transform:", vec3);

}
void provaIota(){
    vector<int> vec(10);
    skrivHorisontellt("prova iota A:", vec);
    iota( begin(vec), end(vec), 42);
    skrivHorisontellt("prova iota A:", vec);

    vector<int> vecb(10);
    skrivHorisontellt("prova iota B:", vecb);
    iota(begin(vecb), end(vecb), 0);
    skrivHorisontellt("prova iota B:", vecb);


    string str('z'-'a'+1,' ');
    skrivHorisontellt("prova iota string:", str);
    iota(begin(str),end(str), 'a');
    skrivHorisontellt("prova iota string:", str);
}

void provaGenerator_n()
{
    vector<int> fibsekvens;
    auto ite = back_inserter(fibsekvens);
    auto generator = [fore =0, forefore=0]() mutable
    {
        int e = forefore + fore; forefore=fore; fore=e; return e;
    };
    generate_n(ite, 10 , generator);
    skrivHorisontellt("fibsekvens:",fibsekvens);
}

void provaGenerator_n2()
{
    vector<int> data;
    auto ite = back_inserter(data);
    auto generator = [x=0]() mutable
    {
        return x++;
    };

    generate_n(ite,10, generator);
    skrivHorisontellt("fylld till 10:",data);

}
void provaSort()
{
    string str ="Here is a pretty large number of ASCII-characters.";

    sort(begin(str), end(str));
    cout <<"provaSort A:" <<str<<endl;

    auto aForeB = [](char a, char b)    {return a>b;};
    sort(begin(str), end(str), aForeB);
    cout <<"provaSort B:" <<str<<endl;
}

struct AB{
    int m_a;
    int m_b;
};
ostream& operator <<(ostream &o, const AB &ab)
{
    o << "(" << ab.m_a << "," <<ab.m_b <<")";
    return o;
}

void provaSortOchStableSort()
{
   vector <AB> data;
   auto generateRandom = [] () {return AB{rand()%100, rand()%2};};
   auto ite = back_inserter(data);
   generate_n(ite,100,generateRandom);
   skrivHorisontellt("före sort", data);


   auto vilkorA = [](const AB &ab1, const AB &ab2) {return ab1.m_a<ab2.m_a;};
   auto vilkorB = [](const AB &ab1, const AB &ab2) {return ab1.m_b<ab2.m_b;};

   sort(begin(data), end(data), vilkorA);
   skrivHorisontellt("efter sort A:", data);

   stable_sort(begin(data), end(data), vilkorB);

   skrivHorisontellt("efter sort B", data);
}
void provaRemoveIf()
{
    vector<int> data(10);
    iota(begin(data),end(data),0);
    skrivHorisontellt("före remove:",data);

    auto vilkor = [] (int i) {return i<5;};
    auto iteFrom = remove_if(begin(data), end(data), vilkor);
    skrivHorisontellt("efter remove:",data);

    data.erase(iteFrom,end(data));
    skrivHorisontellt("Efter remove på riktigt",data);
}




void ingangTillStdAlgoritmer()
{
   //provaTransorm1();
    //provaTransorm2();
    //provaIota();
    //provaGenerator_n();
   // provaGenerator_n2();
   // provaSort();
    //provaSortOchStableSort();
    provaRemoveIf();


}
