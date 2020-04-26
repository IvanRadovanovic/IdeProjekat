#ifndef SKIJAS_HPP_INCLUDED
#define SKIJAS_HPP_INCLUDED

using namespace std;
#include "Osoba.hpp"
#include "Skipass.hpp"

enum Oprema {Skijas2, Border};

class Skijas:public Osoba{

protected:
    Skipass SkijasPass;
    Oprema Vrsta;

public:

    Skijas():Osoba("Ime","Prezime"), SkijasPass(), Vrsta(Skijas2){}
    Skijas(string ime1, string prezime1, int danP,int mesecP,int godinaP,int danK,int mesecK,int godinaK,VrstaSkipassa v, Oprema o1):Osoba(ime1, prezime1), SkijasPass(danP,mesecP,godinaP,danK,mesecK,godinaK,v), Vrsta(o1){}


    };

#endif // SKIJAS_HPP_INCLUDED

