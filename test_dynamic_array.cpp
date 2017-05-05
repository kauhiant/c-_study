//用指標陣列建立矩陣
//一開始輸入 列,行的數目 
//再輸入每一列的每個數值 
#include<iostream>
using namespace std; 

int main()
{
	//x=number of row
	//y=number of colon 
	int x,y;
	
	//輸入列與行 
	cin>>x>>y;
	
	//建立二維指標 
	int** p;
	//建立列指標 
	p=new int* [x];
	//建立各行的記憶體空間 
	for(int i=0;i<x;i++){
		p[i]=new int[y];
	}
	
	//使用者輸入各行各列中的數值 
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			cin>>p[i][j];
		}
		cout<<endl;
	} 
	cout<<endl;
	
	//輸出矩陣 
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			cout<<p[i][j]<<" ";
		}
		cout<<endl;
	} 
	
	//刪除矩陣 
	for(int i=0;i<x;i++){
		delete [] p[i];
	}
	delete [] p;
	
	return 0;
}
//"寫高斯消去時生出來的"by kauhia ^_^ 
