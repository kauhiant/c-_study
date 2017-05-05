#include<iostream> 
using namespace std;


void str_sep_todouble(string str,double *a,int &siz,char sep);
//字串轉浮點數
// str  原始字串 
// a	要輸出的陣列 
// siz 	陣列大小(函式產生) 
// sep 	分隔字元 
//------------------------------------------------------------ 
void str_sep_toint(string str,double *a,int &siz,char sep);
//字串轉整數 
// str  原始字串 
// a	要輸出的陣列 
// siz 	陣列大小(函式產生) 
// sep 	分隔字元
//------------------------------------------------------------
 
void str_sep_todouble(string str,double *a,int &siz,char sep){
    double tmp=0.0;
    bool flag=false;
    int c=0;
    siz=0;
    for(int i=0;i<str.length();i++){
        if(str[i]==sep){
        	tmp=1;
        	while(c > 0){
        		tmp*=10;
        		c--;
			}	
			a[siz]/=tmp;
        	flag=false;
        	c=0;
            siz++;
            tmp=0;
        }
        else if(str[i]>='0' && str[i]<='9'){
            tmp=tmp*10+int(str[i]-48);
            a[siz]=tmp;
            if(flag) c++;
        }
        else if(str[i]=='.'){
        	flag=true;
		}
    }
    tmp=1;
    while(c > 0){
    	tmp*=10;
   		c--;
	}
	a[siz]/=tmp;
    siz++;
}
void str_sep_toint(string str,int *a,int &siz,char sep){
    int tmp=0;
    siz=0;
    for(int i=0;i<str.length();i++){
        if(str[i]==sep){
            siz++;
            tmp=0;
        }
        else if(str[i]>='0' && str[i]<='9'){
            tmp=tmp*10+int(str[i]-48);
            a[siz]=tmp;
        }
    }
    siz++;
}
int main(){
	string str;
	double arry[20];
	int arrysize;
	
	getline(cin,str);
	str_sep_todouble(str,arry,arrysize,' ');
	for(int i=0;i<arrysize;i++){
		cout<<arry[i]<<endl;
	}
	
	return 0;
}

