//Napisz program wczytuj¹cy liczbê naturaln¹ z klawiatury i odpowiadaj¹cy na pytanie,
//czy liczba ta jest wielokrotnoœci¹ dowolnego wyrazu ci¹gu danego wzorem A(n)=n*n+n+1
#include <iostream>
bool jestWILOKROTNOSCIAciagu(int liczba)
{
    int a;              //zaczynamy od i=1 bo dla 0 nie ma sensu, kazda liczba jest wilokrotnoscia 1
    for(int i=1;i*i<=liczba;i++)//Mussi byc "<=" bo np dla 121 zeby sprawdzic o jeszcze 11!!//przy sqrt()ta sama zasada
    {
        //i=i*i+i+1; //tak nie moze byc bo zmienia wartosc i w kolejnej iteracji i ma wieksza wartosc, a co z tym idie omija niektore przypadki jak 31
        a=i*i+i+1;
        if(liczba%a==0)return true;
    }
    return false;
}
using namespace std;
int main()
{
    int liczba;
    cout<<"Podaj liczbe, sprawdze czy jest wielokrotnoscia ciagu A(n)=n*n+n+1: ";
    cin>>liczba;
    if(jestWILOKROTNOSCIAciagu(liczba))cout<<"----JEST----";
    else cout<<"----NIE JEST----";
    return 0;
}
