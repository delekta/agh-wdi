//Dana jest tablica int t[MAX][MAX] wype³niona liczbami naturalnymi.
//Proszê napisaæ funkcjê który odpowiada na pytanie, czy w ka¿dym wierszu tablicy wystêpuje
//co najmniej jedna liczba z³o¿ona wy³¹cznie z nieparzystych cyfr.
 #include <iostream>

using namespace std;
const int MAX=5;
bool sameNIEPARZYSTE(int liczba)
{
    int dlg=0;
    int nieparzyste=0;
    while(liczba>0)
    {
        dlg++;
        if(liczba%2!=0)nieparzyste++;
        liczba/=10;
    }
    return dlg==nieparzyste;//tutaj porownujesz czyli ==
}
bool czyKAZDYwierszTABLICYmaJEDNAzlozanaZnieparzystychCYFR(int tablica[MAX][MAX])
{
    for(int y=0;y<MAX;y++)
    {
        bool znaleziona=false;
        for(int x=0;x<MAX;x++)
            if(sameNIEPARZYSTE(tablica[y][x]))//jak uzywasz funkcji to bez int przed wszystkim
            {
                znaleziona=true;
            }
            if(!znaleziona)
            {
                return false;
                break;
            }
    }
    return true;
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
    int tablica[MAX][MAX]={{52,7,8,729,26},{12,35,629,14,534},{54,5,946,254,78},{7,8,1283,48,7589},{78,98,11,161,14}};
    wypiszTABLICEdwuwymiarowa(tablica);
    if(czyKAZDYwierszTABLICYmaJEDNAzlozanaZnieparzystychCYFR(tablica))cout<<"W kazdym wierszu tablicy wystepuje co najmniej jedna liczba zlozona wylacznie z nieparzystych";
    else cout<<"Nie w kazdym wierszu tablicy wystepuje co najmniej jedna liczba zlozona wylacznie z nieparzystych";
    return 0;
}
