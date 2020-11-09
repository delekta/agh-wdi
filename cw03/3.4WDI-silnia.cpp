//Napisaæ program obliczaj¹cy i wypisuj¹cy wartoœæ N! dla N z zakresu od 1 do 1000
#include <iostream>
using namespace std;
int main()
{
    const int MAX = 3000;
    int tab[MAX];
    int n;
    cout<< "Enter the number: ";
    cin >> n;
    int len = 1;
    for(int i = 0; i < 3000; i++)tab[i] = 0;
    tab[0] = 1;
    for(int i = 2; i <= n; i++){
        int przeniesienie = 0;
        for(int j = 0; j < len; j++){
            tab[j] = tab[j] * i + przeniesienie;
            //tab[len - 1] --> czyli jesli poprzedni jest juz przepelniony
            if(tab[len - 1] > 9)len++;
            przeniesienie = tab[j] / 10;
            tab[j] %= 10;
        }
    }
    cout << n << "! = ";
    for(int i = len - 1; i >= 0; i--){
        cout << tab[i];
    }
    return 0;
}
