#ifndef TEZINASTAZE_HPP_INCLUDED
#define TEZINASTAZE_HPP_INCLUDED

using namespace std;

enum BojaStaze {Zelena, Plava, Zuta, Crvena};

class TezinaStaze
{
protected:
    BojaStaze Boja1;
    int Duzina;
    int nagib;
public:
    TezinaStaze():Boja1(Zelena),Duzina(200),nagib(10){}

};

#endif // TEžINASTAZE_HPP_INCLUDED
