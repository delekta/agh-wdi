//
// Created by Kamil Delekta on 30.11.2019.
//
//Prosz? napisa? funkcj?, która dla podanej sumy i listy
//nomina?ów wypisuje ilo?? mo?liwo?ci na jakie mo?liwo?ci
//na jakie mo?na wyda? dan? sum?.
#include <iostream>
using namespace std;
void wypisz(int nominaly[], int N, int &ile, int suma, string tasma = "", int p = 0)
{
    if(suma < 0)return;
    if(p == N) {
        if (suma == 0) {
            ile++;
            cout << tasma << endl;
        }
        else return;
    }
    else {
        wypisz(nominaly, N, ile, suma - nominaly[p], tasma + to_string(nominaly[p]) + " ", p);
        wypisz(nominaly, N, ile, suma, tasma, p + 1);
    }
}
void ile(int nominaly[], int N, int suma)
{
    int ile = 0;
    wypisz(nominaly, N, ile, suma);
    cout << "ilosc mozliowsci wydania: " << ile;
}
int main()
{
    const int N = 8;
    int nominaly[N] = {1, 2, 5, 20, 50, 100, 200, 500};
    int suma;
    cout << "Podaj sume: ";
    cin >> suma;
    ile(nominaly, N, suma);
    return 0;
}
