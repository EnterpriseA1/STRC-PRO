#include <iostream>
#define STACKSIZE 100
using namespace std;


class Stack {
	public:
		
		char stack[STACKSIZE] = {'\0'};
		int top = -1;	
		
		void push(char bracket){
			top++;
			if (!isFull()){
				stack[top] = bracket;
			}
			else{
				cout<<"Stack is overflow!!";
				return;
			}
		}
		char pop(){
			if (!isEmpty()){
				char temp = stack[top];
				top--;
				return temp;
			}
//			else{
//				cout<<"Stack is underflow!!";
//			}
		}
		bool isEmpty(){
			return top == -1;
		}
		bool isFull(){
			return top >= STACKSIZE;
		}
		
};

int main(){
	Stack *main = new Stack();
	char input[100];
	bool firstRightBracket = false;
	cin>>input;
	for (int i = 0 ; input[i] != '\0';i++){
		if (input[i] == '('){
			main->push(input[i]);
		}
		else if (input[i] == ')'){
			if (main->isEmpty()){
				firstRightBracket = true;
			}
			else{
				main->pop();
			}
		}
		
}
	if (main->isEmpty() && !firstRightBracket){
		cout<<"Pass";
	}
	else{
		cout<<"Error";
	}
}
