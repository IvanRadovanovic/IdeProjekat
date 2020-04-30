#ifndef VREME_HPP_INCLUDED
#define VREME_HPP_INCLUDED

class Vreme{

protected:
    int minut;
    int sat;
public:
    Vreme(): minut(0), sat(12){}

    Vreme(int sat1, int minut1){

        minut=minut1;
        sat=sat1;
    }
    Vreme(const Vreme& a): minut(a.minut),sat(a.sat){}
    void setVreme(Vreme v){
        minut=v.minut;
        sat=v.sat;
    }
};

#endif // VREME_HPP_INCLUDED
