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
				std::cout << "found : IDindex = " << IDindex << ", id = " << id << std::endl;
				for (Node *temp = head; temp != NULL; temp = temp->next)
				{
					if (temp->id == IDindex && !(foundID(id)))
					{
						newNode->next = head;
						head = newNode;
						printA();
						return;
					}
					else
					{
						return;
					}
				}
			}
			else
			{
				std::cout << "not found : IDindex = " << IDindex << ", id = " << id << std::endl;
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
	list->insertBefore(2, 2);
	list->insertBefore(2, 3);
	list->insertBefore(2, 3);
	list->insertBefore(1, 4);
}
