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

    /*skrivHorisontellt("originalvektorn:",vec1);
    auto multiTre = [](int i) {return i*3;};
    transform(begin(vec1),end(vec1),begin(vec2), multiTre);
    skrivHorisontellt("efter transform:", vec2);
*/
    skrivHorisontellt("originalvektorn:",vec1);
    auto ite3 = back_inserter(vec3);
    auto multiFem = [] (int i) { return i*5;};
    transform(begin(vec1),end(vec1),(*ite3++), multiFem);
    skrivHorisontellt("efter transform:", vec3);

}

void ingangTillStdAlgoritmer()
{
   //provaTransorm1();
    provaTransorm2();
}
