//
// Created by Kamil Delekta on 10.01.2020.
//
//Dana jest lista jednokierunkowa zawierajaca liczby calkowite. Liczbe oznaczamy jako niskobitowa, jesli w
//reprezentacji binarnej liczba jedynek jest mniejsza niz 8, sredniobitowa, gdy liczba jedynek pomiedzy 8 a 24,
//wysokobitowa, gdy liczba jedynek przekracza 24. Napisaæ funkcje, ktora podzieli liste na trzy listy z liczbami
//nisko, srednio i wysokobitowymi,a nastepnie z³aczy te listy w jedna
#include <iostream>
using namespace std;
struct node{
    int v;
    node *next;
};
int ile_jedynek(int liczba){
    int counter = 0;
    while(liczba > 0){
        if(liczba %2 == 1) counter++;
        //musi byc /= 2
        liczba /= 2;
    }
    return counter;
}
node *split(node *head){
    if(head == NULL) return head;
    node *first[3];
    node *last[3];
    for(int i = 0; i < 3; i++) last[i] = first[i] = NULL;
    while(head != NULL){
        int jaka = ile_jedynek(head -> v);
        int idx = -1;
        if(jaka < 8) idx = 0;
        //tu musi byc else if
        else if(jaka >= 8 and jaka <= 24) idx = 1;
        else idx = 2;
        //tu musi byc first, bo last zawsze jest na NULLa
        //zawsz ==
        if(first[idx] == NULL){
            first[idx] = last[idx] = head;
            //dziala bez tego, ale jak juz robisz to head = head -> next nad last[idx] -> next = NULL
            //head = head -> next;
            //last[idx] -> next = NULL;
        }
        else{
            last[idx] -> next = head;
            last[idx] = last[idx] -> next;
            //head = head -> next;
            //last[idx] -> next = NULL;
        }
        head = head -> next;
    }
    node *result = NULL;
    for(int i = 2; i >= 0; i--){
        if(first[i] != NULL){
            //musi byc last -> = result;
            last[i] -> next = result;
            result = first[i];
        }
    }
    return result;
}
//---ZESTAW SPRAWDZAJACY---
void call_out_list(node *head){
    while(head != nullptr){
        cout << head -> v << " ";
        head = head -> next;
    }
    cout << endl;
}
void add_node(node *& head, int val){
    node *p = new node;
    p-> v = val;
    p->next = head;
    head = p;
}
void create_list(node *&head){
    char option;
    int val;
    while(true){
        cout <<"Option: \n-a(add)\n-e(exit)" << endl;
        cout << "Enter option: ";
        cin >> option;
        if(option == 'e') break;
        cout << "Enter a value: ";
        cin >> val;
        switch(option){
            case 'a':
                add_node(head, val);
                break;
            default:
                cout << "There is no option -" << option << " !" << endl;
                break;
        }
        call_out_list(head);
    }
}
int main() {
    node *head = NULL;
    //cout << ile_jedynek(65535);
    create_list(head);
    call_out_list(split(head));
    return 0;
}
