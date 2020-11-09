//
// Created by Kamil Delekta on 09.01.2020.
//
//Zbi�r liczb naturalnych jest reprezentowany jako jednokierunkowa lista. Y-lista to strukturareprezentuj�ca dwa zbiory liczb naturalnych (rysunek).
//Prosz� napisa� funkcj�, kt�ra dwa zbiory A,B reprezentowane jako Y-lista przekszta�ca w dwazbiory reprezentowane jako niezale�ne listy.
//Do funkcji nale�y przekaza� wska�niki do dw�chlist, funkcja powinna zwr�ci� liczb� element�w cz�ci wsp�lnej zbior�w A,B
#include <iostream>
using namespace std;
struct node{
    int v;
    node *next;
};
//na poczatku zle zrozumialem
int intersection(node *&headA, node *&headB){
    node *currA = headA;
    node *currB = headB;
    //potrzebny bedzie prev do B, bo wlasnie B bedziemy odlaczac od A a while sie zatrzym jak beda na tym samym;
    node *prevB = NULL;
    //w warunku nie poruwnujesz ich wartosci, a adresy
    while(currA == currB){
        if(currA == NULL) currA = headB;
        if(currB == NULL) currB = headA;
        prevB = currB;
        currB = currB -> next;
        currA = currA -> next;
    }
    //cofam tym B
    currB = prevB;
    int length = 0;
    //teraz currA nie zmieniasz, tylko do currB towrzysz kopie nodow z czesci wspolnej
    while(currA != NULL){
        node *added = new node;
        added -> v = currA -> v;
        added -> next = NULL;
        currB -> next = added;
        currB = currB -> next;
        currA = currA -> next;
        length++;
    }
    return length;
}
int main() {

    return 0;
}
