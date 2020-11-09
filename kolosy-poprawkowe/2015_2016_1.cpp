//
// Created by Kamil Delekta on 08.01.2020.
//
//Dana jest tablica int t[N][N] zawieraj¹ce liczby naturalne. Dok³adnie w jednym z wierszy
//tablicy znajduje sie fragment ciagu Fibonnacciego o dlugosci wiekszej niz 2, a mniejszej  niz N. Proszê
//napisac funkcje, ktora odszuka ten fragment ciagu i zwroci numer wiersza w ktorym on sie znajduje
#include <iostream>
using namespace std;
const int N = 6;
bool fibonacci(int f1, int f2, int f3){
    int a = 1;
    int b = 0;
    while(a < f2){
        a = a + b;
        b = a - b;
    }
    return b == f1 and a == f2;
}
int find_fib(int t[N][N]){
    for(int w = 0; w < N; w++){
        for(int k = 0; k < N - 2; k++) {
            if (t[w][k] + t[w][k + 1] == t[w][k + 2]){
                if (fibonacci(t[w][k], t[w][k + 1], t[w][k + 2])) return w;
            }
        }
    }
    return -1;
}
int main() {
    int t[N][N] = {
            {1, 2, 5, 6, 8, 9},
            {1, 2, 5, 6, 8, 9},
            {1, 2, 5, 6, 8, 9},
            {1, 2, 2, 3, 5, 9},
            {1, 2, 5, 54, 55, 89},
            {1, 2, 5, 6, 8, 9},
    };
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
    int wiersz = find_fib(t);
    if(wiersz != -1) cout << "Fragment ciagu fibonacciego wystepuje w " << wiersz << " wierszu";
    else cout << "W tej tablicy nie ma fragmentu ciagu fibonacciego!";
    return 0;
}
