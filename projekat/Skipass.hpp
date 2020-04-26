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
public:
    Skipass(){
        VrstaPassa=Obican;
        KrajSP.setCelo(1,4,2021);
    }
    Skipass(int danP,int mesecP,int godinaP,int danK,int mesecK,int godinaK,VrstaSkipassa v){
        PocetakSP.setCelo(danP,mesecP,godinaP);
        KrajSP.setCelo(danK,mesecK,godinaK);
        VrstaPassa=v;
    }

};

#endif // SKIPASS_HPP_INCLUDED
