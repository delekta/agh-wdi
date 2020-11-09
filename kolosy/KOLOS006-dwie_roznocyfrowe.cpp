//
// Created by Kamil Delekta on 01.12.2019.
//
//Dwie liczby naturalne są “różnocyfrowe”, jeżeli nie posiadają żadnej wspólnej cyfry. Proszę
//napisać program, który wczytuje dwie liczby naturalne i poszukuje najmniejszej podstawy
//systemu (w zakresie 2-16), w którym liczby są różnocyfrowe. Program powinien wypisać
//znalezione podstawy; jeżeli podstawa taka nie istnieje, należy wypisać komunikat o jej braku.
//Na przykład: dla liczb 123 i 522 odpowiedzią jest podstawa 4, bo 123(10) = 1323(4) i 522(10) = 20022(4)
#include  <iostream>
using namespace std;
int main()
{
    long int liczba1, liczba2, RMBliczba1, RMBliczba2;
    cout<<"Podaj dwie liczby, a znajde najmniejsza podstawe w ktorej te liczby sa roznocyfrowe: ";
    cin >> liczba1 >> liczba2;
    RMBliczba1 = liczba1;
    RMBliczba2 = liczba2;
    bool tab1[16];
    bool tab2[16];
    int pierwszROZNOCYFROWA = -1;
    bool znaleziona = false;
    for(int i = 2; i <= 16 && !znaleziona ; i++)
    {
        liczba1 = RMBliczba1;
        liczba2 = RMBliczba2;
        for(int i=0; i < 16; i++) tab1[i] = tab2[i] = 0;
        while(liczba1 > 0)
        {
            tab1[liczba1 % i] = 1;
            liczba1 /= i;
        }
        while(liczba2 > 0)
        {
            tab2[liczba2%i] = 1;
            liczba2 /= i;
        }
        int j = 0;
        for( j = 0; j < i && tab1[j] == tab2[j]; j++);
        if(j < i)
        {
            pierwszROZNOCYFROWA = i;
            znaleziona = true;
        }
    }
    if(pierwszROZNOCYFROWA != -1) cout << "Najmniejsza podstawowa dla ktorej liczby sa roznocyfrowa jest " << pierwszROZNOCYFROWA;
    else cout << "Nie istnieje podstawa, dla ktorej liczby sa roznocyfrowe ";
    return 0;
}
