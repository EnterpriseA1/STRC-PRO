#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    Node *left;
    Node *right;
    int value = 0;
    int height = 0;
    Node(int v)
    {
        value = v;
        left = NULL;
        right = NULL;
        height = 0;
    }
};
class AVL
{
public:
    Node *root;
    AVL()
    {
        root = NULL;
    }

    int height(Node *node)
    {
        return node == NULL ? -1 : node->height;
    }

    int getImbalance(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return height(node->left) - height(node->right);
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *z = y->left;
        y->left = x;
        x->right = z;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }

    Node *rightRotate(Node *x)
    {
        Node *y = x->left;
        Node *z = y->right;
        y->right = x;
        x->left = z;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }

    Node *insert(Node *root, int value)
    {
        if (root == NULL)
        {
            return new Node(value);
        }

        if (value < root->value)
        {
            root->left = insert(root->left, value);
        }
        else if (value > root->value)
        {
            root->right = insert(root->right, value);
        }
        else
        {
            return root;
        }

        root->height = max(height(root->left), height(root->right)) + 1;
        int imbalance = getImbalance(root);
        if (imbalance > 1)
        {
            if (value < root->left->value)
            { // left-left
                return rightRotate(root);
            }
            else
            { // left-right
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }
        else if (imbalance < -1)
        {
            if (value < root->right->value)
            { // right-left
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
            else
            { // right-right
                return leftRotate(root);
            }
        }
        return root;
    }

    Node *getSuccessor(Node *curr)
    {
        curr = curr->right;
        while (curr != NULL && curr->left != NULL)
            curr = curr->left;
        return curr;
    }

    Node *delNode(Node *root, int value)
    {
        if (root == NULL)
        {
            return root;
        }

        if (value < root->value)
        {
            root->left = delNode(root->left, value);
        }
        else if (value > root->value)
        {
            root->right = delNode(root->right, value);
        }
        else
        {
            if (root->left == NULL)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }

            if (root->right == NULL)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }

            Node *succ = getSuccessor(root);
            root->value = succ->value;
            root->right = delNode(root->right, succ->value);
        }

        root->height = max(height(root->left), height(root->right)) + 1;
        int imbalance = getImbalance(root);
        if (imbalance > 1)
        {
            if (getImbalance(root->left) >= 0)
            {
                return rightRotate(root);
            }
            else
            {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }
        else if (imbalance < -1)
        {
            if (getImbalance(root->right) <= 0)
            {
                return leftRotate(root);
            }
            else
            {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }
        return root;
    }

    void preorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->value << " ";
        preorder(root->left);
        preorder(root->right);
    }
};

int main()
{
    AVL *newTree = new AVL();
    bool state = true;
    int value = 0;
    char input = '\0';
    while (state)
    {
        cin >> input;
        switch (input)
        {
        case 'a':
            cin >> value;
            newTree->root = newTree->insert(newTree->root, value);
            break;
        case 'd':
            cin >> value;
            newTree->root = newTree->delNode(newTree->root, value);
            break;
        case 'p':
            newTree->preorder(newTree->root);
            cout << endl;
            break;
        case 'x':
            state = false;
            break;
        }
    }
}
