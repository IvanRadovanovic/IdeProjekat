#ifndef DATUM_HPP_INCLUDED
#define DATUM_HPP_INCLUDED

using namespace std;

class Datum
{
protected:
    int dan;
    int mesec;
    int godina;
public:
    Datum()
    {
        dan=3;
        mesec=12;
        godina=2020;
    }
    Datum(int dan1, int mesec1,int godina1)
    {
        if(dan1<=31 && dan1>=1)
        {
            dan=dan1;
        }
        else
        {
            cout<<"Greska u datumu"<<endl;
        }
        if(mesec1<=12 && mesec1>=1)
        {
            mesec=mesec1;
        }
        else
        {
            cout<<"Greska u datumu"<<endl;
        }
        if(godina1==2019 || godina1==2020)
        {
            godina=godina1;
        }
        else
        {
            cout<<"Greska u datumu"<<endl;
        }
    }
    Datum(const Datum &a) : Datum(a.dan, a.mesec, a.godina){}

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
        if(godina1==2019 || godina1==2020)
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
    friend ostream& operator<<(ostream& izlaz, const Datum& o);
};
ostream& operator<<(ostream& izlaz, const Datum& o){

izlaz<<"Datum - ispis"<<endl;

izlaz<<"Dan: "<<o.dan<<endl;

izlaz<<"Mesec: "<<o.mesec<<endl;

izlaz<<"Godina:"<<o.godina<<endl<<endl;

return izlaz;

}
#endif // DATUM_HPP_INCLUDED
