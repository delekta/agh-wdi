//
// Created by Kamil Delekta on 16.01.2020.
//

#include <iostream>
using namespace std;
int functionA(int n){
    return n + 3;
}
int functionB(int n){
    return 2*n;
}
int functionC(int n){
    if(n % 2 == 0) return n + 1;
    else return n;
}
//moje
int przeksztalcenie(int x, int y, int n, int func){
    int licznik = 0;
    if(x == y) return 1;
    else if(x > y) return 0;
    else if(n == 0) return 0;
    else{
        if(func != 1){
            x = functionA(x);
            licznik += przeksztalcenie(x, y, n - 1, 1);
        }
        if(func != 2){
            x = functionB(x);
            licznik += przeksztalcenie(x, y, n - 1, 2);
        }
        if(func != 3){
            x = functionC(x);
            licznik += przeksztalcenie(x, y, n - 1, 3);
        }
    }
    return licznik;
}
//wzorcowe
int przeksztalcenie_c(int x, int y, int n, int func){
    int licznik = 0;
    if(x == y) return 1;
    else if(x > y) return 0;
    else if(n == 0) return 0;
    else{
        if(func != 1){
            licznik += przeksztalcenie_c(functionA(x), y, n - 1, 1);
        }
        if(func != 2){
            licznik += przeksztalcenie_c(functionB(x), y, n - 1, 2);
        }
        if(func != 3){
            licznik += przeksztalcenie_c(functionC(x), y, n - 1, 3);
        }
    }
    return licznik;
}
int main() {
    int x = 5;
    int y = 13;
    int n = 5;
    int func = 0;
    cout << przeksztalcenie(x, y, n, func) << "<- moje" << endl;
    cout << przeksztalcenie_c(x, y, n, func) << "<- wzorcowe, niewiele sie rozniace";
    return 0;
}
