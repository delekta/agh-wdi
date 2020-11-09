//
// Created by Kamil Delekta on 09.01.2020.
//
//Dwie liczby naturalne s¹ „przyjació³kami” je¿eli zbiory cyfr z których zbudowane s¹ liczby
//s¹ identyczne. Na przyk³ad: 123 i 321, 211 i 122, 35 i 3553. Dana jest tablica int t[N][N]
//wype³niona liczbami naturalnymi. Proszê napisaæ funkcjê, która dla tablicy t zwraca ile
//elementów tablicy s¹siaduje wy³¹cznie z przyjació³kami.
#include <iostream>
using namespace std;
const int N = 6;
//lepsze rozwiazanie
bool sa_przyjaciolkami(int liczba1, int liczba2){
    {
        bool digits1[10];
        bool digits2[10];
        for(int i = 0; i < 10; i++) digits1[i] = digits2[i] = false;
        while(liczba1 > 0){
            digits1[liczba1 % 10] = true;
            liczba1 /= 10;
        }
        while(liczba2 > 0){
            digits2[liczba2 % 10] = true;
            liczba2 /= 10;
        }
        for(int i = 0; i < 10; i++){
            if(digits1[i] != digits2[i]){
                return false;
            }
        }
        return true;
    }
}
int ile_przyjaciolek(int tdigits[N][N]){
    int counter = 0;
    for(int y = 0; y < N; y++){
        for(int x = 0; x < N; x++){
            if(x != 0){
                if(!(sa_przyjaciolkami(tdigits[y][x - 1], tdigits[y][x]))) continue;
            }
            if(x != N - 1){
                if(!(sa_przyjaciolkami(tdigits[y][x + 1], tdigits[y][x]))) continue;
            }
            if(y != 0){
                //tu y-- idzie do gory
                if(!(sa_przyjaciolkami(tdigits[y - 1][x] ,tdigits[y][x]))) continue;
            }
            if(y != N - 1){
                //tu y++ idzie w dol
                if(!(sa_przyjaciolkami(tdigits[y + 1][x], tdigits[y][x]))) continue;
            }
            cout << y << " " << x << endl;
            counter++;
        }
    }
    return counter;
}
//mniej optymalna wersja
bool zawiera(int liczba, int cyfra){
    while(liczba > 0){
        if(liczba % 10 == cyfra) return true;
        liczba /= 10;
    }
    return false;
}
void jakiecyfry(int t[N][N], int tdigits[N][N]){
    for(int y = 0; y < N; y++){
        for(int x = 0; x < N; x++){
            int digits = 0;
            int copy = t[y][x];
            //tak lepiej bo zero dodawane na koncu jak cos jest wpisane
            for(int i = 9; i >= 0; i--){
                if(zawiera(copy, i)) digits = digits * 10 + i;
            }
            tdigits[y][x] = digits;
        }
    }
}
void wypisz_tablice(int t[N][N]){
    for(int y = 0; y < N; y++){
        for(int x = 0; x < N; x++){
            cout << t[y][x] << " ";
        }
        cout << endl;
    }
}
int main() {
    int t[N][N] ={
            {12, 1, 23, 27, 23 , 56},
            {129, 12, 12, 2773, 23 , 56},
            {12, 12, 23772, 732, 732, 576},
            {12, 23, 273, 2773, 23 , 56},
            {3273, 23, 23, 122, 56 , 576},
            {233, 23, 12, 21, 122 , 65},
    };
    /*int tdigits[N][N];
    jakiecyfry(t, tdigits);
    cout << tdigits[0][0];
    for(int y = 0; y < N; y++){
        for(int x = 0; x < N; x++){
            cout << tdigits[y][x] << " ";
        }
        cout << endl;
    }*/
    wypisz_tablice(t);
    cout << ile_przyjaciolek(t);
    return 0;
}
