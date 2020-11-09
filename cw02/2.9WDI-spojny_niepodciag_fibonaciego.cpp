//Pewnych liczb nie mo¿na przedstawiæ jako sumy elementow spojnych fragmentow ci¹gu Fibonacciego,
//np. 9,14,15,17,22.Proszê napisac program, który wczytuje liczbe naturalna n, wylicza i
//wypisuje nastepna tak¹ liczbe wieksza od n. Mo¿na zalozyc, ze 0<n<1000
#include <iostream>
using namespace std;
bool jest_spojnym_podciagiem(int n){
    int a = 1;
    int b = 0;
    int sum = 0;
    while(sum < n){
        sum += a;
        a += b;
        b = a - b;
    }
    if(sum == n) return true;
    a = 1;
    b = 0;
    while(sum > n){
        sum -= a;
        a += b;
        b = a -b;
    }
    if(sum == n) return true;
    return false;
}
int main()
{   int n;
    cin >> n;
    while(jest_spojnym_podciagiem(++n));
    cout << n;
    return 0;
}
