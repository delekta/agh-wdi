//
// Created by Kamil Delekta on 14.11.2019.
//
// Uzywajac funkcji z poprzedniego zadania prosze napisac funkcje rozwiazujace uklad 2 równan o 2 niewiadomych
#include <iostream>
using namespace std;
struct ulamek {
    int l;
    int m;
};
struct rownanie {
    ulamek a, b, c;
};
struct uklad {
    rownanie g;//rownanie pierwsze "gora"
    rownanie d;//rowananie drugie "dol"
};
int nwd(int a, int b) {
    do{
        int t = b;
        b = a  %= b;
        a = t;
    }while(b != 0);
        return a;
}
ulamek skroc(ulamek u) {
    int d = nwd(u.l, u.m);
    u.l /= d;
    u.m /= d;
    return u;
}
ulamek dodaj(ulamek a, ulamek b) {
    ulamek w;
    w.l = a.l * b.m + b.l * a.m;
    w.m = a.m * b.m;
    return skroc(w);
}

ulamek odejmij(ulamek a, ulamek b) {
    ulamek w;
    w.l = a.l * b.m - b.l * a.m;
    w.m = a.m * b.m;
    return skroc(w);
}

ulamek pomnoz(ulamek a, ulamek b) {
    ulamek w;
    w.l = a.l * b.l;
    w.m = a.m * b.m;
    return skroc(w);
}

ulamek dzielenie(ulamek a, ulamek b) {
    ulamek w;
    w.l = a.l * b.m;
    w.m = a.m * b.l;
    return skroc(w);
}

ulamek potegowanie(ulamek u, int p)//p-potega
{
    ulamek w;
    w.l = 1;
    w.m = 1;
    for (int i = 1; i <= p; i++) {
        w.l *= u.l;
        w.m *= u.m;
    }
    return w;
}

ulamek wczytaj() {
    ulamek u;
    cin >> u.l;
    cin >> u.m;
    return u;
}

void wypisz(ulamek u) {
    cout << u.l << "/" << u.m;
}

ulamek wyznacznik(ulamek a, ulamek b, ulamek c, ulamek d) {
    // a b
    // c d
    return odejmij(pomnoz(a, d), pomnoz(b, c));
}

int main() {
    uklad u;
    cout << "WSPOLCZYNNIKI NIEWYMIERNE-->WPISUJ licznik[spacja]mianownik[enter]" << endl;
    cout << "Podaj dwa rownania:" << endl;
    cout << "Postac ax+bx=c" << endl;
    cout << "Wpisz pierwsze rownanie: " << endl;
    cout << "a: ";
    cin >> u.g.a.l >> u.g.a.m;
    cout << "b: ";
    cin >> u.g.b.l >> u.g.b.m;
    cout << "c: ";
    cin >> u.g.c.l >> u.g.c.m;
    cout << "Wpisz drugie rownanie: " << endl;
    cout << "a: ";
    cin >> u.d.a.l >> u.d.a.m;
    cout << "b: ";
    cin >> u.d.b.l >> u.d.b.m;
    cout << "c: ";
    cin >> u.d.c.l >> u.d.c.m;
    ulamek W = wyznacznik(u.g.a, u.g.b, u.d.a, u.d.b);
    ulamek Wx = wyznacznik(u.g.c, u.g.b, u.d.c, u.d.b);
    ulamek Wy = wyznacznik(u.g.a, u.g.c, u.d.a, u.d.c);
    if (W.l != 0) {
        ulamek x = dzielenie(Wx, W);
        ulamek y = dzielenie(Wy, W);
        cout << "Rozwiazaniami tego rowania sa x= ";
        wypisz(x);
        cout << " i y= ";
        wypisz(y);
    }
    if (W.l == 0) {

        if (Wx.l == 0 && Wy.l == 0)cout << "Uklad nioznaczony! ";
        else cout << "Uklad sprzeczny! ";
    }

    return 0;
}