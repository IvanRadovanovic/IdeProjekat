#ifndef INSTRUKTOR_HPP_INCLUDED
#define INSTRUKTOR_HPP_INCLUDED
#include "Osoba.hpp"
#include "Skipass.hpp"
#include <iostream>
using namespace std;


class Instruktor:public Osoba{
protected:
    Skipass InstruktorPass;
    Cas Casovi[10];
    int broj;// dodati u kontruktore
    static int BrojINS;
public:
    Instruktor():Osoba(){
        broj=0;
        BrojINS++;
    }
    Instruktor(Osoba o):Osoba(o){
        broj=0;
        BrojINS++;
    }
    Instruktor(string ime1,string prezime1): Osoba(ime1, prezime1){
        broj=0;
        BrojINS++;
    }
    void NoviCas(int INS,int UC,Datum OD,Vreme OV){
        Cas c(INS,UC,OD,OV);
        Casovi[broj]=c;
        broj++;
    }
    void PromeniVremeCasa(Vreme v){
        int k;
        cout<<"Redni broj casa"<<endl;
        cin>>k;
        Casovi[k].setOV(v);
    }
    void IspisiSveInstruktorCasove (){
        cout<<ime<<" "<<prezime<<" Ukupan broj casova"<<broj<<endl;
        for(int i=0;i<broj;i++){
            cout<<Casovi[i].ispisiCas();

        }

        }


};
#endif // INSTRUKTOR_HPP_INCLUDED
