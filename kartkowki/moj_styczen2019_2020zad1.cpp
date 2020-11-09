//
// Created by Kamil Delekta on 16.01.2020.
//

#include <iostream>
using namespace std;
bool zgodna_piatkowo(int liczba1, int liczba2){
    int licznik1 = 0;
    int licznik2 = 0;
    while(liczba1 > 0){
      if(liczba1 % 5 == 0 or liczba1 % 5 == 2 or liczba1 % 5 == 4) licznik1++;
      liczba1 /= 5;
    }
    while(liczba2 > 0){
        if(liczba2 % 5 == 0 or liczba2 % 5 == 2 or liczba2 % 5 == 4) licznik2++;
        liczba2 /= 5;
    }
    return licznik1 == licznik2;
}
int main() {
    cout << zgodna_piatkowo(122, 114);
    return 0;
}
