//�Ϋ��а}�C�إ߯x�}
//�@�}�l��J �C,�檺�ƥ� 
//�A��J�C�@�C���C�Ӽƭ� 
#include<iostream>
using namespace std; 

int main()
{
	//x=number of row
	//y=number of colon 
	int x,y;
	
	//��J�C�P�� 
	cin>>x>>y;
	
	//�إߤG������ 
	int** p;
	//�إߦC���� 
	p=new int* [x];
	//�إߦU�檺�O����Ŷ� 
	for(int i=0;i<x;i++){
		p[i]=new int[y];
	}
	
	//�ϥΪ̿�J�U��U�C�����ƭ� 
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			cin>>p[i][j];
		}
		cout<<endl;
	} 
	cout<<endl;
	
	//��X�x�} 
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			cout<<p[i][j]<<" ";
		}
		cout<<endl;
	} 
	
	//�R���x�} 
	for(int i=0;i<x;i++){
		delete [] p[i];
	}
	delete [] p;
	
	return 0;
}
//"�g�������h�ɥͥX�Ӫ�"by kauhia ^_^ 
