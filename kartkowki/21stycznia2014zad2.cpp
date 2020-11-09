//
// Created by Kamil Delekta on 15.01.2020.
//
//Tablicat[N]jest wype³niona liczbami naturalnymi. Skok z polai-tego mo¿na
//wykonaæ na pola o indeksach i+k, gdziekjest czynnikiem pierwszym liczby
//t[i](mniejszym od niej samej). Napisz funkcjê, która sprawdza, czy da siê
//przejœæ z pola0doN-1– jeœli siê da, zwraca iloœæ skoków, jeœli siê nie da,zwraca-1
#include <iostream>
#include <cmath>
using namespace std;
const int N = 12;
//wrocic do tego problemu
int czynniki(int liczba){
    int res = 0;
    for(int i = 2; i <= sqrt(liczba); i++){
        bool wpisz = true;
        while(liczba % i == 0){
            if(wpisz){
                res = res * 10 + i;
                wpisz = false;
            }
            liczba /= i;
        }
    }
    if(liczba != 1) res = res * 10 + liczba;
    return res;
} void dasie(int t[N], int &res, int idx = 0){
        if (idx > N - 2){
            if(idx == N - 1) res = 1;
        }
        else{
            int czyn = czynniki(t[idx]);
            while (czyn > 0) {
                int k = czyn % 10;
                 dasie(t, res, idx + k);
                czyn /= 10;
            }
        }
}
int dasie_c(int t[N], int idx = 0){
    if (idx > N - 2){
        if(idx == N - 1) return 1;
        else return -1;
    }
    else{
        int czyn = czynniki(t[idx]);
        while (czyn > 0) {
            int k = czyn % 10;
            if(dasie_c(t, idx + k) == 1) return 1;
            czyn /= 10;
        }
    }
}
int dasie_aux( int t[N]){
    int res = -1;
    dasie(t, res);
    return res;
}
int main() {
    //cout << czynniki(2);
    //cout << 125 % 10;
    int t[N] = {2, 2, 5, 2, 2, 3, 2, 2, 2, 2, 2, 2};
    cout << dasie_aux(t) << endl;
    cout << dasie_c(t);
    return 0;
}
