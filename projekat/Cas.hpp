#ifndef CAS_HPP_INCLUDED
#define CAS_HPP_INCLUDED

#include "Instruktor.hpp"
#include "Datum.hpp"
#include "Vreme.hpp"
#include <iostream>
using namespace std;


class Cas
{

protected:
    int idINS;
    Datum OdrzavanjeDan;
    int idUCenik;
    Vreme OdrzavanjeVreme;
    int idCasa;
    static int BrojCasova;
public:
    Cas():OdrzavanjeDan(), OdrzavanjeVreme()
    {
        idCasa=BrojCasova;
        BrojCasova++;
    }
    Cas(int INSID,int UCID, Datum OD,Vreme OV):idINS(INSID),idUCenik(UCID),OdrzavanjeDan(OD),OdrzavanjeVreme(OV)
    {
        idCasa=BrojCasova;
        BrojCasova++;
    }
    Cas(const Cas& a): idINS(a.idINS),idUCenik(a.idUCenik),OdrzavanjeVreme(a.OdrzavanjeVreme),OdrzavanjeDan(a.OdrzavanjeDan)
    {
        idCasa=BrojCasova;
    }
    ~Cas(){BrojCasova--;}
    void setOV(Vreme a)
    {
        OdrzavanjeVreme=a;
    }
    void setDatum(Datum a)
    {
        OdrzavanjeDan=a;
    }
    void ispisiCas ()const
    {
        cout<<"ID instruktora "<<idINS<<" ID ucenika "<<idUCenik<<" Datum ";
        OdrzavanjeDan.Ispisi();
        cout<<" Vreme ";
        OdrzavanjeVreme.Ispisi();
        cout<<endl;
    }
    Datum getDatum (){return OdrzavanjeDan;}
    int getIDinstukotra (){return idINS;}
    int getIDskijasa (){return idUCenik;}
    Vreme getVreme (){return OdrzavanjeVreme;}
    friend ostream& operator<<(ostream& izlaz, const Cas& o);

};
ostream& operator<<(ostream& izlaz, const Cas& o)
{

    izlaz<<endl;

    izlaz<<"Cas - ispis"<<endl;

    izlaz<<"ID instruktora: "<<o.idINS<<endl;

    izlaz<<"ID Ucenika: "<<o.idUCenik<<endl;

    izlaz<<o.OdrzavanjeDan<<endl;

    izlaz<<o.OdrzavanjeVreme<<endl;

    izlaz<<"Radni broj casa "<<o.idCasa<<endl;

    return izlaz;

}

#endif // CAS_HPP_INCLUDED
