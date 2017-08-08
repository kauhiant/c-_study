#include<iostream>
using namespace std;

class Method{
    public:
    virtual void doing()=0;
};

class A:public Method{
    void doing(){
        cout<<"this is A\n";
    }
};

class B:public Method{
    void doing(){
        cout<<"this is B\n";
    }
};
class C:public Method{
    void doing(){
        cout<<"this is C\n";
    }
};
class D:public Method{
    void doing(){
        cout<<"this is D\n";
    }
};

int main(){
    Method* array[4]={
        new A(),
        new B(),
        new C(),
        new D()
    };
    int i;
    cin>>i;
    array[i]->doing();
    return 0;
}
