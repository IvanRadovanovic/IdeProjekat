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
    Skijas(string ime1, string prezime1,Datum PSP, Datum KSP ,VrstaSkipassa v, Oprema o1):Osoba(ime1, prezime1), SkijasPass(PSP,KSP,v), Vrsta(o1){}
    Skijas(const Skijas& a):Osoba(a.ime,a. prezime), SkijasPass(a.SkijasPass), Vrsta(a.Vrsta){}

    };

#endif // SKIJAS_HPP_INCLUDED

