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
    lik.Ispisi();
    Datum abc;
    abc.Ispisi();
    return 0;
}
