 #include <iostream>
 #include <cmath>
using namespace std;
const double E = 0.0001;
int n;
double wartosc_wielomianu(double x, double A[], int n){
    //x = argument dla ktorego liczymy wartosc
    //n = najwiekszy wspolczynnik przy x
    //A[] = tablica wszystkich wspolczynnikow
    if(n == 0)return A[0];//funkcja stala
    return x * wartosc_wielomianu(x, A, n-1) + A[n];
    //x przed nawias, stopien wielomianu zmniejszam, na koncu zostaje wspolczynnik an
}
double pole_pod_wykresem(double p, double k,int n, double A[],double E){
    double suma = 0;
    double tmp1 = p;
    //to co jest w warunku do_while musi byc zaimplementowane przed petla
    do{
        double tmp2 = min(tmp1 + E, k);
        double s = (tmp1 + tmp2) / 2;
        suma += abs(wartosc_wielomianu(s, A, n) * (tmp2 - tmp1));
        //mogloby byc * E, ale to jest dokladniejsze w sytuacji gdy tmp2 min = k
        //jak podajesz wartosci do funkcji to juz bez int'ow itp
        tmp1 += E;
   } while(tmp1 <= k);
    return suma;
}
int main()
{
    double a[] = {2, -3, -1};//2x^2 - 3x -1 w tabeli kolejne wspolczynniki przy czym a[0], to wspolczynnik przy najwyzszej potedze
    n = sizeof(a) / sizeof(double);
    cout << wartosc_wielomianu(0, a, n-1) << endl;//wartosc dla x = 0,"n-1" bo jesli n = 3,to potega przy najwyzszym wspolczynniki = n-1
    cout << wartosc_wielomianu(3, a, n-1) << endl;
    cout << string(60, '-') << endl;//wupisz 60 razy znak ' - '
    cout << pole_pod_wykresem(2, 4, n-1, a, E);
    cout << endl << string(60, '-') << endl;
    double b[] = {1, 0};//wzor y = x;
    n = sizeof(b) / sizeof(double);
    cout << pole_pod_wykresem(0, 10, n-1, b, E);//sprawdzamy czy wzor funkcja dziala
    return 0;
}
