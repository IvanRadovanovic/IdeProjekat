#ifndef OSOBA_HPP_INCLUDED
#define OSOBA_HPP_INCLUDED

using namespace std;

class Osoba
{

protected:
    string ime;
    string prezime;
public:
    Osoba()
    {
        ime="x";
        prezime="y";
    }
    Osoba(string x, string y)
    {
        ime=x;
        prezime=y;
    }
    string getIme()const
    {
        return ime;
    }
    string getPrezime()const
    {
        return prezime;
    }
    void setIme(string x){
        ime=x;
    }
    void setPrezime(string y){
        ime=y;
    }
    void JaSam()const{
        cout<<ime<<" "<<prezime<<endl;
    }


};
#endif // OSOBA_HPP_INCLUDED
