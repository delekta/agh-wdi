//
// Created by Kamil Delekta on 04.01.2020.
//
//Dane sa dwie tablice int t1[N] oraz int t2[N] wypelnione liczbami naturalnymi. Elementy z tablic t1 i t2
//laczymy w pary(po jednym elemencie z kazdej tablicy) tak, aby suma wybranych elementow z tablicy t1 byla
//rowna sumie wybranych elementow z tablicy t2. prosze napisac funkcje, ktora zwroci maksymalna liczbe
//par, jaka mozna uzyskac. Do funkcji nalezy przekazac wylacznie tablice t1 i t2, funkcja powinna zwrocic
//maksymalna liczbe par
#include <iostream>
using namespace std;
const int N = 5;
void pary_kopia(int t1[N], int t2[N], int &max_ile, int suma1 = 0, int suma2 = 0, int ile1 = 0, int ile2 = 0, int index = 0)
{
    //Najlepszy warunek kancowy
    if (index == N)
    {
        if (ile1 == ile2)
        {
            if (suma1 == suma2)
            {
                if(ile1 > max_ile){
                    max_ile = ile1;
                }
            }
        }
        return;
    }
    else {
        pary_kopia(t1, t2, max_ile, suma1 + t1[index], suma2 + t2[index], ile1 + 1, ile2 + 1, index + 1);
        pary_kopia(t1, t2, max_ile, suma1, suma2 + t2[index], ile1, ile2 + 1, index + 1);
        pary_kopia(t1, t2, max_ile, suma1 + t1[index], suma2, ile1 + 1, ile2, index + 1);
        pary_kopia(t1, t2, max_ile, suma1, suma2, ile1, ile2, index + 1);
    }
}
int gotowy_program2_kopia(int t1[N], int t2[N])
{
    int max_ile = 0;
    pary_kopia(t1, t2, max_ile);
    return max_ile;
}
//zadanie ziomeczka
int maksi(int a, int b, int c,int d)
{
    int maks = a;
    if (b > maks) maks = b;
    if (c > maks) maks = c;
    if (d > maks) maks = d;
    return maks;
}
int pary(int t1[N], int t2[N], int suma1, int suma2, int ile1, int ile2, int index)
{
    if (index == N)
    {
        if (ile1 == ile2)
        {
            if (suma1 == suma2)
            {
                return ile1;
            }
        }
        return 0;
    }
    //ciekawe podejscie
    return maksi(pary(t1, t2, suma1 + t1[index], suma2 + t2[index], ile1 + 1, ile2 + 1, index + 1),
                 pary(t1, t2, suma1, suma2 + t2[index], ile1, ile2 + 1, index + 1),
                 pary(t1, t2, suma1 + t1[index], suma2, ile1 + 1, ile2, index + 1),
                 pary(t1, t2, suma1, suma2, ile1, ile2, index + 1));
}
int gotowy_program2(int t1[N], int t2[N])
{
    return pary(t1, t2, 0, 0, 0, 0, 0);
}
//koniec
//------moj nie dzialajacy program
/*void liczba_par(int t1[], int t2[], int ile_par, int suma1, int suma2, int idx1 = 0, int idx2 = 0){
    if(idx1 == N or idx2 == N) return;
    if(suma1 == suma2) return ile_par;
    else{
        for(int i = idx1; i < N; i++){
            for(int j = idx2; j < N; j++){
                return liczba_par(t1,t2, ile_par - 1, suma1 - t1[i], suma2 - t2[j], i + 1, j + 1)
                || liczba_par(t1, t2, ile_par, suma1, suma2, i + 1, j + 1);
            }
        }
    }
}
int liczba_par_aux(int t1[], int t2[]){
    int ile_par = N;
    int suma1 = 0;
    int suma2 = 0;
    for(int i = 0; i < N; i++){
        suma1 += t1[i];
        suma2 += t2[i];
    }
    return liczba_par(t1,t2,ile_par,suma1,suma2);

}
 */
int main() {
    int t1[N] = {1,3,5,6,5};
    int t2[N] = {1,3,5,4,7};
    //cout << "Liczba par: " << liczba_par_aux(t1,t2);
    cout << "Liczba par: " << gotowy_program2(t1,t2) << " <- ziomeczka" << endl;
    cout << "Liczba par: " << gotowy_program2_kopia(t1,t2) << " <- moja";
    return 0;
}
