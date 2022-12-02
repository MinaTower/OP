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

void del(int* matrix[], const int rows)
{
        for (int j=0; j < rows; j++)
        {
            delete[] matrix[j];
        }
        delete[] matrix;
}

int minor(const int SIZE, int num_element, int* matrix_previous[])
{
    int res = 0;
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
    if (SIZE == 2){
        res = (matrix_next_step[0][0])*(matrix_next_step[1][1]) - ((matrix_next_step[0][1])*(matrix_next_step[1][0]));
        del(&matrix_next_step[0], SIZE);
    } else {
        for (int i = 0; i < SIZE; i++)
        {
        res += (matrix_next_step[0][i])*exponentiation(-1, (i+1)+1)*minor(SIZE -1, i, &matrix_next_step[0]);
        }
        del(&matrix_next_step[0], SIZE);
    }
    return res;
}

int determinant(int* matrix_1[], const int size)
{
    int ans =0;
    if (size == 2){
        ans = (matrix_1[0][0]*(matrix_1[1][1]) - matrix_1[0][1]*(matrix_1[1][0]));
    } else {
        for (int i = 0; i < size; i++)
        {
            ans += (matrix_1[0][i])*exponentiation(-1, (i+1)+1)*minor(size - 1, i, &matrix_1[0]);
        }
    }
    return ans;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << " Это программа для вычисления определителя матрицы n-го порядка" << endl;
    cout << " Введите порядок исследуемой матрицы: ";
    int n;
    cin >> n;
    cout << " Вводите значения элементов матрицы построчно (a[1][1], следом a[1][2] и т.д.)" << endl;
    int** matrix_first = new int*[n];
    for (int row=0;row < n; row ++)
    {
        matrix_first[row] = new int[n];
        for (int column = 0; column < n; column ++)
        {
            int f;
            cin >> f;
            matrix_first[row][column] = f;
        }
    }
    int answer = 0;
    answer = determinant(&matrix_first[0], n);
    cout << "Определитель равен " << answer << endl;
    del(&matrix_first[0], n);
    return 0;
}
