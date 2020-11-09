//Napisać program zamieniajšcy liczbę naturalnš z systemu 10 na podstawę 2-16
#include <iostream>
using namespace std;
void wypisz_liczbe(string slowo){
    for(int i = slowo.length() - 1;i >= 0; i--){
        cout<<slowo[i];
    }
}
void zamiana_systemu(int liczba, int podstawa){
    string szablon = "0123456789ABCDEF";
    string zamieniona = "";
    while(liczba > 0){
        zamieniona += szablon[liczba % podstawa];
        liczba /= podstawa;
    }
    wypisz_liczbe(zamieniona);
}
//Z wykorzystaniem tablicy ASCII, bez szablonu
zamiana_systemu2(int liczba, int podstawa){
    string zamieniona = "";
    char ASCII;
    while(liczba > 0){
        int kopia = liczba % podstawa;
        if((kopia) > 9) kopia += 7;
        ASCII = kopia + 48;
        liczba /= podstawa;
        zamieniona += ASCII;
    }
    wypisz_liczbe(zamieniona);
}
int main()
{
    int liczba;
    cout << "Jaka liczbe zamienic: ";
    cin >> liczba;
    cout << "Zamiana liczby "<< liczba << " na: " << endl;
    for(int podstawa = 2; podstawa <= 16; podstawa++){
        cout<< "System "<< podstawa <<" :";
        zamiana_systemu(liczba, podstawa);
        cout << endl;
    }
    return 0;
}
