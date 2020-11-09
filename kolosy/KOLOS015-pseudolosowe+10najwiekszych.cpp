//
// Created by Kamil Delekta on 02.12.2019.
//
//Proszê napisaæ program, który wype³nia tablicê int tab[MAX] liczbami pseudolosowymiz zakresu [1 .. 1000],
//a nastêpnie wyznacza i wypisuje sumê 10 najwiêkszych elementówz tablicy.Uwagi:- tablica tab zajmuje ponad
//po³owê dostêpnej pamiêci na dane i nie mo¿e ulec zmianie
#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;
const int MAX = 20;
void swapp(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}
void sortt(int tab[]){
    bool znaleziona;
    do{
        znaleziona = true;
        for(int i = 0; i < MAX - 1; i++){
            if(tab[i] > tab[i + 1]){
                swapp(tab[i], tab[i + 1]);
                znaleziona = false;
            }
        }
    }while(!znaleziona);
}
int main() {
    srand(time(NULL));
    int tab[MAX];
    for(int i = 0; i < MAX; i++){
        tab[i] = rand()%1000 + 1;
        cout << tab[i] << " ";
    }
    sortt(tab);
    cout << endl;
    cout << "Posortowane: ";
    for(int i = 0; i < MAX ; i++){
        cout << tab[i] << " ";
    }
    cout << endl;
    cout << "10 najwiekszych elementow: ";
    int suma;
    for(int i = MAX - 1; i > MAX - 11; i--){
        cout << tab[i] << " ";
        suma += tab[i];
    }
    cout << endl <<"Ich suma: " << suma;
    return 0;
}
