#include <iostream>

using namespace std;
const int N = 3;
void sortowanie_zlinearyzowanej(int t[N][N]) {//czy int t[][], int N ? //void ?
    bool posortowana;
    do {
        posortowana = true;
        for (int i = 0; i < N * N - 1; i++) {
                int j = i+1;
            if (t[i / N][i % N] > t[j / N][j % N]) {
                posortowana = false;
                int x = t[i / N][i % N];
                t[i / N][i % N] = t[j / N][j % N];
                t[j/ N][j % N] = x;
            }
        }
    }while(posortowana != true);
}
int main()
{
    int tab[N][N] = {{3, 56, 4}, {6, 8, 12}, {1, 24, 9}};
    sortowanie_zlinearyzowanej(tab);
    for(int y = 0; y < N; y++){
        for(int x = 0; x < N; x++){
            cout << tab[y][x] << " ";
        }
    }
    return 0;
}
