//
// Created by Kamil Delekta on 12.01.2020.
//
//Mamy dan� liczb� ca�kowit�. W tablicy jednowymiarowej nale�y  znale�� n liczb,
//kt�rych suma jest r�wna danej liczbie. Prosz� napisa� funkcj� Nka, kt�ra otrzymuj�c
//jako parametry (1)  tablic� int t[N],) n (ilo�� liczb stanowi�cych sum�) oraz  sum�
//sprawdza, ile mo�na w niej  znale�� �enek
#include <iostream>
using namespace std;
const int N = 8;
int Nka(int t[N], int n, int sum, int idx = 0){
    int licznik = 0;
    if(n == 0 and sum == 0){
        return 1;
    }
    else if(sum > 0 and idx < N){
        licznik += Nka(t, n - 1, sum - t[idx], idx + 1);
        licznik += Nka(t, n, sum, idx + 1);
    }
    return licznik;
}
int Nka_blad(int t[N], int n, int sum, int idx = 0){
    int licznik = 0;
    if(n == 0 and sum == 0){
        return 1;
    }
    else if(sum < 0) return 0;
    else if(idx == N) return 0;
    else{
        licznik += Nka_blad(t, n - 1, sum - t[idx], idx + 1);
        licznik += Nka_blad(t, n, sum, idx + 1);
    }
    return licznik;
}
//na voidzie dziala pieknie
void Nkav(int t[N], int n, int sum, int &licznik , int idx = 0){
    if(n == 0 and sum == 0){
        licznik++;
    }
    else if(idx == N) return;
    else if(sum < 0) return;
    else{
        Nkav(t, n - 1, sum - t[idx], licznik, idx + 1);
        Nkav(t, n, sum, licznik,idx + 1);
    }
}
int nkavoid(int t[N], int n, int sum){
    int licznik = 0;
    Nkav(t, n, sum, licznik);
    return licznik;
}
int main() {
    int t[N] = {1, 5, 7, 25, 2, 0, 28, 3};
    int n = 2;
    int sum = 7;
    cout << nkavoid(t, n, sum) << endl;
    cout << Nka(t, n, sum) << endl;
    cout << Nka_blad(t, n, sum) << " <- tez dziala";
    return 0;
}
