//
// Created by Kamil Delekta on 12.01.2020.
//

#include <iostream>
#include <cmath>
using namespace std;
bool czy_pierwsza(int liczba){
    if(liczba < 2) return false;
    if(liczba == 2) return true;
    if(liczba %2 == 0) return false;
    for(int i = 3; i <= sqrt(liczba); i+=2){
        if(liczba %i == 0) return false;
    }
    return true;
}
//C od razu = 1, bo t¹ jedynke z A od razu ustawilismy, dla tego wywolujemy  (A - 1, B)
int budowanie_liczby(int A, int B, int C = 1){//wywolanie (a - 1, b)
    int counter = 0;
    if(A == 0 and B == 0){
        if(!(czy_pierwsza(C))){
            return 1;
        }
    }
    else{
        if(A > 0) counter += budowanie_liczby(A - 1, B, C * 2 + 1);
        if(B > 0) counter += budowanie_liczby(A, B - 1, C * 2);
    }
    return counter;
}
int main() {
    int A = 2;
    int B = 3;
    cout << budowanie_liczby(A - 1, B);
    return 0;
}
