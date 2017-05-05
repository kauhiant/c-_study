//陣列與指標

#include<iostream>
using namespace std;

int main(){
	int *a=new int[5];//創建一塊指標記憶體 指向int陣列
	int b[5]={996,992,993,994,997};//創建一個int陣列 設定初始值
	int c[5][2];//串間一個二維陣列

	for(int i=0;i<5;i++){
        cin>>a[i];
        cout<<b[i]<<' ';
        c[i][0]=a[i]+b[i];
	}
    cout<<endl;
	for(int i=0;i<5;i++){
        cout<<c[i][0]<<' ';
	}

	return 0;
}
 //by kauhia ^_^
