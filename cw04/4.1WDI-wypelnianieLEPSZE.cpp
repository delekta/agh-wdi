#include <iostream>
#define MAX 15
using namespace std;
void wypelnijSPIRALA(int tab[MAX][MAX])
{
    int n=1;;
    // !int p=0;//zamiast wykrzyknikow petla for
    // !int k=MAX-1;//zamiast wykrzyknikow petla for
    // !while(p<k)//zamiast wykrzyknikow petla for
    int p,k;
    for(p=0,k=MAX-1;p<=k;p++,k--)
    {
        for(int i=p;i<k;i++)tab[p][i]=n++;//bo k=MAX-1
        for(int i=p;i<k;i++)tab[i][k]=n++;//bo k=MAX-1
        for(int i=k;i>p;i--)tab[k][i]=n++;
        for(int i=k;i>p;i--)tab[i][p]=n++;
    }
   if(MAX%2!=0)tab[MAX/2][MAX/2]=n++;//pojedyncze "=" pamietaj
  //if(MAX%2!=0)
}
void wypiszTABLICEdwuwymiarowa(int tablica[MAX][MAX])//jak deklarujesz to piszesz int tablica[MAX][MAX]
{
    for(int y=0;y<MAX;y++)
    {
        for(int x=0;x<MAX;x++)
        {
            cout<<tablica[y][x]<<"\t";
        }
        cout<<endl;
    }
}
int main()
{
    int tablica[MAX][MAX];
    wypelnijSPIRALA(tablica);
    wypiszTABLICEdwuwymiarowa(tablica);

    return 0;
}
