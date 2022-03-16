#include <iostream>
#include <clocale>
#include "Matrix.h"
#include "MathOperations1.h"


using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    try
    {
        int n;
        cout << "Выберите номер теста: \n";
        cout << "1. Проверка всех стандартных функций с обычными матрицами \n2. Верхнетреугольная матрица(+диагональная) \n3. Нижнетреугольная матрица \n4. Симметричная матрица \n5. Диагональная и единичная\n";
        cin >> n;
        switch (n)
        {
        case 1:
        {
            int line1, column1, line2, column2;
            cout << "Введите количество строк и столбцов 1 матрицы:\n";
            cin >> line1 >> column1;
            cout << "Введите количество строк и столбцов 2 матрицы:\n";
            cin >> line2 >> column2;
            cout << "Введите матрицу 1:" << endl;
            Matrix mat1 = Matrix(line1, column1);
            cout << "\nВведите матрицу 2:" << endl;
            Matrix mat2 = Matrix(line2, column2);

     
            cout << "Произведение матриц: \n" << mat1 * mat2 << "\n";
            cout << "Сумма матриц: \n" << mat1 + mat2 << "\n";
            cout << "Разница матриц: \n" << mat1 - mat2 << "\n";
            cout << "Первая матрица, умноженная на -1 \n" << -1 * mat1 << "\n";
            cout << "Произведение Адамара: \n" << MultOfAdamard(mat1, mat2) << "\n";
            
            break;
        }
        case 2:
        {
            int line, column;
            cout << "Нижнетреугольная матрица \n\n";
            cout << "Введите количество строк:";
            cin >> line;
            cout << "Введите количество столбцов:";
            cin >> column;
            Matrix User = LowerTriangularMatrix(line, column);
            cout << "Ваша нижнетреугольная матрица\n" << User;

            cout << "Квадрат Вашей нижнетреугольной матрицы: \n" << User * User;

            cout << "Диагональная матрица, полученная из Вашей матрицы: \n" << DiagMatrix(User);
            break;
        }
        case 3:
        {
            int line, column;
            cout << "Верхнетреугольная матрица \n\n";
            cout << "Введите количество строк:";
            cin >> line;
            cout << "Введите количество столбцов:";
            cin >> column;
            Matrix Up = UpperTriangularMatrix(line, column);
            cout << "Ваша верхнереугольная матрица\n" << Up;
            break;
        }
        case 4:
        {
            cout << "Симметричная матрица размера 3*3\n\n";
            Matrix sym = SymMatrix(3, 3);
            cout << "Ваша матрица: \n" << sym;
            break;
        }
        case 5:
        {
            int line, column;
            cout << "Единичная матрица\n";
            cout << "Введите количество строк:";
            cin >> line;
            cout << "Введите количество столбцов:";
            cin >> column;
            UnitMatrix un(line, column);
            cout << un;
            cout << "Диагональная матрица, полученная некоторыми преобразованиями из единичиной матрицы:\n";
            Matrix diag = 5 * un + 3 * un - 2 * un * un;
            cout << diag;
            
            break;
        }
        default:
            cout << "Неверный ввод\n";
            break;
        }
     

        return 0;
    }
    catch (int exc)
    {
        printf("Программа завершилась с ошибками.\n");
        return 0;
       
    }
}
