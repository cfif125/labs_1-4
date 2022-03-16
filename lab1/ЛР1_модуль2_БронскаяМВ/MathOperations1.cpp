#include "MathOperations1.h"


//Перегрузка операции суммы
Matrix operator+(const Matrix& A, const Matrix& B)
{
    //Исключение
    //Суммироваться могут только матрицы одинакового размера
    // иначе выбросить исключение
    try
    {
        if ((A.countOfLines != B.countOfLines) || (A.countOfColumns != B.countOfColumns))
            throw "Суммирование невозможно, матрицы имеют разные размерности\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    //Временная матрица
    Matrix temp_matrix;

    //Копирование размерностей
    temp_matrix.countOfLines = A.countOfLines;
    temp_matrix.countOfColumns = A.countOfColumns;

    //Временная строка матрицы
    vector<double> temp_vector;
    //для всех линий
    for (int line = 0; line < temp_matrix.countOfLines; line++)
    {
        //для всех столбцов
        for (int column = 0; column < temp_matrix.countOfColumns; column++)
        {
            //заполнить временную строку матрицы суммой соответствующих элементов
            temp_vector.push_back(A.data[line][column] + B.data[line][column]);
        }
        //добавить в матрицу строку из буфера
        temp_matrix.data.push_back(temp_vector);
        temp_vector.clear();
    }
    //возвратить матрицу
    return temp_matrix;
}

//Перегрузка операции вычитания
Matrix operator-(const Matrix& A, const Matrix& B)
{
    //Разность вычисляется только для равноразмерных матриц,
    //иначе выбросить исключение
    try
    {
        if ((A.countOfLines != B.countOfLines) || (A.countOfColumns != B.countOfColumns))
            throw "Вычитание невозможно, матрицы имеют разные размерности\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    //Временная матрица
    Matrix temp_matrix;

    //копирование разерностей
    temp_matrix.countOfLines = A.countOfLines;
    temp_matrix.countOfColumns = A.countOfColumns;
    //временная строка матрицы
    vector<double> temp_vector;
    //Реализация вычитания
    for (int line = 0; line < temp_matrix.countOfLines; line++)
    {
        for (int column = 0; column < temp_matrix.countOfColumns; column++)
        {
            temp_vector.push_back(A.data[line][column] - B.data[line][column]);
        }
        temp_matrix.data.push_back(temp_vector);
        temp_vector.clear();
    }
    return temp_matrix;
}

//Перегрузка операции произведения
Matrix operator*(const Matrix& A, const Matrix& B)
{
    //Исключение
    //Число столбцов в первом сомножителе
    //должно равняться числу строк во втором,
    //иначе выбросить исключение
    try
    {
        if (A.countOfColumns != B.countOfLines)
            throw "Произведение невозможно, матрицы имеют неподходящие размерности\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    //Временная матрица
    Matrix temp_matrix;

    //Размерности
    temp_matrix.countOfLines = A.countOfLines;
    temp_matrix.countOfColumns = B.countOfColumns;
    //Буфер для хранения значения
    double temp_data = 0;
    //Временная строка
    vector<double> temp_vector;
    //Реализация операции умножения (строка вектор матрицы А умножается на
    // столбец вектор матрицы B)
    for (int i = 0; i < A.countOfLines; i++)
    {
        for (int j = 0; j < temp_matrix.countOfColumns; j++)
        {
            for (int k = 0; k < A.countOfColumns; k++)
            {
                temp_data += A.data[i][k] * B.data[k][j];
            }
            temp_vector.push_back(temp_data);
            temp_data = 0;
        }
        temp_matrix.data.push_back(temp_vector);
        temp_vector.clear();
    }
    return temp_matrix;
}

//Перегрузка операции произведения числа на матрицу
Matrix operator*(const double& d, const Matrix& B)
{
    //временная матрица
    Matrix temp_matrix;

    //Копирование размерностей
    temp_matrix.countOfLines = B.countOfLines;
    temp_matrix.countOfColumns = B.countOfColumns;
    //буфер для значений элементов
    double temp_data = 0;
    //временная строка матрицы
    vector<double> temp_vector;
    //Реализация умножения значения на матрицу
    for (int i = 0; i < temp_matrix.countOfLines; i++)
    {
        for (int j = 0; j < temp_matrix.countOfColumns; j++)
        {
            temp_data = d * B.data[i][j];
            temp_vector.push_back(temp_data);
        }
        temp_matrix.data.push_back(temp_vector);
        temp_vector.clear();
    }
    return temp_matrix;
}

//Произведение Адамара
Matrix MultOfAdamard(const Matrix& A, const Matrix& B)
{
  
    try
    {
        if ((A.countOfLines != B.countOfLines) || (A.countOfColumns != B.countOfColumns))
            throw "Произведение Адамара невозможно, матрицы имеют разные размерности\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    //временная матрица
    Matrix temp_matrix;
    //временная строка матрицы
    vector<double> temp_vector;
    //Копирование размерностей
    temp_matrix.countOfLines = A.countOfLines;
    temp_matrix.countOfColumns = A.countOfColumns;

    //Реализация алгоритма произведения Адамара (перемножение элементов)
    for (int line = 0; line < temp_matrix.countOfLines; line++)
    {
        for (int column = 0; column < temp_matrix.countOfColumns; column++)
        {
            temp_vector.push_back(A.data[line][column] * B.data[line][column]);
        }
        temp_matrix.data.push_back(temp_vector);
        temp_vector.clear();
    }
    return temp_matrix;
}