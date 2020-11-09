//
// Created by Kamil Delekta on 05.01.2020.
//
//Dana jest tablica int t[N][N] zawierajaca liczby naturalne. Dok³adnie w jednym
//wierszu, b¹dz jednej kolumnie znajduje sie fragment ciagu arytmetycznego o d³ugosci
//wiekszej niz 2, ktorego elementy sa liczbami pierwszymi. Prosze napisac funkcje
//ktora zwroci d³ugosc tego ciagu.
//czy to ze elementy sa liczbami pierwszymi cos zmienia?
#include <iostream>
using namespace std;
const int N = 5;
int length_of_sequance(int t[N][N]){
    int length;
    for(int y = 0; y < N ; y++){
        for(int x = 0; x < N; x++){
            //przechodze po wierszach
            if((t[y][x] + t[y][x + 2] == 2 * t[y][x + 1]) and (x < N - 2)){
                length = 2;
                while((t[y][x] + t[y][x + 2] == 2 * t[y][x + 1]) and (x < N - 2)){
                    length++;
                    x++;
                }
                return length;
            }
            //przechodze po kolumnach
            if((t[x][y] + t[x + 2][y] == 2 * t[x + 1][y]) and (x < N - 2)){
                length = 2;
                while((t[x][y] + t[x + 2][y] == 2 * t[x + 1][y]) and (x < N - 2)){
                    length++;
                    x++;
                }
                return length;
            }
        }
    }
    //jesli talica nie ma ciagu
    return 0;
}
int main() {
    int t1[N][N] = {
            {1, 2, 6, 7, 9},
            {25, 4, 12, 9, 7},
            {1, 6, 6, 7, 9},
            {25, 8, 12, 9, 7},
            {1, 2, 6, 7, 9}
    };
    int t2[N][N] = {
            {1, 2, 6, 7, 9},
            {25, 10, 12, 9, 7},
            {1, 6, 6, 7, 9},
            {25, 20, 15, 10, 7},
            {1, 2, 6, 7, 9}
    };
    int length = length_of_sequance(t2);
    cout << "Ciag arytmetyczny w tablicy ma dlugosc: " << length;
    return 0;
}
