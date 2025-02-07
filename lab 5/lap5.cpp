
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
			cout<<"NULL\n";
		}
		
			//at start
		void insertAtStart(int d){
			Node* newNode=new Node(d);
			newNode->next=this->head;
			this->head=newNode;
		}
	
	//display first node
		void DisplayFirst(){
				Node* tem=head;
				if(tem==NULL){
					cout<<"NULL\n";
					return;
				}
				else if(tem->next==NULL){
					cout<<tem->data<<" | NULL\n";
					return;
				}
				else{
					cout<<tem->data<<" | "<<tem->next<<endl;
					return;
				}
			}
			
			//display last node
			void DisplayLast(){
				 if (head == NULL) { 
			        cout << "NULL\n";
			        return;
			    }
				Node* tem=head;
				while(tem->next!=NULL){
					tem=tem->next;
				}
				cout<<tem->data<<" | Null\n";
			}
			
			//at Nth node
			void DisplayNth(int num){
				Node* tem=head;
				num--;
				while( num>0){
					if(tem->next==NULL){
						cout << "Position out of bounds.\n";
			        	return;
					}
					tem=tem->next;
					num--;			
				}
			    if (tem->next == NULL) {
			        cout << tem->data << " | Null\n";
			    } else {
			        cout << tem->data << " | " << tem->next << endl;
			    }
			}
			
			//at center node
			void DisplayCenter(){
				Node* tem=head;
				int num=0;
				while(tem->next!=NULL){
					num++;
					tem=tem->next;
				}
				
				num=num/2;
				tem=head;
				while( num>0){
					tem=tem->next;
					num--;			
				}
				cout << tem->data << " | " << tem->next << endl;
			}
};
int main(){
	LinkedList link;
	
	link.insertAtStart(4);
	link.insertAtStart(3);
    link.insertAtStart(2);
    link.insertAtStart(1);
    link.insertAtStart(0);
    cout<<"The first of the link:\n";
	link.DisplayFirst();
	cout<<endl;
	
	cout<<"The last of the link:\n";
	link.DisplayLast();
	cout<<endl;
	
	cout<<"The 2th of the link:\n";
	link.DisplayNth(2);
	cout<<endl;
	
	cout<<"The center of the link:\n";
	link.DisplayCenter();
	cout<<endl;
	
	cout<<"The whole of the link:\n";
	link.display();
}
