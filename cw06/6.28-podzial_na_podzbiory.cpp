//
// Created by Kamil Delekta on 12.01.2020.
//
//Dany jest zbi�r n liczb naturalnych umieszczony w tablicy int t[N]. Prosz� napisa�
//funkcj�, kt�ra zwraca informacj�, czy jest mo�liwy podzia� zbioru n liczb na trzy
//podzbiory, tak aby w ka�dym podzbiorze, ��czna liczba jedynek u�yta do zapisu
//element�w tego podzbioru w systemie dw�jkowym by�a jednakowa. Na przyk�ad:
//{2,3,5,7,15} ->true, bo podzbiory {2,7} {3,5} {15}wymagaj� u�ycia 4 jedynek,
//{5,7,15} ->false, podzia� nie istnieje
#include <iostream>
using namespace std;
const int N = 5;
int ile_jedynek(int liczba){
    int c = 0;
    while(liczba > 0){
        if(liczba % 2 == 1) c++;
        liczba /= 2;
    }
    return c;
}
//zapamietaj ten typ bool!
bool czy_mozna(int tk[N], int idx = 0, int S1 = 0, int S2 = 0, int S3 = 0){
    if(idx == N){
        return S1 == S2 and S2 == S3;
    }
    else{
        return czy_mozna(tk, idx + 1, S1 + tk[idx], S2, S3)
        || czy_mozna(tk, idx + 1, S1 , S2 + tk[idx], S3)
        ||czy_mozna(tk, idx + 1, S1 , S2, S3 + tk[idx]);
    }
}
bool czy_mozna_aux(int t[N]){
    int tk[N];
    for(int i = 0; i < N; i++){
        tk[i] = ile_jedynek(t[i]);
    }
    return czy_mozna(tk);
}
int main() {
    int t[N] = {2, 3, 5, 7, 14};
    cout << czy_mozna_aux(t);
    return 0;
}
