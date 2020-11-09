//Napisaæ program generuj¹cy i wypisuj¹cy liczby pierwsze mniejsze od N metod¹ Sita Eratostenesa
#include <iostream>
#include <cmath>
using namespace std;
void wypisz_liczby_pierwsze(int n){
    bool tab[n + 1];
    for(int i = 2; i <= n; i++) tab[i] = true;
    // 1 nie jest liczba pierwsza!
    for(int i = 2; i <= sqrt(n); i++){
        if(tab[i]){
            int w = i*i;
            while(w <= n){
                tab[w] = false;
                w += i;
            }
        }
    }
    int licznik = 0;
    //wypisuj od dwa, bo przecierz nic nie masz w tablicy o indeksach 0, 1
    for(int k = 2; k <= n; k++){
        if(tab[k]){
            cout << k << " ";
            licznik++;
        }
    }
    cout << endl << "Do "<< n << " jest "<< licznik << " liczb pierwszych";
}
int main()
{
    cout << "Do ilu wypisac liczby pierwsze: ";
    int n;
    cin >> n;
    wypisz_liczby_pierwsze(n);
    return 0;
}
