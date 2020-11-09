//
// Created by Kamil Delekta on 06.12.2019.
//
#include <iostream>
using namespace std;
    struct list{
        list *next;
        char data;
    };
void push_front(list *&head, char v){
    list *p;
    p = new list;
    p -> data = v;
    p -> next = head;
    head = p;
}
void pop_front(list *&head){
    list *p = head;
    if(p){
        head = p -> next;
        delete p;
    }
}

int how_many_nodes(list *p){
    int counter = 0;
    while(p){
        counter++;
        p = p -> next;
    }
    return counter;
}
void print_list(list *p){
    cout << "Number of nodes: " << how_many_nodes(p) << endl;
    for(int i = 1; p; p = p -> next, i++){
        cout << "Element #" << i << " data: " << p -> data << endl;
    }
    cout << endl;
}


int main() {

    list *L = NULL;

    push_front(L, 'A');
    push_front(L, 'B');
    push_front(L, 'C');
    print_list(L);
    pop_front(L);
    pop_front(L);
    print_list(L);

    return 0;
}



