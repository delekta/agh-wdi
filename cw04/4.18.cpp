//
// Created by Kamil Delekta on 12.01.2020.
//
//Dana jest tablica typu int t[MAX][MAX] wype�niona liczbami ca�kowitymi. Prosz�
//napisa� funkcj�, kt�ra wyszuka sp�jny podci�g element�w le��cy poziomo lub
//pionowo o najwi�kszej sumie. Maksymalna d�ugo�� podci�gu mo�e wynosi� 10
//element�w.Do funkcji nale�y przekaza� tablic� typu tab, funkcja powinna zwr�ci�
//sum� maksymalnego podci�gu
#include <iostream>
using namespace std;
const int N = 8;
int sumfromtorow(int i, int p, int k, int t[N][N]){
    int sum = 0;
    for(int z = p; z < k; z++){
        sum += t[i][z];
    }
    return sum;
}
int sumfromtocol(int i, int p, int k, int t[N][N]){
    int sum = 0;
    for(int z = p; z < k; z++){
        sum += t[z][i];
    }
    return sum;
}
int max_sum(int t[N][N]){
    int max_sum = INT_MIN;
    int curr_sum_row;
    int curr_sum_col;
    for(int i = 0; i < N; i++){
        //bo p maks powinno byc n-2
        for(int p = 0; p < N; p++){
            //bo k max powinno byc n ,bo liczymy do mniejszego od k
            for(int k = p + 1; k < N + 1; k++){
                curr_sum_row = 0;
                curr_sum_col = 0;
                if((k - p) > 10) break;
                curr_sum_row = sumfromtorow(i, p, k, t);
                curr_sum_col = sumfromtocol(i, p, k, t);
                if(curr_sum_row > max_sum){
                    max_sum = curr_sum_row;
                }
                if(curr_sum_col > max_sum){
                    max_sum = curr_sum_col;
                }

            }
        }
    }
    return max_sum;
}
int main(){
    int t[N][N] = {
            {-7, 4, 5, 50, 6, 9, -7, 3},
            {-7, -4, 5, -9, 6, 9, -7, 3},
            {-7, -4, 5, -9, 6, 9, -7, 3},
            {-7, -4, 5, -9, 6, -30, -7, 3},
            {-7, -4, 5, -9, 6, 9, -7, 3},
            {-7, -4, 5, -9, 6, 9, -7, 3},
            {-7, -4, 5, -9, 6, 7, -7, 3},
            {-7, -4, 5, -9, 6, 7, -7, 3}
    };
    cout << max_sum(t);
    return 0;
}
