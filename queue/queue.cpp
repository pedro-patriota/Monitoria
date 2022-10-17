#include <iostream>
using namespace std;

typedef struct Link
{
    int value;
    Link *next;
} Link;

typedef struct Queue
{
    Link *head; 
    Link *tail;
    int size;

} Queue;

Queue *create_queue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;

    return q;
}

void enqueue(Queue *q, int value)
{
    Link *new_head = (Link *)malloc(sizeof(Link));
    new_head->next = q->head;
    new_head->value = value;

    q->head = new_head;
    if (q->tail == NULL)
    {
        q->tail = q->head;
    }
    q->size++;
}

Link *get_past_tail(Queue *q, int temp_position, Link *node)
{
    if (node->next == q->tail)
    {
        return node;
    }
    else if (node->next == NULL)
    {
        return node;
    }
    else
    {
        printf("%d\n", temp_position);
        return get_past_tail(q, temp_position + 1, node->next);
    }
}

void dequeue(Queue *q)
{

    Link *past_tail = get_past_tail(q, 0, q->head);
    q->size--;
    if (q->size == 0)
    {
        q->head = NULL;
        q->tail = NULL;
    }
    else
    {
        past_tail->next = q->tail->next;
        q->tail = past_tail;
    }
}

int main()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q = create_queue();

    enqueue(q, 2);
    enqueue(q, 24);
    enqueue(q, 3);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    enqueue(q, 36);
    enqueue(q, 6);

    printf("\n%d %d %d", q->head->value, q->tail->value, q->size);
    free(q);
    return 0;
}