#ifndef INSTRUKTOR_HPP_INCLUDED
#define INSTRUKTOR_HPP_INCLUDED
#include "Osoba.hpp"
#include "Skipass.hpp"
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
    static int BrojINS;
public:
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
    void NoviCas(int INS,int UC,Datum OD,Vreme OV)
    {
        Cas c(INS,UC,OD,OV);
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
    void IspisiSveInstruktorCasove ()
    {
        cout<<ime<<" "<<prezime<<" Ukupan broj casova"<<broj<<endl;
        for(auto ik=InsCasovi.begin(); ik!=InsCasovi.end(); ik++)
        {
            cout<<*ik<<endl;
        }

    }


};
#endif // INSTRUKTOR_HPP_INCLUDED
