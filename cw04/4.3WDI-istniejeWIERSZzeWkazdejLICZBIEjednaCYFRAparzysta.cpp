//Dana jest tablica int t[MAX][MAX] wypełniona liczbami naturalnymi.
//Proszę napisać funkcję który odpowiada na pytanie, czy istnieje wiersz w tablicy,
// w którym każda z liczb zawiera przynajmniej jedna cyfrę parzystš.
 #include <iostream>

using namespace std;
const int MAX=5;
bool sameNIEPARZYSTE(int liczba)
{
    int dlg=0;
    int nieparzysta=0;
    while(liczba>0)
    {
        dlg++;
        if(liczba%2!=0)nieparzysta++;
        liczba/=10;
    }
    return dlg==nieparzysta;
}
bool istniejeWIERSZwKAZDEJliczbieCYFRAparzysta(int tablica[MAX][MAX])
{
    for(int y=0;y<MAX;y++)
    {
        bool samePARZYSTEwWIERSZU=true;
        for(int x=0;x<MAX;x++)
        {
            if(sameNIEPARZYSTE(tablica[y][x]))//musisz dac tablice [y][x]!!!
            {
             samePARZYSTEwWIERSZU=false;
            }
        }
        if(samePARZYSTEwWIERSZU)
        {
            return true;
        }
    }
    return false;
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
    int tablica[MAX][MAX]={{5,12,2,14,6},{12,2,5,9,15},{5,649,28,745,62},{27,45,96,12,35},{9,25,16,48,12}};
    wypiszTABLICEdwuwymiarowa(tablica);
    if(istniejeWIERSZwKAZDEJliczbieCYFRAparzysta(tablica))cout<<"Istnieje taki wiersz! ";
    else cout<<"Nie istnieje taki wiersz! ";
    return 0;
}
