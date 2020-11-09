//
// Created by Kamil Delekta on 15.01.2020.
//
//Dana jest tablica int t[N][N] zawieraj¹ca liczby naturalne. Proszê napisaæ funkcjê, która sprawdza  czy z tablicy
//mo¿na usun¹æ jeden wiersz i dwie kolumny, tak aby ka¿dy z pozosta³ych  elementów  tablicy w zapisie dwójkowym
//posiada³ nieparzyst¹ liczbê jedynek
#include <iostream>
using namespace std;
const int N = 8;
bool nieparzysta_ilosc(int liczba){
    int licznik = 0;
    while(liczba > 0){
        if(liczba % 2 == 1) licznik++;
        liczba /= 2;
    }
    return licznik %2 == 1;
}
bool sprawdz(int t[N][N], int w1, int k1, int k2){
    for(int w = 0; w < N; w++){
        if(w == w1) continue;
        for(int k = 0; k < N; k++){
               if(k == k1) continue;
               if(k == k2) continue;
               if(!(nieparzysta_ilosc(t[w][k]))) return false;
        }
    }
    return true;
}
bool wybierz_wieze_kolumny(int t[N][N]){
    for(int w = 0; w < N; w++){
        for(int k1 = 0; k1 < N - 1; k1++){
            for(int k2 = k1 + 1; k2 < N; k2++){
                if(sprawdz(t, w, k1 , k2)) {
                    return true;
                }
            }
        }
    }
    return false;
}
int main() {
    //cout << nieparzysta_ilosc(7);
    int t[N][N] = {
            {7, 7, 7, 7, 7, 7, 7, 7},
            {7, 7, 7, 7, 7, 7, 7, 7},
            {7, 7, 7, 7, 31, 7, 7, 7},
            {7, 7, 7, 7, 7, 5, 5, 7},
            {7, 7, 7, 7, 7, 7, 7, 7},
            {7, 5, 7, 7, 7, 5, 7, 7},
            {7, 7, 7, 7, 7, 7, 7, 7},
            {7, 7, 7, 7, 7, 7, 7, 7}
    };
    cout << wybierz_wieze_kolumny(t);
    return 0;
}
