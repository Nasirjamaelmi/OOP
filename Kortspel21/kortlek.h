#ifndef KORTLEK_H
#define KORTLEK_H
#include "kort.h"
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <assert.h>
class Kortlek
{
public:
    Kortlek();
    int antalKort() const;
    Kort utplockatKort();
    void aterstallKortlek();
    void blanda();
    void aterstallBlandadKort();

private:
  std::vector<Kort> m_korten;
};

#endif // KORTLEK_H
