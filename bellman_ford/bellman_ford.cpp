#include <iostream>
/* #include <bits/stdc++.h> */
#include <vector>

using namespace std;

struct cell
{
    int connection;
    int weight;
};

class Bell_Ford
{
public:
    vector<cell *> *adj_list;
    // vector<int> *aa;
    int num_vertex;
    int *distance_matrix;

    Bell_Ford(int num_V);
    int weight(int vertex1, int vertex2);
    int next(int vertex1, int value);
    void addEdge(int vertex1, int vertex2, int weight);
    void init(int starter);
};

Bell_Ford ::Bell_Ford(int num_v)
{
    num_vertex = num_v;
    adj_list = new vector<cell *>[num_v];
    distance_matrix = new int[num_v];
    for (int i = 0; i < num_v; i++)
    {
        distance_matrix[i] = 2147483647;
    }
}

int Bell_Ford ::weight(int vertex1, int vertex2)
{
    vector<cell *>::iterator ptr;
    for (ptr = adj_list[vertex1].begin(); ptr < adj_list[vertex1].end(); ptr++)
    {
        cell *aux_cell = *ptr;
        if (aux_cell->connection == vertex2)
        {
            return aux_cell->weight;
        }
    }
}

void Bell_Ford ::addEdge(int vertex1, int vertex2, int weight)
{
    cell *new_cell = new cell;
    new_cell->connection = vertex2;
    new_cell->weight = weight;
    adj_list[vertex1].push_back(new_cell);
}

void Bell_Ford ::init(int starter)
{
    distance_matrix[starter] = 0;

    for (int k = 0; k < num_vertex - 1; k++)
    {
        for (int i = 0; i < num_vertex; i++)
        {

            int j;
            cell *aux_cell;
            vector<cell *>::iterator ptr;

            for (ptr = adj_list[i].begin(); ptr < adj_list[i].end(); ptr++)
            {
                aux_cell = *ptr;
                j = aux_cell->connection;
                if (distance_matrix[j] > distance_matrix[i] + aux_cell->weight)
                {
                    distance_matrix[j] = distance_matrix[i] + aux_cell->weight;
                }
                // j  = adj_list[i+1][0]->connection;// next
            }
        }
    }
    for (int i = 0; i < num_vertex; i++)
    {
        int j;
        cell *aux_cell;
        vector<cell *>::iterator ptr;

        for (ptr = adj_list[i].begin(); ptr < adj_list[i].end(); ptr++)
        {
            aux_cell = *ptr;
            j = aux_cell->connection;
            if (distance_matrix[j] > distance_matrix[i] + aux_cell->weight)
            {
                cout << "Ciclo Negativo \n";
                
            }
        }
    }
}

int main()
{
    Bell_Ford bell_ford(5);
    bell_ford.addEdge(1, 4, -1);
    bell_ford.addEdge(4, 3, 2);
    bell_ford.addEdge(3, 2, -1);
    bell_ford.addEdge(2, 4, 2);
    bell_ford.addEdge(1, 2, 5);
    bell_ford.addEdge(1, 0, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << i << "-> ";
        int j;
        cell *aux_cell;
        vector<cell *>::iterator ptr;

        for (ptr = bell_ford.adj_list[i].begin(); ptr < bell_ford.adj_list[i].end(); ptr++)
        {
            aux_cell = *ptr;
            j = aux_cell->connection;
            cout << j << " ";
        }
        cout << "\n";
    }
    bell_ford.init(1);
    for (int i = 0; i < 5; i++)
    {
        cout << bell_ford.distance_matrix[i] << " ";
    }
}