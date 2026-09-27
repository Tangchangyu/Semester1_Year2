# include<cmath>

//采用二分查找


int FindNumber(int num[], int size , int t){

    int tag = size / 2;    //标记检验数字的序列

    for(int exp = 1; exp ;exp++){
        if (num[tag] < t){
            tag += size / std::pow(2,exp);
        }

        else if (num[tag]> t ){
            tag -= size / std::pow(2,exp);
        }

        else if (num[tag]== t){
            return tag;
        }
    }
    
}