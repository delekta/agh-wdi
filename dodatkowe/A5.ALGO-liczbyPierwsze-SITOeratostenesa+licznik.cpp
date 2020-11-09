#include <iostream>//faktoryzacja-proces,który dla danego x znajduje obiekty, ktorych iloczyn jest równy x
//kryptografia-metody przeobrażania jawnej formy wiadomości w ukrytą
using namespace std;
void SITO(int N)
{
    bool S[N+1];
    int w;
    int licznik=0;
    for(int i=2;i<N+1;i++)S[i]=1;//wyTRUCIE;1=true
    for(int i=2;i<N+1;i++)
        if(S[i])
    {
        w=i*i;
        while(w<N+1)
        {
            S[w]=false;
            w+=i;
        }
    }
    for(int i=2;i<N+1;i++)
        if(S[i])
        {
            cout<<i<<" ";
            licznik++;
        }
        cout<<endl<<"Liczb pierwszych do "<<N<<" jest: "<<licznik;
}

int main()
{
    int n;
    cout<<"DO jakiej liczb wypisać liczby pierwsze: ";
    cin>>n;
    SITO(n);//sito wypisujące liczby pierwsze do n
    return 0;
}
