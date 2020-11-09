//
// Created by Kamil Delekta on 16.01.2020.
//
//Proszê napisaæ funkcjê, otrzymuj¹c¹ jako parametr wskaŸnik na pierwszy
//element listy o wartoœciach typu int, usuwaj¹c¹ wszystkie elementy, których
//wartoœæ jest mniejsza od wartoœci bezpoœrednio poprzedzaj¹cych je elementów
#include <iostream>
using namespace std;
struct node{
    int v;
    node* next;
};
node* usun(node *&head){
    if(head == NULL) return head;
    node *curr = head;
    while(curr -> next != NULL){
        if(curr -> next -> v < curr -> v){
            node *tmp = curr -> next;
            curr -> next = tmp -> next;
            delete tmp;
        }
        else{
            curr = curr -> next;
        }
    }
    return head;
}
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
int main() {
    node *head = NULL;
    create_list(head);
    call_out_list(usun(head));
    return 0;
}
