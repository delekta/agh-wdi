//Dana jest tablica int t[MAX][MAX] wype³niona liczbami naturalnymi.
//Proszê napisaæ funkcjê która zwraca wiersz i kolumnê dowolnego elementu,
// dla którego iloraz sumy elementów w kolumnie w którym le¿y element
// do sumy elementów wiersza w którym le¿y element jest najwiêksza.
#include <iostream>
#include <time.h>//NULL
#include <cstdlib>//musi byc do rand
#define MAX 10
using namespace std;

void wypelnijTABLICEdwuwymiarowaLOSOWO(int tablica[MAX][MAX])
{
    srand(time(NULL));
    for(int y=0;y<MAX;y++)
    {
        for(int x=0;x<MAX;x++)tablica[y][x]=rand()%100+1;//losowe z przedzialu 1..100
    }
}
void wypiszTABLICEdwuwymiarowa(int tablica[MAX][MAX])//jak deklarujesz to piszesz int tablica[MAX][MAX]
{
    for(int y=0;y<MAX;y++)
    {
        for(int x=0;x<MAX;x++)
        {
            cout<<tablica[y][x]<<"\t";
        }
        cout<<endl;
    }
}
void wypiszINDEKSnajwiekszejKOLUMNY(int tablica[MAX][MAX])//jak liczysz sume w kolumnie to x stałe i przechodzi na po y
{
    int najw=0;
    int suma=0;
    int x;
    for(x=0;x<MAX;x++)
    {
        int sumaAKT=0;
        for(int y=0;y<MAX;y++)
            {
                sumaAKT+=tablica[y][x];
            }
            //cout<<"suma: "<<suma<<" sumaAKTUALNA: "<<sumaAKT<<" INDEKS NAJWIEKSZEJ: "<<najw<<endl;
            if(sumaAKT>suma)
            {
                najw=x;
                suma=sumaAKT;
            }
    }
    cout<<"KOLUMNA: "<<najw<<" ";
}
void wypiszINDEKSnajmniejszegoWIERSZA(int tablica[MAX][MAX])
{
    int najm=0;
    bool pierwsza=true;
    int suma=0;
    int y;
    for(y=0;y<MAX;y++)
    {
        int sumaAKT=0;
        for(int x=0;x<MAX;x++)
            {
                sumaAKT+=tablica[y][x];
            }
            if(pierwsza||sumaAKT<suma)
            {
                pierwsza=false;
                najm=y;
                suma=sumaAKT;
            }
    }
    cout<<"WIERSZ: "<<najm<<" ";
}
int main()
{
    int tablica[MAX][MAX];
    wypelnijTABLICEdwuwymiarowaLOSOWO(tablica);
    wypiszTABLICEdwuwymiarowa(tablica);
    cout<<"Najwiekszy iloraz dla: ";//bo iloraz jest najwieksy kiedy kolumna jest najwieksza i kiedy wiersz jest mozliwie najmniejszy!
    wypiszINDEKSnajwiekszejKOLUMNY(tablica);
    wypiszINDEKSnajmniejszegoWIERSZA(tablica);
    return 0;
}
