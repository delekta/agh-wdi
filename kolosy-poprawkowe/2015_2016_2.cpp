//
// Created by Kamil Delekta on 08.01.2020.
//
//Dany jest N elementowy zbior liczb naturalnych w postaci tablicy int t[N]. Prosze napisaæ
//funkcje, ktora zwraca informacje czy jest mozliwy podzial zbioru na trzy zbiory tak, aby w kazdym z
//trzech zbiorow ³¹czna liczba jedynek w liczbach zapisanych w systemie bunarnym by³a jednakowa. Na
//przyk³ad dla zbioru {2, 3, 5, 7, 11, 13, 16} mozliwy podzia³ to {2, 13, 16} {3, 11} {5, 7} czyli w systemie
//dwojkowym {10,1101,10000} {11, 1011} {101, 111} - w kazdym zbiorze jest 5 jedynek.
#include <iostream>
using namespace std;
const int N = 7;
int ile_jedynek_w_binarnym(int liczba){
    int counter = 0;
    while(liczba > 0){
        if(liczba %2 == 1) counter++;
        liczba /= 2;
    }
    return counter;
}
//chyba dzia³a, ale mozna optymalniej np nie nadpisywac tej tablicy
bool czy_mozliwy_podzial(int t[N], int S1 = 0, int S2 = 0, int S3 = 0, int idx = 0){
    if(idx == N) {
        //fajna opcja zwracania
        return S1 == S2 and S2 == S3;
    }
    else{
         return czy_mozliwy_podzial(t, S1 + t[idx], S2, S3, idx + 1)
         || czy_mozliwy_podzial(t, S1, S2 + t[idx], S3, idx + 1)
         || czy_mozliwy_podzial(t, S1, S2, S3 + t[idx], idx + 1);
    }
}
//mozna stworzyc nowa tablice w ktorej podzialy
bool czy_mozliwy(int t[N]){
    for(int i = 0; i < N; i++){
        //swiadomie nadpisuje tablice
        t[i] = ile_jedynek_w_binarnym(t[i]);
        }
     return czy_mozliwy_podzial(t);
}
int main() {
    int tt[N] = {2, 3, 5, 7, 11, 13, 16};
    int tf[N] = {2, 7, 5, 7, 11, 13, 16};
    cout << czy_mozliwy(tf);
    return 0;
}
