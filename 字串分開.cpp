#include<iostream> 
using namespace std;


void str_sep_todouble(string str,double *a,int &siz,char sep);
//�r����B�I��
// str  ��l�r�� 
// a	�n��X���}�C 
// siz 	�}�C�j�p(�禡����) 
// sep 	���j�r�� 
//------------------------------------------------------------ 
void str_sep_toint(string str,double *a,int &siz,char sep);
//�r������ 
// str  ��l�r�� 
// a	�n��X���}�C 
// siz 	�}�C�j�p(�禡����) 
// sep 	���j�r��
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

