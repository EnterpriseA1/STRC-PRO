#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
	Node *left;
	Node *right;
	int value = 0;
	Node(int v)
	{
		value = v;
		left = NULL;
		right = NULL;
	}
};
class Tree
{
public:
	Node *root;
	Tree()
	{
		root = NULL;
	}
	Node *insert(Node *root, int value)
	{
		if (root == NULL)
		{
			return new Node(value);
		}
		if (value < root->value)
		{
			if (root->left == NULL)
			{
				root->left = new Node(value);
			}
			else
			{
				insert(root->left, value);
			}
		}
		else
		{
			if (root->right == NULL)
			{
				root->right = new Node(value);
			}
			else
			{
				insert(root->right, value);
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
		return root;
	}
	void breadthfirst(Node *root)
	{
		if (root == NULL)
			return;
		queue<Node *> q;
		q.push(root);
		int depth = 0;

		while (q.empty() == false)
		{
			int size = q.size();
			if (depth != 0)
			{
				cout << "|";
			}
			for (int i = 0; i < size; i++)
			{
				Node *node = q.front();
				cout << node->value << ",";
				q.pop();
				if (node->left != NULL)
					q.push(node->left);
				if (node->right != NULL)
					q.push(node->right);
			}
			depth++;
		}
		cout << "|";
	}

	void inorder(Node *root)
	{
		if (root == NULL)
		{
			return;
		}
		inorder(root->left);
		cout << root->value << ",";
		inorder(root->right);
	}
	void preorder(Node *root)
	{
		if (root == NULL)
		{
			return;
		}
		cout << root->value << ",";
		preorder(root->left);
		preorder(root->right);
	}
	void postorder(Node *root)
	{
		if (root == NULL)
		{
			return;
		}
		postorder(root->left);
		postorder(root->right);
		cout << root->value << ",";
	}
};
int main()
{
	Tree newTree = Tree();
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
			newTree.root = newTree.insert(newTree.root, value);
			break;
		case 'd':
			cin >> value;
			newTree.delNode(newTree.root, value);
			break;
		case 'b':
			newTree.breadthfirst(newTree.root);
			cout << endl;
			break;
		case 'i':
			newTree.inorder(newTree.root);
			cout << endl;
			break;
		case 'p':
			newTree.preorder(newTree.root);
			cout << endl;
			break;
		case 't':
			newTree.postorder(newTree.root);
			cout << endl;
			break;
		case 'x':
			state = false;
			break;
		}
	}
}
