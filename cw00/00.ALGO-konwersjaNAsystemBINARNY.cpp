#include <iostream>
using namespace std;
void wypisz_w_systemie_dwojkowy(int liczba)
{
    int tablica[100];
    int i=0;
    while(liczba>0)
    {
        tablica[i++]=liczba%2;//po zmianie tych dwojek na 8 mozna robic kowersje na system owsemkowy
        liczba/=2;
    }
    for(int j=i-1;j>=0;j--)//j musi byc i-1!!!
    {
        cout<<tablica[j];
    }
}
int main()
{
    int liczba;
    cout<<"Podaj liczbe, a zamienie ja na system dwojkowy: ";
    cin>>liczba;
    wypisz_w_systemie_dwojkowy(liczba);
    return 0;
}
