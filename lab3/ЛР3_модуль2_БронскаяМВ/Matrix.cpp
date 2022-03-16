#include "Matrix.h"

Matrix::Matrix()
{

}

//Реализация конструктора класса Матрица, с инициализацией переменных
//Если вызывается конструктор без параметров, то считается, что
//количество строк и столбцов = 0
Matrix::Matrix(int countLines, int countCol) : countOfLines(countLines), countOfColumns(countCol)
{
    //Если количество линий или столбцов = 0
    //то исключение
    try
    {
        if ((countOfLines <= 0) || (countOfColumns <= 0))
            throw "Неверное количество и строк и столбцов...\n";
    }
    catch (const char* msg)
    {
        cout << msg << endl;
        throw - 1;
    }
    //Временная переменная для хранения значения
    double item_data;
    //Временный вектор
    vector<double> temp_vector;
    //Заполнение матрицы элементами
    for (int line = 0; line < countOfLines; line++)
    {
        for (int column = 0; column < countOfColumns; column++)
        {
            //Запрос ввода значения для элемента матрицы
            printf("Элемент[%d][%d] = ", line, column);
            cin >> item_data;
            //добавление в временную строку
            temp_vector.push_back(item_data);
        }
        //добавление строки в матрицу
        data.push_back(temp_vector);
        //очистка временной строки
        temp_vector.clear();
    }
}



