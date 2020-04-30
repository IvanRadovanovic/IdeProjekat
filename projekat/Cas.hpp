#ifndef CAS_HPP_INCLUDED
#define CAS_HPP_INCLUDED

#include <iostream>

#include "Instruktor.hpp"
#include "Datum.hpp"
#include "Vreme.hpp"


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
    Cas(const Cas& a): idINS(a.idINS),idUCenik(a.idUCenik),OdrzavanjeVreme(a.OdrzavanjeVreme)
    {
        idCasa=BrojCasova;
        BrojCasova++;
    }
    void setOV(Vreme a)
    {
        OdrzavanjeVreme=a;
    }
    void ispisiCas (Cas a)const{
        cout<<"ID instruktora "<<idINS<<" ID ucenika "<<idUCenik<<" Datum "<<OdrzavanjeDan<<" Vreme "<<OdrzavanjeVreme<<endl;
    }


};

#endif // CAS_HPP_INCLUDED
