//
// Created by Kamil Delekta on 13.01.2020.
//
//List¹ z wybrzuszeniami nazywamy listê, która sk³ada siê z ci¹gu elementów o wartoœciach
//bêd¹cych liczbami pierwszymi oraz mo¿liwych “wybrzuszeñ” w postaci pobocznych,
//równoleg³ych list z wartoœciami bêd¹cymi liczbami nie pierwszymi.
//Napisz funkcjê, która przyjmuje wskaŸnik na pocz¹tek listy z wybrzuszeniami i zwraca listê
//z³o¿on¹ z wybrzuszeñ w odwrotnej kolejnoœci, ni¿ wyst¹pi³y one oryginalnie w liœcie. Dla
//poni¿szego przyk³adu lista wynikowa to: 4->6->100->1->4->NULL. Przyjmij elementy postaci:
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
