//
// Created by Kamil Delekta on 12.01.2020.
//
//Napisz procedurê, która jako argument przyjmuje liczbê ca³kowit¹ i wypisuje
//wszystkie co najmniej dwucyfrowe liczby pierwsze, powsta³e poprzez
//wykreœlenie z liczby pierwotnej co najmniej jednej cyfry
#include <iostream>
#include <cmath>
using namespace std;
//nie dziala jeszcze 100% dobrze
bool czy_pierwsza(int liczba){
    if(liczba < 2) return false;
    if(liczba == 2) return true;
    if(liczba %2 == 0) return false;
    for(int i = 3; i <= sqrt(liczba); i+=2){
        if(liczba %i == 0) return false;
    }
    return true;
}
int how_many_digits(int number){
    int l = 0;
    while(number > 0){
        l++;
        number /= 10;
    }
    return l;
}
void liczby_pierwsze(int liczba, int dziel, bool wykreslona = false){
    int digits = how_many_digits(liczba);
    if(digits >= 2 and wykreslona){
        if(czy_pierwsza(liczba)) cout << liczba << " ";
    }
    if(digits > 2 and liczba %10 != 0){
        int lewa = liczba / dziel;
        int prawa = liczba % dziel;
        lewa = lewa / 10 * 10;//usuwa ostatnio cyfe;
        int nowa;
        if(prawa != 0)nowa = lewa + prawa;
        else nowa = lewa / 10;
        if(nowa %10 != 0) liczby_pierwsze(nowa, dziel, true);
        if(dziel * 10< liczba){
            liczby_pierwsze(liczba, dziel * 10, wykreslona);
        }
    }
    //sprawdzamy czy dzielnik po pommnzozeniu dalej mniejszy do lizba bo jak wiekszy to bez sensu, bo to nic nie zmienia
    //chyba niepotrzebne, bo jak digits nie sa wieksze od 2 to bez sensu wchodzic z wiekszym dzielnikiem bo to nic nie da
}
void liczby_pierwsze_stara(int liczba, int dziel, bool wykreslona = false){
    int digits = how_many_digits(liczba);
    if(digits >= 2 and wykreslona){
        if(czy_pierwsza(liczba)) cout << liczba << " ";
    }
    if (liczba > 0 && dziel <= liczba and digits > 2) {
        int lewa = liczba / (dziel * 10);
        lewa *= dziel;
        int prawa = liczba % dziel;
        int nowa = lewa + prawa;
        liczby_pierwsze_stara(liczba, dziel * 10, wykreslona);
        liczby_pierwsze_stara(nowa, dziel, true);
        }
}
int main() {
    liczby_pierwsze_stara(1371, 1);
    return 0;
}
