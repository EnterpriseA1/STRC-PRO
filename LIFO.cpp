#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
        int id;
        int arrivalTime;
        int serviceTime;
        bool gotInsert;
        Node(){
            gotInsert = false;
        }
        Node (int id, int at,int st){
            this->id = id;
            this->arrivalTime = at;
            this->serviceTime = st;
            this->gotInsert = false;
    }
};
class stack{
    public:
        Node *Stack = new Node[10000];
        int top = -1;
        void push(Node newNode){
            top++;
            if (top >= 10000){
                cout<<"Stack is full"<<endl;
                return;
            }
            
            Stack[top] = newNode;
        }
        void pop(){
            if (top <= -1){
                cout<<"Stack is empty"<<endl;
                return;
            }
            top--;
        }
        void insertNode(int time, Node* arr,int n){
            for (int i = 0 ; i < n ;i++){
                if (arr[i].arrivalTime == time){
                    arr[i].gotInsert = true;
                    push(arr[i]);
                }
            }
            return;
        }
        bool allServiceEmpty(){
            for (int i = 0 ; i <= top ;i++){
                if (Stack[i].serviceTime > 0){
                    return false;
                }
            }
            return true;
        }
        void process(int* processTimer,Node* arr,int n){
            int currentProcess = top;
            while (!allServiceEmpty()){
                if (Stack[currentProcess].serviceTime <= 0){
                    pop();
                    insertNode(*(processTimer),arr,n);
                    currentProcess = top;
                }
                if (Stack[currentProcess].serviceTime > 0){
                    cout<<Stack[currentProcess].id<<" : "<<Stack[currentProcess].serviceTime<<endl;
                    Stack[currentProcess].serviceTime--;
                }
                insertNode(++(*processTimer),arr,n);
            }
        }
        
        void printAll(){
            cout<<top<<endl;
            for (int i = top; i > -1 ;i--){
                cout<<Stack[i].id<<"-"<<Stack[i].arrivalTime<<"-"<<Stack[i].serviceTime<<endl;
            }
        }
};


int main(){
    int n,id,at,st;
    cin>>n;
    int processTimer = 0;
    stack newStack;
    Node *arr = new Node[n];
    for (int i = 0 ; i < n ;i++){
        cin>>id>>at>>st;
        Node process = Node(id,at,st);
        arr[i] = process;
    }
    cout<<endl;
         newStack.insertNode(processTimer,arr,n);
    newStack.process(&processTimer,arr,n);
    ;}
