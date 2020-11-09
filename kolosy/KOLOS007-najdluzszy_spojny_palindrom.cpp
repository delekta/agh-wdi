//
// Created by Kamil Delekta on 01.12.2019.
//
//Dane są deklaracje:
//const int N=1000;
//int tab[N];
//Tablica tab jest wypełniona liczbami naturalnymi. Proszę napisać funkcję, która zwraca długość
//najdłuższego spójnego podciągu będącego palindromem złożonym wyłącznie z liczb
//nieparzystych. Do funkcji należy przekazać tablicę, funkcja powinna zwrócić długość
//znalezionego podciągu, lub wartość 0, jeżeli taki podciąg nie istnieje.
#include <iostream>
using namespace std;
const int N = 10;
int tab[N] = {2, 4, 6, 8, 8, 4, 8, 6, 2, 4};
// np |1|2|2|1| --> |1|left|2|1|
int parzystej_dlg(int left){
    int right = left + 1;
    int licznik = 0;
        while (left >= 0 and right < N) {
            if (tab[left] % 2 != 0 && tab[right] % 2 != 0) {
                if (tab[left] == tab[right]) {
                    licznik += 2;
                    left--;
                    right++;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
    return licznik;
}
//np |1|2|3|2|1| --> |1|2|mid|2|1|
int nieparzystej_dlg(int mid){
    int licznik = 0;
    int i = 1;
    if(tab[mid] %2 != 0) {
        licznik++;
        while (mid - i >= 0 and mid + i < N) {
            if (tab[mid - i] % 2 != 0 && tab[mid + i] % 2 != 0) {
                if (tab[mid - i] == tab[mid + i]) {
                    licznik += 2;
                    i++;
                }
                else{
                    break;
                }
            } else {
                break;
            }
        }
    }
    return licznik;
}
int najdluzszy_podciag(){
    int najw_palindrom = 0;
    for(int i = 0; i < N; i++){
        int najw_parzysty = parzystej_dlg(i);
        if(najw_parzysty > najw_palindrom){
            najw_palindrom = najw_parzysty;
        }
        int najw_nieparzysty = nieparzystej_dlg(i);
        if(najw_nieparzysty > najw_palindrom){
            najw_palindrom = najw_nieparzysty;
        }
    }
    return najw_palindrom;
}
int main() {
    cout << najdluzszy_podciag();
    return 0;
}

