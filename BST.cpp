#include <iostream>
#define queuesize 100
using namespace std;
class Node{
    public:
        int data;
        Node* leftNode;
        Node* rightNode;
        Node(int value){
            data = value;
            leftNode = NULL;
            rightNode = NULL;
        }
};
class Queue{
    public:
        Node* queue[queuesize];
        int front;
        int rear;
        int size;
        Queue(){
            front = -1;
            rear = -1;
            size = 0;
        }
        void enqueue(Node* newNode){
            if (size == queuesize){
                return;
            }
            if (front == -1){
                front = 0;
            }
            size++;
            queue[(++rear) % queuesize] = newNode;

        }
        void dequeue(){
            if (size == 0){
                return;
            }
            if (front == rear){
                front = -1;
                rear = -1;
            }
            else{
                front = (front + 1) % queuesize;
            }
            size--;
        }
};

class BinaryTree{
    public:
        Node* root;
        BinaryTree(){
            root = NULL;
        }
        Node* insertNode(Node* currentRoot, int value){
            if (currentRoot == NULL){
                return new Node(value);
            }
            else if (value < currentRoot->data){
                currentRoot->leftNode = insertNode(currentRoot->leftNode, value);
            }
            else{
                currentRoot->rightNode = insertNode(currentRoot->rightNode, value);
            }
            return currentRoot;
        }
        Node* findMin(Node* currentRoot) {
            while (currentRoot && currentRoot->leftNode != NULL) {
                currentRoot = currentRoot->leftNode;
            }
            return currentRoot;
        }
        Node* removeNode(Node* currentRoot, int value){
            if (currentRoot == NULL){
                return NULL;
            }
            if (value < currentRoot->data){
                currentRoot->leftNode = removeNode(currentRoot->leftNode, value);
            }
            else if (value > currentRoot->data){
                currentRoot->rightNode = removeNode(currentRoot->rightNode, value);
            }
            else{
                if (currentRoot->leftNode == NULL && currentRoot->rightNode == NULL){
                    return NULL;
                }
                else if (currentRoot->leftNode == NULL && currentRoot->rightNode != NULL){
                    return currentRoot->rightNode;
                }
                else if (currentRoot->leftNode != NULL && currentRoot->rightNode == NULL){
                    return currentRoot->leftNode;
                }
                else{
                    Node* temp = findMin(currentRoot->rightNode);
                    currentRoot->data = temp->data;
                    currentRoot->rightNode = removeNode(currentRoot->rightNode, temp->data);
                }
            }
            return currentRoot;
        }   
        void bfsTraversal() { 
            if (root == NULL) {
                return;
            }
            Queue* queue = new Queue();
            queue->enqueue(root);
            while (queue->size > 0){
                int currentdepthSize = queue->size;
                while (currentdepthSize > 0){
                    Node *currentNode = queue->queue[queue->front];
                    queue->dequeue();
                    cout << currentNode->data << ",";
                    if (currentNode->leftNode != NULL){
                        queue->enqueue(currentNode->leftNode);
                    }
                    if (currentNode->rightNode != NULL){
                        queue->enqueue(currentNode->rightNode);
                    }
                    currentdepthSize--;
                }
                cout<<"|";
            }
            cout<<endl;
        }
        void inorderTraversal(Node* currentNode){
            if (currentNode == NULL){
                return;
            }
            inorderTraversal(currentNode->leftNode);
            cout<<currentNode->data<<",";
            inorderTraversal(currentNode->rightNode);
        }
        void preorderTraversal(Node* currentNode){
            if (currentNode == NULL){
                return;
            }
            cout<<currentNode->data<<",";
            preorderTraversal(currentNode->leftNode);
            preorderTraversal(currentNode->rightNode);
        }
        void postorderTraversal(Node *currentNode){
            if (currentNode == NULL){
                return;
            }
            postorderTraversal(currentNode->leftNode);
            postorderTraversal(currentNode->rightNode);
            cout<<currentNode->data<<",";
        }

};
int main(){
    char c;
    int value;
    bool loop = true;
    BinaryTree tree;
    while (loop){
        cin >> c;
        switch (c){
            case 'a' : cin >> value; 
            tree.root = tree.insertNode(tree.root, value); 
            break;
            case 'b' : tree.bfsTraversal(); break;
            case 'i' : tree.inorderTraversal(tree.root);cout<<endl; break;
            case 'p' : tree.preorderTraversal(tree.root);cout<<endl; break;
            case 'd' : cin >> value; tree.removeNode(tree.root, value); break;
            case 't' : tree.postorderTraversal(tree.root);cout<<endl; break;
            case 'x' : loop = false; break;
            default: break;
        }
    }
}