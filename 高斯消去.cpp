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


#include<iostream>
using namespace std;

//double誤差用 
static double ZERO=0.0001;
class Matrix{
public:
    //建構式
    //Matrix(int row,int colon);
    Matrix(int row,int colon,bool isFraction);
    //輸入元素
    void build();
    //顯示
    void show();
    //轉置
    Matrix transpose();
    //列交換
    void swaprow(int row1,int row2);
    //列相減 被減數 減數 倍數 
    void subrow(int subed_row,int sub_row,double mul);
    void subrow(int subed_row,int sub_row,Fraction mul);
    //列除
    void divirow(int row,double n);
    void divirow(int row,Fraction n);
    //模 
    double trace_double();
    Fraction trace_Fraction();
    //反矩陣//還沒寫 
    Matrix inverse();
    //行列式值//還沒寫 
    double determinant();
    //高斯消去
    Matrix guassreduce_double();
	Matrix guassreduce_Fraction();
private:
    int row;
    int colon;
    bool isFraction;
	double **entry;
	Fraction **Fentry;
};
//建構式
Matrix::Matrix(int rows=0,int colons=0,bool isFr=false){
	row=rows;
    colon=colons;	
	isFraction =isFr;
	if(isFraction){		
		Fentry = new Fraction*[row];
    	for(int i=0;i<row;i++)
        	Fentry[i] = new Fraction[colon];
        for(int i=0;i<row;i++)
        	for(int j=0;j<colon;j++)
        		Fentry[i][j]=Fraction();
	}
	else{
		entry = new double*[row];
    	for(int i=0;i<row;i++)
        	entry[i] = new double[colon];    
	}    
}


//輸入元素
void Matrix::build(){
	
	if(isFraction){
		for(int i=0;i<row;i++){
        	cout<<i<<"row:";
        	for(int j=0;j<colon;j++)
            	cin>>Fentry[i][j].sub;      
    	}
	}
	else{
		for(int i=0;i<row;i++){
        	cout<<i<<"row:";
       		for(int j=0;j<colon;j++)
            	cin>>entry[i][j];      
    	}
	}
	
    
}

//顯示
void Matrix::show(){
	
	if(isFraction){
		for(int i=0;i<row;i++){
        	for(int j=0;j<colon;j++)
            	cout<<Fentry[i][j].sub<<'/'
					<<Fentry[i][j].base<<'\t';
        	cout<<endl;
    	}
	}
	else{
		for(int i=0;i<row;i++){
        	for(int j=0;j<colon;j++)
            	cout<<entry[i][j]<<'\t';
        	cout<<endl;
    	}
	}	
}

//轉置
Matrix Matrix::transpose(){
	Matrix tmpmatrix(colon,row,isFraction);
	if(isFraction){		
    	for(int i=0;i<colon;i++){
        	for(int j=0;j<row;j++)
            	tmpmatrix.Fentry[i][j]=Fentry[j][i];        
    	}
	}
	else{
    	for(int i=0;i<colon;i++){
        	for(int j=0;j<row;j++)
            	tmpmatrix.entry[i][j]=entry[j][i];        
    	}	
	}
	
    return tmpmatrix;
}

//列交換
void Matrix::swaprow(int row1,int row2){
	
	if(isFraction){
		Fraction tmpentry;
    	for(int i=0;i<colon;i++){
        	tmpentry=Fentry[row1][i];
        	Fentry[row1][i]=Fentry[row2][i];
        	Fentry[row2][i]=tmpentry;
    	}
	}
	else{
		double tmpentry;
    	for(int i=0;i<colon;i++){
        	tmpentry=entry[row1][i];
        	entry[row1][i]=entry[row2][i];
        	entry[row2][i]=tmpentry;
    	}
	}
	
    
}

