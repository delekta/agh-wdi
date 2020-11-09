//
// Created by Kamil Delekta on 24.12.2019.
//
//Proszê napisaæ funkcjê scalaj¹c¹ dwie posortowane listy w jedn¹ posortowan¹ listê.
// Do funkcji nale¿y przekazaæ wskazania na pierwsze elementy obu list, funkcja powinna zwróciæ wskazanie do scalonej listy.
// - funkcja rekurencyjna.
#include <iostream>
using namespace std;
struct node{
    int v;
    node *next;
};
//---ZESTAW SPRAWDZAJACY---
void call_out_list(node *head){
    while(head != NULL){
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

//jednak dziala 13.01.2020
node *merge(node *l1, node *l2){
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    if(l1 -> v < l2 -> v){
        l1 -> next= merge(l1 -> next, l2);
        return l1;
    }
    else{
        l2 -> next = merge(l1, l2 -> next);
        return l2;
    }
}
int main() {
    node *l1 = NULL;
    node *l2 = NULL;
    cout << "Create first increasing list: ";
    create_list(l1);
    cout << "Create second increasing list: ";
    create_list(l2);
    call_out_list(merge(l1, l2));
    return 0;
}
