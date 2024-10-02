#include <iostream>
#include <queue> 
using namespace std;

class Vertex {
public:
    int vertex;
    int weight;
    bool visited;
    Vertex* next;
    Vertex(int vertex, int weight) {
        this->vertex = vertex;
        this->weight = weight;
        this->visited = false;
        next = NULL;
    }
};

class LinkList {
public:
    Vertex* head;
    Vertex* tail;
    LinkList() {
        head = NULL;
        tail = NULL;
    }
    void insertSorted(Vertex* insertNode) {
        if (head == NULL || head->vertex > insertNode->vertex) {
            insertNode->next = head;
            head = insertNode;
            if (tail == NULL){
                tail = insertNode;
                }
        } 
        else 
        {
            Vertex* current = head;
            while (current->next != NULL && current->next->vertex < insertNode->vertex) {
                current = current->next;
            }
            insertNode->next = current->next;
            current->next = insertNode;
            if (insertNode->next == NULL) {
                tail = insertNode;
            }
        }
    }
};
class AdjacencyList {
    public:
        LinkList* adjList;
        int size;
        
        AdjacencyList(int N) {
            size = N;
            adjList = new LinkList[N];
        }
        
        void insertVertex(int index, int vertex, int weight) {
            if (index >= 0 && index < size) {
                Vertex* newNode = new Vertex(vertex, weight);
                adjList[index].insertSorted(newNode);
            }
        }

        void DFS(int currentVertex) {
            if (adjList[currentVertex].head == NULL || adjList[currentVertex].head->visited) {
                return;
            }
            adjList[currentVertex].head->visited = true;
            cout << currentVertex << " "; 
            Vertex* temp = adjList[currentVertex].head;
            while (temp != NULL) {
                if (!adjList[temp->vertex].head->visited) {
                    DFS(temp->vertex);
                }
                temp = temp->next;
            }
        }


        void BFS(int startVertex) {
            queue<int> q;
            adjList[startVertex].head->visited = true;
            q.push(startVertex);

            while (!q.empty()) {
                int currentVertex = q.front();
                q.pop();
                cout << currentVertex << " ";

                Vertex* temp = adjList[currentVertex].head;
                while (temp != NULL) {
                    if (!adjList[temp->vertex].head->visited) {
                        adjList[temp->vertex].head->visited = true;
                        q.push(temp->vertex);
                    }
                    temp = temp->next;
                }
            }
        }

        void resetVisited() {
            for (int i = 0; i < size; i++) {
                Vertex* temp = adjList[i].head;
                while (temp != NULL) {
                    temp->visited = false;
                    temp = temp->next;
                }
            }
        }
};

int main() {
    int n;
    cin >> n;
    AdjacencyList* graph = new AdjacencyList(n);
    bool loop = true;
    bool traversalStart = false;
    char cmd;
    while (loop) {
        cin >> cmd;
        switch (cmd) {
            case 'e': {
                if (!traversalStart) {
                    int fromVertex, toVertex, weight;
                    cin >> fromVertex >> toVertex >> weight;
                    graph->insertVertex(fromVertex, toVertex, weight);
                }
                break;
            }
            case 's': {
                traversalStart = true;
                break;
            }
            case 'd': {
                int startVertex;
                cin >> startVertex;
                graph->resetVisited();
                graph->DFS(startVertex);
                cout << endl;
                break;
            }
            case 'b': {
                int startVertex;
                cin >> startVertex;
                graph->resetVisited();
                graph->BFS(startVertex);
                cout << endl;
                break;
            }
            case 'q': {
                loop = false;
                break;
            }
        }
    }


    return 0;
}
