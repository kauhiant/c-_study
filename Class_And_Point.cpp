#include<iostream>
using namespace std;
class ForTest{
	int val;
	public:
		ForTest(int tmp = 0):val(tmp){}
		int getVal(){
			return val;
		}
		
};
int main(){
//�غc�� 
	 
	//�H�U��ثغc�� ��@�ӥ� 
	//ForTest a;//val=0
	ForTest a(100);//val=100 
	
	//�ݵ��G
	cout<<a.getVal()<<endl; 
	
	
//���VClass������ 
	
	ForTest* b;//�إߤ@�ӫ��V'ForTest����'��'����b' 
	b = new ForTest();//���ͤ@��'ForTest����' �ñN�L���O�����}��'����b' 
	 
	//���Ъ��ϥΪk
	cout<<b->getVal()<<endl;
	
//�@�몺����
	int* c;//�إߤ@�ӫ��V'int����'��'����c' 
	c = new int(3);//�إߤ@��'int����' �A��L���O�����m��'����c' 
	cout<<  c <<endl;//���'����c'�����e �O�@�ӰO�����m 
	cout<< *c <<endl;//���'����c'�ҫ��V��'int����' �O�@��int�� 
	cout<< &c <<endl;//���'����c'���O�����m �O�@�ӰO�����m
	cout<< &*c <<endl;//���"'����c'���V��'int����'"���O�����m �N�O'����c'�����e
	delete c;//����"'����c'���V��'int����'"���Ŷ� ���O'����c'�٬O�s�b
	cout<< &c;//'����c'�s�b���Ҿ�
	 
	//new:�إߤ@�Ӫ��� �æ^�ǥL���O�����m
	//&:�^�Ǫ��󪺰O�����m
	//*:�^�ǫ��Щҫ��V������
	//delete:���� ���Ы��V������ 
	return 0;
} 