UnitMatrix::UnitMatrix(int countLin, int countCol) :Matrix()
{
    //Если количество линий или столбцов = 0
    //то исключение
    //Бросок исключения, если матрица не квадратная
    try
    {
        if ((countLin <= 0) || (countCol <= 0))
            throw "Неверное количество и строк и столбцов...\n";
        if (((countLin <= 0) || (countCol <= 0)) || (countLin != countCol))
            throw "\nНеверное количество строк и/или столбцов. Матрица должна быть квадратной. \n\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    //Размерности матрицы
    countOfLines = countLin;
    countOfColumns = countCol;
    //Временная строка матрицы (вектор значений)
    vector<double> temp_vector;
    for (int line = 0; line < countOfLines; line++)
    {
        for (int column = 0; column < countOfColumns; column++)
        {
            //елси элемент диагонали
            if (line == column)
            {
                //то установить 1
                temp_vector.push_back(1);
            }
            else
            {
                //во всех остальных элементах 0
                temp_vector.push_back(0);
            }
        }
        //добавить строку в матрицу
        data.push_back(temp_vector);
        //очистка временной строки
        temp_vector.clear();
    }
}

//Единичная матрица на основе созданной матрицы
UnitMatrix::UnitMatrix(const Matrix& pMatrix)
{
    //Копирование размерностей
    countOfLines = pMatrix.countOfLines;
    countOfColumns = pMatrix.countOfColumns;

    //Если количество линий или столбцов = 0
    //то исключение
    //Бросок исключения, если матрица не квадратная
    try
    {
        if ((countOfLines <= 0) || (countOfColumns <= 0))
            throw "Неверное количество и строк и столбцов. \n";
        if (countOfLines != countOfColumns)
            throw "\nНеверное количество строк и/или столбцов. Матрица должна быть квадратной. \n\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    //врменная строка матрицы
    vector<double> temp_vector;
    //установка единиц по диагонали, по остальным нуль
    for (int line = 0; line < countOfLines; line++)
    {
        for (int column = 0; column < countOfColumns; column++)
        {
            if (line == column)
            {
                temp_vector.push_back(1);
            }
            else
            {
                temp_vector.push_back(0);
            }
        }
        data.push_back(temp_vector);
        temp_vector.clear();
    }
}

DiagMatrix::DiagMatrix()
{

}

DiagMatrix::DiagMatrix(int countLin, int countCol)
{
    //Установка размерностей
    countOfLines = countLin;
    countOfColumns = countCol;

    //Если количество линий или столбцов = 0
   //то исключение
   //Бросок исключения, если матрица не квадратная
    try
    {
        if ((countOfLines <= 0) || (countOfColumns <= 0))
            throw "Неверное количество и строк и столбцов. \n";
        if (countOfLines != countOfColumns)
            throw "\nНеверное количество строк и/или столбцов. Матрица должна быть квадратной. \n\n";
    }
    catch (const char* msg)
    {
        cout << msg << endl;
        throw - 1;
    }
    //временный буфер для значений
    double item_data;
    //временная строка матрицы
    vector<double> temp_vector;
    //Заполнение матрицы значениями (элементов на диагонали)
    for (int line = 0; line < countOfLines; line++)
    {
        for (int column = 0; column < countOfColumns; column++)
        {
            if (line == column)
            {
                printf("Элемент[%d][%d] = ", line, column);
                cin >> item_data;
                temp_vector.push_back(item_data);
            }
            else
            {
                temp_vector.push_back(0);
            }
        }
        data.push_back(temp_vector);
        temp_vector.clear();
    }
}

DiagMatrix::DiagMatrix(const Matrix& pMatrix)
{
    //Размерности
    countOfLines = pMatrix.countOfLines;
    countOfColumns = pMatrix.countOfColumns;

    //Если количество линий или столбцов = 0
    //то исключение
    //Бросок исключения, если матрица не квадратная
    try
    {
        if ((countOfLines <= 0) || (countOfColumns <= 0))
            throw "Неверное количество и строк и столбцов. \n";
        if (countOfLines != countOfColumns)
            throw "\nНеверное количество строк и/или столбцов. Матрица должна быть квадратной. \n\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    //Временная строка матрицы
    vector<double> temp_vector;
    //Заполнение значениями диагональных элементов матрицы
    for (int line = 0; line < countOfLines; line++)
    {
        for (int column = 0; column < countOfColumns; column++)
        {
            if (line == column)
            {
                temp_vector.push_back(pMatrix.data[line][column]);
            }
            else
            {
                temp_vector.push_back(0);
            }
        }
        data.push_back(temp_vector);
        temp_vector.clear();
    }
}

UpperTriangularMatrix::UpperTriangularMatrix() {}

UpperTriangularMatrix::UpperTriangularMatrix(const Matrix& pMatrix)
{
    //Размерности
    countOfLines = pMatrix.countOfLines;
    countOfColumns = pMatrix.countOfColumns;

    //Если количество линий или столбцов = 0
   //то исключение
   //Бросок исключения, если матрица не квадратная
    try
    {
        if ((countOfLines <= 0) || (countOfColumns <= 0))
            throw "Неверное количество и строк и столбцов. \n";
        if (countOfLines != countOfColumns)
            throw "\nНеверное количество строк и/или столбцов. Матрица должна быть квадратной. \n\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    //Временная строка матрицы
    vector<double> temp_vector;
    //Заполнение верхней треугольной матрицы
    for (int line = 0; line < countOfLines; line++)
    {
        for (int column = 0; column < countOfColumns; column++)
        {
            if (line == column)
            {
                temp_vector.push_back(pMatrix.data[line][column]);
            }
            else
                if (column > line)
                {
                    temp_vector.push_back(pMatrix.data[line][column]);
                }
                else
                {
                    temp_vector.push_back(0);
                }
        }
        data.push_back(temp_vector);
        temp_vector.clear();
    }
}


//Конструктор для создания новой верхней треугольной матрицы
UpperTriangularMatrix::UpperTriangularMatrix(int countLin = 0, int countCol = 0)
{
    //Размерность
    countOfLines = countLin;
    countOfColumns = countCol;

    //Если количество линий или столбцов = 0
    //то исключение
    //Бросок исключения, если матрица не квадратная
    try
    {
        if ((countOfLines <= 0) || (countOfColumns <= 0))
            throw "Неверное количество и строк и столбцов. \n";
        if (countOfLines != countOfColumns)
            throw "\nНеверное количество строк и/или столбцов. Матрица должна быть квадратной. \n\n";
    }
    catch (const char* msg)
    {
        cout << msg << endl;
        throw - 1;
    }

    //Буфер для хранения значения
    double item_data;
    //Временная строка матрицы
    vector<double> temp_vector;
    //Заполнение верхней треугольной матрицы
    for (int line = 0; line < countOfLines; line++)
    {
        for (int column = 0; column < countOfColumns; column++)
        {
            if (line == column)
            {
                printf("Элемент[%d][%d] = ", line, column);
                cin >> item_data;
                temp_vector.push_back(item_data);
            }
            else
                if (column > line)
                {
                    printf("Элемент[%d][%d] = ", line, column);
                    cin >> item_data;
                    temp_vector.push_back(item_data);
                }
                else
                {
                    temp_vector.push_back(0);
                }
        }
        data.push_back(temp_vector);
        temp_vector.clear();
    }
}


LowerTriangularMatrix::LowerTriangularMatrix()
{

}

//конструктор для создания матрицы на основе существующей матрицы
LowerTriangularMatrix::LowerTriangularMatrix(const Matrix& pMatrix)
{
    //Размерности
    countOfLines = pMatrix.countOfLines;
    countOfColumns = pMatrix.countOfColumns;

    //Если количество линий или столбцов = 0
    //то исключение
    //Бросок исключения, если матрица не квадратная
    try
    {
        if ((countOfLines <= 0) || (countOfColumns <= 0))
            throw "Неверное количество и строк и столбцов. \n";
        if (countOfLines != countOfColumns)
            throw "\nНеверное количество строк и/или столбцов. Матрица должна быть квадратной. \n\n";
    }
    catch (const char* msg)
    {
        cout << msg << endl;
        throw - 1;
    }
    //Временная строка матрицы
    vector<double> temp_vector;
    //Заполнение нижней треугольной матрицы
    for (int line = 0; line < countOfLines; line++)
    {
        for (int column = 0; column < countOfColumns; column++)
        {
            if (line == column)
            {
                temp_vector.push_back(pMatrix.data[line][column]);
            }
            else
                if (column < line)
                {
                    temp_vector.push_back(pMatrix.data[line][column]);
                }
                else
                {
                    temp_vector.push_back(0);
                }
        }
        data.push_back(temp_vector);
        temp_vector.clear();
    }
}

//Конструктор для создания матрицы на основе количества строки и столбца
LowerTriangularMatrix::LowerTriangularMatrix(int countLin = 0, int countCol = 0)
{
    //Размерности
    countOfLines = countLin;
    countOfColumns = countCol;

    //Если количество линий или столбцов = 0
   //то исключение
   //Бросок исключения, если матрица не квадратная
    try
    {
        if ((countOfLines <= 0) || (countOfColumns <= 0))
            throw "Неверное количество и строк и столбцов. \n";
        if (countOfLines != countOfColumns)
            throw "\nНеверное количество строк и/или столбцов. Матрица должна быть квадратной. \n\n";

    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }

    //Буфер для хранения значения элемента матрицы
    double item_data;
    //Временная строка матрицы
    vector<double> temp_vector;
    //Заполнение нижней треугольной матрицы
    for (int line = 0; line < countOfLines; line++)
    {
        for (int column = 0; column < countOfColumns; column++)
        {
            if (line == column)
            {
                printf("Элемент[%d][%d] = ", line, column);
                scanf_s("%lf", &item_data);
                temp_vector.push_back(item_data);
            }
            else
                if (column < line)
                {
                    printf("Элемент[%d][%d] = ", line, column);
                    cin >> item_data;
                    temp_vector.push_back(item_data);
                }
                else
                {
                    temp_vector.push_back(0);
                }
        }
        data.push_back(temp_vector);
        temp_vector.clear();
    }
}

//Конструктор для создания новой симметричной матрицы (переменные по умолчанию = 0)
SymMatrix::SymMatrix(int countLin = 0, int countCol = 0)
{
    countOfLines = countLin;
    countOfColumns = countCol;

    //Если количество линий или столбцов = 0
   //то исключение
   //Бросок исключения, если матрица не квадратная
    try
    {
        if ((countOfLines <= 0) || (countOfColumns <= 0))
            throw "Неверное количество и строк и столбцов. \n";
        if (countOfLines != countOfColumns)
            throw "\nНеверное количество строк и/или столбцов. Матрица должна быть квадратной. \n\n";
    }
    catch (const char* msg)
    {
        cout << msg << endl;
        throw - 1;
    }

    //Буффер для хранения значения
    double item_data;

    //Временная строка матрицы
    vector<double> temp_vector;
    cout << "Введите матрицу поэлементно: " << endl;
    //Заполнение симметричной матрицы значениями. Сначала заполняется верхняя треугольная матрица
    for (int line = 0; line < countOfLines; line++)
    {
        for (int column = 0; column < countOfColumns; column++)
        {
            if (line == column)
            {
                printf("Элемент[%d][%d] = ", line, column);
                cin >> item_data;
                temp_vector.push_back(item_data);
            }
            else
                if (column > line)
                {
                    printf("Элемент[%d][%d] и Элемент[%d][%d] = ", line, column, column, line);
                    cin >> item_data;

                    temp_vector.push_back(item_data);
                }
                else
                {
                    temp_vector.push_back(0);
                }
        }
        data.push_back(temp_vector);
        temp_vector.clear();
    }
    //Зеркальное отображение верхнего "треугольника" на нижний "треугольник"
    for (int line = 0; line < countOfLines; line++)
    {
        for (int column = 0; column < countOfColumns; column++)
        {
            if (column < line)
            {
                data[line][column] = data[column][line];
            }
        }
    }

}


//перегрузка оператора ввывода
std::ostream& operator<< (std::ostream& out, const Matrix& matrix)
{
    //Временная строка матрицы
    vector<double> temp;

    //Для всех линий матрицы
    for (int line = 0; line < matrix.countOfLines; line++)
    {
        //скопировать в буфер строку матрицы
        temp = matrix.data[line];
        //Для всех столбцов матрицы
        for (int column = 0; column < matrix.countOfColumns; column++)
        {
            //вывод всех элементов строки
            cout << temp[column] << "\t";
        }
        //абзац
        cout << "\n";
    }
    //возврат вывода
    return out;
}