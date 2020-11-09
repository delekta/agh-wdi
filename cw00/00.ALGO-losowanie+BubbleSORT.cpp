#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int n;//ile liczb
    int p,k;//p-poczatek zakresu losowania//k-koniec
    bool f;//zmienna bool potrzebna do Bubble Sorta
    int schowek;//przechowuje wartosc tablicy w Bubble Sort
    cout<<"Ile liczb wylosowac: ";
    cin>>n;
    cout<<"Na jakim zakresie losowac liczby p...k: "<<endl;
    cout<<"p = ";
    cin>>p;
    cout<<"k = ";
    cin>>k;
    int tab[n];
    if(k>p)
    {
         for(int i=0;i<n;i++)
        {
            tab[i]=rand()%(k+1-p) +p;//k+1 zeby wyszedl dobry zakres
        }
        cout<<endl<<"Wylosowane "<<n<<" liczb: ";//duzo endl dla efektu wizualnego
        for(int i=0;i<n;i++)
        {
            cout<<tab[i]<<" ";
        }
        do//Bubble Sort
        {
            f=true;
            for(int i=0;i<n-1;i++)//n-1 bo nizej masz tab[i+1] a nie mozesz wyjsc poza tablice
            {
                if(tab[i]>tab[i+1])
                {
                    swap(tab[i],tab[i+1]);
                    f=false;
                }
                /*{//swap działa lepiej,ale ta wersja tez spoko
                    schowek=tab[i];
                    tab[i]=tab[i+1];
                    tab[i+1]=schowek;
                    f=false;
                }*/
            }
        }while(f!=true);//srednik po while w do..while//petla sie skonczy gdy f=true czyli gdy petla for przejdzie cala tablice bezzadnej zmiany->tablica juz posortowana
        cout<<endl<<endl<<"Posortowane "<<n<<" liczb z przedzialu "<<p<<"..."<<k<<" : ";
        for(int i=0;i<n;i++)
        {
            cout<<tab[i]<<" ";
        }
        cout<<endl;
    }
    else cout<<"BLAD-zle wpisany przedzial";
    return 0;
}
