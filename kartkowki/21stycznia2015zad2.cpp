//
// Created by Kamil Delekta on 14.01.2020.
//
//Ka¿dy ³añcuchz zawiera niepowtarzaj¹ce siê liczby naturalne. W obu ³añcuchach liczby s¹ posortowane rosn¹co.
//Proszê napisaæ funkcjê usuwaj¹c¹ z ka¿dego ³añcuchaliczby nie wystêpuj¹ce w drugim.Do funkcji nale¿y przekazaæ
//wskazania na oba ³añcuchy, funkcja powinna zwróciæ ³¹czn¹ liczbê usuniêtych elementów.
#include <iostream>
using namespace std;
struct node{
    int w;
    node *next;
};
//---ZESTAW SPRAWDZAJACY---
//dziala dobrze
void call_out_list(node *head){
    while(head != NULL){
        cout << head -> w << " ";
        head = head -> next;
    }
    cout << endl;
}
void add_node(node *& head, int val){
    node *p = new node;
    p-> w = val;
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

int remove_different(node *&head1, node *&head2){
    node* w1 = new node; node * w2 = new node;
    w1 -> next = head1; w2 -> next = head2;
    node* prev1 = w1; node *prev2 = w2;
    int licznik = 0;
    while(head1 != NULL and head2 != NULL){
        if(head1 -> w == head2 -> w){
            prev1 = head1; head1 = head1 -> next;
            prev2 = head2; head2 = head2 -> next;
        }
        else if( head1 -> w < head2 -> w){
            prev1 -> next = head1 -> next;
            delete head1;
            head1 = prev1 -> next;
            licznik++;
        }
        else{//wykonuje jeslii head2 -> w < head1 -> w
            prev2 -> next = head2 -> next;
            delete head2;
            head2 = prev2 -> next;
            licznik++;
        }
    }
    //wyglada ze musza byc jako znak konca list bo zrobimy delete to i tak konca nie dostaniemy jakos  magicznie
    prev1 -> next = NULL;
    prev2 -> next = NULL;
    while(head1 != NULL){
        node* tmp = head1;
        head1 = head1 -> next;
        delete tmp;
        licznik++;
    }
    while(head2 != NULL){
        node* tmp = head2;
        head2 = head2 -> next;
        delete tmp;
        licznik++;
    }
    head1 = w1 -> next; head2 = w2 -> next;
    delete w1; delete w2;
    return licznik;
}
int main() {
    node* head1 = NULL;
    node* head2 = NULL;
    cout << "Create first increasing list: ";
    create_list(head1);
    cout << "Create second increasing list: ";
    create_list(head2);
    cout << remove_different(head1, head2) << " <- liczba usunietych" << endl;
    call_out_list(head1);
    call_out_list(head2);
    return 0;
}
