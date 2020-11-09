//Problem skoczka szachowego
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
    cout << "\n\n";
}
void wyzeruj_tablice(int t[rozm][rozm]){
    for(int y = 0; y < rozm; y++){
        for(int x = 0; x < rozm; x++){
            t[y][x] = 0;
        }
    }
}
// funkcja sprawdzajaca czy mozna wykonac ruch
bool czy_mozna(int t[rozm][rozm], int rozm, int w, int k, int &newW, int &newK, int wariant){
    switch(wariant){
        case 1:
            newW = w + 2;
            newK = k + 1;
            break;
        case 2:
            newW = w + 1;
            newK = k + 2;
            break;
        case 3:
            newW = w - 1;
            newK = k + 2;
            break;
        case 4:
            newW = w - 2;
            newK = k + 1;
            break;
        case 5:
            newW = w - 2;
            newK = k - 1;
            break;
        case 6:
            newW = w - 1;
            newK = k - 2;
            break;
        case 7:
            newW = w + 1;
            newK = k - 2;
            break;
        case 8:
            newW = w + 2;
            newK = k - 1;
            break;
    }
    if(newW >= 0 && newK >= 0 && newW < rozm && newK < rozm && t[newW][newK] == 0){
        return true;
    }
    else return false;
}
void skoczek_szachowy(int t[rozm][rozm], int rozm, int w, int k, int licznik = 1){
    int newW, newK , wariant;
    t[w][k] = licznik;
    if(licznik == rozm * rozm){
        wypisz_tablice(t);
    }
    else{
        for(wariant = 1; wariant <= 8; wariant++)
            if(czy_mozna(t, rozm, w, k, newW, newK, wariant))
                skoczek_szachowy(t, rozm, newW, newK, licznik + 1);
    }
    t[w][k] = 0;
}
int main()
{
    int tab[rozm][rozm];
    wyzeruj_tablice(tab);
    cout << "Podaj pole startowe: ";
    cout << endl <<"Zakres: <0 , " << rozm - 1 << " >" << endl;
    cout << "y : ";
    int y;
    cin >> y;
    cout << "x : ";
    int x;
    cin >> x;
    cout<< "Czy mozna, zaczynajac z pozycji wiersz = " << y  << " i kolumna= " << x  << endl;
    skoczek_szachowy(tab, rozm, y, x);
    return 0;
}
