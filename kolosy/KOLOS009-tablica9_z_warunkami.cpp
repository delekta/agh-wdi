//
// Created by Kamil Delekta on 01.12.2019.
//
//Dana jest tablica int t[9], w której nale¿y umieœciæ liczby od 1 do 9 tak, aby by³y spe³nione warunki:
//1) wartoœci na s¹siednich polach tablicy musz¹ siê ró¿niæ co najmniej o 2
//2) liczby pierwsze nie mog¹ zajmowaæ s¹siednich pól tablicy
//Wartoœæ 1 zosta³a ju¿ umieszczona na pierwszym miejscu (pod indeksem 0). Proszê napisaæ
//program, który wypisuje wszystkie poprawne rozmieszczenia liczb w tablicy
#include <iostream>
#include <cmath>
using namespace std;
bool used[10];
bool czy_pierwsza(int liczba){
    if(liczba < 2) return false;
    if(liczba == 2) return true;
    if(liczba %2 == 0) return false;
    for(int i = 3; i <= sqrt(liczba); i+=2){
        if(liczba %i == 0) return false;
    }
    return true;
}
bool czy_sasiednie_pierwsze(int a, int b){
    return czy_pierwsza(a) && czy_pierwsza(b);
}
int diff(int a, int b) {
    if(a > b) return a - b;
    else return b - a;
}
void tablica_z_warunkami(int t[], int N,int idx = 1){
    if(idx == N){
            for(int i = 0; i < N; i++) cout << t[i] << " ";
            cout << endl;
    }
    else{
        for(int licznik = 2; licznik <= N; licznik++){
            if(used[licznik] == 0) {
                if(diff(t[idx - 1], licznik) >= 2){
                    if(!(czy_sasiednie_pierwsze(t[idx - 1], licznik))){
                    t[idx] = licznik;
                    used[licznik] = 1;
                    tablica_z_warunkami(t, N, idx + 1);
                    used[licznik] = 0;
                    }
                }
            }
        }
    }
}
int main() {
    const int N = 9;
    int t[N];
    t[0] = 1;
    for(int i = 1; i < N; i++){
        used[i] = 0;
    }
    used[1] = true;
    tablica_z_warunkami(t, N);
    return 0;
}
