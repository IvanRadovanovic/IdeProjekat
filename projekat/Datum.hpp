#ifndef DATUM_HPP_INCLUDED
#define DATUM_HPP_INCLUDED
#include <string>
using namespace std;

class Datum
{
protected:
    int dan;
    int mesec;
    int godina;
public:
    Datum(int dan1=3, int mesec1=12,int godina1=2020)
    {
        dan=dan1;
        mesec=mesec1;
        godina=godina1;

    }
    Datum(const Datum &a) : dan(a.dan),mesec(a.mesec),godina(a.godina) {}

    int getDan()const
    {
        return dan;
    }
    int getMesec()const
    {
        return mesec;
    }
    int getGodina()const
    {
        return godina;
    }
    void setDan(int dan1)
    {
        if(dan1<=31 && dan1>=1)
        {
            dan=dan1;
        }
        else
        {
            cout<<"Greska u datumu"<<endl;
        }
    }
    void setMesec (int mesec1)
    {
        if(mesec1<=12 && mesec1>=1)
        {
            mesec=mesec1;
        }
        else
        {
            cout<<"Greska u datumu"<<endl;
        }
    }
    void setGodina(int godina1)
    {
        if(godina1==2021 || godina1==2020)
        {
            godina=godina1;
        }
        else
        {
            cout<<"Greska u datumu"<<endl;
        }
    }
    void Ispisi()const
    {
        cout<<dan<<"."<<mesec<<"."<<godina<<"."<<endl;
    }
    int poredenje (){
        return (godina*10000+mesec*1000000+dan*100000000);
    }
    friend ostream& operator<<(ostream& izlaz, const Datum& o);
};
ostream& operator<<(ostream& izlaz, const Datum& o)
{

    izlaz<<"Datum - ispis"<<endl;

    izlaz<<"Dan: "<<o.dan<<endl;

    izlaz<<"Mesec: "<<o.mesec<<endl;

    izlaz<<"Godina:"<<o.godina<<endl;

    return izlaz;

}
#endif // DATUM_HPP_INCLUDED
