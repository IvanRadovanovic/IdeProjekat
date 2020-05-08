#include <iostream>
#include "Datum.hpp"
#include "Instruktor.hpp"
#include "Osoba.hpp"
#include "Radnik.hpp"
#include "Skijas.hpp"
#include "Staza.hpp"
#include "Cas.hpp"
#include "Vreme.hpp"
#include <fstream>
using namespace std;
void citajTxt()
{
    string linija;
    ifstream fajl ("FajlCasovi.txt");
    if (fajl.is_open())
    {
        while ( getline (fajl,linija) )
        {
            cout << linija << '\n';
        }
        fajl.close();
    }

    else
        cout << "Neuspesno otvoren fajl";

}
int Instruktor::BrojINS=0;
int Cas::BrojCasova=100;
int Skijas::BrojSkijasa=0;
int main()
{
    citajTxt();
    Osoba i("Mirouljub","Petrovic");
    Osoba u("Nikola","Petrusic");
    Instruktor inst(i);
    Skijas s;
    s.setIme(u.getIme());
    s.setPrezime(u.getPrezime());
    Datum d(6,1,2021);
    Vreme v(14,30);
    Cas c(inst.getIDINS(),s.getID(),d,v);
    cout<<c<<endl;

    return 0;
}
/* Ideja mi je da napravim fukcionalnost zakazivanja casova kao i njihovog menjanja odtkazivanja izvršavanja itd.*/
