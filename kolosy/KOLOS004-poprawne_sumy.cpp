//
// Created by Kamil Delekta on 30.11.2019.
//
//Dane s¹ dwie tablice t1[N] i t2[N] zawieraj¹ce liczby naturalne. Z wartoœci w obu
//tablicachmo¿emy tworzyæ sumy. „Poprawna” suma to taka, która zawiera co najmniej
// jeden element(z tablicy t1 lub t2) o ka¿dym indeksie. Na przyk³ad dla tablic:
// t1 = [1,3,2,4] i t2 = [9,7,4,8]poprawnymi sumami s¹ na przyk³ad 1+3+2+4, 9+7+4+8,
// 1+7+3+8, 1+9+7+2+4+8.Proszê napisaæ funkcjê generuj¹c¹ i wypisuj¹c¹ wszystkie
// poprawne sumy, które s¹ liczbamipierwszymi. Do funkcji nale¿y przekazaæ dwie tablice,
// funkcja powinna zwróciæ liczbêznalezionych i wypisanych sum
#include <iostream>
#include <cmath>
using namespace std;
const int N = 4;
void wyzeruj_tablice(bool tab[], int N){
    for(int i = 0; i < N; i++){
        tab[i] = 0;
    }
}
bool czy_pierwsza(int liczba){
    if(liczba < 2) return false;
    if(liczba == 2 || liczba == 3 || liczba == 5) return true;
    if(liczba %2 == 0 || liczba %3 == 0 || liczba %5 == 0) return false;
    int i = 7;
    while(i <= sqrt(liczba)){
        if(liczba %i == 0) return false;
        i += 4;
        if(liczba %i == 0) return false;
        i += 2;
    }
    return true;
}
bool przynajmniej_jeden_o_kazdym_indexie(bool t1[],bool t2[], int N){
    for(int i = 0; i < N; i++){
        if(t1[i] == 0 && t2[i] == 0) return false;
    }
    return true;
}
void poprawna_suma(int t1[], int t2[], bool used1[], bool used2[], int &licznik, int suma = 0, int idx = 0){
    if(idx == 2 * N){
        if(przynajmniej_jeden_o_kazdym_indexie(used1, used2, N)) {
            if (czy_pierwsza(suma)) {
                licznik++;
                for (int i = 0; i < N; i++) {
                    if (used1[i]) {
                        cout << t1[i] << " ";
                    }
                    if (used2[i]) {
                        cout << t2[i] << " ";
                    }
                }
                cout << endl;
            }
        }
        else return;
    }
    else {
        if (idx < N) {
            used1[idx] = 1;
            poprawna_suma(t1, t2, used1, used2, licznik, suma + t1[idx], idx + 1);
            used1[idx] = 0;
            poprawna_suma(t1, t2, used1, used2, licznik, suma, idx + 1);
        } else {
            used2[idx - N] = 1;
            poprawna_suma(t1, t2, used1, used2, licznik, suma + t2[idx - N], idx + 1);
            used2[idx - N] = 0;
            poprawna_suma(t1, t2, used1, used2, licznik, suma, idx + 1);
        }
    }
}
void licznik(int t1[], int t2[], bool used1[], bool used2[] ){
    int licznik = 0;
    poprawna_suma(t1, t2, used1, used2, licznik);
    cout << "Wszystkich kombinacji: " << licznik;
}

int main(){
    int t1[N] = {1, 3, 2, 4};
    int t2[N]= {9, 7, 4, 8};
    bool used1[N];
    bool used2[N];
    wyzeruj_tablice(used1, N);
    wyzeruj_tablice(used2, N);
    licznik(t1, t2, used1, used2);
    return 0;
}
