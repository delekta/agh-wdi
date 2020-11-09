//napisac program wypisujacy elementy ciagu fibonacciego mniejsze od miliona
#include <iostream>

using namespace std;

int main()
{
    int a=1,b=0;//b=0 zeby wypisalo dwie jedynki
    while(a<1000000)
    {
        cout<<a<<" ";
        a+=b;//jesli tu mamy a2=a1+b
        b=a-b;//tu przypisujemy b wartosc starego a(a1) czyli b=a2-b|bo z rownaia wyzej mamy a1=a2-b
    }
    return 0;
}
