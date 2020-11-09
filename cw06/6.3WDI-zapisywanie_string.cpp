//
// Created by Kamil Delekta on 21.11.2019.
//
//Dany jest zestaw odwa¿ników int t[N]. Napisaæ funkcjê, ktora wypisuje odwzniki potrzebne do
//odwazenia pewnej masy, odwazniki mo¿na umieszczac na obu szalkach,
#include <iostream>
using namespace std;
//uzycie stringa najlepsza opcja, bo kazdy napis jest innt dla innej instancji
void write_out(int weight[], int N, int mass, int p, string tasma){
    if(p == N){
        if(mass == 0) {
            cout << "Left: ";
            for (int i = 0; i < N; i++) {
                if (tasma[i] == 'L') {
                    cout << weight[i] << " ";
                }
            }
            cout<< endl << "Right: ";
            for (int i = 0; i < N; i++) {
                if (tasma[i] == 'R') {
                    cout << weight[i] << " ";
                }
            }
            cout << "\n\n\n\n";
        }
    }
    //musi byc ten else, bo jesli by go nie bylo to wychodzimy poza tablice odwaznikow, poniewaz nie ma tu wyzej zadnego returna ktory konczylby to
    else {
    //odwaznika nie kladziemy na zadnej szalce
    write_out(weight, N, mass, p + 1, tasma + '0');
    //na lewej szalce
    write_out(weight, N , mass - weight[p], p + 1, tasma + 'L');
    //na prawej szalce
    write_out(weight, N , mass + weight[p], p + 1, tasma + 'R');
    }

}
int main(){
    const int N = 6;
    int weight[N] = {1, 2, 3, 5, 10, 15,};
    int mass;
    cin >> mass;
    string tasma;
    write_out(weight, N, mass, 0, tasma);
    return 0;
}
