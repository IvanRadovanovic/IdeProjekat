#ifndef VREME_HPP_INCLUDED
#define VREME_HPP_INCLUDED

class Vreme
{

protected:
    int minut;
    int sat;
public:
    Vreme(): minut(0), sat(12) {}

    Vreme(int sat1, int minut1)
    {

        minut=minut1;
        sat=sat1;
    }
    Vreme(const Vreme& a): minut(a.minut),sat(a.sat) {}
    void setVreme(Vreme v)
    {
        minut=v.minut;
        sat=v.sat;
    }
    void Ispisi ()const
    {
        cout<<sat<<"|"<<minut<<"|";
    }
    int poredenje (){
         return (sat*100+minut*10000);
    }
    friend ostream& operator<<(ostream& izlaz, const Vreme& o);
};

ostream& operator<<(ostream& izlaz, const Vreme& o)
{

    izlaz<<"Vreme - ispis"<<endl;

    izlaz<<"Sat: "<<o.sat<<endl;

    izlaz<<"Minut:"<<o.minut<<endl;

    return izlaz;

}
#endif // VREME_HPP_INCLUDED
