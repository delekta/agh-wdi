//znalaezc wyrazy poczatkowe zamiast 1,1 o najmniejszej sumie aby w ciagu analogicznym do fibonaciego
//wystapil wyraz rowny numerowi biezacego roku
#include <iostream>

using namespace std;

int czy_istnieje_fibonaci(int a,int b,int szukana)
{
    while(a<=szukana)
    {
        if(a==szukana)return 1;
        a+=b;
        b=a-b;
    }
    return 0;
}



int main()
{
    int szukana;
    bool f=true;
    int suma=1;
    cout<<"Obecnosc jakiej liczby sprawdzic: ";
    cin>>szukana;
    while(f)
    {
        int a=suma;
        int b=0;
        while(a>0)
        {
            if(czy_istnieje_fibonaci(a,b,szukana))
            {
               cout<<"Zeby wystapil wyraz "<<szukana<<" w ciagu analogicznym do ciagu fibonaciego ciag musi zaczynac sie od a = "<<a<<" i b = "<<b<<" dla tych wartosci suma = "<<suma<<" jest mozliwe najmniejsza ";
               f=false;
            }
            a--;
            b++;
        }
        suma++;
    }
     return 0;
}
