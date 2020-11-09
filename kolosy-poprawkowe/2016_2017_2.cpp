//
// Created by Kamil Delekta on 05.01.2020.
//
//Dana jest tablica booli int t[N][N] reprezentujaca szachownice. Pole szachownicy ma
//wartosc true, jezeli stoi na nim figura, a false, jesli jest ono puste. Prosze napisac
//funkcje ktora sprawdza czy istnieje droga skoczka przemieszczajacego sie z wiersza
//0 do wiersza N - 1. Skoczek moze poruszac sie tylko po polach pustych.Skoczek w
// kazdym ruchu powinien przyblizac sie do N - 1 wiersza. Funkcja ma zwrocic
//najmniejsza mozliwa liczbe ruchow. Skoczek moze zaczac poruszac sie z dowolnego
//pustego pola z wiersza 0. N z zakresu 4...20.
#include <iostream>
using namespace std;
const int N = 6;
bool belong(int w, int k){
    return (w >= 0 and k >= 0 and w < N and k < N);
}
bool itspossible(bool t[N][N], int w, int k, int variant, int &newW, int &newK){
    int dy[4] = {1, 2, 2, 1};
    int dx[4] = {-2, -1, 1, 2};
    newW = w + dy[variant];
    newK = k + dx[variant];
    if(belong(newW, newK) and t[newW][newK] == false) return true;
    else return false;
}
void skoczek(bool t[N][N], int w, int k, int &move_min, int move = 0){
    int variant;
    int newW;
    int newK;
    if(w == N - 1){
        if(move < move_min){
            move_min = move;
        }
    }
    else{
        for(variant = 0; variant < 4; variant++){
            if(itspossible(t, w, k, variant, newW, newK)){
                skoczek(t, newW, newK, move_min, move + 1);
            }
        }
        return;
    }
}
int skoczek_aux(bool t[N][N]){
    //maksymalna wartosc dla zmiennej typu int = 2147483647
    int move_min = INT_MAX;
    int move_the_least = INT_MAX;
    for(int k = 0; k < N; k++){
        if(t[0][k] == false){
            skoczek(t, 0, k, move_min);
            if(move_min < move_the_least){
                move_the_least = move_min;
            }
        }
    }
    return move_the_least;
}
int main() {
    bool t[N][N] = {
            {0, 0, 1, 0, 1, 0},
            {1, 0, 1, 0, 0, 0},
            {1, 1, 1, 0, 1, 1},
            {1, 1, 1, 1, 1, 1},
            {0, 1, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0},
    };
    int move = skoczek_aux(t);
    if(move != INT_MAX) cout << "Minimalna liczba ruchow, by skoczek dotarl na koniec: " << move;
    else cout << "Nie istnieje droga skoczka na drugi koniec szachownicy";
    return 0;
}
