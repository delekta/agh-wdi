//
// Created by Kamil Delekta on 12.01.2020.
//
//W szachownicy o wymiarach 8x8 ka¿demu z pól przypisano liczbê naturaln¹. Na ruchy
//króla na³o¿ono dwa ograniczenia: król mo¿e przesun¹æ siê na jedno z 8 s¹siednich
//pól je¿eli ostatnia cyfra liczby na polu na którym stoi jest mniejsza od pierwszej
//cyfry liczby pola docelowego, oraz w  drodze do obranego celu (np. naro¿nika) król
//nie mo¿e wykonaæ ruchu, który powoduje oddalenie go od celu. Dana jest globalna
//tablica int t[8][8] wype³niona liczbami naturalnymi reprezentuj¹ca szachownicê.
//Lewy górny naro¿nik ma wspó³rzêdne w=0 i k=0. Proszê napisaæ funkcjê sprawdzaj¹c¹
//czy król mo¿e dostaæ siê z pola w,k do prawego dolnego naro¿nik
//FAJNIE ZROBIONE
#include <iostream>
using namespace std;
const int N = 8;
void wypisz_tablice(int t[N][N]){
    for(int y = 0; y < N; y++){
        for(int x = 0; x < N; x++){
            cout << t[y][x] << " ";
        }
        cout << endl;
    }
}
void wyzeuj_tablice(bool t[N][N]){
    for(int y = 0; y < N; y++){
        for(int x = 0; x < N; x++){
            t[y][x] = false;
        }
    }
}
void wypisz_tablice_booli(bool t[N][N]){
    for(int y = 0; y < N; y++){
        for(int x = 0; x < N; x++){
            cout << t[y][x] << "  ";
        }
        cout << endl;
    }
}
int pow(int liczba, int wykladnik){
    int result = 1;
    while(wykladnik > 0){
        wykladnik--;
        result *= liczba;
    }
    return result;
}
int how_many_digits(int number){
    int l = 0;
    while(number > 0){
        l++;
        number /= 10;
    }
    return l;
}
bool mozna(int t[N][N], int wariant, int w, int k, int &newW, int &newK){
    int dw[3] = {1, 1, 0};
    int dk[3] = {0, 1, 1};
    newW = w + dw[wariant];
    newK = k + dk[wariant];
    int digits = how_many_digits(t[newW][newK]);
    if(k < N and w < N and t[w][k] % 10 < (t[newW][newK] / pow(10, digits -1))) return true;
    return false;
}
bool krol(int t[N][N], bool trasa[N][N],int w, int k){
    int newW, newK;
    trasa[w][k] = true;
    if(w == N - 1 and k == N - 1){
        wypisz_tablice_booli(trasa);
        return true;
    }
    else{
        for(int wariant = 0; wariant < 3; wariant++){
            if(mozna(t, wariant, w, k, newW, newK)){
                if(krol(t, trasa, newW, newK)) return true;
            }
        }
        trasa[w][k] = false;
        return false;
    }
}
int main() {
    int t[N][N] = {
            {12, 53, 45, 124, 76, 42, 89, 13},
            {72, 63, 45, 124, 76, 42, 89, 13},
            {12, 234, 42, 124, 76, 42, 89, 13},
            {12, 23, 45, 524, 76, 82, 89, 13},
            {12, 23, 45, 124, 76, 42, 87, 13},
            {12, 23, 45, 124, 76, 42, 86, 13},
            {12, 23, 45, 124, 76, 42, 81, 13},
            {12, 23, 45, 124, 76, 42, 89, 23}
    };
    wypisz_tablice(t);
    bool trasa[N][N];
    wyzeuj_tablice(trasa);
    cout << krol(t, trasa, 0, 0);
    return 0;
}
