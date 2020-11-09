//
// Created by Kamil Delekta on 04.01.2020.
//
//Dana jest tablica int t[N] wypelniona liczbami calkowitymi. Prosze napisac funkcje, ktora sprawdza,czy
//mozliwe jest "pociecie" tablicy na co najmniej 2 kawalki o jednakowych sumach elementow. Do funkcji nalezy
//przekazac tablice, funkcja powinna zwrocic najwieksza liczbe kawalkow, na ktora mozna pociac tablice, lub
//wartosc 0, jesli takie pociecie nie jest mozliwe. Na przyklad: dla tablicy [1,2,3,1,5,2,2,2,6] odpowiedzia
//powinno byc 4, bo [1,2,3|1,5|2,2,2|6]
#include <iostream>
using namespace std;
const int N = 9;
//zadanko nr1
int maksium(int a, int b)
{
    if (a > b) return a;
    return b;
}
int kawal	(int t[N], int sumy[N], int index, int kawalki)
{
    if (index==N)
    {
        int aktualna = sumy[0];
        for (int i = 1;i <=kawalki;i++)
        {
            if (aktualna != sumy[i])
            {
                return 0;
            }
        }
        return kawalki+1;
    }
    // bo tablice przez referencje
    int nowa[N] = {};
    for (int i = 0; i <= kawalki;i++)
    {
        nowa[i] = sumy[i];
    }
    nowa[kawalki] += t[index];
    return maksium(kawal(t, nowa, index + 1, kawalki + 1),
                   kawal(t, nowa, index + 1, kawalki));
    //sumy[kawalki] -= t[index];
}
int gotowy_program1(int tablica[N])
{
    int sumy[N] = {};
    return kawal(tablica, sumy, 0, 0);
}
void kawal_kopia(int t[N], int sumy[N], int &kawalki_max, int index = 0, int kawalki = 0)
{
    if (index==N)
    {
        //na sile ralizowanie polecenia
        if(kawalki == 0) return;
        int aktualna = sumy[0];
        for (int i = 1;i <= kawalki;i++)
        {
            if (aktualna != sumy[i])
            {
                return;
            }
        }
        if(kawalki + 1 > kawalki_max){
            // + 1
            kawalki_max = kawalki + 1;
        }
    }
    else {
         sumy[kawalki] += t[index];
         kawal_kopia(t, sumy, kawalki_max, index + 1, kawalki + 1);
         kawal_kopia(t, sumy, kawalki_max, index + 1, kawalki);
         sumy[kawalki] -= t[index];
    }
}
int gotowy_program1_kopia(int tablica[N])
{
    int sumy[N];
    for(int i = 0; i < N; i++)sumy[i] = false;
    int kawalki_max = 0;
    kawal_kopia(tablica, sumy, kawalki_max);
    return kawalki_max;
}
//koniec
//--------W rekurencji musi byc warunek bazowy!!!-----------
//----moje nie dzialajace--------
/*int mozliwe(int t[], int p, int k, int ile = 0){
    int suma1 = 0;
    int suma2 = 0;
    int idx = p;
    for(int i = 0; i < k; i++)suma2 += t[i];
    if(suma1 == suma2){
        if((mozliwe(t, p, idx, ile) != 0) && (mozliwe(t, idx, k, ile) != 0)){
            return ile + 2;
        }
        else return ile + 2;
    }
    while(suma1 < suma2 or idx == N){
        suma1 += t[idx];
        suma2 -= t[idx];
        idx++;
    }
    //else return 0;
}*/
int main() {
    int t[N] = {1, 2, 3, 1, 5, 2, 2, 2, 6};
    cout << "Liczba podzialow tej tablicy  na kawalki o rownych sumach wynosi: " << gotowy_program1(t) << " <-ziomeczka" << endl;
    cout << "Liczba podzialow tej tablicy  na kawalki o rownych sumach wynosi: " << gotowy_program1_kopia(t) << " <-moje";

    return 0;
}
