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

int main()
{
    citajTxt();
    Osoba lik("Ivan", "Radovanovic");
    return 0;
}
/* Ideja mi je da napravim fukcionalnost zakazivanja casova kao i njihovog menjanja odtkazivanja izvršavanja itd.*/
