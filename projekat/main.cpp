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
#include <vector>
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
//string ime1, string prezime1,Datum PSP, Datum KSP,VrstaSkipassa v, Oprema o1
Skijas DodajSkijasa ()
{
    string ime1;
    string prezime1;
    int d,m,g;
    int o1;
    cout<<endl<<endl<<"Unesite ime novog skijasa"<<endl;
    cin>>ime1;
    cout<<"Unesite prezime novog skijasa"<<endl;
    cin>>prezime1;
    cout<<"Unesite dan, mesec i godinu pocetka vazenja skipass-a"<<endl;
    cin>>d;
    cin>>m;
    cin>>g;
    Datum a(d,m,g);
    cout<<"Unesite dan, mesec i godinu zavrsetka vazenja skipass-a"<<endl;
    cin>>d;
    cin>>m;
    cin>>g;
    Datum b(d,m,g);
    cout<<"Unesite da li je skijas ili border(0 ukoliko je skijas i 1 ukoliko je border)"<<endl;
    cin>>o1;
    Skijas s(ime1,prezime1,a,b,Skijas2); //pitaj Olju
    return s;

}
int Instruktor::BrojINS=0;
int Cas::BrojCasova=0;
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
    inst.NoviCas(inst,s,d,v);
    inst.JaSam();
    vector<Instruktor> SviInstruktori;
    vector<Skijas> SviSkijasi;
    SviSkijasi.push_back(s);
    SviInstruktori.push_back(inst);
    int k;
    do
    {
        cout<<"Ukupan broj intrukotra je: "<<Instruktor::BrojINS<<endl;
        cout<<"Ukupan broj skijasa je: "<<Skijas::BrojSkijasa<<endl;
        cout<<"Ukupan broj casova je: "<<Cas::BrojCasova<<endl<<endl;
        cout<<"Da dodate novog skijasa unesite 1"<<endl;


        cin>>k;
        if(k==1)
        {
            SviSkijasi.push_back(DodajSkijasa());

        }

    }
    while(1);

    return 0;
}
/* Ideja mi je da napravim fukcionalnost zakazivanja casova kao i njihovog menjanja odtkazivanja izvršavanja itd.*/
