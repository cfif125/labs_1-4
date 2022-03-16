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
        cout << "�������� ����� �����:" << endl;
        cout << "1. ����� ���� ����� ��������� \n2. ���� �������\n3. �������� ������� (���� ����������)\n4. ���������������� �������\n";
        cin >> n;

        Matrix m1(2, 2);
        cout << m1 * InverseMatrix(m1) << endl;

        switch (n) {
        case 1:
        {
            int line1, column1, line2, column2;
            cout << "������� ���������� ����� � �������� � 1 �������:";
            cin >> line1 >> column1;
            cout << "������� ���������� ����� � �������� � 2 �������:";
            cin >> line2 >> column2;
            Matrix v1(line1, column1);
            cout << "\n";
            Matrix v2(line2, column2);
            cout << "���� ����� ���������: "<<AngleBetVectors(v1, v2) << endl;
            
            break;
        }
        case 2:
        {
            int line, column;
            cout << "������� ���������� ����� � �������� � �������:";
            cin >> line >> column;
            Matrix m(line, column);
            cout << "���� �������: \n" << m << endl;
            cout << "���� �������: " << GaussMatrixRank(m) << endl;

            
            break;
        }
        case 3:
        {
            int line, column;
            cout << "������� ���������� ����� � �������� � �������:";
            cin >> line >> column;
            Matrix m(line, column);
            cout << "���� �������: \n" << m << endl;
            cout << "�������� �������: \n" << InverseMatrix(m) << endl;

            break;
        }
        case 4:
        {
            int line, column;
            cout << "������� ���������� ����� � �������� � �������:";
            cin >> line >> column;
            Matrix m(line, column);
            cout << "���� �������: \n" << m << endl;
            cout << "����������������� �������: \n" << TransposeMatrix(m) << endl;
            system("pause");
            break;
            
        }
        default:
            cout << "�������� ����" << endl;
            break;
        }


        return 0;
    }
    catch (int exc)
    {
        printf("��������� ����������� � ��������.\n");
        return 0;

    }
}