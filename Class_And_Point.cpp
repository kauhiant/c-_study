#include<iostream>
using namespace std;
class ForTest{
	int val;
	public:
		ForTest(int tmp = 0):val(tmp){}
		int getVal(){
			return val;
		}
		
};
int main(){
//建構式 
	 
	//以下兩種建構式 選一個用 
	//ForTest a;//val=0
	ForTest a(100);//val=100 
	
	//看結果
	cout<<a.getVal()<<endl; 
	
	
//指向Class的指標 
	
	ForTest* b;//建立一個指向'ForTest物件'的'指標b' 
	b = new ForTest();//產生一個'ForTest物件' 並將他的記憶體位址給'指標b' 
	 
	//指標的使用法
	cout<<b->getVal()<<endl;
	
//一般的指標
	int* c;//建立一個指向'int物件'的'指標c' 
	c = new int(3);//建立一個'int物件' 再把他的記憶體位置給'指標c' 
	cout<<  c <<endl;//顯示'指標c'的內容 是一個記憶體位置 
	cout<< *c <<endl;//顯示'指標c'所指向的'int物件' 是一個int值 
	cout<< &c <<endl;//顯示'指標c'的記憶體位置 是一個記憶體位置
	cout<< &*c <<endl;//顯示"'指標c'指向的'int物件'"的記憶體位置 就是'指標c'的內容
	delete c;//釋放"'指標c'指向的'int物件'"的空間 但是'指標c'還是存在
	cout<< &c;//'指標c'存在的證據
	 
	//new:建立一個物件 並回傳他的記憶體位置
	//&:回傳物件的記憶體位置
	//*:回傳指標所指向的物件
	//delete:釋放 指標指向的物件 
	return 0;
} 
