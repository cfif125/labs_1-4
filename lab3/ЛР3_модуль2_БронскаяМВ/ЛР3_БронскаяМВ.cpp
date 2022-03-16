#include <iostream>
#include <clocale>
#include "Matrix.h"
#include "MathOperations3.h"


using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    try
    {

        int n;
        cout << "Выберите номер теста:" << endl;
        cout << "1. Найти угол между векторами \n2. Ранг матрицы\n3. Обратная матрица (если существует)\n4. Транспонирование матрицы\n";
        cin >> n;

        Matrix m1(2, 2);
        cout << m1 * InverseMatrix(m1) << endl;

        switch (n) {
        case 1:
        {
            int line1, column1, line2, column2;
            cout << "Введите количество строк и столбцов в 1 вектора:";
            cin >> line1 >> column1;
            cout << "Введите количество строк и столбцов в 2 вектора:";
            cin >> line2 >> column2;
            Matrix v1(line1, column1);
            cout << "\n";
            Matrix v2(line2, column2);
            cout << "Угол между векторами: "<<AngleBetVectors(v1, v2) << endl;
            
            break;
        }
        case 2:
        {
            int line, column;
            cout << "Введите количество строк и столбцов в матрице:";
            cin >> line >> column;
            Matrix m(line, column);
            cout << "Ваша матрица: \n" << m << endl;
            cout << "Ранг матрицы: " << GaussMatrixRank(m) << endl;

            
            break;
        }
        case 3:
        {
            int line, column;
            cout << "Введите количество строк и столбцов в матрице:";
            cin >> line >> column;
            Matrix m(line, column);
            cout << "Ваша матрица: \n" << m << endl;
            cout << "Обратная матрица: \n" << InverseMatrix(m) << endl;

            break;
        }
        case 4:
        {
            int line, column;
            cout << "Введите количество строк и столбцов в матрице:";
            cin >> line >> column;
            Matrix m(line, column);
            cout << "Ваша матрица: \n" << m << endl;
            cout << "Транспонированная матрица: \n" << TransposeMatrix(m) << endl;
            system("pause");
            break;
            
        }
        default:
            cout << "Неверный ввод" << endl;
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