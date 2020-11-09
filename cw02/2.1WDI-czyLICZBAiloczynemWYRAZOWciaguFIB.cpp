//Napisz program wczytuj¹cy liczbê naturaln¹ z klawiatury i odpowiadaj¹cy na pytanie,
//czy liczba ta jest iloczynem dowolnych dwóch wyrazów ci¹gu Fibonacciego.
#include <iostream>
bool czy_liczba_jest_elementem_ciagu_fibonacciego(int liczba)
{
    int a=1;
    int b=0;
    while(a<=liczba)
    {
        if(liczba==a)return true;
        a=a+b;//trzeba wykonywac te petle po if'ie sprawdzajacym
        b=a-b;
    }
    return false;
}
bool iloczyn_dwoch_wyrazow_fibonacciego(int liczba)
{
    int a=1;
    int b=0;
    while(a*a<liczba)//mozna ten "a<sqrt(liczba)
    {
        if(liczba%a==0)
        {
        if(czy_liczba_jest_elementem_ciagu_fibonacciego(liczba/a))return true;//do tej funkcji musisz przekazac "liczba/2"
        }
        a=a+b;//trzeba to robic po if'ie
        b=a-b;
    }
    return false;

}

using namespace std;

int main()
{
    int liczba;
    cout<<"PODAJ LICZBE,SPRAWDZE CZY JEST ILOCZYNEM DOWOLNYCH DWOCH WYRAZOW CIAGU FIBONACCIEGO: ";
    cin>>liczba;
    if(iloczyn_dwoch_wyrazow_fibonacciego(liczba))cout<<"----JEST----";
    else cout<<"----NIE JEST----";
    return 0;
}
