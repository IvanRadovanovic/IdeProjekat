#ifndef RADNIK_HPP_INCLUDED
#define RADNIK_HPP_INCLUDED

using namespace std;
#include "Osoba.hpp"
#include "Skipass.hpp"

class Radnik:public Osoba{

protected:
    Skipass zaposleniPass;
    Staza RadnoMesto;

};



#endif // RADNIK_HPP_INCLUDED
