#include <stdio.h>
#include <stdlib.h>

typedef struct BSTnode{
    int key;
    int element;
    struct BSTnode* left;
    struct BSTnode* right;

}BSTnode;

BSTnode* create_node(int key, int element){
    BSTnode* new_node = (BSTnode*) malloc(sizeof(BSTnode));
    new_node->element = element;
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

typedef struct BST{
    BSTnode* root;
    int count;
}BST;

BST* create_bst(){
    BST* bst = (BST*) malloc(sizeof(BST));
    bst->root = NULL;
    bst->count = 0;

    return bst;
}

int findHelp(BSTnode* node, int key){
    if (node == NULL ){
        return NULL;
    }
    if (node->key > key){
        return findHelp(node->left, key);
    }
    else if (node->key == key)
    {
        return node->element;
    }
    else{
        return findHelp(node->right, key);
    }
    
}
int Remove(BST* bst, int key){
    int temp = findHelp(bst->root, key);

}


int find(BST* bst, int key){
    return findHelp(bst->root, key);
}
BSTnode* insertHelp(BSTnode* node, int key, int element){
    if (node == NULL){
        create_node(key, element);
    }
    else if(node->key > key){
        node->left = insertHelp(node->left, key, element);
    }
    else{
        node->right = insertHelp(node->right, key, element);
    }
    return node;
}
void insert(BST* bst, int key, int element){
    bst->root = insertHelp(bst->root, key, element);
    bst->count+= 1;
}

int main(){

}