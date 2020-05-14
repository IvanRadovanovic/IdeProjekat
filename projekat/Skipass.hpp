#ifndef SKIPASS_HPP_INCLUDED
#define SKIPASS_HPP_INCLUDED

using namespace std;

#include "Datum.hpp"
class Skipass
{

protected:
    Datum PocetakSP;
    Datum KrajSP;
public:
    Skipass():KrajSP(1,4,2021){}
    Skipass(Datum PSP, Datum KSP): PocetakSP(PSP), KrajSP(KSP) {}
    Skipass(const Skipass& a):PocetakSP(a.PocetakSP), KrajSP(a.KrajSP){}
};

#endif // SKIPASS_HPP_INCLUDED
