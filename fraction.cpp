//#include"fraction.h"
//程そ计
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
//程虏だ计
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
//	int sub;	//だ 
//	int base;	//だダ 

//篶(だ,だダ)
Fraction::Fraction(int a=0,int b=1){
	sub=a;
	base=b;
} 

// 
Fraction Fraction::operator+(Fraction a){
	Fraction tmp;
	tmp.sub = (sub*a.base) + (a.sub*base);
	tmp.base = base * a.base;
	tmp.simple();
	return tmp;
}

//搭 
Fraction Fraction::operator-(Fraction a){
	Fraction tmp;
	tmp.sub = (sub*a.base) - (a.sub*base);
	tmp.base = base * a.base;
	tmp.simple();
	return tmp;
} 
 
// 
Fraction Fraction::operator*(Fraction a){
	Fraction tmp;
	tmp.sub  = sub  * a.sub;
	tmp.base = base * a.base;
	tmp.simple();
	return tmp;
}
//埃 
Fraction Fraction::operator/(Fraction a){
	Fraction tmp;
	tmp.sub  = sub  * a.base;
	tmp.base = base * a.sub;
	tmp.simple();
	return tmp;
}



