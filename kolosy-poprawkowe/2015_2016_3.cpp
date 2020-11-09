//
// Created by Kamil Delekta on 05.01.2020.
//
//Dany jest zbior punktow plaszczyzny o wspolrzednych bedacych liczbami calkowitymi. Zbior
//ten dany jest w postaci listy jednokierunkowej. Prosze funkcje, ktora rozdziela ³añcuch na cztery
//³añcuchy zawierajace punkty nalezace odpowiednio do I, II, III, IV cwiartki ukladu wsporzednych,
//natomiast punkty lezace na osiach ukladu usuwa z pamieci. Prosze zadeklarowac odpowiednie typy.
//Co znaczy prosze zadeklarowac odpowiednie typy
#include <iostream>
using namespace std;
const int N = 5;
struct node{
    int x;
    int y;
    node *next;
};
//---ZESTAW SPRAWDZAJACY---
void call_out_list_for_arrays(node *head[]){
    for(int i = 1; i < N; i++) {
        cout << i << "quarter: " << endl;
        while (head[i] != nullptr) {
            cout << "x: " << head[i] -> x << " y:" << head[i] -> y << endl;
            head[i] = head[i] -> next;
        }
        cout << "---------------";
    }
    cout << endl;
}
void call_out_list(node *head){
    while(head != nullptr){
        cout << "x: " << head -> x <<  " y:" << head -> y << endl;
        head = head -> next;
    }
    cout << endl;
}
void add_node(node *& head, int x,int y){
    node *p = new node;
    p -> x = x;
    p -> y = y;
    p -> next = head;
    head = p;
}
void create_list(node *&head){
    char option;
    int x;
    int y;
    while(true){
        cout <<"Option: \n-a(add)\n-e(exit)" << endl;
        cout << "Enter option: ";
        cin >> option;
        if(option == 'e') break;
        cout << "Enter x: ";
        cin >> x;
        cout << "Enter y: ";
        cin >> y;
        switch(option){
            case 'a':
                add_node(head, x, y);
                break;
            default:
                cout << "There is no option -" << option << " !" << endl;
                break;
        }
        call_out_list(head);
    }
}
void split(node *head, node* first[N]){
    //ale odjabales z nazwami, first a quarter to to samo
    node *last[N];
    //inicjalizacja
    for(int i = 0; i < N; i++) first[i] = NULL;
    while(head != NULL){
        int idx;
        if(head -> x == 0 or head -> y == 0) idx = 0;
        else if(head -> x > 0 and head -> y > 0) idx = 1;
        else if(head -> x < 0 and head -> y > 0) idx = 2;
        else if(head -> x < 0 and head -> y < 0) idx = 3;
        else idx = 4;
        if(idx == 0){
            node *tmp = head;
            head = head -> next;
            delete tmp;
        }
        else if(first[idx] == NULL){
            first[idx] = last[idx] = head;
            head = head -> next;
            //czy musi byc? - musi,(bo musisz przerwac to polaczenie, bo np ten head moze wskazywac na punkt ktorynie nalezy do tej cwiartki)
            //ale obawiazkowo pod head = head -> next
            last[idx] -> next = NULL;
        }
        else{
            last[idx] -> next = head;
            last[idx] = last[idx] -> next;
            //wazne last[idx] -> next = NULL ma wplyw na heada
            head = head -> next;
            //czy musi byc? - musi,(bo musisz przerwac to polaczenie, bo np ten head moze wskazywac na punkt ktorynie nalezy do tej cwiartki)
            //ale obawiazkowo pod head = head -> next
            last[idx] -> next = NULL;
        }
    }
}
int main() {
    node *head = NULL;
    node *first[N];
    create_list(head);
    for(int i = 0; i < N; i++) first[i] = NULL;
    split(head, first);
    call_out_list_for_arrays(first);
    return 0;
}
