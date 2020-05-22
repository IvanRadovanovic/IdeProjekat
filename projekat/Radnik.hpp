#ifndef RADNIK_HPP_INCLUDED
#define RADNIK_HPP_INCLUDED

using namespace std;
#include "Osoba.hpp"
#include "Skipass.hpp"
#include "Staza.hpp"

class Radnik:public Osoba
{

protected:
    Skipass zaposleniPass;
    Staza RadnoMesto;
public:
    Radnik(): Osoba(), RadnoMesto(){}
};



#endif // RADNIK_HPP_INCLUDED
