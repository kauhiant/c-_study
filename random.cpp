//�Ϋ���new int���üƭ�
//�Q��C++���|�۰ʳ]�w��l�Ȫ��S��
//�Ө��o�������ƭ�
//���O���Ʃʫܰ� 

#include<iostream>
using namespace std;

//���Ʃʦ��I��
//range �O�üƭȪ��d�� 
int rand(int range){
	int *a=new int;
	int b=*a;
	delete a; 
	b%=range;
	return b;
}

int main(){
	
	//��X10�Ӷü� 
	for(int i=0,tmp=0,s=1;i<10;i++){		
		tmp=rand(100);
		//�]�����Ʃʰ��A�ҥH�⭫�ƪ��h�� 
		if(tmp == s){
			i--;
			continue;
		}
		
		cout<<tmp<<' ';
		s=tmp;
	}
	
	return 0;
}
 //"C++�N�O��"by kauhia ^_^ 
