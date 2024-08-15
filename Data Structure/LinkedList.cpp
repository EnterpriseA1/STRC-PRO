#include <iostream>
class Node
{
public:
	int id;
	Node *next;
	Node()
	{
		next = NULL;
	}
	Node(int i)
	{
		this->id = i;
		next = NULL;
	}
};
class List
{
public:
	Node *head;
	List()
	{
		head = NULL;
	}

	bool foundID(int id)
	{
		Node *temp;
		for (temp = head; temp != NULL; temp = temp->next)
		{
			if (temp->id == id)
			{
				return true;
			}
		}
		return false;
	}

	void insertBefore(int IDindex, int id)
	{
		if (foundID(id))
		{
			return;
		}
		Node *newNode = new Node(id);
		if (head == NULL)
		{
			head = newNode;
			printA();
			return;
		}
		else
		{
			if (head->id == IDindex)
			{
				newNode->next = head;
				head = newNode;
				printA();
				return;
			}
			if (foundID(IDindex))
			{
				for (Node *temp = head; temp != NULL; temp = temp->next)
				{
					if (temp->next->id == IDindex)
					{
						newNode->next = temp->next;
						temp->next = newNode;
						printA();
						return;
					}
				}
			}
			else
			{
				for (Node *temp = head; temp != NULL; temp = temp->next)
				{
					if (temp->next == NULL)
					{
						temp->next = newNode;
						printA();
						return;
					}
				}
			}
		}
	}

	void insertAfter(int IDindex, int id)
	{
		Node *newNode = new Node(id);
		if (head == NULL)
		{
			head = newNode;
			printA();
			return;
		}
		else
		{
			if (foundID(IDindex))
			{
				for (Node *temp = head; temp != NULL; temp = temp->next)
				{
					if (temp->id == IDindex && !(foundID(id)))
					{
						newNode->next = temp->next;
						temp->next = newNode;
						printA();
						return;
					}
				}
			}
			else
			{
				for (Node *temp = head; temp != NULL; temp = temp->next)
				{
					if (temp->next == NULL)
					{
						temp->next = newNode;
						printA();
						return;
					}
				}
			}
		}
	}

	void deleteNode(int IDindex)
	{
		if (head->next == NULL)
		{
			printA();
			return;
		}
		if (head->id == IDindex)
		{
			head = head->next;
			printA();
			return;
		}
		if (foundID(IDindex))
		{
			for (Node *temp = head; temp != NULL; temp = temp->next)
			{
				if (temp->next->id == IDindex)
				{
					temp->next = temp->next->next;
					printA();
					return;
				}
			}
		}
		else
		{
			return;
		}
	}

	void printA()
	{
		Node *temp;
		for (temp = head; temp != NULL; temp = temp->next)
		{
			std::cout << temp->id << " ";
		}
		std::cout << std::endl;
	}
};

int main()
{
	List *list = new List();
	char input;
	int id, index;
	bool state = true;
	while (state)
	{
		std::cin >> input;
		switch (input)
		{
		case 'D':
			std::cin >> index;
			list->deleteNode(index);
			break;
		case 'I':
			std::cin >> id;
			std::cin >> index;
			list->insertBefore(index, id);
			break;
		case 'A':
			std::cin >> id;
			std::cin >> index;
			list->insertAfter(index, id);
			break;
		case 'E':
			state = false;
			break;
		default:
			break;
		}
	}

	return 0;
}
