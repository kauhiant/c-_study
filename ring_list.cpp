//�����s����C
//define�P�_ ifndef,else,endif
//define a b ���Ϊk 
#include<iostream>
using namespace std;
#define for(i,j) for(int x=i;x<=j;x++)
#define intp int*

//#define aaa	//��e�������ѥh���ոլ� 
#ifndef aaa
	string s="not defined";
#else
	string s="defined";
#endif
 
//������C��node 
struct loop{
	int a;
	loop* link;
}; 

int main()
{
	//����ifdef�����G 
	cout<<s<<endl;
	
	//����define���Ϊk 
	intp a=new int;
	
	//������C���i�J�I 
	loop L;
	L.a=10000;
	
	//���ӥs�|�N������?? 
	loop* each=&L;
	
	//define���� + �쵲��C�إ�10��node 
	for(1 , 10)
	{
		each->link=new loop;
		each=each->link;
		each->a=x-1;
	}
	cout<<endl;
	
	//���쵲��C�����ݩԦ^�� �ܦ����� 
	each->link=L.link;
	
	//������C��X �]100�� 100/10�� 
	for(1,100){
		each=each->link;
		cout<<each->a;
		cout<<' ';
	}
}
 //"��C++�A���j�j"by kauhia ^_^
