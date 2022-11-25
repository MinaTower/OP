#include<iostream>
#include<locale>
using namespace std;

int exponentiation(int num, int degree)
{
    int res = num;
    for (int i = 2; i <= degree; i++)
    {
        res *= num;
    }
    return(res);
}

int determinant(const int SIZE, int num_element, int* matrix_previous[])
{
    int res;
    int** matrix_next_step = new int*[SIZE];
    for (int row = 0; row < SIZE; row++ )
    {
        int column = 0;
        matrix_next_step[row] = new int[SIZE];
        for (int filler = 0; filler < SIZE +1; filler++)
        {
            if (filler != num_element){
                matrix_next_step[row][column] = matrix_previous[row + 1][filler];
                column += 1;
            }
        }
    }
    //cout << "dva"<<endl;//
    if (SIZE == 2){
        res = (matrix_next_step[0][0])*(matrix_next_step[1][1]) - ((matrix_next_step[0][1])*(matrix_next_step[1][0]));
        for (int j=0; j < 2; j++)
        {
            delete[] matrix_next_step[j];
        }
        delete[] matrix_next_step;
    } else {
        //cout <<"Det"<<endl;//
        for (int i = 0; i < SIZE; i++)
        {
        res += (matrix_next_step[0][i])*exponentiation(-1, (i+1)+1)*determinant(SIZE -1, i, &matrix_next_step[0]);
        }
        for (int j=0; j < SIZE; j++)
        {
            delete[] matrix_next_step[j];
        }
        delete[] matrix_next_step;
    }
    cout <<res<<endl;//
    return res;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << " Это программа для вычисления определителя матрицы n-го порядка" << endl;
    int answer = 0;
    const int n = 4;
    int** matrix_first = new int*[n];
    for (int row=0;row <n; row ++)
    {
        matrix_first[row] = new int[n];
        for (int column = 0; column < n; column ++)
        {
            //int f;
            //cin >> f;
            matrix_first[row][column] = (row*n + column+1);//f;
        }
    }
    if (n == 2){
        answer = (matrix_first[0][0]*(matrix_first[1][1]) - matrix_first[0][1]*(matrix_first[1][0]));
        for (int j=0; j < n; j++)
        {
            delete[] matrix_first[j];
        }
        delete[] matrix_first;
    } else {
        for (int i = 0; i < n; i++)
        {
            answer += (matrix_first[0][i])*exponentiation(-1, (i+1)+1)*determinant(n - 1, i, &matrix_first[0]);
        }
    }
    cout << "Определитель равен " << answer << endl;
    return 0;
}
