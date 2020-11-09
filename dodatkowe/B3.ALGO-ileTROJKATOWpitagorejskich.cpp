#include <iostream>

using namespace std;
int trojkat(int a,int b, int c)
{
    int counter=0;
    for(int i=1;i<=c;i++)
        for(int j=1;j<=b;j++)
            for(int k=1;k<=a;k++)
                {
                        if(k*k +j*j==i*i)
                            counter++;
                }
                return counter;
}
int main()
{
  cout<<trojkat(14,15,17);
  return 0;
}
