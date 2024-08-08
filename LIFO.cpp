#include <iostream>
#include <vector>
using namespace std;

class Node{
	public:
		int id;
		int arrivalTime;
		int serviceTime;
		bool gotInsert;
		Node (int id, int at,int st){
			this->id = id;
			this->arrivalTime = at;
			this->serviceTime = st;
			this->gotInsert = false;
	}
};
class stack{
	public:
		vector<Node> Stack;
		int top = -1;
		void push(Node newNode){
			top++;
			if (top >= 10000){
				cout<<"Stack is full"<<endl;
				return;
			}
			
			Stack.push_back(newNode);
		}
		void pop(){
			if (top <= -1){
				cout<<"Stack is empty"<<endl;
				return;
			}
			top--;
		}
		bool availableNode(int time, vector<Node>arr){
			bool isFound = false;
			for (int i = 0 ; i <= top ;i++){
				if (arr[i].serviceTime == time){
					isFound = true;
					Stack.push_back(arr[i]);
					return isFound;
				}
			}
			return isFound;
		}
		void process(int* processTimer,vector<Node>arr){
			while (availableNode(*processTimer,arr)){
				if (Stack[top].serviceTime <= 0){
					pop();
				}
				if (Stack[top].serviceTime > 0){
					cout<<Stack[top].id<<" : "<<Stack[top].serviceTime<<endl;
					Stack[top].serviceTime--;
				}
				(*processTimer)++;
			}
		}
		
		void printAll(){
			cout<<top<<endl;
			for (int i = top; i >= 0 ;i--){
				cout<<Stack[i].id<<" "<<Stack[i].arrivalTime<<" "<<Stack[i].serviceTime<<endl;
			}
		}
};

void swap(Node* one,Node *two){
	Node temp = *one;
	*one = *two;
	*two = temp;
}
int main(){
	int n,id,at,st;
	cin>>n;
	int minAt = INT_MAX;
	int processTimer = 0;
	stack newStack;
	vector<Node>arr;
	for (int i = 0 ; i < n ;i++){
		cin>>id>>at>>st;
		Node process = Node(id,at,st);
		arr.push_back(process);
	}

	newStack.printAll();
	cout<<endl;
	newStack.process(&processTimer,arr);

	;}
/*
4
1010
2
3
2002
0
4
3030
4
3
4040
3
2*/

