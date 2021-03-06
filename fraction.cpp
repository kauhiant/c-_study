//#include"fraction.h"
//最大公因數
int Fraction::gcd(int a,int b){
	if(a==b)return a;
	if(a%b == 0) return b;
	int tmp=1;
	while(a%b != 0){
		tmp=a%b;
		a=b;
		b=tmp;
	}
	return tmp;
} 
//最簡分數
void Fraction::simple(){
	int div=gcd(sub,base);
	sub/=div;
	base/=div;
	if(base<0){
		sub *=-1;
		base*=-1;
	}
	if(sub==0)base=1;
	
	
} 
//	int sub;	//分子 
//	int base;	//分母 

//建構(分子,分母)
Fraction::Fraction(int a=0,int b=1){
	sub=a;
	base=b;
} 

//加 
Fraction Fraction::operator+(Fraction a){
	Fraction tmp;
	tmp.sub = (sub*a.base) + (a.sub*base);
	tmp.base = base * a.base;
	tmp.simple();
	return tmp;
}

//減 
Fraction Fraction::operator-(Fraction a){
	Fraction tmp;
	tmp.sub = (sub*a.base) - (a.sub*base);
	tmp.base = base * a.base;
	tmp.simple();
	return tmp;
} 
 
//乘 
Fraction Fraction::operator*(Fraction a){
	Fraction tmp;
	tmp.sub  = sub  * a.sub;
	tmp.base = base * a.base;
	tmp.simple();
	return tmp;
}
//除 
Fraction Fraction::operator/(Fraction a){
	Fraction tmp;
	tmp.sub  = sub  * a.base;
	tmp.base = base * a.sub;
	tmp.simple();
	return tmp;
}



