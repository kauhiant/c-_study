//���� �ϰ� 

#include<iostream>
using namespace std;

string s="global";//�����ܼ� 

void test(){
	string s="function";//�ϰ��ܼ� �Y��string���ѱ� �N�ܦ�"���s�������쪺s"
	cout<<s<<"�O�����}"<<&s<<endl;
}

int main(){
	string s="local";//�ϰ��ܼ� �Y��string���ѱ� �N�ܦ�"���s�������쪺s"
	
	{
		 string s="block";//�ϰ��ܼ� �Y��string���ѱ� �N�ܦ�"���s����main��s"��"���s�������쪺s" 
		 cout<<"block��s:"<<s<<"�O�����}"<<&s<<endl;
	}
	
	cout<<"main()��s:"<<s<<"�O�����}"<<&s<<endl;
	cout<<"global��s:"<<::s<<"�O�����}"<<&::s<<endl;
	cout<<"function��s:";test();
	
	return 0;
}
 //"..."by kauhia ^_^ 
