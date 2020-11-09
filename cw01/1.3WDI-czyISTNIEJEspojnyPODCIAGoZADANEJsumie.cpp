//napisac program sprawdzajacy czy istnieje spojny podciag ciagu fibonaciego o zadanej sumie
#include <iostream>

using namespace std;

int main()
{
    int zadana_suma;
    cout<<"Podaj jaka sume sprawdzic: ";
    cin>>zadana_suma;
    int a=1,b=0;
    bool f=true;
    while(a<=zadana_suma)
    {
        a+=b;
        b=a-b;
    }
    a--;//dlaczego?
    int x=1,y=0;
    while(a>=zadana_suma)
    {
        if(a==zadana_suma)
        {
            cout<<"tak istnieje spojny podciag o sumie: "<<zadana_suma;
            f=false;
        }
        a-=x;
        x+=y;
        y=x-y;


    }
    if(f)cout<<"nie istnieje spojny podciag o sumie: "<<zadana_suma;

    return 0;
}
