//
// Created by Kamil Delekta on 30.11.2019.
//
//Dane s¹ trzy operacje na liczbach naturalnych oznaczone literami A, B i C.
//A. je¿eli liczba posiada co najmniej 2 cyfry zamienia miejscami dwie ostatnie cyfry w liczbie
//B. mno¿y liczbê przez 3
//C. je¿eli liczba posiada co najmniej 2 cyfry usuwa pierwsz¹ cyfrê z liczby
//Proszê napisaæ funkcjê, która szuka sekwencji operacji przekszta³caj¹cej liczbê naturaln¹ x na y
//(x!=y) o d³ugoœci nie wiêkszej ni¿ 7. Do funkcji nale¿y przekazaæ liczby x, y.
//Funkcja powinna zwróciæ napis z³o¿ony z liter ABC realizuj¹cy przekszta³cenie albo ³añcuch pusty
//je¿eli przekszta³cenie nie istnieje. Na przyk³ad dla liczb 6,3 funkcja powinna zwróciæ napis "BACB"
#include <iostream>
using namespace std;
int how_many_digits(int number){
    int digits = 0;
    if(number == 0) return 1;
    while(number > 0){
        digits++;
        number  /= 10;
    }
    return digits;
}
int poww(int number, int base){
    int result = 1;
    for(int i = 1; i <= base; i++){
        result *= number;
    }
    return result;
}
int funA(int number){
    // j * 10 zeby zamienic miejscami z d
    int j = (number % 10) * 10;
    int d = number % 100 / 10;
    number /= 100;
    number *= 100;
    return number + j  + d ;
}
int funB(int number){
    return 3 * number;
}
int funC(int number){
    int digits_of_number = how_many_digits(number);
    return number % poww(10, digits_of_number - 1);
}
void sequance(int x, int y, string s = ""){
    if (s.length() > 7) {
        return;
    }
    if(x == y){
        cout <<  s << endl;
    }
    else {
        if (how_many_digits(x) >= 2) {
            sequance(funA(x), y, s + "A");
            sequance(funC(x), y, s + "C");
        }
        sequance(funB(x), y, s + "B");
    }
}
int main(){
    int x, y;
    cout << "Enter two numbers: ";
    cout << endl;
    cout << "x :";
    cin >> x;
    cout << "y :";
    cin >> y;
    sequance(x, y);
    return 0;
}
