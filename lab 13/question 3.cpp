#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* right;
    Node* left;
    Node(int d) {
        data = d;
        right = NULL;
        left = NULL;
    }
};

class DSA {
public:
    Node* head;
    DSA() {
        head = NULL;
    }

    void insert(int d) {
        if (head == NULL) {
            head = new Node(d);
            return;
        }
        Node* temp = head;
        while (true) {
            if (d > temp->data) {
                if (temp->right == NULL) {
                    temp->right = new Node(d);
                    return;
                }
                temp = temp->right;
            } else if (d < temp->data) {
                if (temp->left == NULL) {
                    temp->left = new Node(d);
                    return;
                }
                temp = temp->left;
            } else {
                cout << temp->data << " = " << d << endl;
                return;
            }
        }
    }

    void display(Node* temp) {
        cout << temp->data << " ";
    }

    void Travers() {
        bfsTraversal(head);
    }

    void bfsTraversal(Node* root) {
        if (root == NULL) return;

        const int MAX_SIZE = 100;
        Node* queue[MAX_SIZE];
        int front = 0, rear = 0;

        queue[rear++] = root;

        while (front < rear) {
            Node* current = queue[front++];
            display(current);

            if (current->left != NULL)
                queue[rear++] = current->left;

            if (current->right != NULL)
                queue[rear++] = current->right;
        }
    }
};

int main() {
    DSA me;
    me.insert(6);
    me.insert(1);
    me.insert(2);
    me.insert(3);
    me.insert(4);
    me.insert(4); // duplicate
    me.insert(5);
    
    me.insert(6); // duplicate
    me.Travers(); // BFS Traversal
}

