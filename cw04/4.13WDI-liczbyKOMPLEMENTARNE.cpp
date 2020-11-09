//Liczby naturalne a,b s¹ komplementarne je¿eli ich suma jest liczb¹ pierwsz¹. Dana jest tablica typu int t[MAX][MAX]
//wype³niona liczbami naturalnymi. Proszê napisaæ funkcjê, która zeruje elementy nie posiadaj¹ce liczby komplementarnej.
#include <iostream>
#include <math.h>
using namespace std;
const int MAX = 3;
bool komplem[MAX][MAX];
bool liczba_pierwsza(int liczba){
    if(liczba %2 == 0) return false;
    if(liczba %3 == 0) return false;
    if(liczba %5 == 0) return false;
    for(int i = 7; i < sqrt(liczba);i +=2){//bo jak masz pierwsza to pozniej
        if(liczba %i == 0 && liczba != i)return false;
    }
    return true;
}
void zaznacz_komplementarne(int t[MAX][MAX]){
    for(int y=0;y<MAX;y++)
    {
        for(int x = 0 ;x < MAX; x++)
        {
            for(int yy = 0;yy < MAX; yy++)
            {
                for(int xx = 0; xx < MAX; xx++)
                {
                   if(liczba_pierwsza(t[y][x] + t[yy][xx]))
                   {
                        komplem[y][x]=komplem[yy][xx]=true;
                   }
                }
            }
        }
    }
}
void wyzeruj_niekomplementarne(int t[MAX][MAX]){
     zaznacz_komplementarne(t);
     for(int y=0;y<MAX;y++)
    {
        for(int x = 0 ;x < MAX; x++){
            if(!komplem[y][x]){
                t[y][x] = 0;
            }
        }
    }
}
int main()
{
    int t[MAX][MAX] = {{2, 2, 4},{4, 6, 8},{6, 1, 14}};
    for(int i = 0;i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            komplem[i][j]=false;
        }
    }
    wyzeruj_niekomplementarne(t);
    for(int y = 0 ;y < MAX; y++)
        {
            for(int x = 0;x < MAX; x++)
            {
                cout<<t[y][x]<<" ";
            }
            cout<<endl;
        }
    return 0;
}
