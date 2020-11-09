//
// Created by Kamil Delekta on 07.01.2020.
//
//Dwie listy zawieraja niepowtarzajace sie (w obrebie listy) liczby
//naturalne. W pierwszej liscie liczby sa posortowane rosnaco, a w drugiej
//nie. Proszê napisac funkcje usuwajaca z obu list liczby wystepujace w obu
//listach. Do funkcji nalezy przekazac wskazania na obie listy, funkcja
//powinna zwrocic ³aczn¹ liczbe usunietych elementow
#include <iostream>
using namespace std;
struct node{
    int v;
    node *next;
};
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
//najlepiej chyba na tych wartownikach?
int remove_duplicates(node* &headR, node* &headN){
    node* wR = new node; node* wN = new node;
    node *prevR, *prevN, *currR, *currN;
    wR -> next = headR; wN -> next = headN;
    prevR = wR; prevN = wN;
    //currR = headR;
    currN = headN;
    int counter = 0;
    while(currN != NULL){
        //wazne!!!
        //tutaj chyba
        prevR = wR;
        currR = wR -> next;
        //wazne cuurR != NULL, na kolosa najczestrzy blad + wazne w tym while musi byc and
        while(currR != NULL and currR -> v < currN -> v){
            prevR = currR;
            currR = currR -> next;}
        //wazne currR != NULL, bo nie wiesz jak sie zakonczy powyzsza petla while
        //na tejj funkcji sprawdzam ta ciekawa opcje deletowania bez uzywania tmp'a, jesli masz preva
        if (currR != NULL and currR->v == currN->v) {
            counter += 2;
            prevN->next = currN->next;
            delete currN;
            currN = prevN -> next;
            prevR->next = currR->next;
            delete currR;
            //currR = prevR -> next;
        }
        //else, bo jak tam usuniesz n to i tak przchodzisz, wiec zebys dwa razy nie przeszedl
        else{
            prevN = currN;
            currN = currN -> next;
        }
    }
    headR = wR -> next;
    headN = wN -> next;
    delete wR;
    delete wN;
    return counter;
}
int main() {
     node *headR = NULL;
     node *headN = NULL;
     create_list(headR);
     create_list(headN);
     cout << "Liczba usunietych: ";
     cout << remove_duplicates(headR, headN);
     cout << endl;
     call_out_list(headR);
     call_out_list(headN);


    return 0;
}
