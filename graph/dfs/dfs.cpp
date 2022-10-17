#include <iostream>
using namespace std;
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

void print_stack(Link* l){
    if (l->next != NULL){
        cout << l->value << ", ";
        return print_stack(l->next);
    }
    else{
        cout << l->value << "\n";
        return;
    }
}

void Pop(Stack* s){
    if (s->top == NULL){
        printf("Nao tem nada para excluir\n");
    }
    else{
        int value = s->top->value;
        //printf("%d\n", value);
        s->top = s->top->next;
        s->size--;
    }
}


void Push(Stack* s, int value){
    Link* new_top = (Link*) malloc(sizeof(Link));
    new_top->value = value;
    new_top->next = s->top;

    s->top = new_top;
    s->size++;
}

//--------------------------

class DFS{
    private:
    public:
    int* vertexs;
    int* is_visited;
    int num_vertexs;
    Stack* dfs_stack;
    int** adjacency_matrix;

    DFS(int num_vertex);
    void create_edge(int vertex1, int vertex2);
    bool check_edge(int vertex1, int vertex2);
    void dfs();
    void dfs_process(int i);

};

DFS :: DFS(int num_vertex){
    dfs_stack = create_stack();
    num_vertexs = num_vertex;
    vertexs = new int[num_vertex];
    is_visited = new int[num_vertex];

    adjacency_matrix =  new int*[num_vertex];
    for (int i = 0; i < num_vertex; i ++){
        adjacency_matrix[i] = new int [num_vertex];
    }
}

void DFS :: create_edge(int vertex1, int vertex2){
    vertexs[vertex1] = 1;
    vertexs[vertex2] = 1;
    adjacency_matrix[vertex1][vertex2] = 1;
    adjacency_matrix[vertex2][vertex1] = 1;
}

bool DFS :: check_edge(int vertex1, int vertex2){
    if (adjacency_matrix[vertex1][vertex2] == 1){
        return true;
    }
    else{
        return false;
    }
}
void DFS :: dfs(){
    int count = 0;

    for (int i = 0; i < num_vertexs; i++){
        if (vertexs[i] == 1){
            if (is_visited[i] != 1){
                is_visited[i] = 1;
                Push(dfs_stack, i);
                //print_stack(dfs_stack->top);
                dfs_process(i);
                cout << dfs_stack->top->value << " ";
                Pop(dfs_stack);
            }
        }   
        else{
            continue;
        }
    }
    
    
}

void DFS :: dfs_process(int i){
    for (int j = 0; j < num_vertexs; j++){
        if(adjacency_matrix[i][j] == 1){
            if (is_visited[j] != 1){
                Push(dfs_stack, j);
                //print_stack(dfs_stack->top);
                is_visited[j] = 1;
                dfs_process(j);
                cout << dfs_stack->top->value << " ";
                Pop(dfs_stack);
            }
        }
    }
}

int main(){
    int num_vertex = 8;
    DFS dfs(num_vertex);
    dfs.create_edge(1, 2);
    dfs.create_edge(1, 3);  
    dfs.create_edge(2,6);
    dfs.create_edge(2,4);
    dfs.create_edge(3,4);
    dfs.create_edge(2,5);
    dfs.create_edge(4,5);
    dfs.create_edge(5,7);

    dfs.dfs();

    /* for (int i = 0; i < num_vertex; i++){
        cout << dfs.num_vertexs << "-" <<dfs.is_visited[i] << "..";
    } */

}