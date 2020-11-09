//Napisaæ program wczytuj¹cy trzy liczby naturalne a,b,n i wypisuj¹cy rozwiniêcie dziesiêtne u³amka a/b
//z dok³adnoœci¹ do n miejsc po kropce dziesiêtnej. (n jest rzêdu 100
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
