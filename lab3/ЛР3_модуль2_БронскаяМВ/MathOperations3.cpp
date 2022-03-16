#include "MathOperations3.h"


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
    //для всех строк
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

//ЛАБОРАТОРНАЯ РАБОТА №2

//Вычисление определителя методом Гаусса
double MethodGauss(const Matrix& matrix)
{
    //Если количество линий или столбцов = 0
   //то исключение
   //Бросок исключения, если матрица не квадратная
    try
    {
        if (((matrix.countOfLines <= 0) || (matrix.countOfColumns <= 0)) || (matrix.countOfLines != matrix.countOfColumns))
            throw "Неверное количество строк и столбцов\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    //Временная матрица = передаваемой в функцию матрицу
    Matrix temp_matrix = matrix;
    //Изначально определитель = 1ж
    double det = 1;
    //Номер строки, где 1 элемент
    //имеет максимальное значение
    int max_item_index;
    //Значение максимального элемента
    double max_item;
    //временный буфер
    //double temp_buffer;
    //коэффициент перемножения (для формрования треугольной матрицы)
    double mult_coeff;
    //для всех линий матрицы
    for (int line = 0; line < matrix.countOfLines; line++)
    {
        //максимальный элемент = значению элемента по модулю
        max_item = fabs(matrix.data[line][line]);
        //максимальный индекс строки
        max_item_index = line;
        //поиск максимального элемента
        for (int i = line + 1; i < matrix.countOfLines; i++)
        {
            double element = fabs(matrix.data[i][line]);
            if (element > max_item)
            {
                max_item = element;
                max_item_index = i;
            }
        }

    }
    //Приведение матрицы в вид верхней треугольной матрицы
    for (int line = 0; line < temp_matrix.countOfLines; line++)
    {
        for (int line2 = line + 1; line2 < temp_matrix.countOfLines; line2++)
        {
            if (temp_matrix.data[line][line] != 0)
                mult_coeff = -1.0 * temp_matrix.data[line2][line] / temp_matrix.data[line][line];
            else break;
            mult_coeff = -1.0 * temp_matrix.data[line2][line] / temp_matrix.data[line][line];
            //cout << "mult_coeff = " << mult_coeff << endl;
            for (int column = line; column < matrix.countOfColumns; column++)
            {
                temp_matrix.data[line2][column] = temp_matrix.data[line2][column] + temp_matrix.data[line][column] * mult_coeff;
            }
        }
    }

    //Определитель рассчитывается как произведение элементов матрицы,
    //расположенных по диагонали
    for (int line = 0; line < temp_matrix.countOfLines; line++)
    {
        for (int column = 0; column < temp_matrix.countOfColumns; column++)
        {
            if (line == column)
            {
                det *= temp_matrix.data[line][column];
            }
        }
    }
    return det;
}

double Trace(const Matrix& matrix)
{
    //след имеет смысл искать только у квадратных матриц
    try
    {
        if (((matrix.countOfLines <= 0) || (matrix.countOfColumns <= 0)) || (matrix.countOfLines != matrix.countOfColumns))
            throw "Неверное количество строк и столбцов\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    //Копирование матрицы в временную
    Matrix temp_matrix = matrix;
    //След = 0
    double tr = 0;
    //Для всех строк
    for (int line = 0; line < temp_matrix.countOfLines; line++)
    {
        //Для всех столбцов
        for (int column = 0; column < temp_matrix.countOfColumns; column++)
        {
            //Суммирование элементов, расположенных по диагонали
            if (line == column)
                tr += temp_matrix.data[line][column];
        }
    }
    return tr;
}


double ScalarMult(const Matrix& v1, const Matrix& v2)
{
    //Исключение.
   //Если одная (каждая) из матриц не является вектором
   //то выбросить исключение
    try
    {
        if (!((v1.countOfLines == 1) && (v1.countOfColumns >= 1)) && !((v1.countOfLines >= 1) && (v1.countOfColumns == 1)))
            throw "Не являются вектором одна из (все) переменных(ые)...\n";
        if (!((v2.countOfLines == 1) && (v2.countOfColumns >= 1)) && !((v2.countOfLines >= 1) && (v2.countOfColumns == 1)))
            throw "Не являются вектором одна из (все) переменных(ые)...\n";
        
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    //временные вектора
    vector<double> temp_v1;
    vector<double> temp_v2;
    //значения модули векторов
    double abs_val[2];
    //скалярное произведение векторов
    double scalar_mult = 0;
    //временные буффера
    double temp[2];
    //Приведение столбцов-векторов в строки-вектора
    if (v1.countOfLines > 1)
    {
        for (int line = 0; line < v1.countOfLines; line++)
        {
            temp_v1.push_back(v1.data[line][0]);
        }
    }
    else
    {
        temp_v1 = v1.data[0];
    }

    if (v2.countOfLines > 1)
    {
        for (int line = 0; line < v2.countOfLines; line++)
        {
            temp_v2.push_back(v2.data[line][0]);
        }
    }
    else
    {
        temp_v2 = v2.data[0];
    }
    /*try {
        if (temp_v1.size() != temp_v2.size())
            throw ("Размеры векторов не совпадают\n\n");
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }*/

    //Скалярное произведение векторов
    for (int column = 0; column < temp_v2.size(); column++)
    {
        scalar_mult += temp_v1[column] * temp_v2[column];
    }


    return scalar_mult;
}

double Norma(const Matrix& v1)
{
    //Исключение.
    //Если одная (каждая) из матриц не является вектором
    //то выбросить исключение
    try
    {
        if (!((v1.countOfLines == 1) && (v1.countOfColumns >= 1)) && !((v1.countOfLines >= 1) && (v1.countOfColumns == 1)))
            throw "Объект не является вектором\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    vector<double> temp_v1;
    double summa = 0;
    double abs_val;

    if (v1.countOfLines > 1)
    {
        for (int line = 0; line < v1.countOfLines; line++)
        {
            temp_v1.push_back(v1.data[line][0]);
        }
    }
    else
    {
        temp_v1 = v1.data[0];
    }

    for (int column = 0; column < temp_v1.size(); column++)
    {
        summa += temp_v1[column] * temp_v1[column];
    }
    //вычисление модуля из суммы квадратов элементов (извлечение из под корня)
    abs_val = sqrt(summa);
    return abs_val;
}

double MaxNorma(const Matrix& v1)
{
    //Исключение.
    //Если одная (каждая) из матриц не является вектором
    //то выбросить исключение
    try
    {
        if (v1.countOfLines <= 0 || v1.countOfColumns <= 0)
            throw "Неподходящий размер вектора \n";
        if (!((v1.countOfLines == 1) && (v1.countOfColumns >= 1)) && !((v1.countOfLines >= 1) && (v1.countOfColumns == 1)))
            throw "Объект не является вектором\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    vector<double> temp_v1;
    double max = DBL_MIN;

    if (v1.countOfLines > 1)
    {
        for (int line = 0; line < v1.countOfLines; line++)
        {
            temp_v1.push_back(v1.data[line][0]);
        }
    }
    else
    {
        temp_v1 = v1.data[0];
    }

    for (int column = 0; column < temp_v1.size(); column++)
    {
        if (temp_v1[column] > max)
            max = temp_v1[column];
    }
    return max;
}


//Норма Фробениуса - корень из суммы квадратов всех элементов
double NormFrobenius(const Matrix& matrix)
{
    //Копирование матрицы в временную
    Matrix temp_matrix = matrix;
    //Суммма возведенных в квадрат элементов = 0
    double acc = 0;
    //Для всех линий
    for (int line = 0; line < temp_matrix.countOfLines; line++)
    {
        //Для всех столбцов
        for (int column = 0; column < temp_matrix.countOfColumns; column++)
        {
            //Суммирование элементов возведенных в квадрат
            acc += temp_matrix.data[line][column] * temp_matrix.data[line][column];
        }
    }
    //Возврат значения равному сумме извлеченной из квадратного корня
    return sqrt(acc);
}

double AngleBetVectors(const Matrix& v1, const Matrix& v2)
{

    //временные вектора
    vector<double> temp_v1;
    vector<double> temp_v2;
    //значения модули векторов
    double abs_val[2];
    //скалярное произведение векторов
    double scalar_mult = 0;
    //временные буффера
    double temp[2];
    //Приведение столбцов-векторов в строки-вектора
    if (v1.countOfLines > 1)
    {
        for (int line = 0; line < v1.countOfLines; line++)
        {
            temp_v1.push_back(v1.data[line][0]);
        }
    }
    else
    {
        temp_v1 = v1.data[0];
    }

    if (v2.countOfLines > 1)
    {
        for (int line = 0; line < v2.countOfLines; line++)
        {
            temp_v2.push_back(v2.data[line][0]);
        }
    }
    else
    {
        temp_v2 = v2.data[0];
    }
    double scalar = ScalarMult(v1, v2);

    //обнуление
    temp[0] = 0;
    temp[1] = 0;
    //сумма квадратов элементов векторов
    for (int column = 0; column < temp_v2.size(); column++)
    {
        temp[0] += temp_v1[column] * temp_v1[column];
        temp[1] += temp_v2[column] * temp_v2[column];
    }
    //вычисление модуля из суммы квадратов элементов (извлечение из под корня)
    abs_val[0] = sqrt(temp[0]);
    abs_val[1] = sqrt(temp[1]);


    return (scalar / (abs_val[0] * abs_val[1]));
}

//Ранг Матрицы (с помощью алгоритма Гаусса);
int GaussMatrixRank(const Matrix& matrix)
{
    //временная матрица = матрице аргументу
    Matrix temp_matrix = matrix;
    //индекс строки с максимальных элементов
    //int max_item_index;
    //максиальное значение
    //double max_item;
    //временный буффер
    double temp_buffer;
    //коэффициент умножения
    double mult_coeff;
    //Приведение матрицы в треугольный вид
    for (int line = 0; line < matrix.countOfLines; line++)
    {
        for (int line2 = line + 1; line2 < temp_matrix.countOfLines; line2++)
        {
            if (temp_matrix.data[line][line] != 0)
                mult_coeff = -1.0 * temp_matrix.data[line2][line] / temp_matrix.data[line][line];
            else break;

            for (int column = line; column < matrix.countOfColumns; column++)
            {
                temp_matrix.data[line2][column] = temp_matrix.data[line2][column] + temp_matrix.data[line][column] * mult_coeff;
            }
        }
    }
    cout << temp_matrix << endl;
    //Подсчет ненулевых строк
    int count_rank = 0;
    int have_line = 0;
    for (int line = 0; line < temp_matrix.countOfLines; line++)
    {
        for (int column = 0; column < temp_matrix.countOfColumns; column++)
        {
            if (temp_matrix.data[line][column] != 0.0)
            {
                have_line = 1;
                break;
            }
        }
        if (have_line)
            count_rank++;
        have_line = 0;
    }
    //Вернуть ранг матрицы
    return count_rank;
}

//Вспомогательная функция получения минора матрицы
Matrix GetMinorElementsMatrix(const Matrix& matrix, int line, int column)
{
    //Временная матрица
    Matrix temp_matrix;
    //временная строка матрицы
    vector<double> temp_vector;
    //Для каждой строки i1 определителя
    for (int i = 0; i < matrix.countOfLines; i++)
    {
        //Для каждого столбца j1 определителя
        for (int j = 0; j < matrix.countOfColumns; j++)
        {
            //поиск значений минора, и добавление во временную строку
            if (!((i == line) && (j == column)) && !((i == line) && (j != column)) && !((i != line) && (j == column)))
            {
                temp_vector.push_back(matrix.data[i][j]);
                
            }
            //Конец цикла
        }
        //Елси временная строка не пуста, добавить в матрицу минора
        if (temp_vector.size() != 0)
        {
            temp_matrix.data.push_back(temp_vector);
            temp_vector.clear();
        }
        //Конец цикла
    }
    //Возврат определителя ij
    //Копирование размерностей
    temp_matrix.countOfLines = temp_matrix.data.size();
    temp_matrix.countOfColumns = temp_matrix.data.size();
    //вернуть минор 
    return temp_matrix;
   
}

//Транспонирование матрицы
Matrix TransposeMatrix(const Matrix& matrix)
{
    //Временная матрица
    Matrix temp_matrix;
    //Временная строка матрицы
    vector<double> temp_vector;
    //Копирование размерностей
    temp_matrix.countOfLines = matrix.countOfColumns;
    temp_matrix.countOfColumns = matrix.countOfLines;

    //поворот строк (отображение в столбцы)
    for (int column = 0; column < matrix.countOfColumns; column++)
    {
        for (int line = 0; line < matrix.countOfLines; line++)
        {
            temp_vector.push_back(matrix.data[line][column]);
        }
        temp_matrix.data.push_back(temp_vector);
        temp_vector.clear();
    }
    return temp_matrix;
}

//Вычисление обратной матрицы
Matrix InverseMatrix(const Matrix& matrix)
{

    try {
        if (MethodGauss(matrix) == 0)
            throw ("Обратной матрицы не существует\n");
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    //Матрица алгебраических дополнений
    Matrix algMatrix;
    //транспонированная матрица алгебраических дополнений
    Matrix transAlgMatrix;
    //обратная матрица
    Matrix reverseMatrix;
    //временная строка матрицы
    vector<double> temp_vector;
    //определитель матрицы
    double detMatrix = MethodGauss(matrix);
    //Циклы обходят каждый элемент, начиная с вернего левого,
    // слева направо, сверху вниз
    for (int line = 0; line < matrix.countOfLines; line++)
    {
        for (int column = 0; column < matrix.countOfColumns; column++)
        {
            //вычисление алгебраического дополнения для каждого элемента матрицы
            double temp = pow(-1, line + column) * MethodGauss(GetMinorElementsMatrix(matrix, line, column));
            if (temp == 0)
                temp = fabs(temp);
            temp_vector.push_back(temp);
        }
        //добавление буфферной строки в матрицу
        algMatrix.data.push_back(temp_vector);
        temp_vector.clear();
    }
    //копирование размерностей
    algMatrix.countOfLines = matrix.countOfLines;
    algMatrix.countOfColumns = matrix.countOfColumns;
    //вычисление транспонированной матрицы
    transAlgMatrix = TransposeMatrix(algMatrix);
    //вычисление обратной матрицы
    reverseMatrix = 1 / detMatrix * transAlgMatrix;
    //вернуть результат
    return reverseMatrix;
}