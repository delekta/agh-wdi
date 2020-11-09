//Napisaæ program wypisuj¹cy wszystkie mo¿liwe podzia³y liczby naturalnej na sumê sk³adników.
//Na przyk³ad dla liczby 4 s¹ to:  1+3, 1+1+2, 1+1+1+1, 2+2
#include <iostream>
#include <string>
using namespace std;
int how_many_digits(int number){
    int counter = 0;
    if(number == 0) return 1;
    while( number > 0){
        number /= 10;
        counter++;
    }
    return counter;
}
//components is needed not to cout div(11) = 11
void div(int number, string s = "" , int last = 1, int components = 0){
    if(number == 0) {
        if(components > 1) cout << s << endl;
        else return;
    }
    for(int i = last; i <= number; i++){
        div(number - i, s + to_string(i) +" ", i, components + 1);
    }
}
int main()
{
    int n = 6;
    div(n);
    return 0;
}
