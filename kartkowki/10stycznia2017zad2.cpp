//
// Created by Kamil Delekta on 10.01.2020.
//
//Dane s¹ dwie listy cykliczne powsta³e przez zapêtlenie listy jednokierunkowej posortowanej
//rosn¹co, dla ka¿dej listy dany jest wskaŸnik wskazuj¹cy przypadkowy element w takiej liœcie.
//Proszê napisaæ funkcjê, która dla dwóch list cyklicznych, usuwa z obu list elementy
//wystêpuj¹ce w obu listach. Do funkcji nale¿y przekazaæ wskaŸniki na dwie listy, funkcja
//powinna zwróciæ ³¹czn¹ liczbê usuniêtych elementów
#include <iostream>
using namespace std;
struct node{
    int v;
    node *next;
};
//sprawdzic czy dziala
int remove_duplicates(node *&head1, node *&head2){
    node *prev1, *prev2 , *curr1, *curr2;
    //prevy musza byc przed tymi whileami zeby pozzniej umozliwic usuwanie pierwszego elementu z listy
    prev1 = head1;
    prev2 = head2;
    //zeby ustawic prevy
    head1 = head1 -> next;
    head2 = head2 -> next;
    while(prev1 -> v < head1 ->  v){
        prev1 = head1;
        head1 = head1 -> next;
    }
    while(prev2 -> v < head2 -> v){
        prev2 = head2;
        head2 = head2 -> next;
    }
    //wychadzac z while mamy wskazania na poczatki list
    //i prevy ustawione element wczesniej
    curr1 = head1;
    curr2 = head2;
    int counter = 0;
    while(prev1 -> v < curr1 -> v and prev2 -> v < curr2 -> v){
        if(curr1 -> v == curr2 -> v){
            node *tmp1 = curr1;
            prev1 -> next = curr1 -> next;
            curr1 = curr1 -> next;
            delete tmp1;
            node *tmp2 = curr2;
            prev2 -> next = curr2 -> next;
            curr2 = curr2 -> next;
            delete tmp2;
            counter += 2;
        }
        else if(curr1 -> v < curr2 -> v){
            prev1 = curr1;
            curr1 = curr1 -> next;
        }
        else{
            prev2 = curr2;
            curr2 = curr2 -> next;
        }
    }
    return counter;

}
int main() {

    return 0;
}
