#include <iostream>
using namespace std;


class Node{
	public:
		int data;
		Node* next;
		Node(int data){
			this->data=data;
			next=NULL;
		}
};

class LinkedList{
	public:
		Node* head;
		LinkedList(){
			head=NULL;
		}
		
			//at start
		void insertAtStart(int d){
			Node* newNode=new Node(d);
			newNode->next=this->head;
			this->head=newNode;
		}
	
	//display
		void display(){
				Node* tem=head;
				while(tem!=NULL){
					cout<<tem->data<<"->";
					tem=tem->next;
				}
				cout<<"Null\n";
			}
			
			
		// at specifc number:
		void insertAt(int d, int n) {
	    Node* newNode = new Node(d);
	    if (n == 1) {
	        newNode->next = head;
	        head = newNode;
	        return;
	    }
	
	    Node* tem = head;
	    int num = 1;
	    while (tem != NULL && num < n - 1) {
	        tem = tem->next;
	        num++;
	    }
	
	    if (tem == NULL) {
	        cout << "Invalid position: " << n << endl;
	        delete newNode;
	        return;
	    }
	    newNode->next = tem->next;
	    tem->next = newNode;
	}
};


int main(){
	LinkedList link;
	link.insertAtStart(10);
    link.insertAtStart(20);
    link.insertAtStart(30);
    
    link.insertAt(101,2);

    cout << "Linked List Contents:" << endl;
   	link.display();
}
