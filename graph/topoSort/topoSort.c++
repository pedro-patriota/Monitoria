#include <iostream>
#include <stdio.h>
#include <list>
#include <stack>
#include <string>
using namespace std;

class TopoSort{
    public:
    int num_vertexs;
    list<int>* topo_adjlist;
    int* is_visited;
    stack<int> topo_stack;

    TopoSort(int num_vertex);

    void create_edge(int vertex1, int vertex2);

    void dfs();
    void dfs_process(int i);

    list<int> getAdjacent(int vertex);

};

TopoSort :: TopoSort(int num_vertex){

    is_visited = new int[num_vertex];
    topo_adjlist = new list<int>[num_vertex];
    num_vertexs = num_vertex;

}

void TopoSort :: create_edge(int vertex1, int vertex2){
    topo_adjlist[vertex1].push_back(vertex2);
}

list<int> TopoSort :: getAdjacent(int vertex){
    list<int> :: iterator ptr;
    list<int> adjacent_list;
    for (ptr = topo_adjlist[vertex].begin(); ptr != topo_adjlist[vertex].end(); ptr++){
        adjacent_list.push_back(*ptr);
    }       

    return adjacent_list;


}

void TopoSort :: dfs(){

    for (int vertex = 0; vertex < num_vertexs; vertex++){
       
            if (is_visited[vertex] == 0 ){
                is_visited[vertex] = 1;
                topo_stack.push(vertex);
                dfs_process(vertex);
                
                topo_stack.pop();
            }
    
        
    }
}

void TopoSort :: dfs_process(int i){
    list<int> :: iterator ptr;
    
    for (ptr = topo_adjlist[i].begin(); ptr != topo_adjlist[i].end(); ptr++){
        if (is_visited[*ptr] == 0 ){
            is_visited[*ptr] = 1;
            topo_stack.push(*ptr);
            dfs_process(*ptr);
            topo_stack.pop();
            cout << topo_stack.top();

        }
    }
    cout << i;       
    
    
}

int main(){
    TopoSort toposort(3);
    toposort.create_edge(0,1);
    toposort.create_edge(2,1);
    toposort.create_edge(0,0);
    toposort.dfs();

    return 0;
}