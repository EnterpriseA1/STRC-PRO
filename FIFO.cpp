#include <iostream>
#define QUEUESIZE 100;
using namespace std;

class Node{
	public:
		int value;
		Node* next;
		Node(int value){
			this->value = value;
			next = NULL;
		}
};
class LinkList{
	public:
		Node* head;
		LinkList(){
			head = NULL;
		}
		void insertBefore(int value,int timequantum){
			if (head == NULL){
			}
		}
		void createDuplicate(int value,int serviceTime){
			Node* temp;
			for (int i = 0 ; i < serviceTime;i++){
				Node* newNode = new Node(value);
				if (head == NULL){
					head = newNode;
				}
				else{
					Node* temp = head;
					while (temp->next != NULL){
						temp = temp->next;
					}
					temp->next = newNode;
				}
			}
		}
		void printAll(){
            Node* temp = head;
            while (temp != NULL)
            {
                cout<< temp->value <<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
};
//class Queue{
//	public:
//		LinkList *queue = new LinkList();
//		
//};

int main(){
	LinkList* linklist = new LinkList(); 
	linklist->createDuplicate(6,2);
	linklist->createDuplicate(9,2);
	linklist->printAll();
}
