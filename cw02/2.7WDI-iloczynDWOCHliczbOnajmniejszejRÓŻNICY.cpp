//Napisa� program wczytuj�cy liczb� naturaln� z klawiatury i rozk�adaj�cy
//j� na iloczyn 2 liczb o najmniejszej r�nicy. Np. 30=5*6, 120=10*12.
#include <iostream>
#include <cmath>
using namespace std;
void iloczyn_liczb_o_najmniejszej_roznicy(int liczba)
{
    int i;
    for(i=sqrt(liczba);i>=0;i--)
    {
        if(liczba%i==0)break;
    }
    cout<<"Liczbami o najmniejszej roznicy ktorych iloczyn jest rowny "<<liczba<< " sa "<<i<<" oraz "<<liczba/i;
}
int main()
{
    int liczba;
    cout<<"Podaj liczbe, a znajde liczby o najmniejszej roznicy ktorych iloczyn jest rowny danej liczbie: ";
    cin>>liczba;
    iloczyn_liczb_o_najmniejszej_roznicy(liczba);
    return 0;
}
