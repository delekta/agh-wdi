#include <iostream>//DOBRZE

using namespace std;

void nwd(int a, int b)
{
    while(a!=b)
    {
        if(a>b)a-=b;
        else b-=a;
    }
    cout<<a;
}

int main()
{
    int a,b;
    cout<<"Podaj liczby do znalezienia dzielnika: ";
    cin>>a>>b;
    cout<<"NWD tych liczb: ";
    nwd(a,b);
    return 0;
}
