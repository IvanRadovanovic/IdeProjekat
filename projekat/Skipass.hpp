#ifndef SKIPASS_HPP_INCLUDED
#define SKIPASS_HPP_INCLUDED

using namespace std;

#include "Datum.hpp"
enum VrstaSkipassa {Obican, Casovi, Radnik};

class Skipass{

protected:
    Datum PocetakSP;
    Datum KrajSP;
    VrstaSkipassa VrstaPassa;

};

#endif // SKIPASS_HPP_INCLUDED
