//
// Created by Kamil Delekta on 01.12.2019.
//
//Dana jest tablica t[N][N] reprezentuj¹ca szachownicê, wype³niona liczbami naturalnymi. na
//szachownicy znajduj¹ siê dwie wie¿e. Proszê napisaæ funkcjê, która odpowiada na pytanie: czy
//istnieje ruch wie¿y zwiêkszaj¹cy sumê liczb na “szachowanych” przez wie¿e polach? Do funkcji
//nale¿y przekazaæ tablicê oraz po³o¿enia dwóch wie¿, funkcja powinna zwróciæ wartoœæ logiczn¹.
//Uwagi: zak³adamy, ¿e wie¿a szachuje ca³y wiersz i kolumnê z wy³¹czeniem pola, na którym stoi.
//N to globalny const int
#include <iostream>
using namespace std;
const int N = 4;
void wyzeruj_tabliceINT(int t[N]){
    for(int i = 0; i < N; i++){
            t[i] = 0;
        }
}
void wypisz_tabliceINT(int t[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
}
int presum(int wartosci[N][N], int presumK[N], int presumW[N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            presumK[i] += wartosci[j][i];
            presumW[i] += wartosci[i][j];
        }
    }
}
int sum(int wartosci[N][N], int presumK[N],int presumW[N], int y1 , int x1, int y2, int x2){
    int s1 = presumW[y1] + presumK[x1] - 2 * wartosci[y1][x1];
    int s2 = presumW[y2] + presumK[x2] - 2 * wartosci[y2][x2];
    if(y1 != y2 && x1 != x2){
        return (s1 + s2 - wartosci[y1][x2] - wartosci[y2][x1]);
    }
    if(y1 == y2 && x1 != x2){
        return (presumK[x1] + presumK[x2] + presumW[y1]  -  2 * wartosci[y1][x2] - 2 * wartosci[y2][x1]);
    }
    if(y1 != y2 && x1 == x2){
        return (presumW[y1] + presumW[y2] + presumK[x1]  - 2 * wartosci[y1][x2] -  2 * wartosci[y2][x1]);
    }
    if(y1 == y2 && x1 == x2) {
        return  -1;
    }
}
bool driver( int y1, int x1, int y2, int x2, int wartosci[N][N], int presumK[N],int presumW[N]){
    int suma = sum(wartosci, presumK, presumW, y1, x1, y2, x2);
    for(int i = 0; i < N; i++){
        if((sum(wartosci, presumK, presumW, i, x1, y2, x2) > suma) ||
        (sum(wartosci, presumK, presumW, y1, i, y2, x2) > suma) ||
        (sum(wartosci, presumK, presumW, y1, x1, i, x2) > suma) ||
        (sum(wartosci, presumK, presumW, y1, x1, y2, i) > suma))return true;
    }
    return false;
}
int main() {
    int wartosci[N][N] = {
            {1, 11, 345, 1},
            {22, 1, 170, 1},
            {56, 94, 1, 13},
            {1, 1, 100, 1}
    };
    wypisz_tabliceINT(wartosci);
    int presumK[N];
    int presumW[N];
    wyzeruj_tabliceINT(presumK);
    wyzeruj_tabliceINT(presumW);
    presum(wartosci, presumK, presumW);
    int y1, x1, y2, x2;
    cout << "Podaj wiersz i kolumne 1 wiezy: ";
    cin >> y1 >> x1;
    cout << "Podaj wiersz i kolumne 2 wiezy: ";
    cin >> y2 >> x2;
    cout << driver(y1, x1, y2, x2, wartosci, presumK, presumW);
    return 0;
}

