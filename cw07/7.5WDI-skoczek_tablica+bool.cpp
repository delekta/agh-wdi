#include <iostream>
using namespace std;
const int rozm = 5;
void wypisz_tablice(int t[rozm][rozm]){
    for(int y = 0; y < rozm; y++){
        for(int x = 0; x < rozm; x++){
            cout<< t[y][x] << "\t";
        }
        cout << endl;
    }
}
void wyzeruj_tablice(int t[rozm][rozm]){
    for(int y = 0; y < rozm; y++){
        for(int x = 0; x < rozm; x++){
            t[y][x] = 0;
        }
    }
}
//tablica na ruchy
bool cz_mozna(int tab[rozm][rozm], int rozm, int w, int k, int &newW, int &newK , int wariant){
    int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    newW = w + dy[wariant];
    newK = k + dx[wariant];
    if(newW >= 0 && newW < rozm && newK >= 0 && newK < rozm && tab[newW][newK] == 0) return true;
    else return false;

}
//funkcja bool
bool ruch(int tab[rozm][rozm], int rozm, int w, int k, int licznik = 1){
    int newW, newK, wariant;
    tab[w][k] = licznik;
    //licznik "==" pamietaj!!
    if(licznik == rozm * rozm){
        wypisz_tablice(tab);
        return true;
    }
    else{
        for(wariant = 0; wariant < 8; wariant++){
            if(cz_mozna(tab, rozm, w, k, newW, newK, wariant)){
                if(ruch(tab, rozm, newW, newK, licznik +1)) return true;
                //else return false; -- nie moze tu byc return false
                //bo ten return stopuje wykonanie reszty petli for
            }
        }
    }
    tab[w][k] = 0;
    //musi byc ten return false
    //czemu return false a w void nic nie musi byc, nawet return;
    return false;
}
int main()
{
    int tab[rozm][rozm];
    wyzeruj_tablice(tab);
    int w = 0;
    int k = 0;
    //dawaj argumenty do funkcji bo bez jest zawsze prawdziwa
    if(ruch(tab,rozm, w, k)) cout << "mozna";
    else cout << "nie mozna";
    return 0;
}
