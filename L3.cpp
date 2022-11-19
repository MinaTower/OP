#include<iostream>
#include<locale>
using namespace std;
const int n = 3;
int exponentiation(int num, int degree){
    int res = num;
    for (int i = 2; i <= degree; i++)
    {
        res *= num;
    }
    return(res);
}
int determinant(int *matrix[], int matrix_order = n){//
    int res = 0;
    if (matrix_order == 2){
        cout << (matrix[0][0])<< endl;//d
        //res = (matrix[0]*(matrix[3])) - (matrix[1]*matrix[2]);//
        cout << res;
    } else{
        for (int i = 0; i < matrix_order; i++)//выделение подматриц
        {
            int matrix_next_step[-1 + matrix_order][-1 + matrix_order];
            int filler = 0;
            for (int nj = 0; nj < (exponentiation(matrix_order, 2)); nj ++)
            {
                if ((nj%matrix_order) != i){
                    matrix_next_step[int(filler/(-1 + matrix_order))][filler%(matrix_order-1)] = matrix[int(nj/matrix_order)][nj%matrix_order];
                    filler +=1;
                }
            }
            cout << 'r';//*matrix_next_step[0]<< endl;//d
            //res += matrix[0][i]*exponentiation(-1, (i+1)+1)*determinant(&matrix_next_step[0][0], matrix_order-1);
        }
    }
        return res;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << " Это программа для вычисления определителя матрицы n-го порядка" << endl;
    int n = 3;
    int matrix_first[n][n] = {{1,2,3},{4,5,6},{7,8,9}};//
    cout << determinant(matrix_first, n);
    return 0;
}
