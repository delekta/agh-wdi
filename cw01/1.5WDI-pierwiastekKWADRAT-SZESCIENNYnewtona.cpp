//napisac program wyznaczajacy pierwiastek kwadratowy ze wzoru NEWTONA
//wzor Newtona-->A(n+1)=((A(n)*A(n)+liczba)/A)/2
//+pierwiastek 3 stopnia
#include <iostream>
#define N 100
using namespace std;

int main()
{
    double a,b;//prawie losowa liczba
    a=b=2;
    double pierw;//pierwastek
    cout<<"Z jakiej liczby policzyc ci pierwiastek kwadratowy i szescienny: ";
    cin>>pierw;
    for(int i=0;i<N;i++)
    {
        a=((a*a+pierw)/a)/2;
    }
    cout<<"Pierwiastek kwadratowy z "<<pierw<<" = "<<a;

    for(int i=0;i<N;i++)//||BONUS||-->pierwiastek szescienny
    {
        b=(b+(pierw/(b*b)))/2;
    }
    cout<<endl<<"Pierwiastek szescienny z "<<pierw<<" = "<<b;




    return 0;
}
