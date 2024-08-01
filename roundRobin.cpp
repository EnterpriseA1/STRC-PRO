#include <iostream>

using namespace std;

class Node{
	public:
		int id;
        int arrivalTime;
        int serviceTime;
		Node* next;
		Node(int id,int arrivalTime,int serviceTime){
			this->id = id;
            this->arrivalTime = arrivalTime;
            this->serviceTime = serviceTime;
			next = NULL;
		}
};
class LinkList{
	public:
		Node* head;
        Node* tail;
		LinkList(){
			head = NULL;
            tail = NULL;
		}
        void insertBack(Node* insertNode){
            if(head == NULL){
                head = insertNode;
                tail = insertNode;
            }
            else{
                tail->next = insertNode;
                tail = insertNode;
            }
            tail->next = NULL;
        }
        void process(int timeQuantum){
            cout<<"Doing process: "<<head->id<<'\n';
            int timer = 0;
            while (head->serviceTime > 0 && timer < timeQuantum){
                (head->serviceTime)--;
                timer++;
            }
            if(head->serviceTime == 0){
                cout<<"Eliminated Process: "<<head->id<<endl;
                head = head->next;
                if (head == NULL){
                    tail = NULL;
                }
            }
            else{
                Node* incompleteNode = head;
                head = head->next;
                insertBack(incompleteNode);
            }
        }
		void printQueue(){
            Node* temp = head;
            cout<<"Process to insert : "<<endl<<"=> ";
            while (temp != NULL)
            {
                cout<<temp->id <<"("<< temp->serviceTime <<")"<<
                "["<<temp->arrivalTime<<"]";

                if (temp->next != NULL) {
                    cout << " -> ";
                }   
                temp = temp->next;
            }
            cout<<"\n";
        }
        void printProcess(){
            Node* temp = head;
            cout<<"Process in queue :\n"<<endl<<"=> ";
            while (temp != NULL)
            {
                cout<<temp->id <<"("<< temp->serviceTime <<")";
                if (temp->next != NULL) {
                    cout << " -> ";
                }   
                temp = temp->next;
            }
            cout<<"\n\n";
        }
        Node* minArrivalNode(){
            Node* temp = head;
            Node* minArrival = NULL;
            double minArrivalTime = 1e+10;
            while (temp != NULL){
                if( temp->arrivalTime < minArrivalTime && temp->arrivalTime >= 0){
                    minArrival = temp;
                    minArrivalTime = temp->arrivalTime;
                 }
                 temp = temp->next;
            }
            if (minArrival != NULL){
                if (minArrival == head){
                    head = head->next;
                }
                else{
                    Node *deltemp = head;
                    while (deltemp->next != minArrival && deltemp->next != NULL){
                        deltemp = deltemp->next;
                    }
                    deltemp->next = minArrival->next;
                }
            }
            return minArrival;
        }
};

int main(){
    LinkList *processQueue = new LinkList();
    LinkList *insertQueue = new LinkList();
    int timeQuantum = 3;
    int n;
    int id, arrivalTime, serviceTime;
    cout << "Enter Number of processes: ";
    cin >> n;
    cout << "Enter the " << n << " processes (id arrivalTime serviceTime): " << '\n';
    for (int i = 0; i < n; i++) {
        cin >> id >> arrivalTime >> serviceTime;
        Node* newNode = new Node(id, arrivalTime, serviceTime);
        insertQueue->insertBack(newNode);
    }
    insertQueue->printQueue();
    while (true) {
        Node* minNode = insertQueue->minArrivalNode();
        if (minNode == NULL) {
            break;
        }
        processQueue->insertBack(minNode);
    }
    
    processQueue->printProcess();
    while (processQueue->head != NULL) {
        processQueue->process(timeQuantum);
        if (processQueue->head != NULL) {
            processQueue->printProcess();
        }
        else{
            cout<<"\nAll processes done!"<<endl;
            break;
        }
    }

    return 0;
}
