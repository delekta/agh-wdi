//Napisaæ program wczytuj¹cy dwie liczby naturalne i odpowiadaj¹cy na pytanie
//czy s¹ one zbudowane z takich samych cyfr, np. 123 i 321, 1255 i 5125, 11000 i 10001
#include <iostream>
using namespace std;
int main()
{
    bool t1[10];
    bool t2[10];
    for(int i = 0; i < 10 ; i ++){
        t1[i] = t2 [i] = false;
    }
    cout << "Podaj dwie liczby: ";
    int liczba1, liczba2;
    cin >> liczba1 >> liczba2;
    while(liczba1 > 0){
        t1[liczba1 % 10] = true;
        liczba1 /= 10;
    }
    while(liczba2 > 0){
        t2[liczba2 % 10] = true;
        liczba2 /= 10;
    }
    bool sa = true;
    for(int k = 0; k < 10; k++){
            if(t1[k] != t2[k]){
                sa = false;
                break;
            }
    }
    if(sa) cout << "Liczby SA zbdowane z tych samych cyfr";
    else cout << "NIE SA zbudowane z tych samych cyfr";
    return 0;
}
