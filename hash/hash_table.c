#include <stdio.h>
#include <stdlib.h>

typedef struct Link{
    int value;
    struct Link* next;
}Link;

typedef struct List{
    Link* head;
    Link* tail;
    Link* curr;
    int cnt;
}List;

void print_list(Link* head){
    printf("%d ", head->value);
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

Link* create_list(){
    Link* new_link = (Link*) malloc(sizeof(Link));
    new_link->next = NULL;
    new_link->value = -1;

    return new_link;
}

void add(int val, struct Link* head){
    Link* actual_link = (Link*) malloc(sizeof(Link));
    actual_link->value = val;
    actual_link->next = NULL;

    Link* last = get_last(head);
    last ->next = actual_link;
    
}

typedef struct Dictionary{
    int m;
    int counter;
    Link** lines;
    int (*h)(int K);

}Dictionary;

int hash(int K){
    return abs(K)%10;
}
Dictionary* create_dict(int size, int(*h)(int K));
void insertD(Dictionary* d, int k, int e);
int find (Dictionary*d, int k);
void displayD(Dictionary* d, int size);

int main(){
    int choice = 0;
    int number;
    int size = 10;
    int i;
    Dictionary* dictionary = create_dict(size, hash);

    scanf("%d", &choice);
    
    for (i = 0 ; i < choice; i++) {
        scanf("%d", &number);
        insertD(dictionary, number, number);
    }
    displayD(dictionary, size);

    return 0;
}

Dictionary* create_dict(int size, int(*h)(int K)){
    int i;
    Dictionary* d = (Dictionary*) malloc(sizeof(Dictionary));
    d->m = size;
    d->counter= 0;
    d->lines =  (Link**) malloc(size*sizeof(Link*));
    for (int i = 0; i < size; i++){
        d->lines[i] = create_list();
    }
    d->h = &hash;
    return d;
}

void insertD(Dictionary* d, int k, int e){
    if (!find(d, k)){
        int pos = d->h(k);
        Link* temp =  d->lines[pos];
        add(e, temp);
        d->counter+=1;
    }
}
int find(Dictionary* d, int key){
    int i = 0;
    int h  = hash(key);
    Link* holder = d->lines[h];
    while (holder->value != key && holder== NULL)
    {
        holder = holder->next;
    }
    if (holder ->value == key){
        return 1;
    }
    else{
        return 0;
    }
    
}
void displayD(Dictionary* d, int size){
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", i);
        print_list(d->lines[i]->next);
        printf("\n");
    }
}