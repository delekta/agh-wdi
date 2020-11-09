//
// Created by Kamil Delekta on 02.12.2019.
//
//Dane s¹ dwa ci¹gi okreœlone nastêpuj¹co:
// a1= 1 an=an?1+bn/3
// b1= 2 bn=bn?1+an?1
// Proszê napisaæ program, który wczytuje liczbê naturalna k i odnajduje wyraz nale¿¹cy do jednego z ci¹gów o wartoœci najblizej.
// Program powinien wypisaæ numer znalezionego wyrazu i ci¹g z którego on pochodzi. Je¿eli wiêcej ni¿ jeden wyraz jest jednakowo
// odleg³y od k, nale¿y wybraæ ten o mniejszym numerze
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    float k;
    cout << "Podaj liczbe naturalna: ";
    cin >> k;
    float A[1000];
    float B[1000];
    A[0] = B[0] = 0;
    A[1] = 1;
    B[1] = 2;
    int i = 1;
    //indeksy wyrazow wiekszych od k
    //defaultowe wartosci do rmb | POTRZEBNE |
    int rmbA = 1;
    int rmbB = 1;
    bool b1 = true;
    bool b2 = true;
    cout << "Bi: " << 1 <<" wartosc:"<<B[1] << endl;
    cout << "Ai: " << 1 <<" wartosc:"<<A[1] << endl;
    //kiedy petla sie skonczy to oba wyrazy z obu ciagow beda miec wieksza wartosc niz k
    while(k > A[i] || k > B[i] ){
        i++;
        B[i] = B[i - 1] + A[i - 1];
        cout << "Bi: " << i <<" wartosc:"<<B[i] << endl;
        A[i] = A[i - 1] + B[i]/3;
        cout << "Ai: " << i <<" wartosc:"<<A[i] << endl;
        //zapis indeksu dla pierwszego wyrazu wiekszego od k
        if(B[i] > k && b1){
            rmbB = i;
            b1 = false;
        }
        if(A[i] > k && b2){
            rmbA = i;
            b2 = false;
        }
    }
    float najm;
    int najm_index;
    char ciag;
    najm = abs(k - A[1]);
    najm_index = 1;
    ciag = 'A';
    if(abs(k - A[rmbA - 1]) < najm){
        najm = abs(k - A[rmbA - 1]);
        najm_index = rmbA -1;
        ciag = 'A';
    }
    if(abs(k - A[rmbA]) < najm){
        najm = abs(k - A[rmbA]);
        najm_index = rmbA;
        ciag = 'A';
    }
    if(abs(k - B[rmbB - 1]) < najm){
        najm = abs(k - B[rmbB - 1]);
        najm_index = rmbB - 1;
        ciag = 'B';
    }
    if(abs(k - B[rmbB]) < najm){
        najm = abs(k - B[rmbB]);
        najm_index = rmbB;
        ciag = 'B';
    }
    cout << "Wyraz: " << najm_index << " ciagu: " << ciag;
    return 0;
}
