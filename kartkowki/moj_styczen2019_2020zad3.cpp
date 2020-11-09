//
// Created by Kamil Delekta on 16.01.2020.
//
#include <iostream>
using namespace std;
struct node{
    int v;
    node *next;
};
//troche przkombinowane, ale dziala
int remove(node *&head){
    if(head == NULL) return 0;
    node *w = new node;
    w -> next = head;
    int max_dlg1 = 0;
    int max_dlg2 = 0;
    node *prev = w;
    node *pocz_akt;
    node *pocz_max;
    node *koniec_max;
    while(head -> next != NULL){
        if(head -> v == head -> next -> v){
            int dlg = 1;
            pocz_akt = prev;
            //mialem head != NULL
            while(head -> next != NULL and head -> v == head -> next -> v){
                dlg++;
                head = head -> next;
            }
            if(dlg > max_dlg1){
                max_dlg1 = dlg;
                pocz_max = pocz_akt;
                //mialem head
                koniec_max = head -> next;
            }
            else if(dlg > max_dlg2){
                max_dlg2 = dlg;
            }
        }
        if(head == NULL or head -> next == NULL) break;
        else {
            prev = head;
            head = head->next;
        }

    }
    if(max_dlg1 != max_dlg2){
        node *tmp = pocz_max -> next;
        pocz_max -> next = koniec_max;
        delete tmp;

    }
    else{
        max_dlg1 = 0;
    }
    head = w -> next;
    delete w;
    return max_dlg1;
}
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
int main(){
    node *head = NULL;
    create_list(head);\
    cout << "Ile usunietych: ";
    cout << remove(head) << endl;
    call_out_list(head);
    return 0;
}
