//1. Create 2 Singly LinkedLists and Merge them and display them.
//2. Create 2 Double LinkedLists and Merge them and display them.
#include <iostream>
using namespace std;


class Snode{
	public:
		int data;
		Snode* next;
	
		Snode(int d){
			data=d;
			next=NULL;
		}
};
class Slink{
	public:
		Snode* head;
		Slink(){
			head=NULL;
		}
		
		void InsertAtStart(int d){
			Snode* newNode= new Snode(d);
			newNode->next=head;
			head=newNode;
		}
		
		void Display() {
		    Snode* temp = head;
		    while (temp != NULL) {
		        cout << temp->data << " -> ";
		        temp = temp->next;
		    }
		    cout << "NULL\n\n";
		}
		
		void Merge(Slink list){
			Snode* temp=this->head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=list.head;	
		}
};



class Dnode{
	public:
		int data;
		Dnode* next;
		Dnode* prev;
		Dnode(int d){
			data=d;
			next=NULL;
			prev=NULL;
		}
};
class Dlink{
	public:
		Dnode* head;
		Dlink(){
			head=NULL;
		}
		
		void InsertAtStart(int d){
			Dnode* newNode= new Dnode(d);
			newNode->next=head;
			if (head != NULL) {  
		        head->prev = newNode;
		    }
			head=newNode;
		}
		
		void Display() {
		    Dnode* temp = head;
		    while (temp != NULL) {
		        cout << temp->data << " <-> ";
		        temp = temp->next;
		    }
		    cout << "NULL\n\n";
		}
		
		void Merge(Dlink list){
			Dnode* temp=this->head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=list.head;
			list.head->prev=temp;	
		}
};




int main(){
	Slink s1,s2;
	s1.InsertAtStart(2);
	s1.InsertAtStart(1);
	s2.InsertAtStart(4);
	s2.InsertAtStart(3);
	s1.Merge(s2);
	s1.Display();
	
	
	Dlink d1,d2;
	d1.InsertAtStart(20);
	d1.InsertAtStart(10);
	d2.InsertAtStart(40);
	d2.InsertAtStart(30);
	d1.Merge(d2);
	d1.Display();
	
}
