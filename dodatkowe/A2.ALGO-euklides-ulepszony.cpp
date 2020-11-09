#include <iostream>

using namespace std;
void nwd(int a, int b)
{
    int t;
    do
    {
        t=b;
        b=a%b;
        a=t;
    }while(b!=0);
    cout<<a;//mozesz dac cout<<t albo cout<<a, to nic nie zmienia!

}

int main()
{
    int a,b;
    cout<<"Z jakich liczb policzyc ci NWD: ";
    cin>>a>>b;
    cout<<"NWD tych liczb to: ";
    nwd(a,b);

    return 0;
}
