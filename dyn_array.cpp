#include<iostream>
using namespace std;
int main(){
	int x;
	cin>>x;
	
	int* array = new int[x];
	for(int n=0;n<x;n++)
		cin>>array[n];
	cout<<endl;
	for(int n=0;n<x;n++)
		cout<<array[n]<<" ";
	cout<<endl;
	
	//delete [] array;
	
	for(int n=0;n<x;n++)
		cout<<array[n]<<" ";
	cout<<endl;
	
	return 0;
}
