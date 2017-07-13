#include<iostream>
#include<vector>
#include<climits>
#include<iomanip>
#include<cmath>
using namespace std;

class Number{
    static const int digitSizeLog=3;
    static const int digitSize=1000;//must to be pow(10,digitSizeLog)
public:
    /**
        num[0] - lower digit
        num[size-1] - higher digit
        digit - referent digitSize
    */
    vector<unsigned int> num;

    /**
        true - negative
        false- positive
    */
    bool isNegtive;

    /**
        constructor
        int argument can't over digitSize
        int argument default 0
    */
    Number(const int);
    /**
        constructor
        copy Number argument
    */
    Number(const Number&);

    /**
        compare operators
        no commit
    */
    bool operator>(const Number&);
    bool operator<(const Number&);
    bool operator==(const Number&);
    bool operator!=(const Number&);

    /**
        add , subtract operators
        no commit
    */
    Number operator+(/*const*/ Number&);
    Number operator-(/*const*/ Number&);

    /**
        out stream
        no commit
    */
    friend ostream& operator<<(ostream&,const Number&);

    /**
        return absolution
        can't change original Number
    */
    Number abs();

    /**
        return Reverse Number
        will change original Number
    */
    Number& toReverse();
};
//-------------------------------------------------------------------------------------------------------
Number::Number(const int n=0){
    if(n >= digitSize){
        cout<<"error: constructor argument too big"<<endl;
        isNegtive = false;
        num.push_back(digitSize-1);
    }
    else if(n < -digitSize){
        cout<<"error: constructor argument too small"<<endl;
        isNegtive = true;
        num.push_back(digitSize-1);
    }
    else if(n<0){
        isNegtive = true;
        num.push_back(-n);
    }
    else{
        isNegtive = false;
        num.push_back(n);
    }

}
Number::Number(const Number& refNum){
    isNegtive = refNum.isNegtive;
    num = refNum.num;
}
//----------------------------------------------------------------------------------------------
bool Number::operator>(const Number& tmp){
    if(isNegtive != tmp.isNegtive)
        return tmp.isNegtive;

    bool res;
    if(num.size() != tmp.num.size())
        res = num.size() > tmp.num.size();
    else{
        int nums=num.size();
        while(--nums >= 0){
            if(num[nums] != tmp.num[nums]){
                res = num[nums] > tmp.num[nums];
                break;
            }
        }
    }
    if(isNegtive)
        return !res;
    return res;
}
bool Number::operator<(const Number& tmp){
    if(isNegtive != tmp.isNegtive)
        return isNegtive;

    bool res;
    if(num.size() != tmp.num.size())
        res = num.size() < tmp.num.size();
    else{
        int nums=num.size();
        while(--nums >= 0){
            if(num[nums] != tmp.num[nums]){
                res = num[nums] < tmp.num[nums];
                break;
            }
        }
    }

    if(isNegtive)
        return !res;
    return res;
}
bool Number::operator==(const Number& tmp){
    if(isNegtive != tmp.isNegtive)
        return false;
    if(num.size() != tmp.num.size())
        return false;

    int nums=num.size();
    while(--nums >= 0){
        if(num[nums] != tmp.num[nums])
            return false;
    }
    return true;
}
bool Number::operator!=(const Number& tmp){
    return !(*this == tmp);
}
//--------------------------------------------------------------------------------------------------------

Number Number::operator+(/*const*/ Number& tmp){
    if(isNegtive != tmp.isNegtive){
        if(isNegtive){
            Number a(*this);
            a.isNegtive = false;
            return tmp - a;//為何不能加const
        }
        else{
            Number a(tmp);
            a.isNegtive = false;
            return *this - a;//為何不能加const
        }
    }

    Number resNum;
    resNum.isNegtive = isNegtive;
    int sizeOfNum = num.size()>tmp.num.size()?num.size():tmp.num.size();
    resNum.num.resize(sizeOfNum);
    bool isOverflow = false;

    for(int i=0;i<sizeOfNum;++i){

        long long tmp1 = 0 , tmp2 = 0;
        if(i<num.size()) tmp1 = num[i];
        if(i<tmp.num.size()) tmp2 = tmp.num[i];

        long long check = tmp1 + tmp2;
        if(isOverflow){
            ++check;
            isOverflow=false;
        }

        if(check >= digitSize){
            isOverflow = true;
            check %= digitSize;
        }

        resNum.num[i] = (static_cast<unsigned int>(check));
    }
    if(isOverflow){
        resNum.num.push_back(1);
    }
    return resNum;
}
Number Number::operator-(/*const*/ Number& tmp){
    if(isNegtive != tmp.isNegtive){
        if(!isNegtive){
            return tmp.abs() + *this;//為何不能加const
        }
        else{
            Number a(tmp);
            a.isNegtive = false;
            return *this + a;//為何不能加const
        }
    }
    if(tmp.abs() > this->abs()){
        return (tmp - *this).toReverse() ;
    }
    Number resNum;
    resNum.isNegtive = isNegtive;
    int sizeOfNum = num.size()>tmp.num.size()?num.size():tmp.num.size();
    resNum.num.resize(sizeOfNum);
    bool isOverflow = false;

    for(int i=0;i<sizeOfNum;++i){

        long long tmp1 = 0 , tmp2 = 0;
        if(i<num.size()) tmp1 = num[i];
        if(i<tmp.num.size()) tmp2 = tmp.num[i];

        long long check = tmp1 - tmp2;
        if(isOverflow){
            --check;
            isOverflow=false;
        }
        if(check<0){
            check += digitSize;
            if(check >= digitSize)cout<<"error/n";
            isOverflow = true;
        }

        resNum.num[i] = (static_cast<unsigned int>(check));
    }
    if(isOverflow){
        resNum.num[resNum.num.size()-1] *= -1;
        cout<<" - overflow\n"<<resNum.num[0]<<endl;
    }
    return resNum;
}
//--------------------------------------------------
Number Number::abs(){
    Number res(*this);
    res.isNegtive = false;

    return res;
}
Number& Number::toReverse(){
    isNegtive = !isNegtive;
    return *this;
}
//---------------------------------------------------------
 ostream& operator<<(ostream& output,const Number& refNum){
    if(refNum.isNegtive)
        output<<'-';
    output<<refNum.num[refNum.num.size()-1];
    for(int i=refNum.num.size()-2; i>=0; --i){
        cout<<setw(Number::digitSizeLog)<<setfill('0')<<refNum.num[i];
    }
    return output;
}
//---------------------------------------------------------

int main(){
    cout<<"INT_MAX:"<<INT_MAX<<endl;
    //cout<<"digitSize:"<<digitSize<<endl;
    cout<<"LONG_MAX:"<<LONG_MAX<<endl;
    Number a(999);
    Number b(1);
    a.num.push_back(5);
    b.num.push_back(9);
    a.num.push_back(6);
   // b.num.push_back(1);
    cout<<b<<'-'<<b<<'=';
    cout<< (b-b);

    //Number d(c+c+c+c);
//    cout<<c.num.size()<<endl;
    //cout<<c.num.size();
    return 0;
}
