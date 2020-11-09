//Dana jest tablica int t[N]. Proszê napisaæ funkcjê, która znajdzie niepusty, najmniejszy (w sensie liczebnoœci) podzbiór elementów tablicy,
//dla którego suma elementów jest równa sumie indeksów tych elementów. Do funkcji nale¿y przekazaæ tablicê, funkcja powinna zwróciæ sumê
//elementów znalezionego podzbioru. Na przyk³ad dla tablicy: [ 1, 7, 3, 5, 11, 2 ] rozwi¹zaniem jest liczba 10
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
