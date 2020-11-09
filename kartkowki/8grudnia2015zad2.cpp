//
// Created by Kamil Delekta on 10.01.2020.
//
// Dana jest tablica  t[N][N](reprezentujaca szachownice) wypelniona liczbami calkowitymi -9 ...9. Prosze napisac funkcje, ktora
//ustawia na szachownicy dwie wieze, tak aby suma liczb na szachowanych polach by³a najwieksza. Do funkcji nalezy przekazac tablice,
//funkcja powinna zwrocic polozenie wiez.
#include <iostream>
using namespace std;
const int N = 6;
struct poz{
    int y1;
    int y2;
    int x1;
    int x2;
};
//dziala
int sum_of_checked(int sumX[N], int sumY[N], int t[N][N], int y1, int x1, int y2, int x2){
    //if(y1 == y2 and x2 == x1) return INT_MIN;
    if(y1 != y2 and x1 != x2) return sumX[x1] + sumX[x2] + sumY[y1] + sumY[y2] - 2 * t[y1][x1] - 2 * t[y2][x2] - t[y1][x2] - t[y2][x1];
    else return sumX[x1] + sumX[x2] + sumY[y1] + sumY[y2] - 3 * t[y1][x1] - 3 * t[y2][x2];
}
void sumXY(int sumX[N], int sumY[N], int t[N][N]){
    for(int y = 0; y < N; y++){
        for(int x = 0; x < N; x++){
            //sumY[y], a sumX[x] a nie sumY[N]
            sumY[y] += t[y][x];
            sumX[x] += t[y][x];
        }
    }
}
poz best_poz(int t[N][N], int sum_max, int sumX[N], int sumY[N]){
    int curr_sum;
    poz best_poz{};
    for(int y1 = 0; y1 < N; y1++){
        for(int x1 = 0; x1 < N; x1++){
            for(int y2 = 0; y2 < N; y2++){
                for(int x2 = 0; x2 < N; x2++){
                    if(y1 == y2 and x1 == x2) continue;
                    curr_sum = sum_of_checked(sumX, sumY, t, y1, x1, y2, x2);
                    if(curr_sum > sum_max){
                        sum_max = curr_sum;
                        best_poz.y1 = y1;
                        best_poz.y2 = y2;
                        best_poz.x1 = x1;
                        best_poz.x2 = x2;
                    }
                }
            }
        }
    }
    return best_poz;
}
poz best_poz_aux(int t[N][N]){
    int sumY[N];
    int sumX[N];
    for(int i = 0; i < N; i++) sumX[i] = sumY[i] = 0;
    sumXY(sumX, sumY, t);
    int sum_max = INT_MIN;
    return best_poz(t, sum_max, sumX, sumY);
}
void wypisz_tablice(int t[N][N]){
    for(int y = 0; y < N; y++){
        for(int x = 0; x < N; x++){
            cout << t[y][x] << " ";
        }
        cout << endl;
    }
}
int main() {
    int t[N][N] = {
            {8, -3, 6, 2, -1, 5},
            {80, 10, 6, 2, -1, -75},
            {8, 3, 6, -2, -1, 5},
            {8, -3, 3, 2, 56, 5},
            {-38, -3, 6, 2, -1, 5},
            {8, -3, 664, 2, -1, 5},
    };
    wypisz_tablice(t);
    poz best_poz = best_poz_aux(t);
    cout << "Y1: " << best_poz.y1 << " X1: " << best_poz.x1 << endl;
    cout << "Y2: " << best_poz.y2 << " X2: " << best_poz.x2;
    return 0;
}
