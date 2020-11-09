#include <iostream>
using namespace std;
int binarySEARCH(int tab[],int size,int key)
{
    int low=0;
    int high=size-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(key==tab[mid])return mid;
        if(key>tab[mid])low=mid+1;
        else high=mid-1;
    }
    return -1;
}
int main()
{
    const int n=10;
    // n=12//bo tablica do binary searcha musi byc posortowana//indeksy do 11
    int tab[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key;
    cout<<"Liczba do znalezienia: ";
    cin>>key;
    cout<<"Liczba znajduje sie w szufladce o indeksie: "<<binarySEARCH(tab,n,key);
    return 0;
}
