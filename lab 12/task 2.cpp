#include <iostream>
using namespace std;



class Node{
	public:
		int data;
		Node* right;
		Node* left;
		Node(int d){
			data=d;
			right=NULL;
			left=NULL;
		}
		
};
class BST{
	public:
		Node* head;
		BST(){
			head=NULL;
		}
		
		
		void insert(int d){
			if(head==NULL){
				head=new Node(d);
				return;
			}
			Node* temp=head;
			while(true){
				if(d>temp->data){
					if(temp->right==NULL){
						temp->right=new Node(d);
						return;
					}
					temp=temp->right;
				}
				else if(d<temp->data){
					if(temp->left==NULL){
						temp->left=new Node(d);
						return;
					}
					temp=temp->left;
				}
				else{
					cout<<temp->data<<"="<<d<<endl;
					return;
				}
			}
		}
		
		void display(){
			printTree(head);
			cout<<"\n\nend here\n\n";
		}
		void printTree(Node* root, int space = 0, int indent = 5) {
		    if (root == NULL) return;
		
		    space += indent;
		
		    // Print right subtree first
		    printTree(root->right, space);
		
		    // Print current node
		    cout << endl;
		    for (int i = indent; i < space; i++) cout << " ";
		    cout << root->data << "\n";
		
		    // Print left subtree
		    printTree(root->left, space);
		    
		}

		// Recursive function to calculate height of a subtree
		int getHeight(Node* root) {
		    if (root == NULL) return 0;
		    return 1 + max(getHeight(root->left), getHeight(root->right));
		}
		
		// Function to check if a node is AVL-balanced
		int isAVL(Node* node) {
		    if (node == NULL) return 0;
		
		    int leftHeight = getHeight(node->left);
		    int rightHeight = getHeight(node->right);
		    int balance = leftHeight - rightHeight;
		
		    return balance;
		}
		
		// Right Rotation
		Node* rotateRight(Node* y) {
		    Node* x = y->left;
		    Node* T2 = x->right;
		
		    x->right = y;
		    y->left = T2;
		
		    return x; // New root
		}
		
		// Left Rotation
		Node* rotateLeft(Node* x) {
		    Node* y = x->right;
		    Node* T2 = y->left;
		
		    y->left = x;
		    x->right = T2;
		
		    return y; // New root
		}


		Node* fixAVL(Node* node) {
		    if (node == NULL) return NULL;
		
		    int balance = isAVL(node);
		
		    // Left heavy
		    if (balance > 1) {
		        if (isAVL(node->left) < 0) {
		            // Left-Right Case
		            node->left = rotateLeft(node->left);
		        }
		        // Left-Left Case
		        return rotateRight(node);
		    }
		
		    // Right heavy
		    if (balance < -1) {
		        if (isAVL(node->right) > 0) {
		            // Right-Left Case
		            node->right = rotateRight(node->right);
		        }
		        // Right-Right Case
		        return rotateLeft(node);
		    }
		
		    return node; // Already balanced
		}
		
		Node* fixWholeTree(Node* node) {
		    if (node == NULL) return NULL;
		
		    // Fix left and right subtrees first
		    node->left = fixWholeTree(node->left);
		    node->right = fixWholeTree(node->right);
		
		    // Then fix this node
		    return fixAVL(node);
		}


		
	
};

int main(){
	BST me;
	me.insert(1);
	me.insert(2);
	me.insert(3);
	me.insert(4);
	me.insert(5);
	me.insert(6);
	me.insert(0);
	me.insert(-1);
	me.insert(-2);
	me.display();
	me.head=me.fixWholeTree(me.head);
	me.display();
}



