#include <iostream>
class Queue
{
public:
    int SIZE = 6;
    int size = 0;
    int arr[6] = {0};
    int front = 0;
    int rear = -1;

    bool empty()
    {
        if (front > rear)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    bool full()
    {
        if (rear >= SIZE-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void enqueue(int data)
    {
        if (!full())
        {
            size++;
            rear++;
            arr[rear] = data;
        }
    }

    int dequeue()
    {
        if (!empty())
        {
            int temp = arr[front];
            size--;
            front++;
            return temp;
        }
        return -1;
    }
};

int main()
{
    Queue q;
    int num = 0;
    char input = '\0';
    bool status = true;
    while (status)
    {
        std::cin >> input;
        switch (input)
        {
        case 'e':
            std::cin >> num;
            q.enqueue(num);
            break;
        case 'd':
            std::cout << q.dequeue() << std::endl;
            break;
        case 'p':
            for (int i = q.front; i <= q.rear; i++)
            {
                std::cout << q.arr[i] << " ";
            }
            std::cout << std::endl;
            break;
        case 'n':
            std::cout << q.size << std::endl;
            break;
        case 's':
            std::cout << q.arr[q.front] << " " << q.arr[q.rear] << std::endl;
            break;
        default:
            status = false;
            break;
        }
    }
    return 0;
}
