//
// Created by Kamil Delekta on 30.11.2019.
//
#include <iostream>
#include <cmath>
using namespace std;
bool czy_pierwsza(int liczba){
    if(liczba < 2) return false;
    if(liczba == 2 || liczba == 3 || liczba == 5) return true;
    if(liczba %2 == 0 || liczba %3 == 0 || liczba %5 == 0) return false;
    int i = 7;
    while(i <= sqrt(liczba)){
        if(liczba %i == 0) return false;
        i += 4;
        if(liczba %i == 0) return false;
        i += 2;
    }
    return true;
}
int ile_roznych_czynnikow_pierwszych(int liczba){
    int ile = 1;
    int i = 2;
    while(i < sqrt(liczba)){
        if(liczba % i == 0){
            ile++;
            while(liczba %i == 0){
                liczba /= i;
            }
        }
        i++;
    }
    return (liczba == 1 ? ile: ile + 1);
}
void swapp(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}
void bubble_sort(int tab[],int N) {
    int posortowana;
    do {
        posortowana = true;
        for (int i = 0; i < N - 1; i++) {
            if (tab[i] > tab[i + 1]) {
                swapp(tab[i], tab[i + 1]);
                posortowana = false;
            }
        }
    } while (posortowana == false);
}
void wypisz_n_wyraz_FIBONACCI(int n){
    int a = 1;
    int b = 0;
    int licznik = 1;
    while(licznik < n){
        a += b;
        b = a - b;
        licznik ++;
    }
    cout << a;
}
int nwd(int a, int b){
    while(b != 0){
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int nww(int a, int b){
    return a / nwd(a, b) * b;
}
void wypisz_liczbe(string slowo){
    for(int i = slowo.length() - 1;i >= 0; i--){
        cout<<slowo[i];
    }
}
//z dziesietnego
void zamiana_systemu(int liczba, int podstawa){
    string szablon = "0123456789ABCDEF";
    string zamieniona = "";
    while(liczba > 0){
        zamieniona += szablon[liczba % podstawa];
        liczba /= podstawa;
    }
    wypisz_liczbe(zamieniona);
}
bool cz_jest_palindromem(int liczba){
    int kopia = liczba;
    int t;
    while(liczba > 0) {
        t = t * 10 + liczba % 10;
        liczba /= 10;
    }
    return t == kopia;
}
int main(){
    cout << "Czy liczba pierwsza jest ";
    int m;
    cin >> m;
    cout <<czy_pierwsza(m) << endl;
    cout << "Ile roznych czynnikow  ma: ";
    int n;
    cin >> n;
    cout << ile_roznych_czynnikow_pierwszych(n) << endl;
    const int N = 8;
    int tab[N] = {1, 21, 7, 9, 70, 12, 3, 5};
    for(int i = 0; i < N; i++){
        cout << tab[i] << " ";
    }
    bubble_sort(tab, N);
    cout << endl << "Posortowana: " << endl;
    for(int i = 0; i < N; i++){
        cout << tab[i] << " ";
    }
    int k;
    cout << endl << "Ktory wyraz ciagu fibonnaciego wypisac:";
    cin >> k;
    wypisz_n_wyraz_FIBONACCI(k);
    int a, b;
    cout << endl << "NWD: ";
    cin >> a >> b;
    cout << nwd(a, b) << endl;
    cout << "NWW: " << nww(a, b);
    int palindrom;
    cout << endl << "Czy jest palindromem: ";
    cin >> palindrom;
    cout << cz_jest_palindromem(palindrom);
    return 0;
}