#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h> 
#include <string>



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
        //printf("%d\n", temp_position);
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

string print_queue(Link *l, string path)
{
    if (l->next != NULL)
    {
        cout << l->value << ", ";
        path += to_string(l->value);
        return print_queue(l->next, path);
    }
    else
    {
        cout <<"\n";
        path += to_string(l->value);
        return path;
    }
}

//--------------------------

class BFS
{
private:
public:
    int *distance;
    int num_vertexs;
    string* shortest_path;
    Queue *bfs_queue;
    int **adjacency_matrix;

    BFS(int num_vertex);
    void create_edge(int vertex1, int vertex2);
    bool check_edge(int vertex1, int vertex2);
    void bfs(int root);
    void bfs_process(int i ,int d);
};

BFS ::BFS(int num_vertex)
{
    bfs_queue = create_queue();

    num_vertexs = num_vertex;
    distance = new int[num_vertex];
    shortest_path = new string[num_vertex];

    adjacency_matrix = new int *[num_vertex];
    for (int i = 0; i < num_vertex; i++)
    {   
        distance[i] = 0;
        adjacency_matrix[i] = new int[num_vertex];
    }
}

void BFS ::create_edge(int vertex1, int vertex2)
{
    adjacency_matrix[vertex1][vertex2] = 1;
    adjacency_matrix[vertex2][vertex1] = 1;
}

bool BFS ::check_edge(int vertex1, int vertex2)
{
    if (adjacency_matrix[vertex1][vertex2] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void BFS ::bfs(int root)
{
    int count = -1;

    distance[root] = count;
    enqueue(bfs_queue, root);
    bfs_process(root, 0);
            
    
}

void BFS ::bfs_process(int i, int d)
{

    int count = 0, j = 0;
    int temp_visited[num_vertexs];
    for (j = 0; j < num_vertexs; j++)
    {
        
        cout << j << "(" << distance[j]<< ") ";
    
        if (adjacency_matrix[i][j] == 1)
        {

            if (distance[j] == 0)
            {
                distance[j] = d + 1;
                temp_visited[count] = j;
                count++;
                enqueue(bfs_queue, j);
            }
        }
    }

  /*   cout << "\n"; */
    for (int pos = 0; pos < count; pos++)
    {
        j = temp_visited[pos];
        shortest_path[j] = print_queue(bfs_queue->head, "");
        dequeue(bfs_queue);
        bfs_process(j, d+1);

    }
}

int main()
{
    BFS bfs(8);
    bfs.create_edge(0, 2);
    bfs.create_edge(4, 0);
    bfs.create_edge(3,2);
    bfs.create_edge(2,5);
    bfs.create_edge(2,1);
    bfs.create_edge(5,4);
    
    bfs.bfs(0);
    /*  for (int i = 0; i < bfs.num_vertexs; i++)
    {
        cout << i << "->" << bfs.shortest_path[i] << "\n";
    } */

}