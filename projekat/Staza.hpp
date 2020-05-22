#ifndef STAZA_HPP_INCLUDED
#define STAZA_HPP_INCLUDED

using namespace std;
#include "TezinaStaze.hpp"

class Staza
{

protected:
    string Naziv;
    TezinaStaze TStaze;
public:
    Staza():Naziv("staza bez naziva"),TStaze(){}
};
#endif // STAZA_HPP_INCLUDED
