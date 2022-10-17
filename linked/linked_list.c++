#include <iostream>
using namespace std;

struct Link{
    int value = 0;
    Link* next = NULL;
};

void print_list(Link* head){
    cout << head->value << " ";
    if (head->next != NULL){
        return print_list(head->next);
    }
}

Link*  get_last(Link* head){
    if (head->next != NULL){
        return get_last(head->next);
    }
    return head;
}



void add(int val, Link* head){
    Link* actual_link = new Link;
    actual_link->value = val;
    actual_link->next = NULL;

    Link* last = get_last(head);
    last ->next = actual_link;
    
}

int main(){
    Link* head = new Link;
    head->value = -1;
    head->next = NULL;
    //Link* last = get_last(head);

    add(5, head);
    add(1, head);
    add(4, head);
    print_list(head);


    return 0;
}

