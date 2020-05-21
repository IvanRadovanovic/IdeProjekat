#ifndef INSTRUKTOR_HPP_INCLUDED
#define INSTRUKTOR_HPP_INCLUDED
#include "Osoba.hpp"
#include "Skipass.hpp"
#include "Skijas.hpp"
#include <iostream>
#include <vector>
using namespace std;


class Instruktor:public Osoba
{
protected:
    Skipass InstruktorPass;
    vector<Cas> InsCasovi;
    int broj;
    int IDinstruktora;
public:
    static int BrojINS;
    Instruktor():Osoba(),InstruktorPass()
    {
        broj=0;
        IDinstruktora=BrojINS;
        BrojINS++;
    }
    Instruktor(Osoba o):Osoba(o),InstruktorPass()
    {
        broj=0;
        IDinstruktora=BrojINS;
        BrojINS++;
    }
    Instruktor(string ime1,string prezime1,Datum PSP, Datum KSP): Osoba(ime1, prezime1), InstruktorPass(PSP,KSP)
    {
        broj=0;
        IDinstruktora=BrojINS;
        BrojINS++;
    }
    Cas NoviCas(Instruktor &INS,Skijas &UC,Datum &OD,Vreme &OV)
    {
        Cas c(INS.getIDINS(),UC.getID(),OD,OV);
        UC.ZakazivanjeCasa(c);
        InsCasovi.push_back(c);
        broj++;
        cout<<"Ovde se pravi novi cas XXX"<<INS.getIDINS()<<"  "<<UC.getID()<<"////////"<<endl;
        return c;
    }
    void PromeniVremeCasa(Vreme& v)
    {
        int k;
        cout<<"Redni broj casa"<<endl;
        cin>>k;
        InsCasovi[k].setOV(v);
    }
    int getIDINS ()
    {
        return IDinstruktora;
    }
    void JaSam()
    {
        Osoba::JaSam();
        cout<<"i ukupan broj casova mi je:"<<broj<<endl;
    }
    void MojiCasovi()
    {
        for(auto ik=InsCasovi.begin(); ik!=InsCasovi.end(); ik++)
        {
            cout<<*ik<<endl;
        }

    }
    ~Instruktor(){BrojINS--;}



friend ostream& operator<<(ostream& izlaz, const Instruktor& o);

};
ostream& operator<<(ostream& izlaz, const Instruktor& o)
{

    izlaz<<endl<<endl;

    cout<<"Redni broj "<<o.IDinstruktora<<endl<<"Moje ime je: "<<o.ime<<" "<<o.prezime<<endl;
    cout<<"i ukupan broj casova mi je:"<<o.broj<<endl;
    cout<<endl<<"---------------------------"<<endl<<endl;

    return izlaz;

}
#endif // INSTRUKTOR_HPP_INCLUDED
