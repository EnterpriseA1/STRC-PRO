#include <iostream>
using namespace std;

class Node {
public:
    int id;
    int arrivalTime;
    int serviceTime;
    Node() {}
    Node(int id, int at, int st) {
        this->id = id;
        this->arrivalTime = at;
        this->serviceTime = st;
    }
};

class Stack {
public:
    Node* Stack = new Node[10000];
    int top = -1;
    void push(Node newNode) {
        if (top >= 10000 - 1) {
            cout << "Stack is full" << endl;
            return;
        }
        top++;
        Stack[top] = newNode;
    }
    void pop() {
        if (top <= -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        top--;
    }
    void insertNode(int time, Node* arr, int n) {
        for (int i = 0; i < n; i++) {
            if (arr[i].arrivalTime == time) {
                push(arr[i]);
                return;
            }
        }
    }
    bool allServiceEmpty() {
        int marker = top;
        while (marker >= 0){
            if (Stack[marker].serviceTime > 0) {
                return false;
            }
            marker--;
        }
        return true;
    }
    void process(int* processTimer, Node* arr, int n) {
        insertNode(*(processTimer),arr,n);
        int currentProcess = top;
        while (!allServiceEmpty()) {
            if ( Stack[currentProcess].serviceTime < 1) {
                if (currentProcess != top){
                    currentProcess = top;
                }
                else{
                    pop();
                    currentProcess = top;
                }
            } 
            else{
                cout << Stack[currentProcess].id << " : " << Stack[currentProcess].serviceTime << endl;
                Stack[currentProcess].serviceTime--;
                insertNode(++(*processTimer), arr, n);
            }
        }
    }
};

int main() {
    int n, id, at, st;
    cin >> n;
    int processTimer = 0;
    Stack newStack;
    Node* arr = new Node[n];
    for (int i = 0; i < n; i++) {
        cin >> id >> at >> st;
        Node process = Node(id, at, st);
        arr[i] = process;
    }
    cout << endl;
    newStack.process(&processTimer, arr, n);
    return 0;
}
