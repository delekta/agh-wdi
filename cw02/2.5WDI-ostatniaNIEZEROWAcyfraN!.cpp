//made by kamildelekta
//Napisa� program, kt�ry wyznacza ostatnia niezerow� cyfra N!
//Program powinien dzia�a� dla N rz�du 1000000
#include <iostream>
using namespace std;
void wypiszOSTATNIAniezerowaCYFREsilnia(int liczba)
{
    int silnia=1;//wartosc startowa-->1WAZNE
    for(int i=2;i<=liczba;i++)
    {
        silnia*=i;
        while(silnia%10==0)silnia/=10;
        silnia%=10000;
    }
    cout<<silnia%10;
}
int main()
{
    int liczba;
    cout<<"Podaj liczbe, wypisze jej ostatnia niezerowa cyfre N!(silnia): ";
    cin>>liczba;
    wypiszOSTATNIAniezerowaCYFREsilnia(liczba);
    return 0;
}
