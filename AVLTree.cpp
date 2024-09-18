#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
        int height;
		Node(){
			left = NULL;
			right = NULL;
            height = 0;
		}
		Node(int value){
			data = value;
			left = NULL;
			right = NULL;
            height = 0;
		}
};
class AVLtree{
    public:
        Node* root;
        AVLtree(){
            root = NULL;
        }

        int height(Node* currentNode) {
            if (currentNode == NULL) {
                return -1; 
            }
            return currentNode ->height;
        }

        int getBalanceFactor(Node* currentNode ) {
            if (currentNode  == NULL) {
                return 0;
            }
            return height(currentNode->left) - height(currentNode->right);
        }

        Node* rightRotate(Node* y) {
            Node* x = y->left;
            Node* T2 = x->right;
            x->right = y;
            y->left = T2;
            y->height = max(height(y->left), height(y->right)) + 1;
            x->height = max(height(x->left), height(x->right)) + 1;
            return x;
        }

        Node* leftRotate(Node* x) {
            Node* y = x->right;
            Node* T2 = y->left;
            y->left = x;    
            x->right = T2;
            x->height = max(height(x->left), height(x->right)) + 1;
            y->height = max(height(y->left), height(y->right)) + 1;
            return y;
        }

        Node* insertNode(Node* currentNode, int value) {
            if (currentNode == NULL) {
                return new Node(value);
            }

            if (value < currentNode->data) {
                currentNode->left = insertNode(currentNode->left, value);
            } else if (value > currentNode->data) {
                currentNode->right = insertNode(currentNode->right, value);
            } else {
                return currentNode;
            }

            currentNode->height = 1 + max(height(currentNode->left), height(currentNode->right));
            int balance = getBalanceFactor(currentNode);
            if (balance > 1 && value < currentNode->left->data) { // LeftHeavy ,RightRotation
                return rightRotate(currentNode);
            }

            if (balance < -1 && value > currentNode->right->data) {// RightHeavy ,LeftRotation
                return leftRotate(currentNode);
            }

            if (balance > 1 && value > currentNode->left->data) { // LeftHeavy ,LR-Double Rotation
                currentNode->left = leftRotate(currentNode->left);
                return rightRotate(currentNode);
            }

            if (balance < -1 && value < currentNode->right->data) { //RightHeavy ,RL-Double Rotation
                currentNode->right = rightRotate(currentNode->right);
                return leftRotate(currentNode);
            }
            return currentNode;
        }

        void insert(int value) {
            root = insertNode(root, value);
        }

        void preorderTraversal(Node *currentNode){
            if (currentNode == NULL){
                return;
            } 
            cout << currentNode->data << " ";
            preorderTraversal(currentNode->left);
            preorderTraversal(currentNode->right);
        }
        Node* minValueNode(Node* currentNode) {
            Node* temp = currentNode;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            return temp;
            }

        Node* deleteNode(Node* currentRoot, int value) {
            if (currentRoot == NULL){
                return NULL;
            }
            if (value < currentRoot->data){
                currentRoot->left = deleteNode(currentRoot->left, value);
            }
            else if (value > currentRoot->data){
                currentRoot->right = deleteNode(currentRoot->right, value);
            }
            else{
                if (currentRoot->left == NULL && currentRoot->right == NULL){
                    return NULL;
                }
                else if (currentRoot->left == NULL && currentRoot->right != NULL){
                    return currentRoot->right;
                }
                else if (currentRoot->left != NULL && currentRoot->right == NULL){
                    return currentRoot->left;
                }
                else{
                    Node* temp = minValueNode(currentRoot->right);
                    currentRoot->data = temp->data;
                    currentRoot->right = deleteNode(currentRoot->right, temp->data);
                }
            }
            currentRoot->height = 1 + max(height(currentRoot->left), height(currentRoot->right));
            int balance = getBalanceFactor(currentRoot);

            if (balance > 1 && getBalanceFactor(currentRoot->left) >= 0) {
                return rightRotate(currentRoot);
            }

            if (balance > 1 && getBalanceFactor(currentRoot->left) < 0) {
                currentRoot->left = leftRotate(currentRoot->left);
                return rightRotate(currentRoot);
            }

            if (balance < -1 && getBalanceFactor(currentRoot->right) <= 0) {
                return leftRotate(currentRoot); 
            }

            if (balance < -1 && getBalanceFactor(currentRoot->right) > 0) {
                currentRoot->right = rightRotate(currentRoot->right); 
                return leftRotate(currentRoot);
            }

            return currentRoot;
        }
        void deleteValue(int value) {
            root = deleteNode(root, value);
        }
};

int main(){
    char c;
    int value;
    AVLtree tree;
    bool loop = true;
    while (loop){
        cin >> c;
        switch(c){
            case 'a' : cin >> value; tree.insert(value); break;
            case 'p' : tree.preorderTraversal(tree.root); cout << endl; break;
            case 'd' : cin >> value; tree.deleteValue(value); break;
            case 'x' : loop = false; break;
            default : break;
        }
    }

}