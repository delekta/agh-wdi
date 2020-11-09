//„Waga” liczby jest okreœlona jako iloœæ ró¿nych czynników pierwszych liczby.
//Na przyk³ad waga(1)=0, waga(2)=1, waga(6)=2, waga(30)=3, waga(64)=1. Dana jest tablica: int t[N].
//Tablica  zawiera liczby naturalne. Proszê napisaæ funkcjê, która sprawdza czy mo¿na elementy tablicy
// podzieliæ na 3 podzbiory o równych wagach. Do funkcji nale¿y przekazaæ wy³¹cznie tablicê!!!, funkcja powinna zwróciæ wartoœæ typu bool.
//zadanie podobne do stabilnej wagi trojkatnej!!!
//
// Created by Kamil Delekta on 20.11.2019.
//
#include <iostream>
#include <math.h>
using namespace std;
const int N = 7;
int ilosc_roznych_czynnikow_pierwszych(int liczba){
    int licznik = 0;
    //-----inna dzialajaca wersja------
    /*for(int i = 2; liczba > 1; i++){
        bool pierwszy = true;
        while(liczba %i == 0) {
            liczba /= i;
            if(pierwszy)licznik++;
            pierwszy = false;
        }
    }
    //return licznik;
    */
    int dz = 2;
    while(dz < sqrt(liczba)){
        if(liczba %dz == 0)licznik++;
        while(liczba %dz == 0) liczba /= dz;
        dz++;
    }
    // warunek ze jesli liczba == 1 zwroc licznik jesli nie to licznik + 1,
    // bo nasza petla nie uwzglednia duzej liczby pierwszej ktora jest tu uwzgledniana
    return (liczba == 1?licznik:licznik + 1);
}
// S1 S2 S3 --> pojemniki
// do funkcji przekaz wylacznie tablice --> albo reszte implementujesz w naglowku
// albo robisz funkcje okalajaca np
bool mozna(int wagi[N],int suma3, int S1 = 0, int S2 = 0, int S3 = 0, int p = 0){//przykladowe wywolanie mozna(tab,N)
    // jesli w ktoryms pojemniku jest wiecej niz 1/3 calej sumy to zwracamy false
    if(S1 > suma3 || S2 > suma3 || S3 > suma3) return false;
    if(p == N) return (S1 == S2 && S2 == S3);
    return mozna(wagi, suma3, S1 + wagi[p], S2, S3, p + 1) || mozna(wagi, suma3, S1, S2 + wagi[p], S3, p + 1) || mozna(wagi, suma3, S1, S2, S3 + wagi[p], p + 1);
}
bool funkcja_okalajaca(int t[N], int suma = 0){ // do tej funkcji N musi byc globalny
    for(int i = 0; i < N; i++){
        suma += t[i];
    }
    if(suma % 3 == 0)return mozna(t, suma / 3);//przekazujemy 1/3 sumy
    else return false;
}
int main(){
    //cout << ilosc_roznych_czynnikow_pierwszych(37);
    //cout << ilosc_roznych_czynnikow_pierwszych(30);
    //cout << ilosc_roznych_czynnikow_pierwszych(32);
    int t[N] = {2, 5, 7, 30, 1, 8, 10};
    //int t[N] = {1, 1, 1, 1, 1, 8, 1};
    //int t[N] = {120, 1, 1, 42, 91, 27, 1};
    //int t[N] = {120, 54, 1, 1, 1, 1, 1};
    int wagi[N];
    //cout << ilosc_roznych_czynnikow_pierwszych(12);
    for(int k = 0; k < N; k++){
        wagi[k] = ilosc_roznych_czynnikow_pierwszych(t[k]);// mozna tez nadpisywav tablice t
    }
    //przekazujesz do funkcji tylko tablice wag, reszte implementujesz w naglowku
    //if(mozna(wagi)) cout << "mozna";
    //wywolanie przez funkcje okalajaca
    if(funkcja_okalajaca(wagi)) cout << "mozna";
    else cout << "nie mozna";
    return 0;
}
