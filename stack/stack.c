#include <stdio.h>
#include <stdlib.h>




typedef struct Link{
    int value;
    struct Link* next;

}Link;
typedef struct Stack{
    Link* top;
    int size;
}Stack;

Stack* create_stack(){
    Stack* s = (Stack*) (malloc(sizeof(Stack)));
    s->top = NULL;
    s->size = 0;

    return s;
}

void Push(Stack* s, int value){
    Link* new_top = (Link*) malloc(sizeof(Link));
    new_top->value = value;
    new_top->next = s->top;

    s->top = new_top;
    s->size++;
}

void Pop(Stack* s){
    if (s->top == NULL){
        printf("Pare\n");
    }
    else{
        int value = s->top->value;
        printf("%d\n", value);
        s->top = s->top->next;
        s->size--;
    }
}

int main(void){
    Stack* s = create_stack();
    Pop(s);
    Push(s, 12);
    Push(s, 1);
    printf("%d", s->top->value);

    return 0;
}