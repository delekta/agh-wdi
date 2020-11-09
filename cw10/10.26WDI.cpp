//
// Created by Kamil Delekta on 11.01.2020.
//
//Dane  s¹  dwie  niepuste  listy,  z  których  ka¿da  zawiera  niepowtarzaj¹ce
//siê  elementy.  Elementy  w  pierwszej  liœcie  s¹  uporz¹dkowane  rosn¹co,  w
//drugiej  elementy  wystêpuj¹  w  przypadkowej  kolejnoœci.  Proszê  napisaæ
//funkcjê,  która  z  dwóch  takich  list  stworzy  jedn¹,  w  której  uporz¹dkowane
//elementy bêd¹ stanowiæ sumê mnogoœciow¹ elementów z list wejœciowych.
//Do  funkcji  nale¿y  przekazaæ  wskazania  na  obie  listy,  funkcja  powinna
//zwróciæ wskazanie na listê  wynikow¹. Na przyk³ad dla list:
// 2 -> 3 -> 5 ->7-> 11
// 8 -> 2 -> 7 -> 4
// powinna pozostaæ lista:
// 2 -> 3 -> 4 -> 5 ->7-> 8 -> 11
#include <iostream>
struct node{
    int v;
    node *next;
};
using namespace std;
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
//
node* zbior_mnogosciowy(node *head1, node *head2){
    node *w1 = new node;
    //node *w2 = new node;
    //curr chyba niepotrebne
    //prev2 chyba niepotrzebuje
    //bo wszystko dodaje do head1
    node *prev1;
    //prevy kluczowe do dodawania elementow
    w1 -> next = head1;
    //w2 chyba niepor=trzebny
    //w2 -> next = head2;
    prev1 = w1;
    //moge dzialac na headach bo wartownik trzyma poczatek
    while(head2 != NULL){
        head1 = w1 -> next;
        //musi byc ten warunek head1 != NULL
        while(head1 != NULL and head1 -> v < head2 -> v){
            prev1 = head1;
            head1 = head1 -> next;
        }
        //wykorzystanie tmp zeby nie pisac dwa razy
        node *tmp = head2 -> next;
        if(head1 != NULL) {
            if (head1->v != head2->v) {
                //gubisz head2 "head2 -> next = head1;" stara wersja
                //pamietaj zeby nie zgubic listy z ktorej wyciagasz elementy
                head2 -> next = head1;
                prev1 -> next = head2;
                //zwroc uwage ze tu robisz head2 = head2 -> next z tmp i na koncu po wszytskim robisz to samo
            }
        }
        //dodawanie na koniec head1
        else{
            prev1 -> next = head2;
            //tez liste head2;
            head2 -> next = head1;
        }
        //w obu ifach sie przydaje
        head2 = tmp;
    }
    node *result = w1 -> next;
    delete w1;
    //delete w2;
    return result;
}
//kopia bz komentarzy
node* zbior_mnogosciowy_kopia(node *head1, node *head2){
    node *w1 = new node;
    node *prev1;
    w1 -> next = head1;
    prev1 = w1;
    while(head2 != NULL){
        head1 = w1 -> next;
        while(head1 != NULL and head1 -> v < head2 -> v){
            prev1 = head1;
            head1 = head1 -> next;
        }
        node *tmp = head2 -> next;
        if(head1 != NULL) {
            if (head1->v != head2->v) {
                head2 -> next = head1;
                prev1 -> next = head2;
            }
        }
        else{
            prev1 -> next = head2;
            head2 -> next = head1;
        }
        head2 = tmp;
    }
    node *result = w1 -> next;
    delete w1;
    return result;
}
int main() {
    node *head1 = NULL;
    node *head2 = NULL;
    cout << "Stworz pierwsza rosnaca liste: ";
    create_list(head1);
    cout << "Stworz druga dowolna liste: ";
    create_list(head2);
    call_out_list(zbior_mnogosciowy_kopia(head1, head2));
    return 0;
}
