//
// Created by Kamil Delekta on 16.01.2020.
//
//Tablica int t[8][8] zawiera liczby naturalne. Proszê napisaæ funkcjê, która
//sprawdza czy mo¿na wybraæ ztablicy niepusty podzbiór o zadanej sumie. Warunkiem
//dodatkowym jest  aby ¿adne dwa wybrane elementy nie le¿a³y w tej samej kolumnie ani
//wierszu. Do funkcji nale¿y przekazaæ wy³¹cznie tablicê  oraz wartoœæ sumy,
//funkcja powinna zwróciæ wartoœæ typu boo
#include <iostream>
using namespace std;
const int N = 8;
//do poprawy
bool mozna(int t[N][N], int suma, int w, int k, bool col[N]){
    if(suma == 0) return true;
    else if(suma < 0) return false;
    else if(w > N or k > N) return false;
    else{
        if(col[k] == false){
            col[k] = true;
            return mozna(t, suma - t[w][k], w + 1, k, col);
            // col[k] = false; po return nic nie mozesz dac
        }
        col[k] = false;
        return mozna(t, suma, w + 1, k, col) || mozna(t, suma, w, k + 1, col);
    }
}
bool mozna_k1(int t[N][N], int suma, int w, int k, bool col[N], bool b = false){
    if(suma == 0) return true;
    else if(suma < 0) return false;
    else if(w > N or k > N) return false;
    else{
        if(col[k] == false){
            col[k] = true;
            b = mozna_k1(t, suma - t[w][k], w + 1, k, col);
            col[k] = false;
        }
        b = b or mozna_k1(t, suma, w + 1, k, col);
        b = b or mozna_k1(t, suma, w, k + 1, col);
    }
    return b;
}
bool mozna_k2(int t[N][N], int suma, int w, int k, bool col[N]){
    if(suma == 0) return true;
    else if(suma < 0) return false;
    else if(w > N or k > N) return false;
    else{
        if(col[k] == false){
            col[k] = true;
             if(mozna(t, suma - t[w][k], w + 1, k, col)) return true;
             col[k] = false;
        }
        return mozna(t, suma, w + 1, k, col) || mozna(t, suma, w, k + 1, col);
    }
}
int main() {
    bool col[N];
    for(int i = 0; i < N; i++) col[i] = false;
    int t[N][N] = {
            {2, 4, 6, 8, 90, 34, 4, 6},
            {2, 4, 6, 8, 90, 34, 4, 6},
            {2, 4, 6, 8, 90, 34, 4, 6},
            {2, 4, 6, 8, 90, 34, 4, 6},
            {2, 4, 6, 8, 90, 34, 4, 6},
            {2, 4, 6, 8, 90, 34, 4, 6},
            {2, 4, 6, 8, 90, 34, 4, 6},
            {2, 4, 6, 8, 90, 34, 4, 6},
    };
    cout << mozna_k1(t, 9, 0, 0, col) << endl;
    cout << mozna_k2(t, 9, 0, 0, col) << endl;
    cout << mozna(t, 9, 0, 0,col);//nie dziala
    return 0;
}
