//環狀連結串列
//define判斷 ifndef,else,endif
//define a b 的用法 
#include<iostream>
using namespace std;
#define for(i,j) for(int x=i;x<=j;x++)
#define intp int*

//#define aaa	//把前面的註解去掉試試看 
#ifndef aaa
	string s="not defined";
#else
	string s="defined";
#endif
 
//環狀串列的node 
struct loop{
	int a;
	loop* link;
}; 

int main()
{
	//測試ifdef的結果 
	cout<<s<<endl;
	
	//測試define的用法 
	intp a=new int;
	
	//環狀串列的進入點 
	loop L;
	L.a=10000;
	
	//應該叫疊代的指標?? 
	loop* each=&L;
	
	//define測試 + 鏈結串列建立10個node 
	for(1 , 10)
	{
		each->link=new loop;
		each=each->link;
		each->a=x-1;
	}
	cout<<endl;
	
	//把鏈結串列的尾端拉回來 變成環狀 
	each->link=L.link;
	
	//環狀串列輸出 跑100次 100/10圈 
	for(1,100){
		each=each->link;
		cout<<each->a;
		cout<<' ';
	}
}
 //"讓C++再次強大"by kauhia ^_^
