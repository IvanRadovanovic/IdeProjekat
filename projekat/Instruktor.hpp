#ifndef INSTRUKTOR_HPP_INCLUDED
#define INSTRUKTOR_HPP_INCLUDED
#include <iostream>
#include "Osoba.hpp"
#include "Skipass.hpp"
#include "Cas.hpp"

using namespace std;


class Instruktor:public Osoba{
protected:
    Skipass InstruktorPass;
    Cas Casovi[10];
    int broj=0;
    static int BrojINS;
public:
    Instruktor():Osoba(){
        BrojINS++;
    }
    Instruktor(Osoba o):Osoba(o){
        BrojINS++;
    }
    Instruktor(string ime1,string prezime1): Osoba(ime1, prezime1){
        BrojINS++;
    }
    void NoviCas(Osoba INS,Skijas UC,Datum OD,Vreme OV){
        Casovi[broj]=Cas(INS,UC,OD,OV);
        broj++;
    }
    void PromeniVremeCasa(Vreme v){
        int k;
        cout<<"Redni broj casa"<<endl;
        cin>>k;
        Casovi[k].setOV(v);
    }

};
#endif // INSTRUKTOR_HPP_INCLUDED
