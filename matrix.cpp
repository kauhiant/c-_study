//���������x�}���O 

#include<iostream>
using namespace std;

//double�~�t�� 
static double ZERO=0.0001;
class Matrix{
public:
    //�غc��
    Matrix(int row,int colon);
    //��J����
    void build();
    //���
    void show();
    //��m
    Matrix transpose();
    //�C�洫
    void swaprow(int row1,int row2);
    //�C�۴� �Q��� ��� ���� 
    void subrow(int subed_row,int sub_row,double mul);
    //�C��
    void divirow(int row,double n);
    //�� 
    double trace();
    //�ϯx�}//�٨S�g 
    Matrix inverse();
    //��C����//�٨S�g 
    double determinant();
    //�������h
    Matrix guassreduce();
private:
    int row;
    int colon;
	double **entry;
};
//�غc��
Matrix::Matrix(int rows,int colons){
    entry = new double*[rows];
    for(int i=0;i<rows;i++){
        entry[i] = new double[colons];
    }

    row=rows;
    colon=colons;
}

//��J����
void Matrix::build(){
    for(int i=0;i<row;i++){
        cout<<i<<"row:";
        for(int j=0;j<colon;j++){
            cin>>entry[i][j];
        }
    }
}

//���
void Matrix::show(){
    for(int i=0;i<row;i++){
        for(int j=0;j<colon;j++){
            cout<<entry[i][j]<<'\t';
        }
        cout<<endl;
    }
}

//��m
Matrix Matrix::transpose(){
    Matrix tmpmatrix(colon,row);

    for(int i=0;i<colon;i++){
        for(int j=0;j<row;j++){
            tmpmatrix.entry[i][j]=entry[j][i];
        }
    }

    return tmpmatrix;
}

//�C�洫
void Matrix::swaprow(int row1,int row2){
    double tmpentry;
    for(int i=0;i<colon;i++){
        tmpentry=entry[row1][i];
        entry[row1][i]=entry[row2][i];
        entry[row2][i]=tmpentry;
    }
}

//�C�۴� �Q��� ��� ����
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

//�C��
void Matrix::divirow(int row,double n){
    for(int i=0;i<colon;i++){
    	if(n==0)break;
    	entry[row][i] /= n;
	}
        
}

//��
double Matrix::trace(){
    double tr=0.0;
    if(row==colon){
        for(int i=0;i<row;i++)
            tr += entry[i][i];
        return tr;
    }
    else{

    }
}

//�������h 
Matrix Matrix::guassreduce(){
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

//���� 
int main(){
	int x,y;
	cin>>x>>y;
    Matrix one(x,y);
    one.build();
    one.show();
    cout<<endl;
    one=one.guassreduce();

    one.show();
    cout<<endl;
    return 0;
}
//"�s�褤..."by kauhia ^_^ 
