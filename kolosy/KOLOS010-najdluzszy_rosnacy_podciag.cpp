//
// Created by Kamil Delekta on 01.12.2019.
//
//Tablica tab jest wypelniona liczbami naturalnymi. Prosze napisac funkcje, ktora zwraca dlugosc najdluzszego
//spojnego podciagu rosnacaego, dla ktorego suma jego elementow jest rowna sumie indeksow tych elementow.
//Do funkcji nalezy przekazac tablice, funkcja powinna zwrocic dlugosc znalezionego podciagu lub wartosc 0 jezeli podciag nie istnieje
#include <iostream>
using namespace std;
int najdluzszy_spojny_podciag(int tab[], int N, int start){
    int obecnaDlg = 1;
    int sumaWartosci = tab[start];
    int sumaIndeksow = start;
    int najdluzszy = 0;
    for(int i = start; i < N - 1; i ++){
        if(sumaIndeksow == sumaWartosci){
            if(obecnaDlg > najdluzszy){
                najdluzszy = obecnaDlg;
            }
        }
        if(tab[i] < tab[i + 1]){
            obecnaDlg++;
            sumaWartosci += tab[i + 1];
            sumaIndeksow += i + 1;
        }
        else{
            obecnaDlg = 1;
            sumaWartosci = tab[i + 1];
            sumaIndeksow = i + 1;
        }
    }
    return najdluzszy;
}
int najdluzszy_spojny_podciag_okalajaca(int tab[], int N){
    int najdluzszy = 0;
    //zmiana poczatku sprawdzania najdluzszego podciagu poniewaz ma to wplyw na sumaIndeksow i sumaWartosci
    for(int start = 0; start < N; start++){
        int podciag = najdluzszy_spojny_podciag(tab , N, start);
        if(podciag > najdluzszy){
            najdluzszy = podciag;
        }
    }
    return najdluzszy;
}
int main() {
    const int N = 10;
    int tab[N] = {1, 1, 2, 3, 4, 5, 8, 9 ,9 , 7};
    cout << najdluzszy_spojny_podciag_okalajaca(tab, N);
    return 0;
}
