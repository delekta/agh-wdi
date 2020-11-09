//
// Created by Kamil Delekta on 09.12.2019.
//
#include <iostream>
using namespace std;
struct node{
    int w;
    node *next;
};
int main() {
   struct node{
        int w;
        node *next;
    };
    int c = 3;
    int *p;
    p = &c;
    //albo int *p = &a jak przypisujesz od razy przy incicjalizacji
    cout << p << "\t<- adres ( p )" << endl;
    cout << *p << "\t\t\t<- wartosc ( *p )"<< endl;
    node *w1;
    w1 = new node;
    w1 -> w = 2;
    node *r;
    r = new node;
    r -> w = 5;
    w1 -> next = r;
    cout << w1 ->next->w << "  wartosc w1 -> next czyli tak naprawde r" << endl;
    cout << w1 ->next << " w1 ->next " << r << " r";//czyli w1 -> next to adres tak samo jak r
    node* kiwa = new node;
    kiwa -> w = 13;
    cout << endl;
    cout << kiwa -> w;
    float l = 4.5;
    cout <<;
    return 0;

}
