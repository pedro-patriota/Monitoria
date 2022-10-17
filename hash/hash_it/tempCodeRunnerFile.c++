#include <iostream>
#include <string.h>
using namespace std;

struct individual
{
    string key = "";
    int position;
};

class Hash
{
private:
public:
    individual *node;
    int hash_funct(string key);
    int add(string key);
    int summary();

    int delete_key(string key);

    Hash();
};

Hash ::Hash()
{
    node = new individual[101];
}

int Hash ::delete_key(string key)
{
    int pos = 0, new_pos = 0;
    pos = hash_funct(key);

    if (node[pos].key == key)
    {
        node[pos].key = "";
        return 1;
    }
    else
    {
        for (int i = 1; i < 20; i++)
        {
            new_pos = i ^ 2 + 23 * i + pos;
            new_pos = new_pos % 101;
            if (node[new_pos].key == key)
            {
                node[pos].key = "";
              
                return 1;
            }
        }
        return 0;
    }
}

int Hash ::hash_funct(string key)
{
    int aux_val = 0, ascii = 0, temp_val = 0, result = 0;
    for (int i = 0; i < key.length(); i++)
    {
        ascii = (int)key[i];
        temp_val += ascii * (i + 1);
    }
    result = (19 * temp_val) % 101;

    return 1;
}

int Hash ::add(string key)
{
    int new_pos = 0, pos = 0;
    pos = hash_funct(key);

    if (node[pos].key.empty())
    {
        node[pos].key = key;
        return 1;
    }
    else
    {
        if (node[pos].key != key)
        {
    
            for (int i = 1; i < 20; i++)
            {
                new_pos = i ^ 2 + 23 * i + pos;
                new_pos = new_pos % 101;
                if (node[new_pos].key.empty())
                {
                    node[new_pos].key = key;
                    return 1;
                }
            }
            return 0;
        }
        else
        {
            return 0;
        }
    }
}
int Hash ::summary()
{   
    for (int i = 0; i < 101; i++){
        if (!node[i].key.empty()){
            cout << i << ":" << node[i].key << "\n";
        }
    }
}

int main()
{
    int cycle, num_op;

    string input, type, key; // char str[100];
    cin >> cycle;
    int add = 0, del = 0; 
    for (int i = 0; i < cycle; i++)
    {
        Hash *my_hashtable = new Hash;
        cin >> num_op;

        for (int j = 0; j < num_op; j++)
        {
            cin >> input;
            type = input.substr(0, input.find(':'));
            key = input.substr(input.find(':') + 1, sizeof(input));
            if (type == "ADD")
            {
                add += 1;
                my_hashtable->add(key);
            }
            else
            {   
                del+=1;
                my_hashtable->delete_key(key);
            }
        }
        cout << add - del << endl;
        add = del = 0;
        my_hashtable->summary();
    }
}