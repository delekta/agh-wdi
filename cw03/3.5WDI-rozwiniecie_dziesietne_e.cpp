//Obliczanie sta³ej e z rozwiniêcia w szereg e=1/0!+1/1!+1/2!+1/3!+... z dok³adnoœci¹ do np. 1000 cyfr dziesi êtnych
#include <iostream>
using namespace std;
int main()
{
    const int N = 1005;//N==1005 bo cyfry na miejscach 1001,1002,... moga miec wplyw na 1000 cyfre np 8|9|9|9|9|9 +1 = 9|1|0|0|0|0
    int suma[N];
    int liczba[N];
    for(int i = 0; i < N; i++)
    {
        suma[i] = liczba[i] = 0;
    }
    liczba[0] = suma[0] = 1;
    for(int i = 1; i < N; i++)
    {
        int reszta = 0;
        for(int k = 0; k < N; k++)
        {
            int tmp = reszta * 10 + liczba[k];
            reszta = tmp % i;
            liczba[k] = tmp / i;// !-->liczba[k]=tmp/i
        }
        int przeniesienie = 0;
        for(int j = N; j >= 0; j--)
        {
           suma[j] = suma[j] + liczba[j] + przeniesienie;
           przeniesienie = suma[j] / 10;
           suma[j] %= 10;
        }
    }
    for(int i = 0; i < 1000; i++)//N=1005 ale wypisujemy 1000
    {
        cout << suma[i];
    }
    return 0;
}
