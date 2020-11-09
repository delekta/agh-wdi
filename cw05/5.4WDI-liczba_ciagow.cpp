//
// Created by Kamil Delekta on 14.11.2019.
//
//Dana jest tablica ulamek t[100] zawierajaca ciag liczb wymiernych. Proszê napisaæ funkcje, która policzy wystepujace w tablicy ciagi arytmetyczne (LA)
//i geometryczne (LG) o dlugoœci wiêkszej nie 2. Funkcja powinna zwrócic wartosci 1 gdy LA>LG, wartosci-1 gdy LA<LG oraz 0 gdy LA=LG
#include <iostream>
#define MAX 11
using namespace std;
struct ulamek
{
    int l;
    int m;
};
int nwd(int a, int b)
{
    do{
        int t = b;
        b = a % b;
        a = t;
    }while(b != 0); //do while konczy sie ;
}
ulamek skroc(ulamek u)
{
    int d=nwd(u.l,u.m);
    u.l/=d;
    u.m/=d;
    return u;
}
ulamek dodaj(ulamek a,ulamek b)
{
    ulamek w;
    w.l=a.l*b.m+b.l*a.m;
    w.m=a.m*b.m;
    return skroc(w);
}
ulamek odejmij(ulamek a,ulamek b)
{
    ulamek w;
    w.l=a.l*b.m-b.l*a.m;
    w.m=a.m*b.m;
    return skroc(w);
}
ulamek pomnoz(ulamek a,ulamek b)
{
    ulamek w;
    w.l=a.l*b.l;
    w.m=a.m*b.m;
    return skroc(w);
}
ulamek dzielenie(ulamek a,ulamek b)
{
    ulamek w;
    w.l=a.l*b.m;
    w.m=a.m*b.l;
    return skroc(w);
}
ulamek potegowanie(ulamek u)//p-potega
{
    ulamek w;
    w.l=1;
    w.m=1;
    for(int i=1;i<=2;i++)
    {
        w.l*=u.l;
        w.m*=u.m;
    }
    return w;
}
ulamek wczytaj()
{
    ulamek u;
    cin>>u.l;
    cin>>u.m;
    return u;
}
void wypisz(ulamek u)
{
    cout<<"("<<u.l<<"/"<<u.m<<")";
}
bool taki_sam_ulamek(ulamek u,ulamek v)
{
    return u.l==v.l && u.m==v.m;
}
int licznik_ARYTMETYCZNY(ulamek t[MAX])
{
    int licznik = 0;
    bool started = false;
    ulamek dwa;
    dwa.l = 2;
    dwa.m = 1;
    for(int i=0;i<MAX-2;i++)
    {
        if(taki_sam_ulamek(pomnoz(t[i+1],dwa),dodaj(t[i], t[i+2])))
        {
            if(started==false)
            {
                started = true;
                licznik++;
            }
        }
        else
        {
            started = false;
        }


    }
    return licznik;
}
int licznik_GEOMETRYCZNY(ulamek t[MAX])
{
    int licznik = 0;
    bool started = false;
    for(int i=0;i<MAX-2;i++) {
        if (taki_sam_ulamek(potegowanie(t[i + 1]), pomnoz(t[i], t[i + 2]))) {
            if (started == false) {
                started = true;
                licznik++;
            }
        } else {
            started = false;
        }
    }
    return licznik;
}
int greater_set(ulamek t[]){//jak funkcja zwraca trzy wartosci to int bo bool tylko dwie
    int geo = licznik_GEOMETRYCZNY(t);
    int aryt = licznik_ARYTMETYCZNY(t);
    if(geo > aryt) return  -1;
    if(geo < aryt) return  1;
    if(geo == aryt) return 0;
}
int main()
{
    ulamek t[MAX] = {

            { 1, 2 },
            { 1, 4  },
            { 1, 8 },
            { 1, 3 },
            { 1, 32 },
            { 1, 64 },
            { 1, 128 },
            { 3, 2 },
            { 1, 3 },
            { 1, 9 },
            { 1, 27}
    };
    cout<<licznik_GEOMETRYCZNY(t)<<endl;
    cout<<licznik_ARYTMETYCZNY(t)<<endl;
    if(greater_set(t) == 1) cout<<"Liczba ciagow arytmetycznych jest wieksza";
    else if(greater_set(t) == -1) cout<<"Liczba ciagow geometrycznych jest wieksza";
    else cout<<"Zbiory sa rownoliczne";
    return 0;
}
