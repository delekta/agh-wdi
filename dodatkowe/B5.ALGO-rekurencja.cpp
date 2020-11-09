#include <iostream>

using namespace std;
void zamien_system_liczbowy(int liczba,int podstawa)
{
    if(podstawa == 1)return;
    if(liczba==0)return;
    //cout<<liczba%podstawa;//jesli tak zostawimy to wypisuje od tylu
    zamien_system_liczbowy(liczba/podstawa,podstawa);
    cout<<liczba%podstawa;//teraz wypisze dobrze

}
void SWAP(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}
void rewers(int p,int k, int arr[])
{
    if(p>k) return;
    SWAP(arr[p],arr[k]);
    return rewers(++p,--k,arr);//srednik po funkcji
}
int binarySearch(int arr[],int x,int p,int k)
{
    if(k>p)
    {
        int s=(k+p)/2;
        if(x==arr[s])return s;
        if(x>arr[s])return binarySearch(arr,x,s+1,k);
        if(x<arr[s])return binarySearch(arr,x,p,s-1);
    }
    return -1;
}
int main()
{
    int liczba;
    int system;
    int k=8;
    int arr[k]={1,2,3,4,5,6,7,8};
    cout<<"Podaj liczbe i system na jaki ja zamienic: ";
    cin>>liczba>>system;
    zamien_system_liczbowy(liczba,system);
    rewers(0,k-1,arr);//k-1 <--WAZNE
    for(int i=0;i<k;i++)cout<<" "<<arr[i];
    cout<<endl;
    cout<<"Jakiej liczby szukasz w tablicy: ";
    int szukana;
    cin>>szukana;
    rewers(0,k-1,arr);//rewers jeszcze raz bo do binary search'a potrzebujesz posortowanej rosnaca;
    if(binarySearch(arr,szukana,0,k-1)!=-1)cout<<"Ta liczba znajduje sie w szufladce o indeksie: "<<binarySearch(arr,szukana,0,k-1);
    else cout<<"Nie ma tej liczby w tablicy :(";
    return 0;
}
