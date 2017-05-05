//全域 區域 

#include<iostream>
using namespace std;

string s="global";//全域變數 

void test(){
	string s="function";//區域變數 若把string註解掉 就變成"重新指派全域的s"
	cout<<s<<"記憶體位址"<<&s<<endl;
}

int main(){
	string s="local";//區域變數 若把string註解掉 就變成"重新指派全域的s"
	
	{
		 string s="block";//區域變數 若把string註解掉 就變成"重新指派main的s"或"重新指派全域的s" 
		 cout<<"block的s:"<<s<<"記憶體位址"<<&s<<endl;
	}
	
	cout<<"main()的s:"<<s<<"記憶體位址"<<&s<<endl;
	cout<<"global的s:"<<::s<<"記憶體位址"<<&::s<<endl;
	cout<<"function的s:";test();
	
	return 0;
}
 //"..."by kauhia ^_^ 
