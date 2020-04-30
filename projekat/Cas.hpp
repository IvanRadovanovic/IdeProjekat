#ifndef CAS_HPP_INCLUDED
#define CAS_HPP_INCLUDED

using namespace std;

#include "Osoba.hpp"
#include "Instruktor.hpp"
#include "Datum.hpp"
#include "Skijas.hpp"
#include "Vreme.hpp"


class Cas{

protected:
    Osoba CasInstuktor;
    Datum OdrzavanjeDan;
    Skijas Ucenik;
    Vreme OdrzavanjeVreme;
public:
    Cas():CasInstuktor(),OdrzavanjeDan(),Ucenik(), OdrzavanjeVreme(){}
    Cas(Osoba CI,Skijas UC, Datum OD,Vreme OV):CasInstuktor(CI),Ucenik(UC),OdrzavanjeDan(OD),OdrzavanjeVreme(OV){}
    Cas(const Cas& a): CasInstuktor(a.CasInstuktor),OdrzavanjeDan(a.OdrzavanjeDan),Ucenik(a.Ucenik),OdrzavanjeVreme(a.OdrzavanjeVreme){}
    void setOV(Vreme a){
        OdrzavanjeVreme=a;
    }


};

#endif // CAS_HPP_INCLUDED
