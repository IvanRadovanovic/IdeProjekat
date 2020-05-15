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
    string getIme()const
    {
        return ime;
    }
    string getPrezime()const
    {
        return prezime;
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
        cout<<"-------------------------"<<endl<<endl;
    }
    void Mojicasovi()
    {
        for(auto ik=SkiCas.begin(); ik!=SkiCas.end(); ik++)
        {
            cout<<*ik<<endl;
        }

    }
friend ostream& operator<<(ostream& izlaz, const Skijas& o);

};
ostream& operator<<(ostream& izlaz, const Skijas& o)
{

    izlaz<<endl<<endl;

    cout<<"Redni broj "<<o.IDS<<endl<<"Moje ime je: "<<o.ime<<" "<<o.prezime<<endl;
    cout<<"i ukupan broj casova mi je:"<<o.brojCas<<endl;
    cout<<endl<<"---------------------------"<<endl<<endl;

    return izlaz;

}
#endif // SKIJAS_HPP_INCLUDED

