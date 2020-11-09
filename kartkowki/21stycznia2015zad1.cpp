//
// Created by Kamil Delekta on 14.01.2020.
//
//Prosz� napisa� funkcj�, kt�ra w poszukuje w tablicy najd�u�szego ci�gu geometrycznego le��cego uko�nie w kierunku
//prawo-d�, licz�cego co najmniej 3 elementy.Do funkcji nale�y przekaza� tablic�. Funkcja powinna zwr�ci�
//informacje czy uda�o si� znale�� taki ci�g oraz d�ugo��tego ci�gu
#include <iostream>
using namespace std;
const int N = 8;
int ciag_geometryczny(int t[N][N], int licznik_max = -1){
    for(int w = 0; w < N -2; w++){
        for(int k = 0; k < N - 2; k++){
            if(t[w][k] * t[w + 2][k + 2] == t[w + 1][k + 1] * t[w + 1][k + 1]){
                int licznik = 2;
                while(t[w][k] * t[w + 2][k + 2] == t[w + 1][k + 1] * t[w + 1][k + 1] and k < N - 2 and w < N - 2){
                    licznik++;
                    w++;
                    k++;
                }
                if(licznik > licznik_max){
                    licznik_max = licznik;
                }
            }
        }
    }
    return licznik_max;
}
int main() {
    int t[N][N] = {
            {8, 3, 6, 2, 1, 5, 6, 8},
            {8, 8, 6, 12, 1, 5, 6, 8},
            {8, 3, 24, 2, 2, 5, 6, 8},
            {8, 3, 6, 12, 8, 48, 6, 6},
            {8, 3, 6, 12, 6, 5, 96, 4},
            {8, 3, 6, 2, 1, 5, 6, 8},
            {8, 3, 6, 2, 1, 5, 5, 8},
            {8, 3, 6, 2, 1, 5, 6, 125},

    };
    cout << ciag_geometryczny(t);
    return 0;
}
