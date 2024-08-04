#include <iostream>

using namespace std;

class Node {
public:
    int id;
    int arrivalTime;
    int serviceTime;
    Node* next;

    Node(int id, int arrivalTime, int serviceTime) {
        this->id = id;
        this->arrivalTime = arrivalTime;
        this->serviceTime = serviceTime;
        next = NULL;
    }
};

class LinkList {
public:
    Node* head;
    Node* tail;

    LinkList() {
        head = NULL;
        tail = NULL;
    }

    void insertBack(Node* insertNode) {
        if (head == NULL) {
            head = insertNode;
            tail = insertNode;
        } else {
            tail->next = insertNode;
            tail = insertNode;
        }
        tail->next = NULL;
    }

    void process(int timeQuantum, int* processTimer, LinkList* insertQueue) {
        cout << "Doing process: " << head->id << '\n';
        int timer = 0;

        while (head->serviceTime > 0 && timer < timeQuantum) {
            head->serviceTime--;
            (*processTimer)++;
            timer++;
        }

        if (head->serviceTime == 0) {
            cout << "Eliminated Process: " << head->id << endl;
            Node* temp = head;
            head = head->next;
            delete temp;
            if (head == NULL) {
                tail = NULL;
            }
        } else {
            Node* incompleteNode = head;
            head = head->next;
            incompleteNode->next = NULL;
            insertBack(incompleteNode);
        }
    }

    void printQueue() {
        Node* temp = head;
        cout << "Processes to insert: " << endl << "=> ";
        while (temp != NULL) {
            cout << temp->id << "(" << temp->serviceTime << ")" << "[" << temp->arrivalTime << "]";
            if (temp->next != NULL) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << "\n";
    }

    void printProcess() {
        Node* temp = head;
        cout << "Processes in queue: " << endl << "=> ";
        while (temp != NULL) {
            cout << temp->id << "(" << temp->serviceTime << ")";
            if (temp->next != NULL) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << "\n\n";
    }

    Node* availableNode(int &processTimer) {
        Node* temp = head;
        Node* prev = NULL;
        while (temp != NULL) {
            if (temp->arrivalTime == processTimer) {
                if (prev == NULL) {
                    head = temp->next;
                } else {
                    prev->next = temp->next;
                }
                if (temp == tail) {
                    tail = prev;
                }
                temp->next = NULL;
                return temp;
            }
            prev = temp;
            temp = temp->next;
        }
        return NULL;
    }
};

int main() {
    LinkList* processQueue = new LinkList();
    LinkList* insertQueue = new LinkList();
    int timeQuantum = 1;
    int n;
    int id, processTimer = 0, arrivalTime, serviceTime;

    cout << "Enter Number of processes: ";
    cin >> n;
    cout << "Enter the " << n << " processes (id arrivalTime serviceTime): " << '\n';
    for (int i = 0; i < n; i++) {
        cin >> id >> arrivalTime >> serviceTime;
        Node* newNode = new Node(id, arrivalTime, serviceTime);
        insertQueue->insertBack(newNode);
    }
    insertQueue->printQueue();

    Node* startNode = insertQueue->availableNode(processTimer);
    while (startNode == NULL) {
        processTimer++;
        startNode = insertQueue->availableNode(processTimer);
    }
    processQueue->insertBack(startNode);

    while (processQueue->head != NULL || insertQueue->head != NULL) {
        cout<<"\nCPU TIME: "<<processTimer<<endl;
        if (processQueue->head != NULL) {
            processQueue->process(timeQuantum, &processTimer, insertQueue);
            if (processQueue->head != NULL) {
                processQueue->printProcess();
                 } 
        }
        else {
            Node* findAvailableNode = insertQueue->availableNode(processTimer);
            if (findAvailableNode != NULL) {
                cout<<"New process enqueue at time: "<<processTimer<<" | Process ID: "<<findAvailableNode->id<<endl;
                processQueue->insertBack(findAvailableNode);
            }
            else{
                cout<<"No processes available at time: "<<processTimer++<<endl;
            }
        }

    }
    cout << "All processes done with the total time of: " << processTimer << endl;
    return 0;
}
