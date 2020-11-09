//
// Created by Kamil Delekta on 30.11.2019.
//
//Dana jest tablica int t[N][N] (reprezentujšca szachownicę) wypełniona liczbami naturalnymi.
//W każdej kolumnie znajduje się dokładnie jedna wieża, której numer wiersza zawiera tablica int w[N].
//Proszę napisać funkcję która wybiera do usunięcia z szachownicy dwie wieże, tak abysuma liczb na
//polach szachowanych przez pozostałe wieże była najmniejsza. Do funkcji należyprzekazać tablice
// t i w, funkcja powinna zwrócić numery kolumn z których usunięto wieże.
#include <iostream>
const int N = 4;
using namespace std;
// stuktura w ktorej zapisujemy kolumny wiez do usuniecia
struct wieze{
    int k1;
    int k2;
};
void wyzeruj_tablice(bool bt[N][N], int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            bt[i][j] = 0;
        }
    }
}
void wypisz_tablice(bool bt[N][N], int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << bt[i][j] << " ";
        }
        cout << endl;
    }
}
// wiezeK1, wiezaK2 --> kolumny wiez ktore usuwamy
void zaznacz_szachowane(bool bt[N][N], int tw[], int N,int wiezaK1, int wiezaK2){
    //wypelnij wiersz
    for(int kw = 0; kw < N; kw++) {
        if (kw == wiezaK1) continue;
        if (kw == wiezaK2) continue;
        for (int k = 0; k < N; k++) {
            bt[tw[kw]][k] = 1;
        }
    }
    //wypelnij kolumne
    for (int k = 0; k < N; k++) {
        if (k == wiezaK1) continue;
        if (k == wiezaK2) continue;
        for(int w = 0; w < N; w++) {
            bt[w][k] = 1;
        }
    }
    // usun pola na ktorych stoja figury
    for (int k = 0; k < N; k++) {
        if (k == wiezaK1) continue;
        if (k == wiezaK2) continue;
        bt[tw[k]][k] = 0;
    }
}
int suma_szachowanych(bool bt[N][N], int wartosci[N][N], int N){
    int suma = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j ++){
            if(bt[i][j]){
                suma += wartosci[i][j];
            }
        }
    }
    return suma;
}
wieze najmniejsza_suma(int wartosci[N][N], bool bt[N][N], int tw[N], int N){
    int najm_suma = INT_MAX;
    wieze do_usuniecia;
    int aktualna_suma = 0;
    for(int i = 0; i < N - 1; i++){
        for(int j = i + 1; j < N; j++){
            int aktualna_suma = 0;
            //wyzeruj tablice, zeby zaznaczac na czystej
            wyzeruj_tablice(bt, N);
            zaznacz_szachowane(bt, tw, N, i, j);
            aktualna_suma = suma_szachowanych(bt, wartosci, N);
            if(aktualna_suma < najm_suma){
                najm_suma = aktualna_suma;
                do_usuniecia.k1 = i;
                do_usuniecia.k2 = j;
            }
        }
    }
    return do_usuniecia;
}

int main() {
    // tablica zawierajaca numery wierszy wiez
    int tw[N] ={1, 0, 1, 2};
    //tablica wartosci na w danych szufladkach tablicy
    int wartosci[N][N] = {
            {1, 11, 345, 4},
            {22, 6, 17, 9},
            {42, 94, 6, 13},
            {17, 1, 10, 6}
    };
    //pomocnicza tablica bool, na ktorej zaznaczam pola szachowane
    bool bt[N][N];
    wyzeruj_tablice(bt, N);
    wieze do_usuniecia = najmniejsza_suma(wartosci, bt, tw, N);
    cout << "Kolumny z ktorych usuniecie wiez skutkuje najmniejsza suma pol szachowanych: ";
    cout << do_usuniecia.k1 << " " << do_usuniecia.k2;
    //podajemy kolumny z ktorych usuwamy wieze odpowiednio 1, 2
    //sprawdza, czy zaznaczanie szachowanych dziala poprawnie
    /*cout << endl ;
    wyzeruj_tablice(bt, N);
    zaznacz_szachowane(bt, tw, N, 1, 2);
    wypisz_tablice(bt, N);*/
    return 0;
}
