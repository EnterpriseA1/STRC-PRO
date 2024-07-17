#include <iostream>
#define MAX_SIZE 100
class Stack
{
public:
    char arr[10];
    int top = -1;

    bool empty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool full()
    {
        if (top >= MAX_SIZE) // top >= 100
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    char pop()
    {
        if (!empty()) // not empty then do
        {
            char temp = arr[top];
            top--;
            return temp;
        }
        return '\0';
    }

    void push(char text)
    {
        if (!full())
        {
            top++;
            arr[top] = text;
        }
    }
};

int main()
{
    Stack *s = new Stack();
    char input[100];
    bool matchBracket = false; // check if Bracket matched
    std::cin >> input;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == '(')
        {
            s->push(input[i]);
        }
        else if (input[i] == ')')
        {
            if (s->empty())
            {
                matchBracket = true;
            }
            else
            {
                s->pop();
            }
        }
    }
    if (s->empty() && !matchBracket)
    {
        std::cout << "Pass";
    }
    else
    {
        std::cout << "Error";
    }
}