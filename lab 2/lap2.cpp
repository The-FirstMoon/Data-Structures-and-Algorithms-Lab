#include <iostream>
using namespace std;


int maximum(int n, int *arr){
	int max=arr[0];
	for(int i=1;i<n;i++){
		if (arr[i]>max){
			max=arr[i];
		}
	}
	return max;
}

int main(){
	int arr[4]={1,90,3,4};
	cout<<maximum(4,arr);
}