//列相減 被減數 減數 倍數
void Matrix::subrow(int subed_row,int sub_row,double mul){
    for(int i=0;i<colon;i++){
    	if(entry[subed_row][i] < ZERO && entry[subed_row][i] > -1*ZERO){
			entry[subed_row][i]=0;
		}
		if(entry[sub_row][i] < ZERO && entry[sub_row][i] > -1*ZERO){
		entry[sub_row][i]=0; 
		}
		entry[subed_row][i] -= entry[sub_row][i]*mul;
	}        
}
void Matrix::subrow(int subed_row,int sub_row,Fraction mul){
	Fraction a;
    Fraction b;
    for(int i=0;i<colon;i++){
    	a=Fentry[subed_row][i];
    	b=Fentry[sub_row][i];
    	a = a-b*mul;
		Fentry[subed_row][i] = Fentry[subed_row][i] - (Fentry[sub_row][i]*mul);
	}        
}

//列除
void Matrix::divirow(int row,double n){
    for(int i=0;i<colon;i++){
    	if(n==0)break;
    	entry[row][i] /= n;
	}      
}
void Matrix::divirow(int row,Fraction n){
    for(int i=0;i<colon;i++){
    	if(n.sub==0)break;
    	Fentry[row][i] = Fentry[row][i] / n;
	}      
}

//模
double Matrix::trace_double(){	
	double tr=0.0;
    if(row==colon){
       	for(int i=0;i<row;i++)
          	tr += entry[i][i];
    }
    return tr;	

}
Fraction Matrix::trace_Fraction(){	
	Fraction tr;
    if(row==colon){
       	for(int i=0;i<row;i++)
           	tr = tr + Fentry[i][i];
    }
    return tr;
}

//高斯消去 
Matrix Matrix::guassreduce_double(){
    Matrix tmp(row,colon);
    tmp.entry=entry;

    for(int step=0;step<row;step++){
    	int var=0;
    	bool leadingget=false;
        for(int i=var;i<colon;i++){
            for(int j=step;j<row;j++){
                if(tmp.entry[j][i] != 0){
                	tmp.swaprow(j,step);
                	leadingget=true;
                	break;
				} 
            }
            if(leadingget){
            	var=i;
            	break;
			}   
        }
        tmp.divirow(step,tmp.entry[step][var]);
       	for(int j=step+1;j<row;j++){
       		tmp.subrow(j,step,tmp.entry[j][var]);
		}
    }
    return tmp;
}
Matrix Matrix::guassreduce_Fraction(){
    Matrix tmp(row,colon,isFraction);
    tmp.Fentry=Fentry;

    for(int step=0;step<row;step++){
    	int var=0;
    	bool leadingget=false;
        for(int i=var;i<colon;i++){
            for(int j=step;j<row;j++){
                if(tmp.Fentry[j][i].sub != 0){
                	tmp.swaprow(j,step);
                	leadingget=true;
                	break;
				} 
            }
            if(leadingget){
            	var=i;
            	break;
			}   
        }
        tmp.divirow(step,tmp.Fentry[step][var]);
       	for(int j=step+1;j<row;j++){
       		tmp.subrow(j,step,tmp.Fentry[j][var]);
		}
    }
    //疊代法
    if(row>1)
	for(int i=1;i<row;i++){
		int lead=0;
    	bool leadingget=false;
		for(int j=lead;j<colon;j++){
			if(tmp.Fentry[i][j].sub!=0){
				lead=j;break;
			}
		}
		for(int j=i-1;j>=0;j--)
			tmp.subrow(j,i,tmp.Fentry[j][lead]);
	} 

    return tmp;
}

//測試 
int main(){
	int x,y;
	Fraction a;
	a.sub=2;
	cin>>x>>y;
    Matrix one(x,y,true),two;
    one.build();
    one.show();
    cout<<endl;
    one=one.guassreduce_Fraction();
    one.show();
    
    cout<<endl;
    return 0;
}
//"剩輸入輸出..."by kauhia ^_^ 

