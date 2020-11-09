//Dany jest ci�g zer i jedynek zapisany w tablicy int t[N]. Prosz� napisa� funkcj�, kt�ra odpowiada na pytanie
//czy jest mo�liwe poci�cie ci�gu na kawa�ki z kt�rych ka�dy reprezentuje liczb� pierwsz�. D�ugo�� ka�dego z
//kawa�k�w nie mo�e przekracza� 30. Na przyk�ad dla ci�gu 111011 jest to mo�liwe, a dla ci�gu 110100 nie jest mo�liwe
#include <iostream>
#include <cmath>
using namespace std;
const int N = 6;
bool czy_pierwsza(int liczba){
    if(liczba < 2) return false;
    if(liczba %2 == 0 && liczba != 2) return false;
    for(int i = 3; i <= sqrt(liczba); i+=2){
        if(liczba %i == 0) return false;
    }
    return true;
}
bool podzial(int tab[N], int poczatek = 0){
    if(poczatek == N) return true;
    int l = 0;
    for(int i = poczatek; i < N; i++){
        l = l*2 + tab[i];
        if(czy_pierwsza(l) && podzial(tab, i +  1)) return true;
    }
    return false;
}
int main()
{
    //int tab[N] = {1, 1, 1, 1, 0, 1, 1, 1, 0, 1}; //tablica mozliwa do podzialu N = 10
    //int tab[N] = {1,1,0};//tablica niemozliwa do podzaialu N = 3
    //int tab[N] = {1,1,1,1};//tablica mozliwa do podzialu N = 4
    int tab [N] = {1, 1, 0, 1, 0, 0};//tablica niemozliwa do podzialu N = 6
    if(podzial(tab)) cout << "mozna";
    else cout << "nie mozna";
    return 0;
}
