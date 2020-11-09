//Szachownica jest reprezentowana przez tablic� int t[8][8] wype�nion� liczbami naturalnymi zawieraj�cymi
//koszt przebywania na danym polu szachownicy. Kr�l szachowy znajduje si� w wierszu 0 i kolumnie k.
//Kr�l musi w dok�adnie 7 ruchach dotrze� do wiersza 7. Prosz� napisa� funkcj�,
//kt�ra wyznaczy minimalny koszt przej�cia kr�la. Do funkcji nale�y przekaza�
//tablic� t oraz startow� kolumn� k. Koszt przebywaniana polu startowym i
//ostatnim tak�e wliczamy do kosztu przej�cia.
#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;
const int N = 8;
void wypisz_tablice(int t[N][N]){
    for(int y = 0; y < N; y++){
        for(int x = 0; x < N; x++){
            cout<< t[y][x] << "\t";
        }
        cout << endl;
    }
    cout << "\n\n";
}
void wypelnij_losowymi(int t[N][N]){
    for(int y = 0; y < N; y++){
        for(int x = 0; x < N; x++){
            t[y][x] = rand()%99 + 1;
        }
    }
}
void przejscie(int tab[N][N], int N,int & suma, int k, int w = 0, int sumaAkt = 0){
    if(k < 0) return;
    if(k == N) return;
    if(w == N){
        if(sumaAkt < suma){
            suma = sumaAkt;
            return;
        }
    }
    else{
        przejscie(tab, N, suma, k, w + 1, sumaAkt + tab[w][k]);
        przejscie(tab, N, suma, k + 1, w + 1, sumaAkt + tab[w][k]);
        przejscie(tab, N, suma, k - 1, w + 1, sumaAkt + tab[w][k]);
    }
    return;
}
int najmnieszjsza_suma(int tab[N][N], int N, int k){
    int suma = INT_MAX;
    przejscie(tab, N, suma, k);
    return suma;
    }
int main()
{
    srand(time(NULL));
    int t[N][N];
    wypelnij_losowymi(t);
    //dane do sprawdzenia
    /*t[0][1] = 2;
    t[1][1] = 2;
    t[2][1] = 2;
    t[3][1] = 2;
    t[4][1] = 2;
    t[5][1] = 2;
    t[6][1] = 2;*/
    wypisz_tablice(t);
    cout << "Podaj kolumne startowa: ";
    int k;
    cin >> k;
    cout << najmnieszjsza_suma(t, N, k);
    return 0;
}
