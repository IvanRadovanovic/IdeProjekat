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
#include <algorithm>
using namespace std;
void citajTxt(string nazivFajla)
{
    string linija;
    ifstream fajl (nazivFajla);
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
    void pisiTxt(string nazivFajla, Osoba &o, char mode='a')
{
    ofstream fajl;
    if (mode=='a'){
        fajl.open (nazivFajla, ios_base::app);
    }
    else{
        fajl.open (nazivFajla);
    }
    fajl << o << " ";
    fajl << o.getID() << endl;
    fajl.close();

}
void pisiTxtCasovi(string nazivFajla, Cas &o, char mode='a')
{
    ofstream fajl;
    if (mode=='a'){
        fajl.open (nazivFajla, ios_base::app);
    }
    else{
        fajl.open (nazivFajla);
    }
    fajl << o << endl;;
    fajl.close();

}
Skijas* DodajSkijasa ()
{
    string ime1;
    string prezime1;
    cout<<endl<<endl<<"Unesite ime novog skijasa"<<endl;
    cin>>ime1;
    cout<<"Unesite prezime novog skijasa"<<endl;
    cin>>prezime1;
    Datum b;
    Skijas *s=new Skijas(ime1,prezime1,b,b,Skijas2);
    return s;

}
Instruktor* DodajIntrukora ()
{
    string ime1;
    string prezime1;
    cout<<endl<<endl<<"Unesite ime novog intsrukora"<<endl;
    cin>>ime1;
    cout<<"Unesite prezime novog intsrukora"<<endl;
    cin>>prezime1;
    Datum b;
    Instruktor *i=new Instruktor(ime1,prezime1,b,b);
    return i;

}
Cas* NoviCas (Instruktor *i1,Skijas *u1)
{
    int d,m,g;
    cout<<"Unesite vreme odrzavanja casa"<<endl;
    cin>>d;
    cin>>m;
    Vreme V(d,m);
    cout<<"Unesite dan, mesec i godinu odrzavanja casa"<<endl;
    cin>>d;
    cin>>m;
    cin>>g;
    Datum D(d,m,g);
    Cas* v=new Cas (i1->NoviCas(i1,u1,D,V));
    return  v;


}



int Instruktor::BrojINS=0;
int Cas::BrojCasova=0;
int Skijas::BrojSkijasa=0;

int main()
{
    //citajTxt();
    Osoba i("Miroljub","Petrovic");
    Instruktor inst(i);
    Datum d(6,1,2021);

    vector<Instruktor*> SviInstruktori;
    vector<Skijas*> SviSkijasi;
    vector<Cas*> SviCasovi;
    Skijas z("Ivan","Radovanovic",d,d,Skijas2);
    SviSkijasi.push_back(&z);
    SviInstruktori.push_back(&inst);
    //inst.NoviCas(&inst,&z,d,v);
    //inst.NoviCas(&inst,&z,p,v);
    //inst.MojiCasovi();
    int k;
    do
    {
        cout<<"Ukupan broj intrukotra je: "<<SviInstruktori.size()<<endl;
        cout<<"Ukupan broj skijasa je: "<<SviSkijasi.size()<<endl;
        cout<<"Ukupan broj casova je: "<<SviCasovi.size()<<endl<<endl;
        cout<<"Da zavrsite sa programom i uspisete sve u fajl -1"<<endl;
        cout<<"Da dodate novog skijasa unesite 1"<<endl;
        cout<<"Da dodate novog intruktora unesite 2"<<endl;
        cout<<"Da ispisete sve skijase unesite 3"<<endl;
        cout<<"Da ispisete sve instrktore unesite 4"<<endl;
        cout<<"Da izbrisete skijasa unesite 5"<<endl;
        cout<<"Da izbrisete instruktora unesite 6"<<endl;
        cout<<"Da ispisete sve casova nekog skijasa unesite 7"<<endl;
        cout<<"Da ispisete sve casova nekog instruktora unesite 8"<<endl;
        cout<<"Da udete u cas meni unesite 9"<<endl;



        cin>>k;
        system("cls");
        if(k==1)    ///Novi Skijas
        {
            SviSkijasi.push_back(DodajSkijasa());
            system("cls");
        }
        if(k==2)    ///Novi Instuktor
        {
            SviInstruktori.push_back(DodajIntrukora());
            system("cls");
        }
        if(k==3)    ///Ispis skijasa
        {
            system("cls");
            for(auto ik=SviSkijasi.begin(); ik!=SviSkijasi.end(); ik++)
            {
                cout<<endl;
                (*ik)->JaSam();
            }
        }
        if(k==4)    ///Ispis instuktora
        {
            system("cls");
            for(auto ik=SviInstruktori.begin(); ik!=SviInstruktori.end(); ik++)
            {
                cout<<endl;
                (*ik)->JaSam();
            }
        }
        if(k==5)    ///Brisanje skijasa
        {
            string a;
            cout<<"Unesite ime skijasa koji je otisao kuci"<<endl;
            cin>>a;
            for(auto ik=SviSkijasi.begin(); ik!=SviSkijasi.end(); ik++)
            {
                if((*ik)->getIme()==a)
                {
                    SviSkijasi.erase(ik);

                    break;
                }

            }
            system("cls");
        }
        if(k==6)    ///Brisanje Instrukotra
        {
            string a;
            cout<<"Unesite ime instukotra koji je otpusten"<<endl;
            cin>>a;
            for(auto ik=SviInstruktori.begin(); ik!=SviInstruktori.end(); ik++)
            {
                if((*ik)->getIme()==a)
                {
                    SviInstruktori.erase(ik);
                    break;
                }

            }
            system("cls");
        }
        if(k==7)    ///Ispis svih casova skijasa
        {
            system("cls");
            string a;
            for(auto ik=SviSkijasi.begin(); ik!=SviSkijasi.end(); ik++)
            {
                cout<<endl;
                (*ik)->JaSam();
            }
            cout<<"Unesite ime skijasa za kojeg zelite da ispiste casove"<<endl;
            cin>>a;
            for(auto ik=SviSkijasi.begin(); ik!=SviSkijasi.end(); ik++)
            {
                if((*ik)->getIme()==a)
                {
                    (*ik)->MojiCasovi();
                    break;
                }

            }
        }
        if(k==8)    ///Ispis svih casova instukotra
        {
            system("cls");
            string a;
            for(auto ik=SviInstruktori.begin(); ik!=SviInstruktori.end(); ik++)
            {
                cout<<endl;
                (*ik)->JaSam();
            }
            cout<<"Unesite ime Instukotra za kojeg zelite da ispiste casove"<<endl;
            cin>>a;
            for(auto ik=SviInstruktori.begin(); ik!=SviInstruktori.end(); ik++)
            {
                if((*ik)->getIme()==a)
                {
                    (*ik)->MojiCasovi();
                    break;
                }

            }
        }
        if(k==9)    ///Cas meni
        {


            do
            {
                cout<<"Da se vratite na prethodni meni pritisnite 0"<<endl;
                cout<<"Da dodate novi cas 1"<<endl;
                cout<<"Da ispisete sve casove pritisnite 2"<<endl;
                cout<<"Da promenite vreme casa unesite 3"<<endl;
                cout<<"Da promenite datum casa unesite 4"<<endl;


                cin>>k;
                if(k==1)    ///Novi cas
                {

                    system("cls");
                    for(auto ik=SviSkijasi.begin(); ik!=SviSkijasi.end(); ik++)
                    {
                        cout<<endl<<endl<<endl<<endl<<endl;
                        (*ik)->JaSam();
                    }
                    cout<<"Unesite ime skijasa koji zeli da doda cas"<<endl;
                    string a,b;
                    cin>>a;
                    for(auto ik=SviInstruktori.begin(); ik!=SviInstruktori.end(); ik++)
                    {
                        cout<<endl;
                        (*ik)->JaSam();
                    }
                    cout<<"Unesite ime instruktora koji ce da odrzi cas"<<endl;
                    cin>>b;

                    auto ik=SviSkijasi.begin();
                    for(ik; ik!=SviSkijasi.end(); ik++)
                    {
                        if((*ik)->getIme()==a)
                        {
                            break;
                        }

                    }
                    auto ip=SviInstruktori.begin();
                    for(ip; ip!=SviInstruktori.end(); ip++)
                    {
                        if((*ip)->getIme()==b)
                        {
                            break;
                        }
                    }
                    SviCasovi.push_back(NoviCas(*ip,*ik));
                }
                if(k==2)    ///Ispis casova
                {
                    system("cls");
                    for(auto ik=SviCasovi.begin(); ik!=SviCasovi.end(); ik++)
                    {
                        cout<<endl;
                        (*ik)->ispisiCas();
                    }
                }
                if(k==3)    ///Menjanje vremena casa
                {
                    int a,b,d,m,g;
                    cout<<"Unesite prvo Id instukotra koji drzi cas pa skijasa koji dolazi na cas"<<endl;
                    cin>>a;
                    cin>>b;
                    cout<<"Unesite datum casa"<<endl;
                    cin>>d;
                    cin>>m;
                    cin>>g;
                    Datum D(d,m,g);
                    cout<<"Unesite trenutno vreme casa"<<endl;
                    cin>>d;
                    cin>>m;
                    Vreme V(d,m);
                    for(auto ik=SviCasovi.begin(); ik!=SviCasovi.end(); ik++)
                    {
                        if((*ik)->getIDinstukotra()==a && (*ik)->getIDskijasa()==b && (*ik)->getDatum().poredenje()==D.poredenje() && (*ik)->getVreme().poredenje()==V.poredenje())
                        {
                            int k,o;
                            cout<<"Trenutno vreme: "<<endl;
                            cout<<(*ik)->getVreme()<<endl;
                            cout<<"Unesite vreme novog casa"<<endl;
                            cin>>k>>o;
                            Vreme p(k,o);
                            (*ik)->setOV(p);

                            break;

                        }

                    }
                }
                if(k==4)    ///Menjanje datuma casa
                {
                    int a,b,d,m,g;
                    cout<<"Unesite prvo Id instukotra koji drzi cas pa skijasa koji dolazi na cas"<<endl;
                    cin>>a;
                    cin>>b;
                    cout<<"Unesite trenutni datum casa"<<endl;
                    cin>>d;
                    cin>>m;
                    cin>>g;
                    Datum D(d,m,g);
                    cout<<"Unesite vreme casa"<<endl;
                    cin>>d;
                    cin>>m;
                    Vreme V(d,m);
                    for(auto ik=SviCasovi.begin(); ik!=SviCasovi.end(); ik++)
                    {
                        if((*ik)->getIDinstukotra()==a && (*ik)->getIDskijasa()==b && (*ik)->getDatum().poredenje()==D.poredenje() && (*ik)->getVreme().poredenje()==V.poredenje())
                        {
                            cout<<"Trenutni datum: "<<endl;
                            cout<<(*ik)->getDatum()<<endl;
                            cout<<"Unesite datum novog casa"<<endl;
                            cin>>d>>m>>g;
                            Datum p(d,m,g);
                            (*ik)->setDatum(p);
                            break;
                        }

                    }
                }
            }
            while(k!=0);
        }


    }
    while(k!=-1);
    vector<Osoba*> SveOsobe;
	SveOsobe.insert(SveOsobe.end(), SviInstruktori.begin(), SviInstruktori.end());
	SveOsobe.insert(SveOsobe.end(), SviSkijasi.begin(), SviSkijasi.end());
	for(auto ik=SveOsobe.begin(); ik!=SveOsobe.end(); ik++)
            {
                if(ik==SveOsobe.begin()){
                    pisiTxt("FajlOsobe.txt",**ik,'w');
                }
                else{
                    pisiTxt("FajlOsobe.txt",**ik);
                }
            }
    for(auto ik=SviSkijasi.begin(); ik!=SviSkijasi.end(); ik++)
            {
                if(ik==SviSkijasi.begin()){
                    pisiTxt("FajlSkijasi.txt",**ik,'w');
                }
                else{
                    pisiTxt("FajlSkijasi.txt",**ik);
                }
            }
    for(auto ik=SviInstruktori.begin(); ik!=SviInstruktori.end(); ik++)
            {
                if(ik==SviInstruktori.begin()){
                    pisiTxt("FajlInstruktori.txt",**ik,'w');
                }
                else{
                    pisiTxt("FajlInstruktori.txt",**ik);
                }
            }
    for(auto ik=SviCasovi.begin(); ik!=SviCasovi.end(); ik++)
            {
                if(ik==SviCasovi.begin()){
                    pisiTxtCasovi("FajlCasovi.txt",**ik,'w');
                }
                else{
                    pisiTxtCasovi("FajlCasovi.txt",**ik);
                }
            }
    return 0;
}
