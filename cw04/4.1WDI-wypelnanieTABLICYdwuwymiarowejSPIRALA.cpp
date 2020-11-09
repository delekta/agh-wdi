//Dana jest tablica t[MAX][MAX] prosze napisac funkcje wypelniajaca tablice liczbami naturalnymi po spirali
#include <iostream>


using namespace std;
const int MAX=12;

void wypelnijSPIRALA(int tablica[MAX][MAX])
{
    int x=0;
    int y=0;
    int a=1;
    for(x=0;x<MAX;x++)tablica[y][x]=a++;

    for(int i=0;i<MAX/2;i++)
    {
        x--;
        y++;
        for(int k=0;k<MAX-2*i-1;k++,y++)tablica[y][x]=a++;//MUSI BYC 2*i!!!
        y--;
        x--;
        for(int k=0;k<MAX-2*i-1;k++,x--)tablica[y][x]=a++;//MUSI BYC 2*i!!!
        x++;
        y--;
        for(int k=0;k<MAX-2*i-2;k++,y--)tablica[y][x]=a++;//MUSI BYC 2*i!!!
        y++;
        x++;
        for(int k=0;k<MAX-2*i-2;k++,x++)tablica[y][x]=a++;//MUSI BYC 2*i!!!
    }
}

int main()
{
    int tablica[MAX][MAX];
    wypelnijspirala(tablica);
    for(int yy=0;yy<MAX;yy++)//tu wszedzie yy
    {
        for(int xx=0;xx<MAX;xx++)//tu tez wszedzie xx
        {
        cout<<tablica[yy][xx]<<"\t";//pamietaj ze tu wszedzie masz miec [xx][yy]
        }
        cout<<endl;
    }
   return 0;
}
