//
// Created by Kamil Delekta on 13.01.2020.
//
//wersja rekurencyjna
//do sprawdzenia dzialania ale zaduzo chujowo nazwanych zmiennych
#include <iostream>
using namespace std;
struct node{
    int val;
    node *next;
};
struct pomka {
    int reszta;
    node *wsk;
};
void dod0(node *&first, node *&second) {
    node *first1 = first;
    node *second1 = second;
    int n=0, m=0;
    while (first!=NULL){
        first=first->next;
        n++;
    }
    while (second!=NULL){
        second=second->next;
        m++;
    }
    node *p;
    node *p1;
    node *q;
    int o;
    if(n>m){
        o=n-m;
        while(o!=0){
            p=new node;
            if(o!=n-m)q->next=p;
            p->val=0;
            p->next=second1;
            q=p;
            if(o==n-m) p1=p;
            o--;
        }
        second1=p1;
    }
    if(m>n){
        o=m-n;
        while(o!=0){
            p=new node;
            if(o!=m-n) q->next=p;
            p->val=0;
            p->next=first1;
            q=p;
            if(o==m-n) p1=p;
            o--;
        }
        first1=p1;
    }
    first=first1;
    second=second1;
}
pomka sumowanko( node *first, node *second){
    if(first->next==NULL){
        node *third;
        third = new node;
        third->next=NULL;
        third->val=(first->val +second->val)%10;
        pomka ost;
        ost.reszta=(first->val +second->val)/10;
        ost.wsk=third;
        return ost;
    }
    node *third;
    third = new node;
    third->next=(sumowanko(first->next,second->next)).wsk;
    third->val = (first->val +second->val +sumowanko(first->next,second->next).reszta)%10;
    pomka ost;
    ost.reszta=(first->val +second->val +sumowanko(first->next,second->next).reszta)/10;
    ost.wsk=third;
    return ost;
}
void wykonaj (node *first, node *second, node *&third){
    dod0(first,second);
    third=sumowanko(first,second).wsk;
    if(sumowanko(first,second).reszta!=0){
        node*p;
        p=new node;
        p->val=1;
        p->next=third;
        third=p;
    }
}
int main(){
}
m