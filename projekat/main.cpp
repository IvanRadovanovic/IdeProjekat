#include <iostream>
#include "Datum.hpp"
#include "Instruktor.hpp"
#include "Osoba.hpp"
#include "Radnik.hpp"
#include "Skijas.hpp"
#include "Staza.hpp"
#include "Cas.hpp"

using namespace std;


int main()
{
    Osoba lik("Ivan", "Radovanovic");
    lik.JaSam();
    Datum abc;
    abc.Ispisi();
    return 0;
}
/* Ideja mi je da napravim fukcionalnost zakazivanja casova kao i njihovog menjanja odtkazivanja izvr�avanja itd.
