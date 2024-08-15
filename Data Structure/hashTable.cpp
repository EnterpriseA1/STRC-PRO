#include <iostream>
using std::string;
class Node
{
public:
    int key;
    string value;
    Node *next;
    Node(int key, string value)
    {
        this->key = key;
        int i = 0;
        this->value = value;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }
    void insert(int key, string value)
    {
        Node *newNode = new Node(key, value);
        Node *temp;
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        else
        {
            for (temp = head; temp != NULL; temp = temp->next)
            {
                if (temp->next == NULL)
                {
                    temp->next = newNode;
                    return;
                }
            }
        }
    }
};

class HashTable
{
public:
    LinkedList *arr = new LinkedList[17];
    void insert(int key, string value)
    {
        int index = key % 17;
        arr[index].insert(key, value);
    }
    void print()
    {
        for (int i = 0; i < 17; i++)
        {
            if (arr[i].head == NULL)
            {
                std::cout << "(-1,-)" << std::endl;
            }
            else
            {
                Node *temp;
                for (temp = arr[i].head; temp != NULL; temp = temp->next)
                {
                    std::cout << "(" << temp->key << "," << temp->value << ")" << " ";
                }
                std::cout << std::endl;
            }
        }
    }

    void search(int key)
    {
        int index = key % 17;
        if (arr[index].head == NULL)
        {
            std::cout << "-" << std::endl;
        }
        else
        {
            Node *temp;
            bool found = true;
            for (temp = arr[index].head; temp != NULL; temp = temp->next)
            {
                if (temp->key == key)
                {
                    std::cout << temp->value << std::endl;
                    return;
                }
            }
            found = false;
            if (!found)
            {
                std::cout << "-" << std::endl;
            }
        }
    }
};

int main()
{
    HashTable *ht = new HashTable();
    char input;
    string msg;
    int key;
    bool state = true;
    while (state)
    {
        std::cin >> input;
        switch (input)
        {
        case 'a':
            std::cin >> key >> msg;
            ht->insert(key, msg);
            break;
        case 'p':
            ht->print();
            break;
        case 's':
            std::cin >> key;
            ht->search(key);
            break;
        case 'e':
            state = false;
            break;
        default:
            break;
        }
    }
    return 0;
}