//�}�C�P����

#include<iostream>
using namespace std;

int main(){
	int *a=new int[5];//�Ыؤ@�����аO���� ���Vint�}�C
	int b[5]={996,992,993,994,997};//�Ыؤ@��int�}�C �]�w��l��
	int c[5][2];//�궡�@�ӤG���}�C

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
