#include <iostream>
using namespace std;
int main(){
	int num=10;
	int* ptr=&num;
	
	cout<<"num="<<num<<endl;
	cout<<"*ptr="<<*ptr<<endl;
	
	
	*ptr=1;
	cout<<"num="<<num<<endl;
	cout<<"*ptr="<<*ptr<<endl;
}
