#ifndef SKIJAS_HPP_INCLUDED
#define SKIJAS_HPP_INCLUDED

using namespace std;
#include "Osoba.hpp"
#include "Skipass.hpp"

enum Oprema {Skijas, Border};

class Skijas:public Osoba{

protected:
    Skipass SkijasPass;
    Oprema Vrsta;
};

#endif // SKIJAS_HPP_INCLUDED
