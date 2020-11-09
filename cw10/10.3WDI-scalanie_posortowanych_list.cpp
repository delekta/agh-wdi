//
// Created by Kamil Delekta on 14.12.2019.
//
//Proszê napisaæ funkcjê scalaj¹c¹ dwie posortowane listy w jedn¹ posortowan¹ listê.
// Do funkcji nale¿y przekazaæ wskazania na pierwsze elementy obu list, funkcja powinna zwróciæ wskazanie do scalonej listy.
// - funkcja iteracyjna,
// - funkcja rekurencyjna.
#include <iostream>
using namespace std;
struct node{
    int v;
    node* next = NULL;
};
void call_out_list(node *head){
    while(head){
        cout << head -> v << " ";
        head = head -> next;
    }
    cout << endl;
}
void reverse_list(node *&head){
    if(head == NULL){
        cout << "lista pusta";
        return;
    }
    node *curr = head;
    node *tmp;
    while(curr -> next){
        tmp = curr -> next;
        curr -> next = tmp -> next;
        tmp -> next = head;
        head = tmp;
    }
}
void add(node *&list3, node *&list){
    node *added = new node;
    added -> v = list -> v;
    added -> next = list3;
    list3 = added;
    //przechodze tym elemenetem dalej
    list = list -> next;
}
//bez tworzenia kopii
void add2(node *&list3, node *&list){
    node *tmp = list -> next;
    list -> next = list3;
    list3 = list;
    list = tmp;
    //przechodze tym elemenetem dalej
}
//scalanie iteracyjne
node* mergeI(node *list1,node *list2){
    node *list3 = NULL;
    while(list1 != NULL and list2 != NULL){
        if(list1 -> v < list2 -> v) {
            add2(list3, list1);
        }
        else {
            add2(list3, list2);
        }
    }
    if(list1 != NULL){
        while(list1 != NULL){
        add2(list3, list1);
        }
    }
    else{
        while(list2 != NULL){
        add2(list3, list2);
        }
    }
    reverse_list(list3);
    return list3;
}
//scalanie rekurencyjne
//nie dziala do konca dobrze
void mergeR(node *list1,node *list2, node *&list3){
    if(list1 == NULL and list2 == NULL){
        reverse_list(list3);
        return;
    }
    else {
        if ((list1 != NULL) and (list2 != NULL)) {
            if (list1->v < list2->v) {
                add(list3, list1);
                mergeR(list1, list2, list3);
            }
            else {
                add(list3, list2);
                mergeR(list1, list2, list3);
            }
        }
        else {
            if (list1 != NULL) {
                add(list3, list1);
                mergeR(list1, list2, list3);
            }
            if(list2 != NULL){
                add(list3, list2);
                mergeR(list1, list2, list3);
            }
        }
    }
}
node *mergeR_aux(node *list1, node *list2){
    node *list3 = NULL;
    mergeR(list1, list2, list3);
    return list3;
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
void remove_node(node *&head, int val){
    //jesli lista pusta
    if(belong(head, val)) {
        //if (head == NULL) return; niepotrzbne bo juz wczesniej sprawdzamy czy element nalezy
        node *p = head;
        node *prev = NULL;
        while (p != NULL and p-> v != val) {
            prev = p;
            p = p->next;
        }
        //if (p == NULL) return; niepotrzebne bo juz wczesniej sprawdzamy czy element nalezy
        //zabezpieczamy sie w systuacji gdy usuwamy pierwszy element, wtedy prev = NULL
        if (prev != NULL) {
            prev->next = p->next;
            delete p;
            return;
        }
            //usuwamy pierwszy
        else {
            node *tmp = head;
            head = head -> next;
            delete tmp;
            return;
        }
    }
    else{
        cout << "The list doesnt contain that element" << endl;
    }
}
void create_list(node *&head){
    char option;
    int val;
    while(true){
        cout <<"Option: \n-a(add)\n-r(remove)\n-e(exit)" << endl;
        cout << "Enter option: ";
        cin >> option;
        if(option == 'e') break;
        cout << "Enter a value: ";
        cin >> val;
        switch(option){
            case 'a':
                add_node(head, val);
                break;
            case 'r':
                remove_node(head, val);
                break;
            default:
                cout << "There is no option -" << option << " !" << endl;
                break;
        }
        call_out_list(head);
    }
}
node *merge(node *l1, node *l2){
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    if(l1 -> v < l2 -> v){
        l1 -> next= merge(l1 -> next, l2);
        return l1;
    }
    else{
        l2 -> next = merge(l1, l2 -> next);
        return l2;
    }
}
int main() {
    node* list1 = NULL;
    node* list2 = NULL;
    cout << "Create first list: " << endl;
    create_list(list1);
    //cout << "wypisuje pierwsza: ";
    call_out_list(list1);
    cout << "Create second list: " << endl;
    create_list(list2);
    cout << "Merged list(iterative): ";
    call_out_list(mergeI(list1, list2));
    cout << "Merged list(recursive): ";
    //call_out_list(mergeR_aux(list1, list2));
    call_out_list(merge(list1, list2));
    return 0;
}
