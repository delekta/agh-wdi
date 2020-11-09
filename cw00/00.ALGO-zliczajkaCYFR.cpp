#include <iostream>
using namespace std;
int main()
{
    long double liczba;
    cout<<"Wklej liczbe ktorej cyfry mam policzyc: ";
    cin>>liczba;
    int i=0;
    for(i=0; liczba >=1; i++)
    {
        liczba=liczba/10;
    }
    cout<<"Liczba ma : "<<i<<" cyfry!";
    return 0;
}
