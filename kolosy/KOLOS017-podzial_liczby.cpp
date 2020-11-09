//
// Created by Kamil Delekta on 02.12.2019.
//
//Dana jest liczba naturalna N niezawieraj�ca cyfry 0, kt�r� rozbijamy na dwie liczby naturalneA i B,
//przenosz�c kolejne cyfry z liczby N do liczby A albo B. Na przyk�ad liczb� 21523mo�emy rozbi� na
//wiele sposob�w, np. (215,23),(2,1523),(223,15),(152,23),(22,153),(1,2523)...Uwaga: wzgl�dna kolejno�c
//cyfr w liczbie N oraz liczbach A i B musi by� zachowana. Prosz�napisa� funkcj� generuj�c� i wypisuj�c�
//wszystkie rozbicia, w kt�rych powsta�e liczby A i Bs� wzgl�dnie pierwsze. Do funkcji nale�y przekaza�
//warto�� N, funkcja powinna zwr�ci� liczb�znalezionych par
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
