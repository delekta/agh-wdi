//
// Created by Kamil Delekta on 15.12.2019.
//
#include <iostream>
struct node{
    int v;
    node *next;
};
using namespace std;
//tablica przez referencje wiec wypisywanie modyfikuje listy
void call_out_lists(node *head[10]){
    for(int i = 0; i < 10 ; i++){
        cout << "Ostatnia cyfra" << i << " : ";
        node *tmp = head[i];
        while(tmp != NULL){
            cout << tmp -> v << " ";
            tmp = tmp -> next;
        }
        cout << endl;
    }
}
void call_out_list(node *head){
    while(head != NULL){
        cout << head -> v << " ";
        head = head -> next;
    }
    cout << endl;
}
void init(node *head_list[10]){
    for(int i = 0; i < 10 ; i++){
        head_list[i] = NULL;
    }
}
void split(node *head,node *head_list[10]){
    while(head != NULL){
        int idx = head -> v % 10;
        node *added = new node;
        added -> v = head -> v;
        added -> next = head_list[idx];
        head_list[idx] = added;
        head = head -> next;
    }
}
void split2(node *&head,node *head_list[10]){
    while(head != NULL){
        int idx = head -> v % 10;
        node *tmp = head -> next;
        head -> next = head_list[idx];
        head_list[idx] = head;
        head = tmp;
    }
}
void merge(node *head_list[],node *&new_list){
    for(int i = 9; i >= 0 ; i--){
        while(head_list[i] != NULL){
            node *tmp = head_list[i] -> next;
            head_list[i] -> next = new_list;
            new_list = head_list[i];
            head_list[i] = tmp;
        }
    }
}
bool belong(node *head, int val){
    while(head){
        if(head -> v == val) return true;
        head = head -> next;
    }
    return false;
}
void add_node(node *& head, int val){
    if(!belong(head, val)) {
        node *p = new node;
        p-> v = val;
        p->next = head;
        head = p;
    }
    else{
        cout << "The list already contain that element" << endl;
        return;
    }
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
    //wskaazniki na head`y 10 nowych list
    node *head_list[10];
    init(head_list);
    create_list(head);
    split2(head,head_list);
    call_out_lists(head_list);
    node *new_list = NULL;
    merge(head_list,new_list);
    call_out_list(new_list);
    return 0;
}
