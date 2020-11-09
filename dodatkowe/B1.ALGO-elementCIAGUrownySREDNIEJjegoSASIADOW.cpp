//Proszę napisac program, który wczytuje wprowadzony z
//klawiatury ciag liczb naturalnych zakonczonych zerem
//stanowiacym wylacznie znacznik konca danych. Program
//powinien wypisać te elementy ciagu które sš rowne
//sredniej arytmetycznej z 4 najbliższych sšsiadow. Mozna
//załozyc, że w ciagu znajduje się co najmniej 5
//elementow
#include <iostream>
#define MAX 100

using namespace std;

int main()
{
    int S[MAX];
    int i=0;
    cout<<"Wypelnij tablice liczbami(tablica musi miec co najmniej 5 elementow): ";
    do
    {
        cin>>S[i];
        i++;
    }while(S[i-1]!=0);//i-1 bo 0 wpisujemy do i, a pozniej zwiekszamy i (i++)
    if(i>=6)//wted
    {
        cout<<endl;
        for(int j=0;j<i-1;j++)cout<<S[j]<<" ";//w tablicy S[i-1] mamy wpisane zero a nie chcemy go wypisac
        //linijka wyzej sluzy tylko do sprawdzenia czy poprawnie zapisujemy w tablicy
        int k=3;//bo najpierw rozwiazujemy problem gdy liczba z kazdej strony dwoch sasiadow
        cout<<endl<<"Elementy ktore sa rowne sredniej arytmetycznej sasiadow: ";
        while(k<i-3)//bo w S[i-1] mamy zero a chemy zeby ostatnia sprawdzana miala jesczedwie liczby po prawej czyliS[i-2],S[i-3]
        {
            int suma=S[k-2]+S[k-1]+S[k+1]+S[k+2];
            if(suma==S[k]*4)cout<<S[k]<<" ";//S[k]*4==suma bo jesli by bylo suma/4 =s[k] to by liczylo blednie, bo suma jest intem i np 15/4=3 bo zapisuje bez reszty
                                            //albo zmienic sume na typ float
            k++;//zeby petla sie kiedys skonczyla
        }
        int suma0=S[1]+S[2]+S[3]+S[4];
        if(suma0==S[0]*4)cout<<S[0]<<" ";
        int suma1=S[0]+S[2]+S[3]+S[4];
        if(suma1==S[1]*4)cout<<S[1]<<" ";
        int sumaOSTATNI=S[i-6]+S[i-5]+S[i-4]+S[i-3];//bo w S[i-1] mamy zapisane 0
        if(sumaOSTATNI==S[i-2]*4)cout<<S[i-2]<<" ";
        int sumaPRZEDOSTATNI=S[i-6]+S[i-5]+S[i-4]+S[i-2];
        if(sumaPRZEDOSTATNI==S[i-3]*4)cout<<S[i-3]<<" ";
        //jesli wpisze 5 elementow to indeksy 0|1|2|3|4 zero jest w |5| robi jeszcze w petli i++ wiec i=6
        //wtedy sumaOSTATNI=S[0]+S[1]+S[2]+S[3] bo i=6
        cout<<"KONIEC!!!";
    }
    else cout<<endl<<"BLAD - zbyt malo elementow w tablicy!";
    return 0;
}
