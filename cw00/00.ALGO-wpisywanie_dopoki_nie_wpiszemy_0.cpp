#include <iostream>
using namespace std;
const int N = 100;
int main()
{
    int arr[N];
    for (int i = 0; i < N; i++) {
        //najlepsze rozwiazanie
        cin >> arr[i];
        if (arr[i] == 0) break;
    }
    return 0;
}
