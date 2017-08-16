#include<iostream>
#include<vector>
using namespace std;

template<class T>
class myVector:public vector<T>{
    friend ostream& operator<<(ostream& out,const myVector<T>& list){
        for(auto& tmp : list){
            out<<tmp<<' ';
        }
        return out;
    }
    friend istream& operator>>(istream& in,myVector<T>& list){
        T tmp;
        in>>tmp;
        list.push_back(tmp);
        return in;
    }

};

int main(){
    myVector<int> a;

  // cin>>a>>a>>a[0];//在輸入a[0]時出錯

  //正常
    cin>>a>>a;
    cin>>a[0];

    cout<<a<<endl;
    return 0;
}
