//�B�⤸���� 

#include<iostream>
using namespace std;

class Test{
public:
	Test(int);//�غc 
	Test operator+(Test);//Test+Test �^��Test 
	int operator+(int);//Test+int �^��int
	int value;
};

//�w�q�غc�� �Y�����w�Ѽ� �۰ʳ]�w��0 
Test::Test(int input=0){
	value=input;
}

//Test+Test �^��Test
Test Test::operator+(Test arg){
	Test tmp;
	tmp.value=value+arg.value;
	return tmp;
} 

//Test+int �^��int 
int Test::operator+(int arg){
	return value+arg;
}



int main(){
	Test a;
	Test b(10);
	Test c(20);
	// ���իغc�� 
	cout<<a.value<<endl;
	
	//����Test+Test 
	a=b+c;
	cout<<a.value<<endl;
	
	//����Test+int 
	a=a+20;
	cout<<a.value<<endl;
	
	return 0;
}
 //"thenewboston is good youtuber!"by kauhia ^_^ 
