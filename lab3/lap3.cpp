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
	
	//display
		void display(){
				Node* tem=head;
				while(tem!=NULL){
					cout<<tem->data<<"->";
					tem=tem->next;
				}
				cout<<"Null\n";
			}
			
			
		//at start
		void insertAtStart(int d){
			Node* newNode=new Node(d);
			newNode->next=this->head;
			this->head=newNode;
		}
		
		// at end
		void insertAtEnd(int d)
		{
			Node* newNode=new Node(d);
			if(head==NULL){
				head=newNode;
				return;
			}
			
			Node* tem=head;
				while(tem->next!=NULL){
					tem=tem->next;
				}
				tem->next=newNode;
				
		}
};


int main(){
	LinkedList link;
	link.insertAtStart(10);
	cout << "Linked List Contents:" << endl;
   	link.display();
    link.insertAtEnd(0);
    
    
    cout << "Linked List Contents:" << endl;
   	link.display();
}
