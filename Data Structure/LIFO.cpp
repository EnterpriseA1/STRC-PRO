#include <iostream>
class Node
{
public:
    int pid;
    int arriv;
    int serv;
    Node()
    {
        pid = INT_MIN;
        arriv = INT_MIN;
        serv = INT_MIN;
    }
};
class Stackk
{
public:
    int top = -1;
    int size = 99;
    Node process[100];
    bool full()
    {
        return top == size;
    }
    bool empty()
    {
        return top == -1;
    }
    Node pop()
    {
        Node temp;
        if (!empty())
        {
            temp = process[top--];
            return temp;
        }
        return Node();
    }
    void push(Node data)
    {
        if (!full())
        {
            top++;
            process[top] = data;
            return;
        }
    }
    int totalServ()
    {
        int temp = 0;
        int i = 0;
        while (i <= top)
        {
            temp += process[i].serv;
            i++;
        }
        return temp;
    }
    void calcServ()
    {
        Stackk s;
        int totalService = totalServ();
        int i = 0;
        while (i <= totalService)
        {
            if (i == process[top].arriv && (!empty()))
            {
                s.push(pop());
                int replicaTop = s.top;
                int servTime = s.process[replicaTop].serv;
                int pid = s.process[replicaTop].pid;
                for (int j = 0; j < servTime; j++)
                {
                    if (i == process[top].arriv && (!empty()))
                    {
                        s.push(pop());
                    }
                    std::cout << pid << " : " << s.process[replicaTop].serv << std::endl;
                    s.process[replicaTop].serv--;
                    i++;
                    if (s.process[s.top].serv <= 0)
                    {
                        s.pop();
                    }
                }
            }
            else
            {
                if (s.empty())
                {
                    break;
                }
                else
                {
                    int servTime = s.process[s.top].serv;
                    int pid = s.process[s.top].pid;
                    for (int j = 0; j < servTime; j++)
                    {
                        std::cout << pid << " : " << s.process[s.top].serv << std::endl;
                        s.process[s.top].serv--;
                        i++;
                    }
                    if (s.process[s.top].serv <= 0)
                    {
                        s.pop();
                    }
                }
            }
        }
    }
};
int main()
{
    Stackk s;
    Node inputNode;
    int processNumber;

    std::cin >> processNumber;
    for (int i = 0; i < processNumber; i++)
    {
        std::cin >> inputNode.pid;
        std::cin >> inputNode.arriv;
        std::cin >> inputNode.serv;
        s.push(inputNode);
    }

    for (int i = 0; i <= s.top; i++)
    {
        for (int j = 0; j <= s.top; j++)
        {
            Node temp;
            if (s.process[j].arriv < s.process[j + 1].arriv)
            {
                temp = s.process[j];
                s.process[j] = s.process[j + 1];
                s.process[j + 1] = temp;
            }
        }
    }
    s.calcServ();
}
