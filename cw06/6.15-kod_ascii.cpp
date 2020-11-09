//
// Created by Kamil Delekta on 11.01.2020.
//
//Wyrazy budowane s� z liter a..z. Dwa wyrazy �wa��� tyle samo je�eli: maj� t� sam�
//liczb� samog�osek oraz sumy kod�w ascii liter z kt�rych s� zbudowane s� identyczne,
//na przyk�ad �ula� -> 117 108 97 oraz   �exe� 101 120 101. Prosz� napisa� funkcj�
//bool wyraz( string s1, string s2), kt�ra sprawdza czy jest mo�liwe zbudowanie
//wyrazu z podzbioru liter zawartych w s2 wa��cego tyle co wyraz s1.
//Dodatkowo funkcja powinna wypisa� znaleziony wyraz
#include <iostream>
using namespace std;
const string samo = "aeyuio";//samogloski
bool the_same_weight(string s1, string s2) {
    int sum1 = 0;
    int sum2 = 0;
    int licznik1 = 0;
    int licznik2 = 0;
    for (int i = 0; i < s1.length(); i++) {
        sum1 += s1[i];
        for (int j = 0; j < samo.length(); j++) {
            if (s1[i] == samo[j]) {
                licznik1++;
                break;
            }
        }
    }
    for (int i = 0; i < s2.length(); i++) {
        sum2 += s2[i];
        for (int j = 0; j < samo.length(); j++){
            if (s2[i] == samo[j]) {
                licznik2++;
                break;
            }
        }
    }
    return sum1 == sum2 and licznik1 == licznik2;
}
bool wyraz(string s1, string s2, string podzbior = "", int i = 0){
    if(the_same_weight(s1, podzbior)){
            cout << s1 << " " << podzbior << endl;
            return true;
    }
    if(i == s2.length()) return false;
    //tu musi byc + s2[i], a nie += s2[i]
    return wyraz(s1, s2, podzbior + s2[i], i + 1) || wyraz(s1, s2, podzbior, i + 1);
}
int main(){
    string s1 = "pari";
    string s2 = "ulanikurwy";
    //cout << wyraz(s1, s2);
    //cout << the_same_weight(ula, exe);
    int p = 0;
    p += s1[0];
    cout << p;
    return 0;
}
