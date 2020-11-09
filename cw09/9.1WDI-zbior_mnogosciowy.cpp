//
// Created by Kamil Delekta on 10.12.2019.
//
//Zaimplementuj zbiór mnogoœciowy liczb naturalnych korzystaj¹c ze struktury listy.
// - czy element nale¿y do zbioru
// - dodanie elementu do zbioru
// - usuniêcie elementu ze zbioru
//zakladam ze naturalne od 1
#include <iostream>
using namespace std;
struct node{
        int val;
        node *next;
};
bool belong(node *head, int val){
    while(head){
        if(head -> val == val) return true;
        head = head -> next;
    }
    return false;
}
void add_node(node *& head, int val){
    if(!belong(head, val)) {
        node *p = new node;
            p->val = val;
            p->next = head;
            head = p;
    }
    else{
        cout << "The list already contain that element" << endl;
        return;
    }
}
void remove_node(node *&head, int val){
    //jesli lista pusta
    if(belong(head, val)) {
        //if (head == NULL) return; niepotrzbne bo juz wczesniej sprawdzamy czy element nalezy
        node *p = head;
        node *prev = NULL;
        while (p != NULL and p->val != val) {
            prev = p;
            p = p->next;
        }
        //if (p == NULL) return; niepotrzebne bo juz wczesniej sprawdzamy czy element nalezy
        //zabezpieczamy sie w systuacji gdy usuwamy pierwszy element, wtedy prev = NULL
        if (prev != NULL) {
            prev->next = p->next;
            delete p;
            return;
        }
            //usuwamy pierwszy
        else {
            node *tmp = head;
            head = head -> next;
            delete tmp;
            return;
        }
    }
    else{
        cout << "The list doesnt contain that element" << endl;
    }
}
void call_out_list(node *head){
    while(head){
        cout << head -> val << " ";
        head = head -> next;
    }
    cout << endl;
}
int main() {
    node *head = NULL;
    char option;
    int val;
    while(true){
        cout <<"Option: \n-a(add)\n-r(remove)\n-e(exit)" << endl;
        cout << "Enter option: ";
        cin >> option;
        if(option == 'e') break;
        cout << "Enter a value: ";
        cin >> val;
        switch(option){
            case 'a':
                add_node(head, val);
                break;
            case 'r':
                remove_node(head, val);
                break;
            default:
                cout << "There is no option -" << option << " !" << endl;
                break;
        }
        call_out_list(head);
    }
    return 0;
}
