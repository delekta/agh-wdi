#include <iostream>

using namespace std;
void hanoi(int n,char source,char aux,char destination){
    if(n == 1)cout << source << destination << " ";
    else{
        hanoi(n-1, source, destination, aux);
        cout << source << destination << " ";
        hanoi(n-1,aux, source, destination);
    }
}
int main()
{
    char a ='A';
    char b ='B';
    char c ='C';
    hanoi(4,a,b,c);
    return 0;
}
