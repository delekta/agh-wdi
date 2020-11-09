//
// Created by Kamil Delekta on 04.01.2020.
//
//Dwie listy zawieraja niepowtarzajace sie (w obrebie listy) liczby naturalne. W obu listach liczby sa posortowane
//rosnaco. Prosze napisac funkcje usuwajaca z kazdej listy liczby wystepujace w drugiej. Do funkcji
//nalezy przekazac wskazania na obie listy, funkcja powinna zwrocic ³¹czn¹ liste usunietych elementow
#include <iostream>
using namespace std;
struct node{
    int v;
    node *next;
};
//---ZESTAW SPRAWDZAJACY---
void call_out_list(node *head){
    while(head != nullptr){
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
//nie dzia³a gdy duplikat na poczatku 05.01//edit juz dziala 05.01 30min pozniej, komentarze na dole
node* remove_duplicates_kopia(node* head1, node* head2){
    //zabezpieczenie gdy któraœ z list bylaby pusta
    if(head1 == NULL) return head1;
    if(head2 == NULL) return head2;
    //koniczna gwiazdka przed KAZDYM wskaznikiem
    node* curr1,*curr2, *prev1, *prev2;
    node* w1 = new node;
    node* w2 = new node;
    w1 -> next = head1;
    w2 -> next = head2;
    curr1 = head1;
    prev1 = w1;
    curr2 = head2;
    prev2 = w2;
    //zawsze inicjalizuj nowy wskaznik na paczatek listy bo psuje sie przy wypisywaniu
    node* result = NULL;
    node* last_result;
    node* wr = new node;
    last_result = wr;
    int licznik = 0;
    while(curr1 != NULL and curr2 != NULL) {
        if(curr1 -> v < curr2 -> v){
            prev1 = curr1;
            curr1 = curr1 -> next;
        }
        else if(curr2 -> v < curr1 -> v){
            prev2 = curr2;
            curr2 = curr2 -> next;
        }
        else{
            node* tmp = curr1;
            prev1 -> next = curr1 ->next;
            curr1 = tmp -> next;
            last_result -> next = tmp;
            tmp -> next = NULL;
            last_result = last_result -> next;
            tmp = curr2;
            prev2->next = curr2->next;
            curr2 = tmp -> next;
            delete tmp;
            licznik += 2;
        }
    }
    //teraz dziala usuwanie duplikatow z ppoczatku :)
    head1 = w1 -> next;
    head2 = w2 -> next;
    delete w1;
    delete w2;
    //^^^_^^^
    cout << "Wypisz pierwsza liste: ";
    call_out_list(head1);
    cout << "Wypisz druga liste: ";
    call_out_list(head2);
    result = wr -> next;
    delete wr;
    return result;
}
//robocza , jesli chcialbym komus wyslac
node* remove_duplicates_kopia_k(node* head1, node* head2){
    //zabezpieczenie gdy któraœ z list bylaby pusta
    if(head1 == NULL) return head1;
    if(head2 == NULL) return head2;
    node *prev1, *prev2;
    node* w1 = new node; node* w2 = new node;
    w1 -> next = head1; w2 -> next = head2;
    prev1 = w1; prev2 = w2;
    //to bedziemy zwracac
    node* result = NULL;
    node* last_result;
    //wartownik do listy result
    node* wr = new node;
    last_result = wr;
    int licznik = 0;
    while(head1 != NULL and head2 != NULL) {
        if(head1 -> v < head2 -> v){
            prev1 = head1;
            head1 = head1 -> next;
        }
        else if(head2 -> v < head1 -> v){
            prev2 = head2;
            head2 = head2 -> next;
        }
        else{
            node* tmp = head1;
            prev1 -> next = head1 ->next;
            head1 = head1 -> next;
            //dalaczamy do listy wynikowej
            last_result -> next = tmp;
            tmp -> next = NULL;
            last_result = last_result -> next;
            //
            prev2 -> next = head2 -> next;
            delete head2;
            //tu musi byc head2 = prev2 -> next
            head2 = prev2 -> next;
            licznik += 2;
        }
    }
    head1 = w1 -> next; head2 = w2 -> next;
    delete w1; delete w2;
    cout << "Wypisz pierwsza liste: ";
    call_out_list(head1);
    cout << "Wypisz druga liste: ";
    call_out_list(head2);
    result = wr -> next; delete wr;
    return result;
}
int main(){
    //---MUSI---
    //----BYC----
    //-----INICJACJA---
    //------HEAD = NULL---
    node *head1 = NULL;
    node *head2 = NULL;
    cout << "Create first list: ";
    create_list(head1);
    cout << "Create second list: ";
    create_list(head2);
    call_out_list(remove_duplicates_kopia_k(head1, head2));
    cout << "^^^lista duplikatow";
    return 0;
}
