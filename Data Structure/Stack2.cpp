#include <iostream>
class stack
{
public:
	int arr[5];
	int top = -1;

	bool empty()
	{
		return top == -1;
	}

	bool full()
	{
		if (top >= 4)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void push(int data)
	{
		if (!full())
		{
			top++;
			arr[top] = data;
		}
	}

	void pop()
	{
		if (!empty())
		{
			int temp = arr[top];
			top--;
			std::cout << temp << std::endl;
		}
	}

	void showTop()
	{
		std::cout << arr[top] << std::endl;
	}

	void showData()
	{ // P
		for (int i = 0; i <= top; i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}

	void showSize()
	{
		int temp = 0;
		for (int i = 0; i <= top; i++)
		{
			temp++;
		}
		std::cout << temp << std::endl;
	}
};

int main()
{
	stack s;
	char input;
	bool state = true;
	int temp = 0;
	while (state)
	{
		std::cin >> input;
		switch (input)
		{
		case 'U':
			std::cin >> temp;
			s.push(temp);
			break;
		case 'O':
			s.pop();
			break;
		case 'T':
			s.showTop();
			break;
		case 'P':
			s.showData();
			break;
		case 'N':
			s.showSize();
			break;
		case 'X':
			state = false;
			break;
		}
	}
	return 0;
}
