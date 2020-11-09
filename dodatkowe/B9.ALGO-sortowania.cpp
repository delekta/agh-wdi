//
// Created by Kamil Delekta on 15.11.2019.
//
#include <iostream>
using namespace std;
const int N = 15;
void SWAP(int &a, int &b){//sprawdz czy dziala
    int t = a;
    a = b;
    b = t;
}
//sortowanie babelkowe
void bubble_sort(int t[], int N) {
    bool sorted;
    do {
        sorted = true;
        for( int i = 0;i < N - 1;i++)
        {
            if (t[i] > t[i + 1]) {
                sorted = false;
                int tmp = t[i];
                t[i] = t[i + 1];
                t[i + 1] = tmp;
            }
        }
    } while (sorted != true);
}

void bubble_sort_bezDOWHILE(int t[], int N){
        bool sorted = false;
        while(!sorted){
            sorted = true;
            for(int i = 0; i < N - 1; i++)
            {
                if (t[i] > t[i + 1]) {
                    sorted = false;
                    SWAP(t[i],t[i+1]);
                }
            }
        }
}
void insert_sort(int t[], int N){
    for(int i = 1;i < N; i++){//lepiej od i = 1, zeby od razu cos sortowalo
        int j = i;
        while(j > 0 && (t[j] < t[j-1])){
            SWAP(t[j], t[j-1]);
            j--;
        }
    }
}
int najm(int t[],int p, int k)//p-->index pierwszego | k-->index ostatniego
{
    int najm = p;
    for(int i = p +1;i <= k; i++){//p + 1 bo najm = p,wiec na poczatku by sprawdza³o same ze soba
        if(t[i] < t[najm]){
            najm = i;
        }
    }
    return najm;
}
void select_sort(int t[], int N){
    for(int i = 0; i < N; i++){
        int mini = najm(t, i, N - 1);
        SWAP(t[i],t[mini]);
    }
}
int binary_search1(int t[], int k, long x){
    int p = 0;
    int srodek;
    while(p <= k){
        srodek = (p + k)/2;
        if(t[srodek] == x) return srodek;
        if(x < t[srodek])  k = srodek -1;
        if(x > t[srodek])  p = srodek +1;
    }
    return -1;
}
int main(){
    int tab[N] = {2, 13, 4, 6, 15, 1, 3, 9, 7, 11, 8, 5, 10, 14, 12};
    //bubble_sort_bezDOWHILE(tab, N);
    //bubble_sort(tab, N);
    //insert_sort(tab, N);
    select_sort(tab,N);
    for(int i = 0;i < N;i++){
        cout << tab[i] << " ";
    }
    cout << endl << "Jakiej liczby szukasz: ";
    int szukana;
    cin >> szukana;
    if(binary_search1(tab, N - 1, szukana) != -1)cout << "Szukana znajduje sie w szufladce o indeksie: " << binary_search1(tab, N - 1, szukana);
        else cout << "Element "<< szukana << " nie znajduje sie w tablicy";
    return 0;
}
