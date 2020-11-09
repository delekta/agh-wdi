#include <iostream>
using namespace std;
string zamiana_ulamka_na_sys2(double ulamek, int ile){
    string odp = "0.";
    while( ulamek > 0 && ile > 0){
        ulamek *= 2;
        if(ulamek >= 1){
            odp += "1";
            ulamek -= 1;
        }
        else{
            odp += "0";
        }
      ile--;
    }
    return odp;
}
int main(){
    cout << "Wpisz ulamek [zakres(0,1)]: ";
    double ulamek;
    cin >> ulamek;
    cout << "Ile miejsc po przecinku?";
    int ile;
    cin >> ile;
    if(ulamek < 1){
        cout << zamiana_ulamka_na_sys2(ulamek, ile);
    }
    else cout <<"To nie jest ulamek!";
    return 0;
}
