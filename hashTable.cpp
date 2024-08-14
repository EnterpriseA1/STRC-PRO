#include <iostream>
using namespace std;

class Node{
    public:
        int key;
        char value[100];
        Node *next;
        Node(int key,char value[]){
            this->key = key;
            int i = 0;
            while (value[i] != '\0' && i < 99) {
                this->value[i] = value[i];
                i++;
            }
            this->value[i] = '\0';
            next = NULL;
        }
};
class Linklist{
    public:
        Node *head;
        Node *tail;
        Linklist(){
            head = NULL;
            tail = NULL;
        }
        void insertBack(int key,char value []){
            Node *newNode = new Node(key,value);
            if(head == NULL){
                head = newNode;
                tail = newNode;
            }else{
                tail->next = newNode;
                tail = newNode;
            }
            tail->next = NULL;
        }
};
class hashTable{
    public:
        Linklist *arr = new Linklist[17];
        int hash(int key){
            return key % 17;
        }
        void insert(int key,char value[]){
            int index = hash(key);
            arr[index].insertBack(key,value);

        }
        void printAll(){
            for (int i = 0; i < 17; i++) {
                if (arr[i].head == NULL){
                    cout<<"(-1,-)"<<endl;
                }
                else{
                    Node *temp = arr[i].head;
                    while (temp != NULL) {
                        cout<<"("<<temp->key<<","<<temp->value<<") ";
                        temp = temp->next;
                    }
                    cout<<endl;
                }
             }    
        }
        void searchItem (int key){
            int index = hash(key);
            if (arr[index].head != NULL){
                Node *temp = arr[index].head;
                if (temp->key == key){
                	cout<<temp->value<<endl;
                    return;
                }
                while (temp->key != key && temp->next != NULL){
					temp = temp->next;
				}
                if (temp->next == NULL && temp->key != key){
                    cout<<'-'<<endl;
                }
                else{
                    cout<<temp->value<<endl;
                }
                return;
            }
            else{
                cout<<'-'<<endl;
            }
        }

};
int main(){
    char value[100];
    int key;
    bool loop = true;
    hashTable *newHash = new hashTable();
    char command;
    while (loop) {
        cin>>command;
        switch (command){
            case 'a' : cin >> key >> value; newHash->insert(key,value) ; break;
            case 'p' : newHash->printAll(); break;
            case 's' : cin >> key;newHash->searchItem(key); break;
            case 'e' : loop = false; break;
            default:break;
        }
        
    }
}
