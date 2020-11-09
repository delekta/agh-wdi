//
// Created by Kamil Delekta on 14.01.2020.
//
//Proszê napisaæ funkcjê, która w poszukuje w tablicy najd³u¿szego ci¹gu geometrycznego le¿¹cego ukoœnie w kierunku
//prawo-dó³, licz¹cego co najmniej 3 elementy.Do funkcji nale¿y przekazaæ tablicê. Funkcja powinna zwróciæ
//informacje czy uda³o siê znaleŸæ taki ci¹g oraz d³ugoœætego ci¹gu
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
