//運算元重載 

#include<iostream>
using namespace std;

class Test{
public:
	Test(int);//建構 
	Test operator+(Test);//Test+Test 回傳Test 
	int operator+(int);//Test+int 回傳int
	int value;
};

//定義建構式 若未指定參數 自動設定為0 
Test::Test(int input=0){
	value=input;
}

//Test+Test 回傳Test
Test Test::operator+(Test arg){
	Test tmp;
	tmp.value=value+arg.value;
	return tmp;
} 

//Test+int 回傳int 
int Test::operator+(int arg){
	return value+arg;
}



int main(){
	Test a;
	Test b(10);
	Test c(20);
	// 測試建構式 
	cout<<a.value<<endl;
	
	//測試Test+Test 
	a=b+c;
	cout<<a.value<<endl;
	
	//測試Test+int 
	a=a+20;
	cout<<a.value<<endl;
	
	return 0;
}
 //"thenewboston is good youtuber!"by kauhia ^_^ 
