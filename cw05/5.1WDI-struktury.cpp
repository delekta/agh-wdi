//
// Created by Kamil Delekta on 14.11.2019.
//
//Prosze napisanie podstawowe operacje na ulamkach, m.in. dodawanie, odejmowanie,
//mno¿enie, dzielenie,potegowanie, skracanie, wypisywanie i wczytywanie
#include <iostream>
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
        b = a%b;
        a = t;
    }while(b != 0);
        return a;
}
ulamek skroc(ulamek u)
{
    int d=nwd(u.l,u.m);
    u.l/=d;
    u.m/=d;
    return u;
}
ulamek dodawanie(ulamek a,ulamek b)
{
    ulamek w;
    w.l=a.l*b.m+b.l*a.m;
    w.m=a.m*b.m;
    return skroc(w);
}
ulamek odejmowanie(ulamek a,ulamek b)
{
    ulamek w;
    w.l=a.l*b.m-b.l*a.m;
    w.m=a.m*b.m;
    return skroc(w);
}
ulamek mnozenie(ulamek a,ulamek b)
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
ulamek potegowanie(ulamek u,int p)//p-potega
{
    ulamek w;
    w.l=1;
    w.m=1;
    for(int i=1;i<=p;i++)
    {
        w.l*=u.l;
        w.m*=u.m;
    }
    return skroc(w);
}
ulamek wczytywanie()
{
    ulamek u;
    cin >> u.l;
    cin >> u.m;
    return u;
}
void wypisywanie(ulamek u)
{
    cout<<"("<<u.l<<"/"<<u.m<<")";
}
int main()
{

    cout<<"Wpisywanie ulamka licznik[spacja]mianownik: "<<endl;
    cout<<"Jakie ulamki podzielic: ";
    ulamek u1=wczytywanie();
    ulamek u2=wczytywanie();
    wypisywanie(dzielenie(u1,u2));
    cout<<endl<<"Jaki ulamek spotegowac: ";
    ulamek u3=wczytywanie();
    cout<<"Do jakiej potegi go podniesc: ";
    int p;
    cin >> p ;
    wypisywanie(potegowanie(u3,p));
    cout<<"Podaj ulamki do odejmowania: ";
    ulamek u10 = wczytywanie();
    ulamek u4 = wczytywanie();
    wypisywanie(odejmowanie(u10,u4));
    cout<<"Jakie ulamki dodac: ";
    ulamek u6 = wczytywanie();
    ulamek u5 = wczytywanie();
    wypisywanie(dodawanie(u6,u5));
    cout<<"Jakie ulamki pomnozyc: ";
    ulamek u7 = wczytywanie();
    ulamek u8 = wczytywanie();
    wypisywanie(mnozenie(u7,u8));
    return 0;
}
