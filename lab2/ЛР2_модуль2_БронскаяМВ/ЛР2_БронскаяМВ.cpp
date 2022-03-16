#include <iostream>
#include <clocale>
#include "Matrix.h"
#include "MathOperations2.h"


using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    try
    {

        int n;
        cout << "Выберите номер теста:" << endl;
        cout << "1. Корректная работа функций с матрицей \n2. Корректная работа с векторами\n3. Посчитать норму у матрицы (неприлично)\n4. Посчитать определитель у неквадратной матрицы (неприлично)\n";
        cin >> n;

        switch (n) {
        case 1:
        {
            cout << "Введите любую матрицу порядка 3" << endl;
            Matrix m(3, 3);
            cout << "\nВаша матрица:\n" << m << endl;
            cout << "След: " << Trace(m) << endl;
            cout << "Определитель: " << MethodGauss(m) << endl;
            cout << "Норма Фробениуса: " << NormFrobenius(m) << endl;
            break;
        }
        case 2:
        {
            cout << "Введите 2 любых вектора" << endl;
            Matrix v1(1, 3), v2(1, 3);
            cout << "Скалярное произведение: " << ScalarMult(v1, v2) << endl;
            cout << "Норма 1-го вектора: " << Norma(v1) << endl;
            cout << "Максимальная норма 1-го: " << MaxNorma(v1) << endl;
            break;
        }
        case 3: 
        {
            cout << "\nВведите матрицу:\n";
            Matrix m(2, 2);
            cout << "\nВычисляем векторную евклидову норму...\n\n";
            cout << Norma(m) << endl;
            break;
        }
        case 4:
        {
            cout << "\nВведите матрицу:\n";
            Matrix v(1, 3);
            cout << "\nВычисляем определитель методом Гаусса...\n\n";
            cout << MethodGauss(v) << endl;
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
