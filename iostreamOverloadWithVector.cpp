#include<iostream>
#include<vector>
using namespace std;

    template<class T>
    ostream& operator<<(ostream& out,const vector<T>& list){
        for(auto& tmp : list){
            out<<tmp<<' ';
        }
        return out;
    }
    template<class T>
    istream& operator>>(istream& in, vector<T>& list){
        T tmp;
        in>>tmp;
        list.push_back(tmp);
        return in;
    }


int main(){
    vector<int> a;

   cin>>a>>a>>a[0];//�b��Ja[0]�ɥX��

  //���`
    cin>>a>>a;
    cin>>a[0];

    cout<<a<<endl;
    return 0;
}
