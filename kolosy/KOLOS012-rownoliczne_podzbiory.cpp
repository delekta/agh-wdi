//
// Created by Kamil Delekta on 01.12.2019.
//
//Dana jest tablica, zawierajaca liczby naturalne. Prosze napisac funkcje, ktora odpowiada na pytanie,
//czy z elementow tablicy (niekoniecznie wszystkich) mozna utworzyc dwa rownoliczne, niepuste podzbiory
//o jednakowej sumie elementow. Do funkcji nalezy przekazac wylacznie tablice t, funkcja powinna zwrocic
// wartosc typu bool
#include <iostream>
const int N = 4;
bool czy_mozna(int t[], int zbior1 = 0,int zbior2 = 0, int ile1 = 0, int ile2 = 0, int idx = 0){
    if(ile1 > 0 and ile2 > 0){
        if(zbior1 == zbior2 and ile1 == ile2){
            return true;
        }
    }
    if (idx == N) return false;
    else {
        return (czy_mozna(t, zbior1 + t[idx], zbior2, ile1 + 1, ile2, idx + 1)) ||
                   (czy_mozna(t, zbior1, zbior2, ile1, ile2, idx + 1)) ||
                   (czy_mozna(t, zbior1, zbior2 + t[idx], ile1, ile2 + 1, idx + 1));
    }
}
using namespace std;
int main() {
    int t[N] = {8, 10, 3, 1};
    cout << czy_mozna(t);
    return 0;
}
