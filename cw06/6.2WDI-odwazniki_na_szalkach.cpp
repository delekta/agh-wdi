//Dany jest zestaw odwa¿ników int t[N]. Napisaæ funkcjê,
//która sprawdza czy jest mo¿liwe odwa¿enie okreœlonej masy.
//Odwa¿niki mo¿na umieszczaæ na obu szalkach
#include <iostream>
using namespace std;
const int N = 5;
int t[N] = {5,2,1,10,20};
bool mozna(int masa, int p){
    if(masa == 0)return true;
    if(p == N)return false;
    return (mozna(masa, p + 1) || mozna(masa + t[p], p + 1) || mozna(masa - t[p], p + 1));
}
int main()
{
    cout << "Podaj mase: ";
    int masa;
    cin >> masa;
    if(mozna(masa, 0)) cout << "mozna";
    else cout << "nie mozna";
    return 0;
}
