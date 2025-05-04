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
class DSA{
	public:
		Node* head;
		DSA(){
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
		void display(Node* temp){
			cout<<temp->data<<" ";
		}
		void Travers() {
		    TraversHelper(head);
		}
		
		void TraversHelper(Node* temp) {
		    if (temp == NULL) return;
		    display(temp);
		    TraversHelper(temp->left);
		    TraversHelper(temp->right);
		}
		
};

int main(){
	DSA me;
	me.insert(1);
	me.insert(2);
	me.insert(3);
	me.insert(4);
	me.insert(4);
	me.insert(5);
	me.insert(6);
	me.insert(6);
	me.Travers();
}
