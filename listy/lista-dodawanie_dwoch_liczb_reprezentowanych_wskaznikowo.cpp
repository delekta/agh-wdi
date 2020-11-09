//
// Created by Kamil Delekta on 09.01.2020.
//
#include <iostream>
//dodawanie dwoch liczb reprezentowanych wskaznikowo np [2] -> [0] -> [1] -> [9]
//                                                      [5] -> [2] -> [1]      | +
//                                                    = [2] -> [5] -> [4] -> [0]
// 1 prosta wersja odwroc dwie listy i dodawaj z poczatku
// 2 rekurencyjnie, dochodzisz do konca i wtedy zaczynasz dodawac
using namespace std;
struct node{
    int v;
    node *next;
};
bool b = true;
//na reverse musi byc ampersand
void reverse(node *&head){
    node *curr = head;
    node *tmp;
    while(curr -> next != NULL){
        tmp = curr -> next;
        //curr -> next pamietaaj
        curr -> next = tmp -> next;
        tmp -> next = head;
        head = tmp;
    }
}
node* add(node* number1, node* number2){
    reverse(number1);
    reverse(number2);
    node *result = NULL;
    int p = 0;
    while(number1 != NULL and number2 != NULL){
        node *res = new node;
        //przy res -> v musi byc % 10, a przy p musi byc / 10
        res -> v = (number1 -> v + number2 -> v + p) % 10;
        //tak trzeba robic pamietaj
        res -> next = result;
        result = res;
        p = (number1 -> v + number2 -> v + p) / 10;
        //nie zapomnij o takich oczywistosciach
        number1 = number1 -> next;
        number2 = number2 -> next;
    }
     if(number1 != NULL){
        while(number1 != NULL){
            node *res = new node;
            res -> v = (number1 -> v + p) % 10;
            p = (number1 -> v + p) / 10;
            res -> next = result;
            result = res;
            number1 = number1 -> next;
        }
    }
    else if(number2 != NULL){
        while(number2 != NULL){
            node *res = new node;
            res -> v = (number2 -> v + p) % 10;
            p = (number1 -> v + p) / 10;
            res -> next = result;
            result = res;
            number2 = number2 -> next;
        }
    }
    if(p > 0){
        node *res = new node;
        res -> v = p;
        res -> next = result;
        result = res;
    }

    return result;
}
//p = przeniesienie
//jak zrobic rekurencyjnie, w trakcie, ostatnie modyfikcaje 09.01.2020
void add_recursive(node *number1, node* number2, node *result, int p = 0){
    if(number1 != NULL and b) add_recursive(number1 -> next, number2, result, p);
    if(number2 != NULL and b) add_recursive(number1, number2 -> next, result, p);
    if(number1 == NULL and number2 == NULL) b = false;
    node *res = new node;
    res -> v = (number1 -> v + p) % 10;
    p = (number1 -> v + p) / 10;
    res -> next = result;
    result = res;

}
node* add_recursive_starter(node *number1, node *number2){
    node *result = NULL;
    add_recursive(number1, number2, result);
    return result;
}
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
int main() {
    node *number1 = NULL;
    node *number2 = NULL;
    cout << "Create first number: ";
    create_list(number1);
    cout << "Create second number: ";
    create_list(number2);
    cout << "Dodaje: ";
    call_out_list(number1);
    call_out_list(number2);
    cout << "Wyniik = " ;
    call_out_list(add(number1, number2));
    return 0;
}
