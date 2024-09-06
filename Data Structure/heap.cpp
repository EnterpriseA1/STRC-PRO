#include <iostream>
class Heap
{
public:
    int queue[1000];
    Heap()
    {
        queue[0] = 0;
    }
    void insert(int n)
    {
        if (queue[0] < 999)
        {
            queue[0]++;
            queue[queue[0]] = n;
            int i = queue[0];
            while (i > 1 && queue[i / 2] < queue[i])
            {
                int temp = queue[i / 2];
                queue[i / 2] = queue[i];
                queue[i] = temp;
                i = i / 2;
            }
        }
    }

    int remove()
    {
        if (queue[0] > 0)
        {
            int root = queue[1];
            queue[1] = queue[queue[0]];
            queue[0]--;
            int parent = 1;
            while (parent <= queue[0])
            {
                int left = 2 * parent;
                int right = 2 * parent + 1;
                if (left <= queue[0] && queue[left] > queue[parent] && queue[left] >= queue[right])
                {
                    int temp = queue[left];
                    queue[left] = queue[parent];
                    queue[parent] = temp;
                    parent = left;
                }
                else if (right <= queue[0] && queue[right] > queue[parent])
                {
                    int temp = queue[right];
                    queue[right] = queue[parent];
                    queue[parent] = temp;
                    parent = right;
                }
                else
                {
                    break;
                }
            }
            return root;
        }
        else
        {
            return 0;
        }
    }

    void print()
    {
        for (int i = 1; i <= queue[0]; i++)
        {
            std::cout << queue[i] << " ";
        }
        std::cout << std::endl;
    }
};
int main()
{
    Heap h;
    bool state = true;
    char input;
    int n;
    while (state)
    {
        std::cin >> input;
        switch (input)
        {
        case 'a':
            std::cin >> n;
            h.insert(n);
            break;
        case 'p':
            h.print();
            break;
        case 'd':
            std::cout << h.remove() << std::endl;
            break;
        case 'e':
            state = false;
            break;
        default:
            break;
        }
    }
}