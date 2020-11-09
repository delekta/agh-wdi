//
// Created by Kamil Delekta on 05.01.2020.
//
//Dane sa trzy listyjednokierunkowe uporzadkowane rosnaco bez powtarzajacych sie
//liczb. Prosze napisac funkcje ktora usunie w kazdej liscie elementy powtarzajace sie
//w trzech listach. Funkcja ma zwrocic liczbe usunietych elementow
#include <iostream>
using namespace std;
struct node{
    int v;
    node* next;
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
void remove_duplicates(node* head1, node* head2, node* head3, int &counter){
    if(head1 == NULL or head2 == NULL or head3 == NULL) return;
    node *curr1, *curr2, *curr3, *prev1, *prev2, * prev3;

    node *w1 = new node;
    node *w2 = new node;
    node *w3 = new node;

    w1 -> next = head1;
    w2 -> next = head2;
    w3 -> next = head3;

    curr1 = head1;
    curr2 = head2;
    curr3 = head3;

    prev1 = w1;
    prev2 = w2;
    prev3 = w3;

    while(curr1 != NULL and curr2 != NULL and curr3 != NULL){
        if (curr1->v < curr2->v and curr1->v < curr3->v) {
            prev1 = curr1;
            curr1 = curr1->next;
        } else if (curr2->v < curr1->v and curr2->v < curr3->v) {
            prev2 = curr2;
            curr2 = curr2->next;
        } else if (curr3->v < curr2->v and curr3->v < curr1->v) {
            prev3 = curr3;
            curr3 = curr3->next;
            //bo dwa moga byc sobie rowne i to wtedy wszytsko psuje, bo usuwamy niepotrzebny element
        }
        else if(curr1 -> v == curr2 -> v and curr2 -> v == curr3 -> v) {
            prev1 -> next = curr1 -> next;
            //bo to nie usuwa wskaznika tylko zwalnia pamiec
            delete curr1;
            curr1 = prev1 -> next;
            prev2 -> next = curr2 -> next;
            delete curr2;
            curr2 = prev2 -> next;
            prev3 -> next = curr3 -> next;
            delete curr3;
            curr3 = prev3 -> next;
            counter += 3;
        }
        else if(curr3 -> v == curr1 -> v){
            prev1 = curr1;
            curr1 = curr1->next;
            prev3 = curr3;
            curr3 = curr3->next;
        }
        else if(curr2 -> v == curr1 -> v) {
            prev1 = curr1;
            curr1 = curr1->next;
            prev2 = curr2;
            curr2 = curr2->next;
        }
        else if(curr3 -> v == curr2 -> v){
            prev3 = curr3;
            curr3 = curr3->next;
            prev2 = curr2;
            curr2 = curr2->next;
        }
        //czemu z elsem nie dziala
    }
    head1 = w1 -> next;
    delete w1;
    head2 = w2 -> next;
    delete w2;
    head3 = w3 -> next;
    delete w3;
    cout << "First list: ";
    call_out_list(head1);
    cout << "Second list: ";
    call_out_list(head2);
    cout << "Third list: ";
    call_out_list(head3);

}
int remove_duplicates_aux(node* head1, node* head2, node* head3){
    int counter = 0;
    remove_duplicates(head1, head2, head3, counter);
    return counter;
}
//funkcja piotrka
/*int delete(node *&l1, node *&l2, node *&l3){
if(l1 == NULL or l2 == NULL or l3 == NULL)
return 0;
int ilosc = 0;
node * wart1 = new node; wart1->next = l1;
node * wart2 = new node; wart2->next = l2;
node * wart3 = new node; wart3->next = l3;
node * p1 = wart1; node * q1 = l1;
node * p2 = wart2; node * q2 = l2;
node * p3 = wart3; node * q3 = l3;
while(q1 != NULL) {
int x = q1->value;
while(q2 != NULL and q2->value < x){
p2 = q2;
q2 = q2->next;
}
if(q2->value == x) {
while(q3 != NULL and q3->value < x) {
p3 = q3;
q3 = q3->next;
}
if(q3->value == x) {
ilosc+=3;
p1->next = q1->next; delete q1; q1 = p1->next;
p2->next = q2->next; delete q2; q2 = p2->next;
p3->next = q3->next; delete q3; q3 = p3->next;
} else {
p1 = q1;
q1 = q1->next;
}
} else {
p1 = q1;
q1 = q1->next;
}
}
l1 = wart1->next;
l2 = wart2->next;
l3 = wart3->next;
delete wart1, wart2, wart3;
return ilosc;
}*/
int main() {
    node *head1 = NULL;
    node *head2 = NULL;
    node *head3 = NULL;
    cout << "Create first list: ";
    create_list(head1);
    cout << "Create second list: ";
    create_list(head2);
    cout << "Create third list: ";
    create_list(head3);
    cout << remove_duplicates_aux(head1, head2, head3) << " usunietych elementow.";
    return 0;
}
