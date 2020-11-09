//Napisz program wczytuj¹cy liczbê naturaln¹ z klawiatury i odpowiadaj¹cy na pytanie,
//czy liczba naturalna jest palindromem, a nastêpnie czy jest palindromem w systemie dwójkowym
#include <iostream>
using namespace std;
bool jestPALINDROMEM(int liczba,int podstawa)
{
  int rewers=0;//musisz daac na poczatku 0,inaczej nie dziala
  int kopia=liczba;

  while(liczba>0)
  {
  rewers=rewers*10+liczba%podstawa;//wazne '%'
  liczba/=podstawa;
  }
  if(rewers==kopia)return true;
  else return false;
}
bool czy_jest_palindromem_w_dwojkowym(int liczba)//pamietaj o int
{
    int tab[100];
    int i=0;
    while(liczba>0)
    {
        tab[i++]=liczba%2;
        liczba/=2;
    }
    int k=0;
    for(int j=i-1;j>=k;j--)
    {
        if(!(tab[j]==tab[k++]))return false;//jesli liczba przechodzac tablice od przodu i od tylu jest taka sama to ta liczba jest palindromem
    }
    return true;
}
int main()
{
    int liczba;
    cout<<"Podaj liczbe, sprawdze czy jest palindromem: ";
    cin>>liczba;
    if(jestPALINDROMEM(liczba,10))cout<<"Liczba "<<liczba<< " JEST palindromem w systemie dziesitnym"<<endl;//w systemie dziesietnym
    else cout<<"Liczba "<<liczba<<" NIE JEST palindromem w systemie w systemie dziesietnym"<<endl;
    if(czy_jest_palindromem_w_dwojkowym(liczba))cout<<"JEST palindromem w systemie dwojkowym";
    else cout<<"Nie jest palindromem w systemie dwojkowym";
    return 0;
}
