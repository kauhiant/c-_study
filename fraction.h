//
class  Fraction{
	void simple();//��²���� 
	int gcd(int a,int b); //�̤j���]�� 
	public:
		int sub;	//���l 
		int base;	//���� 
		Fraction(int,int);//�غc(���l,����) 
		Fraction operator+(Fraction); 
		Fraction operator-(Fraction); 
		Fraction operator*(Fraction); 
		Fraction operator/(Fraction);
};

#include"fraction.cpp"


