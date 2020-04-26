#ifndef VREME_HPP_INCLUDED
#define VREME_HPP_INCLUDED

class Vreme{

protected:
    int minut;
    int sat;
public:
    Vreme():sat(13), minut(0){}

    vreme(int sat1, int minut1){
        sat=sat1;
        minut=minut1;
    }
};

#endif // VREME_HPP_INCLUDED
