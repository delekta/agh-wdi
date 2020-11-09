//Dana jest liczba naturalna o niepowtarzaj¹cych siê cyfrach poœród których nie ma zera.
//Ile ró¿nych liczb podzielnych np. przez 7 mo¿na otrzymaæ   poprzez wykreœlenie dowolnych
//cyfr w tej liczbie. Np. dla 2315 bêd¹ to 21, 35, 231, 315
#include <iostream>
using namespace std;
void ile_podzielnych(int liczba, int &l ,int dziel){
    if(liczba > 0 && dziel <= liczba){
        int lewa = liczba / (dziel * 10);
        lewa *= dziel;
        int prawa = liczba % dziel;
        int nowa = lewa + prawa;
        if(nowa % 7 == 0) l++;
        ile_podzielnych(liczba, l, dziel * 10);
        ile_podzielnych(nowa, l, dziel);
    }
}
int main()
{
    int liczba;
    //nie zapomnij przypisac licznikowi wartosci poczatkowej!
    int l = 0;
    cout << "Podaj liczbe: ";
    cin >> liczba;
    ile_podzielnych(liczba, l, 1);
    cout << l - 1;
    return 0;

}
