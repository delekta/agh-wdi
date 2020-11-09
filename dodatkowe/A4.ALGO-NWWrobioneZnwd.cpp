#include <iostream>

using namespace std;

int nww()
{
  long int a,b,t,ab;
  cout<<"Podaj dwie liczby do policznie NWW: ";
  cin >> a >> b;
  ab = a * b;
  while(b)
  {
    t = b;
    b = a % b;
    a = t;
  }
  ab /= a;
  cout <<"NWW tych liczb: ";
  return ab;
}


int main()
{

  cout<<nww();//jak jest funkcja int(nieVOID) to dajesz returna+couta przy wypisywaniu;

  return 0;
}
