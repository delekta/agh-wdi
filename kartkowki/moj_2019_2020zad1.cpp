//
// Created by Kamil Delekta on 15.01.2020.
//
//Dane s¹ dwie tablice int t1[N], int t2[N] wype³nione liczbami naturalnymi. Proszê napisaæ funkcjê, która
//sprawdza czy z ka¿dej z tablic mo¿na wyci¹æ po jednym kawa³ku,  tak aby suma elementów w obu kawa³kach by³a:
//co najmniej drug¹ potêg¹ dowolnej liczby naturalnej. £¹czna d³ugoœci obu kawa³ków powinna wynosiæ 24
#include <iostream>
using namespace std;
const int N = 12;
bool co_najmniej_druga_potega(int liczba){
    //zaczynanie od 1 jest tricky
    for(int x = 2; x * x <= liczba; x++){
        if(liczba % x * x == 0){
            while(liczba % x == 0){
                liczba /= x;
            }
        }
        if(liczba == 1) return true;
    }
    return false;
}
int suma(int t[N], int p, int k){
    int res = 0;
    for(int i = p; i < k; i++){
        res += t[1];
    }
    return res;
}
//nie dziala zawsze
bool mozna_wyciac(int t1[N], int t2[N]){
    for(int p1 = 0; p1 < N; p1++){
        for(int k1 = p1 + 1; k1 < N + 1 and k1 - p1 < 24; k1++){
            int aktSUM1 = suma(t1, p1, k1);
            int dlg1 = k1 - p1;
            for(int p2 = 0; p2 < N; p2++){
                for(int k2 = p2 + 1; k2 < N + 1 and k2 - p2 < 24; k2++){
                    int aktSUM2 = suma(t2, p2, k2);
                    int dlg2 = k2 - p2;
                    if(dlg1 + dlg2 == 24 and co_najmniej_druga_potega(aktSUM1 + aktSUM2)) return true;
                }
            }
        }
    }
    return false;
}
int main() {
    int t1[N] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int t2[N] = {1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1};
    cout << mozna_wyciac(t1, t2);
    return 0;
}
