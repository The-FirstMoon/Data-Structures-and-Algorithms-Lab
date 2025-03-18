#include<iostream>
using namespace std;

class stackarr{
	public:
		int arr[100];
		int tail;
		stackarr(){
			tail=-1;
		}
		
		void push(int d){
			if(tail==99){
				return;
			}
			tail++;
			arr[tail]=d;
		}
		
		void pop(){
			if(tail==-1){
				return;
			}
			arr[tail]=0;
			tail--;
			
		}
		
		void display(){
			for(int i=0;i<=tail;i++){
				cout<<arr[i]<<" -> ";
			}
			cout<<"NULL\n\n";
		}
	};

class Node{
	public:
		int data;
		Node* next;
		Node(int d){
			data=d;
			next=NULL;
		}
		
		
};

class stacklink{
	Node* head;
	public:
	stacklink(){
		head=NULL;
 }
	
	void push(int d){
		Node* newNode=new Node(d);
		if(head==NULL){
			head=newNode;
			return;
		}
		newNode->next=head;
		head=newNode;
	}
	
	void pop(){
		if(head==NULL){
			return;
		}
		Node* temp=head;
		head=head->next;
		delete temp;
	}
	
	
	
	void display(){
		Node* temp=head;
		
		while(temp!=NULL){
			cout<<temp->data<<" -> ";
			temp=temp->next;
		}
		cout<<"NULL\n\n";
	}
};
int main(){
	
	cout<<"stack with linklist:\n";
	stacklink l1;
	l1.push(1);
	l1.push(2);
	l1.push(3);
	l1.push(4);
	l1.push(5);
	l1.display();
	l1.pop();
	l1.display();

	
	
	cout<<"stack with array:\n";
	stackarr l;
	l.push(1);
	l.push(2);
	l.push(3);
	l.push(4);
	l.push(5);
	l.display();
	l.pop();
	l.display();
	
}
