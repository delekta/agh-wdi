//Dany jest zestaw odwa¿ników int t[N]. Napisaæ funkcje, która sprawdza czy jest mo¿liwe
//odwa¿enie okreslonej masy  Odwa¿niki mo¿na umieszczaæ tylko na jednej szalce
#include <iostream>
using namespace std;
const int N = 6;
bool mozna(int masa , int p,int t[]){// bez zmiennych T[N] , N bo są zadeklarowane globalnie , masa --> masa jakiej szukamy, p index szufladki z odwaznikami
    if(masa == 0) return true;
    if(p == N) return false;
    return mozna(masa, p + 1,t) || mozna(masa - t[p], p + 1,t);
    }
int main()
{
    /*cout << "Podaj mase " << N << " odwaznikow: ";
    for(int i = 0; i < N ; i++){
        cin >> t[i];
    }*/
    int t[N] = {1, 2, 3, 4, 5, 6};
    cout << "Podaj mase: ";
    int masa;
    cin >> masa;
    if(mozna(masa , 0, t)) cout << "mozna";
    else cout << "nie mozna";
    return 0;
}
