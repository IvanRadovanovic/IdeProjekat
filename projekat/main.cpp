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
    Skijas s(ime1,prezime1,a,b,Skijas2);
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
Cas NoviCas (Instruktor i1,Skijas u1)
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

    return  i1.NoviCas(i1,u1,D,V);


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
    Vreme v(14,30);

    vector<Instruktor> SviInstruktori;
    vector<Skijas> SviSkijasi;
    vector<Cas> SviCasovi;
    Skijas z("Ivan","Radovanovic",d,d,Skijas2);//ODAVDE
    SviSkijasi.push_back(z);
    cout<<"ID za ivana je 321//"<<SviSkijasi.begin()->getID()<<endl;
    SviInstruktori.push_back(inst);
    int k;
    do
    {
        cout<<"Ukupan broj intrukotra je: "<<SviInstruktori.size()<<endl;
        cout<<"Ukupan broj skijasa je: "<<SviSkijasi.size()<<endl;
        cout<<"Ukupan broj casova je: "<<SviCasovi.size()<<endl<<endl;
        cout<<"Da dodate novog skijasa unesite 1"<<endl;
        cout<<"Da dodate novog intruktora unesite 2"<<endl;
        cout<<"Da ispisete sve skijase unesite 3"<<endl;
        cout<<"Da ispisete sve instrktore unesite 4"<<endl;
        cout<<"Da izbrisete skijasa unesite 5"<<endl;
        cout<<"Da izbrisete instruktora unesite 6"<<endl;
        cout<<"Da udete u cas meni unesite 7"<<endl;
        cout<<z.getID()<<endl;
        cout<<"Staticko polje je "<<z.getBrojSkijasa()<<endl;
        cout<<"ID za ivana je "<<*(SviSkijasi.begin())<<endl;//DO OVDE SE PROMENI



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
                cout<<endl;
                cout<<"ID je"<<ik->getID()<<endl;
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
                if(ik->getIme()==a)
                {
                    SviSkijasi.erase(ik);

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
                if(ik->getIme()==a)
                {
                    SviInstruktori.erase(ik);
                    Instruktor::BrojINS--;
                    break;
                }

            }
            system("cls");
        }
        if(k==7)
        {


            do
            {
                cout<<"Da se vratite na prethodni meni pritisnite 0"<<endl;
                cout<<"Da dodate novi cas 1"<<endl;
                cout<<"Da ispisete sve casove pritisnite 2"<<endl;
                cout<<"Da promenite vreme casa unesite 3"<<endl;


                cin>>k;
                if(k==1)
                {

                    system("cls");
                    for(auto ik=SviSkijasi.begin(); ik!=SviSkijasi.end(); ik++)
                    {
                        cout<<endl<<endl<<endl<<endl<<endl;
                        ik->JaSam();
                    }
                    cout<<"Unesite ime skijasa koji zeli da doda cas"<<endl;
                    string a,b;
                    cin>>a;
                    for(auto ik=SviInstruktori.begin(); ik!=SviInstruktori.end(); ik++)
                    {
                        cout<<endl;
                        ik->JaSam();
                    }
                    cout<<"Unesite ime instruktora koji ce da odrzi cas"<<endl;
                    cin>>b;

                    auto ik=SviSkijasi.begin();
                    for(ik; ik!=SviSkijasi.end(); ik++)
                    {
                        if(ik->getIme()==a)
                        {
                            break;
                        }

                    }
                    auto ip=SviInstruktori.begin();
                    for(ip=SviInstruktori.begin(); ip!=SviInstruktori.end(); ip++)
                    {
                        if(ip->getIme()==b)
                        {
                            break;
                        }
                    }
                    SviCasovi.push_back(NoviCas(*ip,*ik));
                }
                if(k==2)
                {
                    system("cls");
                    for(auto ik=SviCasovi.begin(); ik!=SviCasovi.end(); ik++)
                    {
                        cout<<endl<<endl<<endl<<endl<<endl;
                        ik->ispisiCas();
                    }
                }
                if(k==3)
                {
                    int a,b;
                    cout<<"Unesite prvo Id instukotra koji drzi cas pa skijasa koji dolazi na cas"<<endl;
                    cin>>a;
                    cin>>b;
                    for(auto ik=SviCasovi.begin(); ik!=SviCasovi.end(); ik++)
                    {
                        if(ik->getIDinstukotra()==a && ik->getIDskijasa()==b)
                        {
                            int k,o;
                            cout<<"Trenutno vreme: "<<endl;
                            cout<<ik->getVreme()<<endl;
                            cout<<"Unesite vreme novog casa"<<endl;
                            cin>>k>>o;
                            Vreme p(k,o);
                            ik->setOV(p);
                            break;

                        }

                    }
                }
            }
            while(k!=0);
        }


    }
    while(1);

    return 0;
}
