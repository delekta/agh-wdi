//
// Created by Kamil Delekta on 02.12.2019.
//
//Proszê napisaæ program, który wczytuje liczbê naturaln¹ A i odpowiada na pytanie: ,,czy w którymkolwiek
//z systemów o podstawie 2-16, wszystkie cyfry liczby A zapisanej w tym systemie, s¹ liczbami pierwszymi?"
#include <iostream>
#include <cmath>
using namespace std;
bool czy_pierwsza(int liczba){
    if(liczba < 2) return false;
    if(liczba == 2) return true;
    if(liczba % 2 == 0) return false;
    for(int i = 3; i <= sqrt(liczba); i++){
        if(liczba % i == 0) return false;
    }
    return true;
}
//zmieni³em na int zeby miec opcje sprawdzenia wyniku
int wszystkie_cyfry_pierwsze(int liczba){
    int kopia = liczba;
    for(int i = 2; i < 16 ; i++){
        liczba = kopia;
        while(liczba > 0){
            if(!(czy_pierwsza(liczba % i))){
                break;
            }
            liczba /= 10;
            if(liczba == 0) return i;
        }
    }
    return 0;
}
int main() {
    int n;
    cout << "Czy liczba w ktorymkolwiek z systemow liczba ma wszystkie cyfry pierwsze: ";
    cin >> n;
    if(wszystkie_cyfry_pierwsze(n) != 0) cout << "W systemie: " << wszystkie_cyfry_pierwsze(n);
    else cout << "NIE";
    return 0;
}
