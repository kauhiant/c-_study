#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//function pointer named CPL
typedef bool (*CPL)(int,int);

bool bigger(int a, int b){
    return a>b;
}
bool smaller(int a, int b){
    return a<b;
}
void swap2int(int*a, int*b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void sortInts(int *start, int *tail, CPL prog){
    //bubble sort by function pointer
    for(int *i=start; i != tail; ++i){
        for(int *j=i+1; j != tail; ++j){
            if(prog(*j,*i)){
                swap2int(i,j);
            }
        }
    }
}



int main(){
	int a[]={1,3,5,6,2,5,3,2,1};
	sortInts(a,a+9,bigger);
	for(int i:a){
        cout<<i<<' ';
	}

	return 0;
}
