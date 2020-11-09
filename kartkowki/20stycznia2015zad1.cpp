//
// Created by Kamil Delekta on 14.01.2020.
//
//Dana jest tablica wype�niona liczbami naturalnymi:
//const int N=1000; int t[N][N];
//Prosz� napisa� funkcj�, kt�ra poszukuje w tablicy kwadratu o liczbie p�l b�d�cej liczb� nieparzyst�
//wi�ksz� od 1, kt�rego iloczyn 4 p�l naro�nych wynosi k. Do funkcji nale�y przekaza� tablic� i warto�� k.
//Funkcja powinna zwr�ci� informacje czy uda�o si� znale�� kwadrat oraz wsp�rz�dne (wiersz, kolumna) �rodka kwadratu
#include <iostream>
using namespace std;
const int N = 6;
struct wspol{
    int w;
    int k;
    bool mozna;
};
//teraz dziala zajebiscie ale pamietaj zeby uwazac z tymi bokami +1 albo -1
wspol kwadrat(int t[N][N], int x){
    wspol wspol;
    for(int bok = 3; bok < N + 1; bok +=2){
        //tu jest zle bo to nie rozwazasz kwadratu
        for(int w2 = bok - 1; w2 < N; w2++){
            for(int k2 = bok - 1; k2 <N; k2++) {
                //w1 = w2 - bok - 1 // edit: jednak - bok + 1
                int w1 = w2 - bok + 1;
                int k1 = k2 - bok + 1;
                if((t[w1][k1] * t[w2][k2] * t[w1][k2] * t[w2][k1]) == x){
                    wspol.w = (w1 + w2) / 2;
                    wspol.k = (k1 + k2) / 2;
                    wspol.mozna = true;
                    return wspol;
                }
            }
        }
    }
    wspol.mozna = false;
    return wspol;
}
int main() {
    int t[N][N] = {
            {1, 2, 5, 6, 8, 9},
            {1, 2, 5, 6, 8, 9},
            {1, 2, 5, 6, 8, 9},
            {1, 2, 2, 3, 5, 9},
            {1, 2, 5, 54, 55, 89},
            {1, 2, 5, 6, 8, 9},
    };
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
    wspol wynik = kwadrat(t, 440);
    if(wynik.mozna == true) {
        cout << wynik.w << " " << wynik.k;
    }
    else cout << "nie mozna";
    return 0;
}
