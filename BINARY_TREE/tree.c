#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *leftNode;
    struct Node *rightNode;

} Node;

Node *createNode(int);
Node *insertNode(Node *,int);
void printNode(Node *,Node *,int,int *);

int main()
{
  int n;
  scanf("%d",&n);
  Node *Tree = NULL;
  int i;
  int TreeHeight = 0;
  for (i = 0 ; i < n;i++){
    int value;
    scanf("%d",&value);
    if (i == 0){
        Tree = createNode(value);
    }
    else{
        Tree = insertNode(Tree,value);
    }
  }
  printNode(Tree,Tree,1,&TreeHeight);
  printf("%d",TreeHeight);


}
Node *createNode(int data){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->leftNode = newNode->rightNode = NULL;
    return newNode;
}
Node *insertNode(Node *root,int data){
    if (root == NULL){
        root = createNode(data);
    }
    if (data < root->data){
        root->leftNode = insertNode(root->leftNode,data);
    }
    if (data > root->data){
        root->rightNode = insertNode(root->rightNode,data);
    }
    return root;
}
void printNode(Node *current, Node *root, int depth,int *max_depth) {
    
    if (current != NULL) {
        // if (current == root) {
        //     printf("Root Node : %d, Depth: %d \n", current->data, depth);
        // }
        // if (current->leftNode) {
        //     printf("Left Node : %d, Depth: %d \n", current->leftNode->data, depth + 1);
        // }
        // if (current->rightNode) {
        //     printf("Right Node : %d, Depth: %d \n", current->rightNode->data, depth + 1);
        // }
        if (depth > *max_depth){
            *max_depth = depth;
        }
        printNode(current->leftNode, root, depth + 1,max_depth);
        printNode(current->rightNode, root, depth + 1,max_depth);
    }
}