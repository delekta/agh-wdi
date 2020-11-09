//
// Created by Kamil Delekta on 02.12.2019.
//
//Dana jest liczba naturalna N niezawieraj¹ca cyfry 0, któr¹ rozbijamy na dwie liczby naturalneA i B,
//przenosz¹c kolejne cyfry z liczby N do liczby A albo B. Na przyk³ad liczbê 21523mo¿emy rozbiæ na
//wiele sposobów, np. (215,23),(2,1523),(223,15),(152,23),(22,153),(1,2523)...Uwaga: wzglêdna kolejnoœc
//cyfr w liczbie N oraz liczbach A i B musi byæ zachowana. Proszênapisaæ funkcjê generuj¹c¹ i wypisuj¹c¹
//wszystkie rozbicia, w których powsta³e liczby A i Bs¹ wzglêdnie pierwsze. Do funkcji nale¿y przekazaæ
//wartoœæ N, funkcja powinna zwróciæ liczbêznalezionych par
#include <iostream>
using namespace std;
int nwd(int a, int b){
    while(b != 0){
         int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int odwroc(int a){
    int c = 0;
    while(a > 0){
        c = c * 10 + a % 10;
        a /= 10;
    }
    return c;
}
void podzial(int N, int &licznik, int A = 0, int B = 0){
    if(N == 0){
        A = odwroc(A);
        B = odwroc(B);
        if(nwd(A, B) == 1){
            licznik++;
            cout << "A: " << A << " B: " << B << endl;
        }
    }
    else{
        podzial(N / 10, licznik, A * 10 + N % 10, B);
        podzial(N / 10, licznik, A, B * 10 + N % 10);
    }
}
//funkcja okalajaca
int counter(int N){
    int licznik = 0;
    podzial(N, licznik);
    return licznik;
}
int main() {
    cout << "Podaj liczbe: ";
    int N;
    cin >> N;
    cout << counter(N);
    return 0;
}
