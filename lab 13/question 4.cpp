#include <iostream>
using namespace std;

class GraphNode;

// Node in the adjacency list
class ListNode {
public:
    GraphNode* neighbor;
    ListNode* next;

    ListNode(GraphNode* n) {
        neighbor = n;
        next = NULL;
    }
};

// Graph node
class GraphNode {
public:
    int data;
    ListNode* adjList;
    bool visited;

    GraphNode(int d) {
        data = d;
        adjList = NULL;
        visited = false;
    }

    void addNeighbor(GraphNode* n) {
        ListNode* newNode = new ListNode(n);
        newNode->next = adjList;
        adjList = newNode;
    }

    void printNeighbors() {
        cout << "Node " << data << " connected to: ";
        ListNode* temp = adjList;
        while (temp != NULL) {
            cout << temp->neighbor->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Simple array-based queue
class NodeQueue {
    GraphNode** arr;
    int front, rear, size;

public:
    NodeQueue(int capacity) {
        arr = new GraphNode*[capacity];
        front = 0;
        rear = 0;
        size = capacity;
    }

    bool isEmpty() {
        return front == rear;
    }

    void enqueue(GraphNode* node) {
        if (rear < size) {
            arr[rear++] = node;
        }
    }

    GraphNode* dequeue() {
        if (!isEmpty()) {
            return arr[front++];
        }
        return NULL;
    }

    ~NodeQueue() {
        delete[] arr;
    }
};

// BFS function
void bfs(GraphNode* start) {
    if (start == NULL) return;

    const int MAX_NODES = 100; // You can adjust based on expected graph size
    NodeQueue q(MAX_NODES);

    start->visited = true;
    q.enqueue(start);

    while (!q.isEmpty()) {
        GraphNode* current = q.dequeue();
        cout << current->data << " ";

        ListNode* temp = current->adjList;
        while (temp != NULL) {
            if (!temp->neighbor->visited) {
                temp->neighbor->visited = true;
                q.enqueue(temp->neighbor);
            }
            temp = temp->next;
        }
    }
}

int main() {
    // Create nodes
    GraphNode* A = new GraphNode(1);
    GraphNode* B = new GraphNode(2);
    GraphNode* C = new GraphNode(3);
    GraphNode* D = new GraphNode(4);
    GraphNode* G = new GraphNode(5);
    GraphNode* F = new GraphNode(6);
    GraphNode* E = new GraphNode(7);

    // Connect nodes (undirected graph example)
    A->addNeighbor(B);
    A->addNeighbor(C);
    B->addNeighbor(A);
    B->addNeighbor(D);
    C->addNeighbor(A);
    D->addNeighbor(B);
    D->addNeighbor(G);
    C->addNeighbor(F);
    F->addNeighbor(E);

    // Print graph
    A->printNeighbors();
    B->printNeighbors();
    C->printNeighbors();
    D->printNeighbors();
    G->printNeighbors();
    F->printNeighbors();
    E->printNeighbors();

    // Perform BFS from node A
    cout << "\nBFS traversal: ";
    bfs(A);
    cout << endl;

    return 0;
}

