#include <iostream>

using namespace std;

int main()
{
    long int liczba1,liczba2,RMBliczba1,RMBliczba2;
    cout<<"Podaj dwie liczby, a sprawdze czy sš rozno-cyfrowe w systemach liczbowych 2-16: ";
    cin>>liczba1>>liczba2;
    RMBliczba1=liczba1;
    RMBliczba2=liczba2;
    bool tab1[16];
    bool tab2[16];
    int pierwszROZNOCYFROWA=0;
    for(int i=2;i<=16;i++)
    {
        liczba1=RMBliczba1;
        liczba2=RMBliczba2;
        for(int i=0;i<16;i++)tab1[i]=tab2[i]=0;
        while(liczba1>0)
        {
            tab1[liczba1%i]=1;
            liczba1/=i;
        }
        while(liczba2>0)
        {
            tab2[liczba2%i]=1;
            liczba2/=i;
        }
        int j=0;
        for( j=0;j<i&&tab1[j]==tab2[j];j++);
        if(j==i)cout<<"Nie sa rozno-cyfrowe dla podstawy "<<i<<endl;
        else
        {
            cout<<"Sa rozno-cyfrowe dla podstawy "<<i<<endl;
            if(pierwszROZNOCYFROWA==0)pierwszROZNOCYFROWA=i;
        }


    }
    if(pierwszROZNOCYFROWA!=0)cout<<"Najmniejsza podstawowa dla ktorej liczba jest roznocyfrowa jest "<<pierwszROZNOCYFROWA;
    else cout<<"Liczby nie sa roznocyfrowe w zadnym systemie liczbowym";

    return 0;
}
