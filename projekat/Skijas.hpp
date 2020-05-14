#ifndef SKIJAS_HPP_INCLUDED
#define SKIJAS_HPP_INCLUDED
#include <iostream>
using namespace std;
#include "Osoba.hpp"
#include "Skipass.hpp"
#include <vector>


enum Oprema {Skijas2, Border};

class Skijas:public Osoba
{

protected:
    Skipass SkijasPass;
    Oprema Vrsta;
    vector<Cas> SkiCas;
    int brojCas;
    int IDS;

public:
    static int BrojSkijasa;

    Skijas():Osoba(), SkijasPass(), Vrsta(Skijas2)
    {
        brojCas=0;
        IDS=BrojSkijasa;
        BrojSkijasa++;
    }
    Skijas(string ime1, string prezime1,Datum PSP, Datum KSP, Oprema o1):Osoba(ime1, prezime1), SkijasPass(PSP,KSP), Vrsta(o1)
    {
        brojCas=0;
        IDS=BrojSkijasa;
        BrojSkijasa++;

    }
    Skijas(const Skijas& a):Osoba(a.ime,a. prezime), SkijasPass(a.SkijasPass), Vrsta(a.Vrsta)
    {
        brojCas=0;
        IDS=BrojSkijasa;
    }
    int getID ()
    {
        return IDS;
    }
    void ZakazivanjeCasa (Cas& a)
    {
        SkiCas.push_back(a);
        brojCas++;
    }
    void JaSam()
    {
        Osoba::JaSam();
        cout<<" Ukupan broj casova"<<brojCas<<endl;
        for(auto ik=SkiCas.begin(); ik!=SkiCas.end(); ik++)
        {
            cout<<*ik<<endl;
        }

    }

};

#endif // SKIJAS_HPP_INCLUDED

