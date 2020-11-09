//ROZWIAZANIE ROWNANIA X^X=OBECNY ROK--> metoda bisekcji
#include <iostream>
#include <math.h>// lub <cmath>|OBOWIAZKOWO POTRZEBNA DO FUNKCJI fabs
using namespace std;
int main()
{
    double a=1,b=2020,x;
    double eps=1e-6;
    int rok;
    cout<<"Wpisz obecny rok: ";
    cin>>rok;
    while(fabs(pow(x,x)-rok)>eps)
    {
        x=(a+b)/2;
        if(pow(x,x)-rok>0)b=x;
        else a=x;
    }
    cout<<"X = "<<x;
    return 0;
}
