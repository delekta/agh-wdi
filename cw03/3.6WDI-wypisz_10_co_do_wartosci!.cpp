//Proszê napisaæ program, który wczytuje wprowadzany z klawiatury ci¹g liczb naturalnych zakoñczonych zerem
//stanowi¹cym wy³¹cznie znacznik koñca danych.  Program powinien wypisaæ 10 co do wielkoœci wartoœæ,
//jaka wyst¹pi³a w ci¹gu.  Mo¿na za³o¿yæ, ¿e w ci¹gu znajduje siê wystarczaj¹ca liczba elementów
#include <iostream>
using namespace std;
void SWAP(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}
void SORT(int tab[], int sizee){
    bool sorted;
    do{
        sorted = true;
        for(int j = 0; j < sizee - 1; j++){
                if(tab[j] > tab[j + 1]){
                    SWAP(tab[j], tab[j + 1]);
                    sorted = false;
                }
        }
    }while(sorted != true);
    // musi byc sorted != true, bo przy sorted = false nie dzia³a
}
void WRITE_OUT(int tab[], int sizee){
    for(int j = 0; j < sizee; j++){
        cout<< tab[j] << " ";
    }
}
void WRITE_OUT_TENTH(int tab[], int sizee){
    //liczy ilosc roznych liczb
    int counter = 0;
    int i = 0;
    int j;
    while(counter < 9){
            j = i + 1;
        while(tab[i] == tab[j]){
            j++;
        }
        counter++;
        i = j;
    }
    cout << "10 elementem co do wartosci jest: " << tab[j];
}
using namespace std;
int main()
{
    const int N = 100;
    int tab[N];
    int i;
    for(i = 0; i < N; i++){
        cin >> tab[i];
        if(tab[i] == 0){
            break;
        }
    }
    SORT(tab, i);
    WRITE_OUT(tab, i);
    cout << endl;
    WRITE_OUT_TENTH(tab, i);
    return 0;
}
