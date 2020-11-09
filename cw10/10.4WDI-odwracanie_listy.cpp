//
// Created by Kamil Delekta on 11.12.2019.
//
#include <iostream>
using namespace std;
struct node{
    int val;
    node *next;
};
void reverse_list(node *&head){
    if(head == NULL){
        cout << "lista pusta";
        return;
    }
    node *curr = head;
    node *tmp;
    while(curr -> next != NULL){
        tmp = curr -> next;
        curr -> next = tmp -> next;
        tmp -> next = head;
        head = tmp;
    }
}
//
void reverse_list_rekurencyjne(node *&head, node *curr, node *prev){
    if(curr -> next == NULL){
        curr -> next = prev;
        head = curr;
        //bez reurna bo zwraca lista jednoelementowa
    }
    else{
        reverse_list_rekurencyjne(head, curr -> next, curr);
        curr -> next = prev;
    }
}
node *reverse_list_rekurencyjnie_pomocnicza2(node *head){
    if(head == NULL) return head;
    node *curr = head;
    reverse_list_rekurencyjne(head, curr, NULL);
    return head;
}
//
node* reverse_recursion3(node *head, node *result = NULL){
    if(head == NULL) return result;
    else{
        node *tmp = head -> next;
        head -> next = result;
        result = head;
        head = tmp;
        return reverse_recursion3(head, result);
    }
}
int main() {
    return 0;
}
