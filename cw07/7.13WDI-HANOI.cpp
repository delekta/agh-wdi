//Problem wie¿ w Hanoi (treœæ oczywista)
#include <iostream>
using namespace std;
void hanoi(int n,char source,char aux,char destination, int &MOVE){
    if(n == 1){
            cout << source << " -> " << destination << " | ";
            MOVE++;
    }
    else{
        hanoi(n-1, source, destination, aux, MOVE);
        hanoi(1, source, aux, destination, MOVE);
        hanoi(n-1,aux, source, destination, MOVE);
    }
}
int main()
{
    char a ='A';
    char b ='B';
    char c ='C';
    int MOVE = 0;
    int h;
    cout << "How many disks? ";
    cin >> h;
    hanoi(h,a,b,c,MOVE);
    cout << endl << "How many moves? --> " << MOVE;
    return 0;
}
