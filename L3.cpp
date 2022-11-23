#include<iostream>
#include<locale>
using namespace std;
const int n = 3;

int exponentiation(int num, int degree)
{
    int res = num;
    for (int i = 2; i <= degree; i++)
    {
        res *= num;
    }
    return(res);
}

int determinant(const int SIZE, int num_element, int** matrix_previous[])
{
    int res = 0;
    int** matrix_next_step[SIZE] = {new int*[SIZE]};
    for (int row = 0; row < SIZE; row++ )
    {
        int filler = 0;
        *matrix_next_step[row] = new int[SIZE];
        for (int column = 0; column < SIZE + 1; column++)
        {
            if (column != num_element){
                matrix_next_step[row][column] = *matrix_previous[((row + 1) * (SIZE + 1)) + filler];
                filler += 1;
            }
        }
    }
    if (SIZE == 2){
        int step = (*matrix_next_step[0][0])*(*matrix_next_step[1][1]) - ((*matrix_next_step[0][1])*(*matrix_next_step[1][0]));
        for (int j=0; j < 2; j++)
        {
            delete[] matrix_next_step[j];
        }
        delete[] matrix_next_step;
        cout << 'r';//
        return step;
    } else {
        for (int i = 0; i < SIZE; i++)
        {
        res += **matrix_previous[i]*exponentiation(-1, (i+1)+1)*determinant(SIZE -1, i, &matrix_next_step[SIZE]);
        }
        for (int j=0; j < SIZE; j++)
        {
            delete[] matrix_next_step[j];
        }
        delete[] matrix_next_step;
    }
    return 0;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << " Это программа для вычисления определителя матрицы n-го порядка" << endl;
    int answer = 0;
    int **matrix_first[n] = {new int*[n]};
    for (int row=0;row <n; row ++)
    {
        *matrix_first[row] = new int [n];
        for (int column = 0; column < n; column ++)
        {
            //int f;
            //cin >> f;
            *matrix_first[row][column] = (row*n + column);//
        }
    }
    cout << 'v';//
    if (n == 2){
            answer = (*matrix_first[0][0]*(*matrix_first[1][1]) - *matrix_first[0][1]*(*matrix_first[1][0]));
    } else {
        for (int i = 0; i < n; i++)
        {
            answer += (*matrix_first[0][i])*exponentiation(-1, (i+1)+1)*determinant(n - 1, i, &matrix_first[n]);
        }
    }
    cout << "Определитель равен " << answer << endl;
    return 0;
}
