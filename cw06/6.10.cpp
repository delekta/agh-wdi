//
// Created by Kamil Delekta on 15.01.2020.
//
//Dana jest tablica int t[N]. Proszê napisaæ program zliczaj¹cy liczbê “enek” o okreœlonym iloczynie
#include <iostream>
using namespace std;
const int N = 8;
//wersja1
void ile_enek(int t[N], int iloczyn_wynik, int &licznik, int iloczyn = 1, int idx = 0){
    if(iloczyn == iloczyn_wynik) licznik++;
    else if(iloczyn > iloczyn_wynik) return;
    else if(idx == N);
    else{
        ile_enek(t, iloczyn_wynik, licznik, iloczyn * t[idx], idx + 1);
        ile_enek(t, iloczyn_wynik, licznik, iloczyn, idx + 1);
    }
}
int ile_enek_aux(int t[N], int iloczyn) {
    int licznik = 0;
    ile_enek(t, iloczyn, licznik);
    return licznik;
}
//wersja 2 = rekurencja zliczajaca
int ile_enek_c(int t[N], int iloczyn_wynik, int licznik = 0, int iloczyn = 1, int idx = 0){
    if(iloczyn == iloczyn_wynik) return 1;
    else if(iloczyn > iloczyn_wynik) return 0;
    else if(idx == N);
    else{
        licznik += ile_enek_c(t, iloczyn_wynik, licznik, iloczyn * t[idx], idx + 1) + ile_enek_c(t, iloczyn_wynik, licznik, iloczyn, idx + 1);
    }
    return licznik;
}
int main() {
    int t[N] = {11, 2, 24, 4, 6, 8, 12, 3};
    cout << ile_enek_aux(t, 12) << endl;
    cout << ile_enek_c(t, 12) << endl;
    return 0;
}
