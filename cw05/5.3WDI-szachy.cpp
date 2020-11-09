//
// Created by Kamil Delekta on 14.11.2019.
//
//Proszę napisac funkcję, która odpowiada na pytanie: czy zadne z dwa hetmany sie nie szachuja? Do funkcji należy przekazac położenie hetmanow
#include <iostream>
#include <time.h>
#include <cstdlib>
#define MAX 10
using namespace std;
struct hetman {
    int w; // wiersz 0..99
    int k; // kolumna 0..99 };
};
struct dane {
    hetman t[100]; // polo¿enie hetmanów
    int N;         // liczba hetmanów };
};
bool szachuje(dane d)
{
    for(int i=0;i<d.N;i++)
    {
        for(int j=i+1;j<d.N;j++)
        {
            if(d.t[i].w==d.t[j].w || d.t[i].k==d.t[j].k || abs(d.t[i].w-d.t[j].w)==abs(d.t[i].k-d.t[j].k))return true;
        }
    }
    return false;
}
void wypisz_szachownice(bool tab[MAX][MAX])//?//podajemy tablice zajete
{
    for(int y=0;y<MAX;y++)
    {
        for(int x=0;x<MAX;x++)
        {
            if(tab[y][x]==false)cout<<" _ ";
            else cout<<" H ";
        }
        cout<<endl;
    }
}
int main()
{
    srand(time(NULL));
    dane d;
    bool wpisany_teraz;
    cout<<"Ilu hetmanow ustawic na szachownicy(n<100): ";
    cin>>d.N;
    bool zajete[MAX][MAX];
    for(int y=0;y<MAX;y++)
    {
        for(int x=0;x<MAX;x++)
        {
            zajete[y][x] = false;
        }
    }
    for(int i=0;i<d.N;i++)
    {
        do
        {
            hetman h;
            h.w=rand()%MAX;
            h.k=rand()%MAX;
            wpisany_teraz = false;
            if(zajete[h.w][h.k]==false)
            {
                d.t[i] = h;//?
                zajete[h.w][h.k] = true;
                wpisany_teraz = true;
            }
        }while(wpisany_teraz != true);//musi byc d.t[]wpisane=false

    }
    wypisz_szachownice(zajete);
    cout<<"Czy hetmani sie szachuja? ";
    if(szachuje(d))cout<<"---TAK---";
    else cout<<"---NIE---";
    return 0;
}

