//Dana jest tablica int t[N]. Prosz� napisa� funkcj�, kt�ra znajdzie niepusty, najmniejszy (w sensie liczebno�ci) podzbi�r element�w tablicy,
//dla kt�rego suma element�w jest r�wna sumie indeks�w tych element�w. Do funkcji nale�y przekaza� tablic�, funkcja powinna zwr�ci� sum�
//element�w znalezionego podzbioru. Na przyk�ad dla tablicy: [ 1, 7, 3, 5, 11, 2 ] rozwi�zaniem jest liczba 10
#include <iostream>
using namespace std;
void najmniejszy_podzbior(int tab[], int rozmiar, int najm,int &SUMA, int p = 0, int sumae = 0, int sumai = 0, int ile = 0){
    if(p == rozmiar){
        if(sumae == sumai && sumae > 0) {
            if (ile < najm) {
                SUMA = sumae;
                najm = ile;
                return;
            }
            return;
        }
    }
    else {
        najmniejszy_podzbior(tab, rozmiar, najm, SUMA, p + 1, sumae + tab[p], sumai + p, ile + 1);
        najmniejszy_podzbior(tab, rozmiar, najm, SUMA, p + 1, sumae, sumai, ile);
        return;
    }
}
int suma(int tab[], int rozmiar){
    int sum = 0;
    najmniejszy_podzbior(tab, rozmiar, rozmiar + 1,sum);
    return sum;
}
int main()
{
    const int rozmiar = 6;
    int tab[rozmiar] = {1, 7, 3, 5, 11, 2};
    cout << suma(tab, rozmiar);
    return 0;
}
