//
// Created by Kamil Delekta on 10.12.2019.
//
//Zastosowania listy do implementacji tablicy rzadkiej. Proszê napisaæ trzy funkcje:
// - void init(node *&tab) – inicjalizuj¹c¹ tablicê,
// - int value(node *tab, int n) – zwracaj¹c¹ wartoœæ elementu o indeksie n,
// - void set(node *&tab, int n, int value) – postawiaj¹c¹ wartoœæ value pod indeks n.
#include <iostream>
using namespace std;
struct node{
    int v;
    int n;
    node *next;
};
void init(node *&tab){
    tab = NULL;
}
int value(node *&tab, int n){
    node *curr = tab;
    while(curr){
        if(curr -> n == n){
            return curr -> v;
        }
    }
    //zwracamy gdy nie znajdziemy elementu
    return -1;
}
void set(node *&tab, int n, int value){
    node *curr = tab;
    while(curr){
        if(curr -> n == n){
            curr -> v = value;
            return;
        }
        curr = curr -> next;
    }
    //inicjalizuje nowa zmienna o indeksie n i dodaje na poczatek
    node *nevv = new node;
    nevv -> v = value;
    nevv -> n = n;
    nevv -> next = tab;
    tab = nevv;
}
void call_out_list(node *head){
    int i = 1;
    while(head){
        cout << i << "# " "val: " << head -> v << " idx: "<< head -> n << " " << endl;;
        head = head -> next;
        i++;
    }
}
int main() {
    node *head;
    init(head);
    char option;
    int val;
    //debugger
    while(true){
        cout <<"Option: \n-v(value)\n-s(set)\n-e(exit)" << endl;
        cout << "Enter option: ";
        cin >> option;
        if(option == 'e') break;
        switch(option){
            case 'v':
                int n;
                cout << "Enter index: ";
                cin >> n;
                cout << value(head, n) << endl;
                break;
            case 's':
                int val;
                cout << "Enter value:";
                cin >> val;
                int idx;
                cout << "Enter index: ";
                cin >> idx;
                set(head, idx, val);
                break;
            default:
                cout << "There is no option -" << option << " !" << endl;
                break;
        }
        call_out_list(head);
    }
    return 0;
}
