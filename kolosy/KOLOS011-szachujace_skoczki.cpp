//
// Created by Kamil Delekta on 01.12.2019.
//
//Dana jest taablica t[N] zawierajaca liczby naturalne. Prosze napisac funkcje, ktora sprawdza,
//czy jest mozliwe ustawienie dwoch wzajemnie szachujacych sie skoczkow tak, aby suma wartosci pol,
//na ktorych staja skoczki, byla liczba pierwsza. Do funkcji nalezy przekazac tablice t, funkcja
// zwrocic wartosc typu bool
#include <iostream>
#include <cmath>
const int N = 4;
using namespace std;
void wypisz_tablice(int t[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
}
void wypisz_szachowane_skoczki(int y1, int x1, int y2, int x2){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == y1 && j == x1 || i == y2 && j == x2){
                cout << "S" << " ";
            }
            else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
bool czy_pierwsza(int liczba){
    if(liczba < 2) return false;
    if(liczba == 2) return true;
    if(liczba %2 == 0) return false;
    for(int i = 3; i <= sqrt(liczba); i++){
        if(liczba % i == 0) return false;
    }
    return true;
}
//bo N jes globalne
bool drugi_szachowany_skoczek(int y, int x, int &nowyY, int &nowyX, int wariant){
    int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    nowyY = y + dy[wariant];
    nowyX = x + dx[wariant];
    return nowyY >= 0 and nowyY < N and nowyX >= 0 and nowyX < N;
}
bool czy_mozna(int t[N][N]){
    int nowyY,nowyX;
    //pole pierwszego skoczka
    for(int y = 0; y < N; y++) {
        for(int x = 0; x < N; x++){
            for(int wariant = 0; wariant < 8; wariant++){
                if(drugi_szachowany_skoczek(y, x, nowyY, nowyX, wariant)){
                    if(czy_pierwsza(t[y][x] + t[nowyY][nowyX])){
                        wypisz_szachowane_skoczki(y, x, nowyY, nowyX);
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
bool czy_mozna(int t[N][N]);
int main() {
    int t[N][N] = {
            {2, 2, 4, 2},
            {4, 2, 7, 2},
            {4, 2, 2, 4},
            {2, 2, 90, 8}
    };
    wypisz_tablice(t);
    cout << endl;
    cout << czy_mozna(t);
    return 0;
}
