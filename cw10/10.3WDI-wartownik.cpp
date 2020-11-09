//
// Created by Kamil Delekta on 24.12.2019.
//listê.
// Do funkcji nale¿y przekazaæ wskazania na pierwsze elementy obu list, funkcja po
//Prosz napisaæ funkcjê scalaj¹c¹ dwie posortowane listy w jedn¹ posortowan¹ winna zwróciæ wskazanie do scalonej listy.
// - funkcjêa iteracyjna,

#include <iostream>
using namespace std;
struct node{
    int v;
    node *next = NULL;
};
node *merge(node *list1, node *list2){
    //czasem sie przydaje
    if(list1 == NULL)return list2;
    if(list2 == NULL) return list1;
    node *w = new node;
    w -> next = NULL;
    node *last = w;
    while(list1 != NULL and list2 != NULL){
        if(list1 -> v < list2 -> v){
            last -> next = list1;
            list1 = list1 -> next;
        }
        else{
            last -> next = list2;
            list2 = list2 -> next;
        }
        //piszemy na koncu zeby nie pisac w if i else
        last = last -> next;
    }
    if(list1 != NULL){
        last -> next = list1;
    }
    else{
        last -> next = list2;;
    }
    node *head = w -> next;
    delete w;
    return head;
}
void call_out_list(node *head){
    while(head != NULL){
        cout << head -> v << " ";
        head = head -> next;
    }
    cout << endl;
}
bool belong(node *head, int val){
    while(head != NULL){
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
//moja, zacina sie przy zmianie listy
node* mergeR(node *&l1, node *&l2){
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    if(l1 -> v < l2 -> v){
        l1 -> next = mergeR(l1 -> next, l2);
        return l1;
    }
    else{
        l2 -> next = mergeR(l1, l2 -> next);
        return l2;
    }
}
//szczepana wgl nie dzia³¹
node *mergeRR(node *l1, node *l2) {
    if (l1 == nullptr) {
        return l2;
    }
    if (l2 == nullptr) {
        return l1;
    }
    if (l1->v > l2->v) {
        l2->next = merge(l1, l2->next);
        return l2;
    }
    else {
        l1->next = merge(l1->next, l2);
        return l1;
    }
}
int main() {
    node* list1 = NULL;
    node* list2 = NULL;
    //listy musza byc posortowane rosnaco
    cout << "Create first list: " << endl;
    create_list(list1);
    //cout << "wypisuje pierwsza: ";
    call_out_list(list1);
    cout << "Create second list: " << endl;
    create_list(list2);
    cout << "Merged list(iterative): ";
    call_out_list(merge(list1, list2));
    cout << "Merged list(recursive): ";
    node *result = mergeRR(list1, list2);
    call_out_list(result);
    return 0;
}
