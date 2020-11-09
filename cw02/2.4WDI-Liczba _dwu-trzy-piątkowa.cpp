//made by kamildelekta
//Liczba dwu-trzy-piątkowa w rozkładzie na czynniki pierwsze nie posiada innych czynników
//niż 2,3,5. Jedynka też jest taką liczbą.  Napisz program, który wylicza ile takich liczb
//znajduje się w przedziale od 1 do N włącznie
#include <iostream>
using namespace std;
int ile_jest_liczb235(int n)
{
    int licznik=0;
    for(int i2=1;i2<=n;i2*=2)
        for(int i3=i2;i3<=n;i3*=3)
            for(int i5=i3;i5<=n;i5*=5)licznik++;
    return licznik;
}
int main()
{
    int n;
    cout<<"W jakim przedziale policzyc ile jest liczb dwu-trzy-piatkowych: ";
    cin>>n;
    cout<<ile_jest_liczb235(n);
    return 0;
}

