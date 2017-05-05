#include<iostream>
using namespace std;
void test1(){
	cout<<"call test1 function\n";
}
void test2(){
	cout<<"call test2 function\n";
}
void test3(){
	cout<<"call test3 function\n";
}

void test(void (*function)()){
	function();
}
 /*
void test(int x,int y){
	cout<<x<<','<<y<<endl;
	cout<<&x<<','<<&y<<endl;
}*/

void test(int* a,int* b){
	cout<<a<<'*'<<b<<endl;
	cout<<*a<<'*'<<*b<<endl;
	cout<<&a<<'*'<<&b<<endl;
} 

void test(int& i,int& j){
	cout<<i<<'&'<<j<<endl;
	cout<<&i<<'&'<<&j<<endl;
}

int main(){
	int a=10,b=20;
	test(test3);
	cout<<&a<<'&'<<&b<<endl;
	test(&a,&b);
	return 0;
} 
