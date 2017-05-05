//用指標new int取亂數值
//利用C++不會自動設定初始值的特性
//來取得未知的數值
//但是重複性很高 

#include<iostream>
using namespace std;

//重複性有點高
//range 是亂數值的範圍 
int rand(int range){
	int *a=new int;
	int b=*a;
	delete a; 
	b%=range;
	return b;
}

int main(){
	
	//輸出10個亂數 
	for(int i=0,tmp=0,s=1;i<10;i++){		
		tmp=rand(100);
		//因為重複性高，所以把重複的去掉 
		if(tmp == s){
			i--;
			continue;
		}
		
		cout<<tmp<<' ';
		s=tmp;
	}
	
	return 0;
}
 //"C++就是神"by kauhia ^_^ 
