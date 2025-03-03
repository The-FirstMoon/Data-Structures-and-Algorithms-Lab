#include <iostream>
using namespace std;


class Node{
	public:
		int data;
		Node* next;
		Node* prev;
		Node(int data){
			this->data=data;
			next=NULL;
			prev=NULL;
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
			Node* temp=head;
			
			do{
				cout<<temp->prev<<" | ";
			
				cout<<temp->data;
				
				cout<<" | "<<temp->next;
				
				if(temp->next!=head){
					cout<<" <-> ";
				}
				else{
					cout<<" <-> head again ";
				}
				temp=temp->next;
			}while(temp!=head);
			
			cout<<endl;
		}
		
		// display reverse
		void DisplayReverse() {
		    Node* temp = head->prev;
		    
		
		    
		    do {
		        
				
					cout<<temp->next<<" | ";
				
				cout<<temp->data;
				
					cout<<" | "<<temp->prev;
				
				if(temp->prev!=head->prev){
					cout<<" <-> ";
				}
				else{
					cout<<" <-> Backnode again ";
				}
		        temp = temp->prev;
		    }while (temp != head->prev);
		    cout << endl;
		}
		
		//insert at start
		void InsertAtStart(int d){
			Node* newNode= new Node(d);
			if(head==NULL){
				head=newNode;
				newNode->prev=head;
				newNode->next=head;
				return;
			}
			newNode->next=head;
			head->prev->next=newNode;
			newNode->prev=head->prev;
			head->prev=newNode;
			head=newNode;
		}
		
		
		//insert at end
		void InsertAtEnd(int d){
			Node* newNode= new Node(d);
			if(head==NULL){
				InsertAtStart(d);
				return;	
			}
			
			Node* temp=head->prev;
			
			temp->next=newNode;
			newNode->prev=temp;
			newNode->next=head;
			head->prev=newNode;
		}
			//insert at any
		void InsertAt(int d, int num){
			Node* newNode= new Node(d);
			if(head==NULL){
				if(num==1){
					InsertAtStart(d);
					
				}
				else{
					cout<<"Invaild Number/n";
					delete newNode;
					newNode=NULL;
					
				}
				return;
			}
			
			if(num==1){
				newNode->next=head;
				head->prev->next=newNode;
				newNode->prev=head->prev;
				head->prev=newNode;
				head=newNode;
				return;
			}
			
			Node* temp=head;
			for(int i=1;i<num-1;i++){
				temp=temp->next;
				if(temp=NULL){
					cout<<"Invaild Number\n";
					return;
				}	
			}
			newNode->prev=temp;
			newNode->next=temp->next;
			temp->next->prev=newNode;
			temp->next=newNode;
		}
	
		
		
		
		//insert at center
		void InsertAtCenter(int d){
			Node* newNode=new Node(d);
			if(head==NULL){
				head=newNode;
				return;
			}
			int num=0;
			Node* temp=head;
			while(temp->next!=head){
				num++;
				temp=temp->next;
			}
			
			num=num/2;
			for(int i=1;i<num+1;i++){
				temp=temp->prev;
			}
			newNode->prev=temp;
			newNode->next=temp->next;
			temp->next->prev=newNode;
			temp->next=newNode;
			return;
		}

		
		
	};
	
	
	int main(){
		LinkedList list;
		
		
		cout<<"After insert at start: \n";
		list.InsertAtStart(1);
		list.display();
		
		cout<<"\nAfter insert at end: \n";
		list.InsertAtEnd(4);
		list.display();
		
		cout<<"\nAfter insert at 2th: \n";
		list.InsertAt(2,2);
		list.display();
		
		cout<<"\nAfter insert at center: \n";
		list.InsertAtCenter(3);
		list.display();
		
		
		cout<<"\ndisplay in order: \n";
		list.display();
		
		cout<<"\ndisplay in revers order: \n";
		list.DisplayReverse();
	}
