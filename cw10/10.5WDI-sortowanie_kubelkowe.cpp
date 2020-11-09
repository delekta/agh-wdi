//
// Created by Kamil Delekta on 24.12.2019.
//
#include <iostream>
using namespace std;
struct node{
    int val;
    node *next;
};
node *split(node *head){
    node *first[10];
    node *last[10];
    for(int i = 0 ; i < 10; i++) first[i] = NULL;
    while(head != NULL){
        int idx = head -> val % 10;
        if(first[idx] == NULL) first[idx] = last[idx] = head;
        else{
            last[idx] -> next = head;
            last[idx] = last[idx] -> next;
        }
        head = head -> next;
    }
    node *result;
    for(int i = 9; i >= 0; i--){
        if(first[i] != NULL){
            last[i] -> next = result;
            result = first[i];
        }
    }
    return result;
}
//zestaw sprawdzajacy
void call_out_list(node *head){
    while(head != NULL){
        cout << head -> val << " ";
        head = head -> next;
    }
    cout << endl;
}
void add_node(node *& head, int val){
        node *p = new node;
        p-> val = val;
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
    node* head;
    create_list(head);
    call_out_list(split(head));
    return 0;
}
