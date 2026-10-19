#include <iostream>
#include <algorithm>   // std::fill
#include <cstring>


// 三元组：行、列、值
struct MatrixTerm {
    int row;
    int col;
    int value;
};

class SparseMatrix {
public:
    // 默认构造：0 行 0 列 0 个非零元
    SparseMatrix() : rows(0), cols(0), terms(0), smArray(nullptr) {}

    // 构造：指定行列数和容量
    SparseMatrix(int r, int c, int t)
        : rows(r), cols(c), terms(t) {
        smArray = (t > 0) ? new MatrixTerm[t] : nullptr;
    }

    // 拷贝构造
    SparseMatrix(const SparseMatrix& other)
        : rows(other.rows), cols(other.cols), terms(other.terms) {
        smArray = (terms > 0) ? new MatrixTerm[terms] : nullptr;
        for (int i = 0; i < terms; ++i) smArray[i] = other.smArray[i];
    }

    // 析构
    ~SparseMatrix() { delete[] smArray; }

    // 赋值运算符（简单实现，防止浅拷贝）
    SparseMatrix& operator=(const SparseMatrix& other) {
        if (this == &other) return *this;
        delete[] smArray;
        rows = other.rows; cols = other.cols; terms = other.terms;
        smArray = (terms > 0) ? new MatrixTerm[terms] : nullptr;
        for (int i = 0; i < terms; ++i) smArray[i] = other.smArray[i];
        return *this;
    }

    // 从三元组数组填充（假设传入的三元组已按行升序排列）
    void setTerms(const MatrixTerm* src, int t) {
        delete[] smArray;
        terms = t;
        smArray = (t > 0) ? new MatrixTerm[t] : nullptr;
        for (int i = 0; i < t; ++i) smArray[i] = src[i];
    }

    // 打印矩阵（按稠密形式输出，便于人眼比对）
    void print(const char* name = "Matrix") const {
        std::cout << name << " (" << rows << "x" << cols
                  << ", terms=" << terms << "):\n";
        // 建一个稠密矩阵来打印
        int R = rows, C = cols;
        int** dense = new int*[R];
        for (int i = 0; i < R; ++i) {
            dense[i] = new int[C];
            for (int j = 0; j < C; ++j) dense[i][j] = 0;
        }
        for (int k = 0; k < terms; ++k)
            dense[smArray[k].row][smArray[k].col] = smArray[k].value;

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j)
                std::cout << dense[i][j] << " ";
            std::cout << "\n";
        }
        for (int i = 0; i < R; ++i) delete[] dense[i];
        delete[] dense;
    }

    SparseMatrix FastTranspose();

public:
    int rows, cols, terms;
    MatrixTerm* smArray;
};


//观察发现，rowSize只用于构造rowStart，可以省略

SparseMatrix SparseMatrix::FastTranspose()
{
    SparseMatrix b (cols,rows,terms);
    if (terms > 0){
        int *rowStart = new int[cols];

        std::fill(rowStart,rowStart+cols, 0);

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
            rowStart[smArray[i].col]++;
        }
        delete []rowStart;
    }
    return b;  

}

int main() {
    SparseMatrix a(3, 4, 3);
    MatrixTerm src[3] = {
        {0, 2, 3},
        {1, 0, 5},
        {2, 3, 7}
    };
    a.setTerms(src, 3);

    a.print("A");
    SparseMatrix b = a.FastTranspose();
    b.print("A^T");

    return 0;
}