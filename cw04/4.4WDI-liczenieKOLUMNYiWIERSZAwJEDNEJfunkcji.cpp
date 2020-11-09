//Dana jest tablica int t[MAX][MAX] wype³niona liczbami naturalnymi.
//Proszê napisaæ funkcjê która zwraca wiersz i kolumnê dowolnego elementu,
//dla którego iloraz sumy elementów w kolumnie w którym le¿y element
//do sumy elementów wiersza w którym le¿y element jest najwiêksza
//__________WERSJA Z JEDNA FUNKCJA__________
#include <iostream>
#define N 5
using namespace std;

void najwiekszyILORAZ(int tablica [N][N],int &w,int &k)//przekazanie wartosci przez referencje
{
    //int indexW=0;//NIEPOTRZEBNE BO ZAPISUJEMY I TAK PRZEZ REFERENCJE!!!
    //int indexK=0;
    int sumaK=0;
    int sumaW=INT_MAX;//zeby pierwsza suma wiersza byla napewno mnniejsza
                     //przypisujemy wartosc najwieksza mozliwa ktora moze przechowac int
    for(int i=0;i<N;i++)
    {
        int aktualnasumaWIERSZA=0;
        int aktualnasumaKOLUMNY=0;
        for(int j=0;j<N;j++)
        {
            aktualnasumaKOLUMNY+=tablica[j][i];
            aktualnasumaWIERSZA+=tablica[i][j];
        }
        if(aktualnasumaKOLUMNY>sumaK)
        {
            sumaK=aktualnasumaKOLUMNY;
            k=i;
        }
        if(aktualnasumaWIERSZA<sumaW)
        {
            sumaW=aktualnasumaWIERSZA;
            w=i;
        }
     }
}
void wypiszTABLICEdwuwymiarowa(int tablica[N][N])//jak deklarujesz to piszesz int tablica[N][N]
{
    for(int y=0;y<N;y++)
    {
        for(int x=0;x<N;x++)
        {
            cout<<tablica[y][x]<<"\t";
        }
        cout<<endl;
    }
}
int main()
{
    int wiersz,kolumna;
    int tablica[N][N]={{52,783,8,729,26},{12,3485,629,14,534},{54,5,6,254,78},{53,8,123,48,7},{78,98,11,161,14}};
    wypiszTABLICEdwuwymiarowa(tablica);
    najwiekszyILORAZ(tablica,wiersz,kolumna);
    cout<<"Najwiekszy iloraz dla kolumny: "<<kolumna<<" i wiersza: "<<wiersz;
    return 0;
}
