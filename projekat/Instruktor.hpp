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
    static int BrojINS;
public:
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
    Instruktor(Instruktor &a): InstruktorPass(a.InstruktorPass),InsCasovi(a.InsCasovi),broj(a.broj),IDinstruktora(a.IDinstruktora){}
    Cas NoviCas(Instruktor *INS,Skijas *UC,Datum &OD,Vreme &OV)
    {
        Cas c(INS->getID(),UC->getID(),OD,OV);
        INS->PovecanjeBrojaCasa(*INS);
        INS->DodavanjeCasa(c,INS);
        UC->ZakazivanjeCasa(c);

        return c;
    }
    void PromeniVremeCasa(Vreme& v)
    {
        int k;
        cout<<"Redni broj casa"<<endl;
        cin>>k;
        InsCasovi[k].setOV(v);
    }
    void PromeniDatumCasa(Datum& d)
    {
        int k;
        cout<<"Redni broj casa"<<endl;
        cin>>k;
        InsCasovi[k].setDatum(d);
    }
    int getID ()
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
             ik->ispisiCas();
        }

    }
    void DodavanjeCasa (Cas c, Instruktor *INS){
        INS->InsCasovi.push_back(c);
        INS->BrojINS++;
    }
    void PovecanjeBrojaCasa (Instruktor &a)
    {
        a.broj++;
    }
    ~Instruktor(){BrojINS--;}
    void MenjaVreme (Vreme p,Cas c){
        for(auto ik=InsCasovi.begin();ik!=InsCasovi.end();ik++){
            if(c.getDatum().poredenje()==ik->getDatum().poredenje() && c.getVreme().poredenje()==ik->getVreme().poredenje() && c.getIDinstukotra()==ik->getIDinstukotra() && c.getIDskijasa()==ik->getIDskijasa())
            {
                ik->setOV(p);
            }

        }

    }
    void MenjaDatum (Datum p,Cas c){
        for(auto ik=InsCasovi.begin();ik!=InsCasovi.end();ik++){
            if(c.getDatum().poredenje()==ik->getDatum().poredenje() && c.getVreme().poredenje()==ik->getVreme().poredenje() && c.getIDinstukotra()==ik->getIDinstukotra() && c.getIDskijasa()==ik->getIDskijasa())
            {
                ik->setDatum(p);
            }

        }

    }




friend ostream& operator<<(ostream& izlaz, const Instruktor& o);

};
ostream& operator<<(ostream& izlaz, const Instruktor& o)
{

    izlaz<<endl<<endl;

    cout<<"ID "<<o.IDinstruktora<<endl<<"Moje ime je: "<<o.ime<<" "<<o.prezime<<endl;
    cout<<"i ukupan broj casova mi je:"<<o.broj<<endl;
    cout<<endl<<"---------------------------"<<endl<<endl;

    return izlaz;

}
#endif // INSTRUKTOR_HPP_INCLUDED
