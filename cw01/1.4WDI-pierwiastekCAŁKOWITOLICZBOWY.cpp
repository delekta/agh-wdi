//napisac program obliczajacy pierwiastek calkowitoliczbowy z liczby naturalnej korzystajac z zaleznosci 1+3+5+...+n=n^2
#include <iostream>

using namespace std;

int main()
{
    int suma=1;
    int n=1;
    int kolejne_wyrazy=3;
    int nasza_liczba;
    cout<<"Z jakiej liczby policzyc pierwiastek: ";
    cin>>nasza_liczba;
    while(suma<=nasza_liczba)//tu musi wchodzic przy rownosci bo wtedy tu n++,a przy wyniku n-1
    {
        suma+=kolejne_wyrazy;
        kolejne_wyrazy+=2;
        n++;
    }
    cout<<"Pierwiastek calkowitoliczbowy z "<<nasza_liczba<<" = "<<n-1;


    return 0;
}
