//Napisa� program wczytuj�cy trzy liczby naturalne a,b,n i wypisuj�cy rozwini�cie dziesi�tne u�amka a/b
//z dok�adno�ci� do n miejsc po kropce dziesi�tnej. (n jest rz�du 100
#include <iostream>
using namespace std;
void wypisz_rozwiniecie_dziesietne(int a,int b,int n){
    cout << a / b <<".";//najpierw wypisujesz czesc calkowita
    while(n > 0){
        a %= b;
        a *= 10;
        cout << a / b;
        n--;
    }
}
int main()
{
    int a, b, n;
    cout << "Wpisz dwie liczby: ";
    cout << "a: "; cin >> a;
    cout << "b: "; cin >> b;
    cout << "Ile liczb po przcinku: "; cin >> n;
    wypisz_rozwiniecie_dziesietne(a, b, n);
    return 0;
}
