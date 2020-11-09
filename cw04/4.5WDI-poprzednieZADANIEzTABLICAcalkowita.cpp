//Dana jest tablica int t[MAX][MAX] wype³niona liczbami calkowitymi.
//Proszê napisaæ funkcjê która zwraca wiersz i kolumnê dowolnego elementu,
//dla którego iloraz sumy elementów w kolumnie w którym le¿y element
//do sumy elementów wiersza w którym le¿y element jest najwiêksza.
#include <iostream>
#define MAX 5
using namespace std;
void najwiekszyILORAZ(int tablica[MAX][MAX],int &w,int &k)//pamietaj ze int &w musi byc int przed!
{
    double ilorazNAJWIEKSZY;//tez double
    bool pierwszy=true;
    for(int y=0;y<MAX;y++)
    {
        for(int x=0;x<MAX;x++)
        {
            int sumaKOLUMNY=0;
            int sumaWIERSZA=0;
            for(int xx=0;xx<MAX;xx++)
            {
                sumaWIERSZA+=tablica[y][xx];
            }
            for(int yy=0;yy<MAX;yy++)
            {
                sumaKOLUMNY+=tablica[yy][x];
            }
            double ilorazTYMCZASOWY=(double)sumaKOLUMNY/(double)sumaWIERSZA;
            //sprawdzam czy wszystko dziala!
            //cout<<"IlorazNAJWIEKSZY: "<<ilorazNAJWIEKSZY<<" ilorazTYMCZASOWY: "<<ilorazTYMCZASOWY<<" sumaKOLUMNY: "<<sumaKOLUMNY<<" sumaWIERSZA: "<<sumaWIERSZA<<endl;
            if(pierwszy||ilorazTYMCZASOWY>ilorazNAJWIEKSZY)
            {
                ilorazNAJWIEKSZY=ilorazTYMCZASOWY;
                pierwszy=false;
                k=x;
                w=y;
            }

        }
    }

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
    int tablica[MAX][MAX]={{200,7,8,9,26},{12,35,9,14,34},{-54,5,6,254,78},{1,-18,1,8,1},{78,98,11,1,14}};
    int wiersz,kolumna;
    wypiszTABLICEdwuwymiarowa(tablica);
    najwiekszyILORAZ(tablica,wiersz,kolumna);
    cout<<"Najwiekszy iloraz sumy elementow w kolumnie do sumy elementow w wierszu dla kolumny: "<<kolumna<<" i wiersza: "<<wiersz;
    return 0;
}
