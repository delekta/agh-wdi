#include <iostream>//normalnie wypisuje --5-- miejsc po przecinku
                   //z setprecision wypisuje --62-- cyfry po przecinku
#include <iomanip>//potrzebne do setprecision
using namespace std;

int main()
{

    long double suma,kolejny_wyraz;
    suma=kolejny_wyraz=1;
    const int N=1000;
    int dokladnosc=0;
    for(int i=2;i<=N;i++)
    {
        suma+=kolejny_wyraz;
        kolejny_wyraz/=i;
    }
    cout<<setprecision(1000)<<"e= "<<suma;//setprecision->zwieksza dokladnosc wypisywanej liczby
    return 0;
}
