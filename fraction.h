//
class  Fraction{
	void simple();//最簡分數 
	int gcd(int a,int b); //最大公因數 
	public:
		int sub;	//分子 
		int base;	//分母 
		Fraction(int,int);//建構(分子,分母) 
		Fraction operator+(Fraction); 
		Fraction operator-(Fraction); 
		Fraction operator*(Fraction); 
		Fraction operator/(Fraction);
};

#include"fraction.cpp"


