//Prosz� napisa� program, kt�ry wczytuje wprowadzany z
//klawiatury ci�g liczb naturalnych zako�czonych zerem
//stanowi�cym wy��cznie znacznik ko�ca danych. Program
//powinien wypisa� 10 co do wielko�ci warto��, jaka
//wyst�pi�a w ci�gu. Mo�na za�o�y�, �e w ci�gu znajduje si�
//wystarczaj�ca liczba element�w
#include <iostream>

using namespace std;
int swapp(int *a,int *b)//tu musza byc '*'
{
        int schowek=*a;//
        *a=*b;//
        *b=schowek;//

}

int main()
{
    const int MAX=100;
    int tab[MAX];
    bool f;
    int i=-1;//zeby i++ mogl byc przed cin>>tab[i]
    cout<<"Wypelnij tablice conajmniej 10 elementami: ";
    do
    {
        i++;
        cout<<"( "<<i+1<<" element )";
        cin>>tab[i];
    }while(tab[i]!=0);
    cout<<"Elementy tablicy przed posortowaniem: ";
    for(int j=0;j<i;j++)cout<<tab[j]<<" ";
    if(i>=10)//w ostatniej szufladce jest 0 a bez niej ma byc 10 elementow
    {
        do
        {
            f=true;
            for(int k=0;k<i-1;k++)
            {
                if(tab[k]>tab[k+1])//ten if musi obejmowac f;
                {
                //cout<<"Xd";<--sprawdzacz
                swapp(&tab[k],&tab[k+1]);//przekazujemy przez referencje!
                f=false;
                }
            }

        }while(f!=true);
        cout<<endl<<"Juz posortowana 10: ";
        for(int j=0;j<10;j++)cout<<tab[j]<<" ";

    }
    else cout<<endl<<"Blad - za malo elementow w tablicy!";
    return 0;
}
