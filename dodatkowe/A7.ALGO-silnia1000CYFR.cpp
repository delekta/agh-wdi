#include <iostream>
using namespace std;

int main()
{
    const int MAX=3000;
    int tab[MAX];
    for(int i=0;i<MAX;i++)tab[i]=0;//manualne zerowaie tablicy
    tab[0]=1;//wazne!
    int n;
    cout<<"Podaj liczbe, a policze silnie: ";
    cin>>n;
    int len=1;//length-długosc//musi byc len=1 na początku bo nie ruszy!
    for(int i=1;i<=n;i++)
    {
        int reszta=0;//liczba która przechodzi do nastepnej szufladki
        for(int j=0;j<len;j++)
        {
            tab[j]=tab[j]*i+reszta;
            if(tab[len-1]>9)len++;//len-1,bo o iletab[j] by działało dla j=0 to pozniej by juz tak nie liczyło, a takto zaczyna od len=1 i i sprawdza za kazdym razem czy ostatnia cyfra nie jest >9 co znaczy czy nie zwiekszyła cyfr tej liczby
            reszta=tab[j]/10;
            tab[j]%=10;
        }
    }
    cout<<n<<"! = ";
    for(int i=len-1;i>=0;i--)cout<<tab[i];

    return 0;
}//zmienna len najwazniesza w algorytmie
