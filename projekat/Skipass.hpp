#ifndef SKIPASS_HPP_INCLUDED
#define SKIPASS_HPP_INCLUDED

using namespace std;

#include "Datum.hpp"
enum VrstaSkipassa {Obican, Casovi1, Radnik};

class Skipass
{

protected:
    Datum PocetakSP;
    Datum KrajSP;
    VrstaSkipassa VrstaPassa;
public:
    Skipass():KrajSP(1,4,2021)
    {
        VrstaPassa=Obican;
    }
    Skipass(Datum PSP, Datum KSP, VrstaSkipassa v): PocetakSP(PSP), KrajSP(KSP), VrstaPassa(v) {}
    Skipass(const Skipass& a):PocetakSP(a.PocetakSP), KrajSP(a.KrajSP), VrstaPassa(a.VrstaPassa) {}
};

#endif // SKIPASS_HPP_INCLUDED
