#include <iostream>//DOBRZE

using namespace std;

void nwd()
{
    int a,b;
    cout<<"Podaj liczby do znalezienia dzielnika: ";
    cin>>a>>b;
    while(a!=b)
    {
        if(a>b)a-=b;
        else b-=a;
    }
    cout<<"NWD tych liczb: ";
    cout<<a;
}

int main()
{
    nwd();
    return 0;
}