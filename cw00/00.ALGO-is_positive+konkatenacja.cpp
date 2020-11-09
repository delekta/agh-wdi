#include <iostream>

using namespace std;
bool is_positive(int a)
{
    return a>0;
}
string napis;

int main()
{ int liczba;
  cin>>liczba;
  if(is_positive(liczba))napis="jest";
  else napis="nie jest";
  cout<<"Liczba "+napis+" dodatnia: ";
    return 0;
}
