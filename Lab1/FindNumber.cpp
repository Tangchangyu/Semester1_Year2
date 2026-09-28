# include<cmath>

//采用二分查找


int FindNumber(int num[], int size , int t){

    int tag = 0 ;    //标记检验数字的序列

    for(int exp = 1; exp ;exp++){
        if (num[tag]== t){
            return tag;
        }
    }

        else if(num[tag] < t){
            if (0== size/std::pow(2,exp)){
                return tag+1;
            }
            tag += size / std::pow(2,exp);
        }

        else if (num[tag]> t ){
            if (0== size/std::pow(2,exp)){
                return tag;
            }
            tag -= size / std::pow(2,exp);
        }

        
    
}
//解决问题：遇到数组外的数字会死循环
//初始值修复 


//----题目二---//
//做成三个运算符重载？
//做成一个比较函数返回枚举类型？
enum class COMPARE{
BIGGER,
SMALLER,
EQUALL
};

COMPARE Compare(int a[],int b[],int n,int m){
    int top = 0;//循环的最大数
    if(n<m){
        top = n;
    }
    else top = m;

    for(int i = 0;i < top ; i++){
        if (a[i]<b[i]){return COMPARE::SMALLER;}
        else if ( a[i]> b[i]){return COMPARE::BIGGER;}

    }

    if (n<m){ return COMPARE::SMALLER;}
    else if (n>m) {return COMPARE::BIGGER;}
    else return COMPARE::EQUALL;    
}


//---题目三---//
class SparseMatrix{
    public:
    SparseMatrix FastTranspose();
}

//观察发现，rowSize只用于构造rowStart，可以省略

SparseMatrix SparseMatrix::FastTranspose()
{
    SparseMatrix b (cols,rows,terms);
    if (terms > 0){
        int *rowStart = new int[cols];

        fill(rowStart,rowStart+cols, 0);

        for (int i = 0; i < terms; i ++){
            rowStart[smArray[i].col]++;

        }//构造原本的rowSize

        for (int i = 1; i < cols ; i++){
            rowStart[i]+=rowStart[i-1];
            //计算总计输入的数字，也就是说标记下一行开始的位置，
        }

        for (int i = cols -1 ; i>0 ; i--){
            rowStart[i] = rowStart[i-1];
        }
        rowStart[0]= 0;


        for(int i = 0; i < terms; i ++){
            int j = rowStart[smArray[i].col]; 
            b.smArray[j].row = smArray[i].col;
            b.smArray[j].col = smArray[i].row;
            b.smArray[j].value = smArray[i].value;
            
        }
        delete []rowStart;
    }


}