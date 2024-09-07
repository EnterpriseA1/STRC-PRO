#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        string id;
        int at,st;
        Node(){
        }
        Node(string id,int at,int st){
            this->id = id;
            this->at = at;
            this->st = st;
        }
};
class Queue{
    public:
        int front = -1;
        int rear = -1;
        vector<Node> arr;
        void enqueue(vector<Node> process,int timer){
            for (int i = 0 ; i < process.size() ; i++){
                if (process[i].at == timer){
                    if (front == -1){
                        front = 0;
                    }
                    rear++;
                    arr.push_back(process[i]);
                    return;
                }
            }
        }
        void dequeue(){
            if (front > rear){
                cout << "Queue empty" << endl;
                return;
            }
            front++;
        }
        void insertBack(Node process){
            if (front == -1){
                front = 0;   
            }
            arr.push_back(process);
            rear++;
        }
        void print(){
            for (int i = front ; i <= rear;i++){
                cout<<arr[i].id<<" ";
            }
            cout<<endl;
        }

        void process(int timeQuantum,int *processTimer,vector<Node> process){
            enqueue(process,(*processTimer));
            while(front <= rear){
                int timer = 0;
                while (timer < timeQuantum && arr[front].st > 0){
                    timer++;
                    cout << arr[front].id <<" : "<<arr[front].st<<endl;
                    arr[front].st--;
                    enqueue(process,++(*processTimer));
                }
                if (arr[front].st <= 0){
                    dequeue();
                }
                else{
                    Node temp = arr[front];
                    dequeue();
                    insertBack(temp);
                }
        }
    }
};

int main(){
    int timeQuantum = 2;
    int processTimer = 0;
    vector<Node> input;
    int n;
    string id;
    int at,st;
    cin>>n;
    for (int i = 0 ; i < n ; i ++){
        cin >> id >> at >> st;
        Node process = Node(id,at,st);
        input.push_back(process);
    }
    Queue newQueue;
    newQueue.process(timeQuantum,&processTimer,input);
    return 0;
}
