#include <iostream>
using namespace std;
int nwd(int a, int b){
    if(b == 0) return a;
    nwd(b , a % b);
}
int main()
{
    int liczba1, liczba2;
    cout << "Podaj dwie liczby: ";
    cin >> liczba1 >> liczba2;
    cout << "Ich nwd : " << nwd(liczba1, liczba2);
    return 0;
}
