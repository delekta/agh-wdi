//
// Created by Kamil Delekta on 02.12.2019.
//
//Prosze napisac funkcje, która dla podanej sumy i listy
//nominalów wypisuje iloraz mozliwosci na jakie mozliwosci
//na jakie mozna wydac dana sume.
#include <iostream>
using namespace std;
int count(int cost, int nominaly[], int N, int i = 0){
    if(cost < 0) return 0;
    if(cost == 0) return 1;
    if(i >= N) return 0;
    return count(cost - nominaly[i], nominaly, N, i) +
           count(cost, nominaly, N, i + 1);
}
int main() {
    const int N = 8;
    int nominaly[N] = {1, 2, 5, 20, 50, 100, 200, 500};
    int suma;
    int cost;
    cin >> cost;
    cout << count(cost, nominaly, N);
    return 0;
}

