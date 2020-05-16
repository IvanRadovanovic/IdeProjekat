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
Instruktor DodajIntrukora ()
{
    string ime1;
    string prezime1;
    int d,m,g;
    cout<<endl<<endl<<"Unesite ime novog intsrukora"<<endl;
    cin>>ime1;
    cout<<"Unesite prezime novog intsrukora"<<endl;
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
    Instruktor i(ime1,prezime1,a,b);
    return i;

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
        cout<<"Da dodate novog intruktora unesite 2"<<endl;
        cout<<"Da ispisete sve skijase unesite 3"<<endl;
        cout<<"Da ispisete sve instrktore unesite 4"<<endl;
        cout<<"Da izbrisete skijasa unesite 5"<<endl;
        cout<<"Da izbrisete instruktora unesite 6"<<endl;



        cin>>k;
        if(k==1)
        {
            SviSkijasi.push_back(DodajSkijasa());
            system("cls");
        }
        if(k==2)
        {
            SviInstruktori.push_back(DodajIntrukora());
            system("cls");
        }
        if(k==3)
        {
            system("cls");
            for(auto ik=SviSkijasi.begin(); ik!=SviSkijasi.end(); ik++)
            {
                cout<<endl<<endl<<endl<<endl<<endl;
                ik->JaSam();
            }
        }
        if(k==4)
        {
            system("cls");
            for(auto ik=SviInstruktori.begin(); ik!=SviInstruktori.end(); ik++)
            {
                cout<<endl;
                ik->JaSam();
            }
        }
        if(k==5)
        {
            string a;
            cin>>a;
            for(auto ik=SviSkijasi.begin(); ik!=SviSkijasi.end(); ik++)
            {
                if((*ik).getIme()==a)
                {
                    SviSkijasi.erase(ik);
                    Skijas::BrojSkijasa--;
                    break;
                }

            }
            system("cls");
        }
        if(k==6)
        {
            string a;
            cin>>a;
            for(auto ik=SviInstruktori.begin(); ik!=SviInstruktori.end(); ik++)
            {
                if((*ik).getIme()==a)
                {
                    SviInstruktori.erase(ik);
                    Instruktor::BrojINS--;
                    break;
                }

            }
            system("cls");
        }


    }
    while(1);

    return 0;
}
/* Ideja mi je da napravim fukcionalnost zakazivanja casova kao i njihovog menjanja odtkazivanja izvršavanja itd.*/
