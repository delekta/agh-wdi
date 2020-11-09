//Napisaæ program, który oblicza pole figury pod wykresem funkcji y=1/x w przedziale od 1 do k, metod¹ prostok¹tów
#include <iostream>
#include <iomanip>//potrzebne do set precision
using namespace std;
const double E = 1e-2;
double f(double s){
    return 1/s;
}
double pole_pod_wykresem(double k, double E){
    float pole = 0;
    double tmp1 = 1;//zmienna z warunku przed petla!!!
    do{
        double tmp2 = min(tmp1 + E, k);
        double s = (tmp1 + tmp2) / 2;
        pole += (tmp2 - tmp1) * f(s);
        tmp1 += E;
    }while(tmp1 < k);
    return pole;
}
int main()
{
    cout << "Podaj k: ";
    float k;
    cin >> k;
    cout << setprecision(1000) << pole_pod_wykresem(k, E);
    return 0;
}
