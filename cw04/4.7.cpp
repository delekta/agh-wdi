//
// Created by Kamil Delekta on 12.01.2020.
//
//Dane s¹ dwie tablice mog¹ce pomieœciæ tak¹ sam¹ liczbê elementów:
// int t1[MAX][MAX];
// int t2[MAX2];
//MAX2 = MAX*MAX W ka¿dym wierszu tablicy t1 znajduj¹ siê uporz¹dkowane niemalej¹co (w obrêbie wiersza) liczby naturalne.
//Proszê napisaæ funkcjê przepisuj¹c¹wszystkie liczby z tablicy t1 do t2, tak aby liczby w tablicy t2 by³y uporz¹dkowane niemalej¹co
#include <iostream>
using namespace std;
const int MAX = 8;
const int MAX2 = MAX * MAX;
int przepisz(int t[MAX][MAX], int tn[MAX2]){
    //wskazuje na wiersz, a z tego juz za pomoca tablicy pointer[min_pointer] mam kolumne
    int min_row;
    int min_val = INT_MAX;
    //idx dla kazdego wiersza
    int columns[MAX];
    for(int i = 0; i < MAX; i++) columns[i] = 0;
    int idx = 0;

    while(idx < MAX2) {
        //po wyjsciu z fora mamy najm element
        min_val = INT_MAX;
        for (int w = 0; w < MAX; w++) {
            if (columns[w] < MAX) {
                if (t[w][columns[w]] < min_val) {
                    min_val = t[w][columns[w]];
                    min_row = w;
                }
            }
        }
        tn[idx] = t[min_row][columns[min_row]];
        columns[min_row]++;
        idx++;
    }
}
int main() {
    int t[MAX][MAX] = {
            {2, 4, 8, 15, 68, 69, 74, 87},
            {2, 4, 26, 45, 56, 97, 98, 99},
            {4, 5, 8, 16, 55, 90, 94, 97},
            {3, 4, 8, 15, 45, 85, 91, 97},
            {2, 6, 8, 35, 49, 91, 94, 97},
            {1, 4, 9, 15, 55, 80, 84, 97},
            {1, 7, 8, 15, 48, 70, 74, 97},
            {1, 3, 8, 15, 55, 90, 96, 97}
    };
    int tn[MAX2];
    przepisz(t, tn);
    for(int i = 0 ; i < MAX2; i++) cout << tn[i] << " ";
    return 0;
}
