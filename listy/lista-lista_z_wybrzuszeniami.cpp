//
// Created by Kamil Delekta on 13.01.2020.
//
//List� z wybrzuszeniami nazywamy list�, kt�ra sk�ada si� z ci�gu element�w o warto�ciach
//b�d�cych liczbami pierwszymi oraz mo�liwych �wybrzusze� w postaci pobocznych,
//r�wnoleg�ych list z warto�ciami b�d�cymi liczbami nie pierwszymi.
//Napisz funkcj�, kt�ra przyjmuje wska�nik na pocz�tek listy z wybrzuszeniami i zwraca list�
//z�o�on� z wybrzusze� w odwrotnej kolejno�ci, ni� wyst�pi�y one oryginalnie w li�cie. Dla
//poni�szego przyk�adu lista wynikowa to: 4->6->100->1->4->NULL. Przyjmij elementy postaci:
struct node{
    int val;
    node* next;
    node* side;
};
#include <iostream>
using namespace std;

//normalny struct, lista wynikowa
struct node_n{
    int w;
    node *next;
};
node_n* lista_z_wybrzuszeniami(node *head){
    bool in_next = true;
    node_n *result = NULL;
    while(head != NULL){
        if(head -> side !=NULL){
            in_next = false;
            head = head -> side;
        }
        else{
            in_next = true;
            head = head -> next;
        }
        //czyli jesli do elementu wchodzilismy side'm
        if(!(in_next)){
            //sprawdzic czy faktycznie tak to sie robi
            node_n *added = new node_n;
            added -> w = head -> w;
            //o chuj im chodzi, nie pzdr
            added -> next = result;
            result = added;
        }
    }
    return result;
}
int main() {

    return 0;
}
