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
    Instruktor():Osoba()
    {
        broj=0;
        IDinstruktora=BrojINS;
        BrojINS++;
    }
    Instruktor(Osoba o):Osoba(o)
    {
        broj=0;
        IDinstruktora=BrojINS;
        BrojINS++;
    }
    Instruktor(string ime1,string prezime1): Osoba(ime1, prezime1)
    {
        broj=0;
        IDinstruktora=BrojINS;
        BrojINS++;
    }
    void NoviCas(Instruktor &INS,Skijas &UC,Datum &OD,Vreme &OV)
    {
        Cas c(INS.getIDINS(),UC.getID(),OD,OV);
        UC.ZakazivanjeCasa(c);
        InsCasovi.push_back(c);
        broj++;
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
        for(auto ik=InsCasovi.begin(); ik!=InsCasovi.end(); ik++)
        {
            cout<<*ik<<endl;
            cout<<endl<<endl<<"-------------------------------------------"<<endl<<endl<<endl;
        }

    }


};
#endif // INSTRUKTOR_HPP_INCLUDED
