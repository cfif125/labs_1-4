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
        cout << "�������� ����� �����: \n";
        cout << "1. �������� ���� ����������� ������� � �������� ��������� \n2. ����������������� �������(+������������) \n3. ���������������� ������� \n4. ������������ ������� \n5. ������������ � ���������\n";
        cin >> n;
        switch (n)
        {
        case 1:
        {
            int line1, column1, line2, column2;
            cout << "������� ���������� ����� � �������� 1 �������:\n";
            cin >> line1 >> column1;
            cout << "������� ���������� ����� � �������� 2 �������:\n";
            cin >> line2 >> column2;
            cout << "������� ������� 1:" << endl;
            Matrix mat1 = Matrix(line1, column1);
            cout << "\n������� ������� 2:" << endl;
            Matrix mat2 = Matrix(line2, column2);

     
            cout << "������������ ������: \n" << mat1 * mat2 << "\n";
            cout << "����� ������: \n" << mat1 + mat2 << "\n";
            cout << "������� ������: \n" << mat1 - mat2 << "\n";
            cout << "������ �������, ���������� �� -1 \n" << -1 * mat1 << "\n";
            cout << "������������ �������: \n" << MultOfAdamard(mat1, mat2) << "\n";
            
            break;
        }
        case 2:
        {
            int line, column;
            cout << "���������������� ������� \n\n";
            cout << "������� ���������� �����:";
            cin >> line;
            cout << "������� ���������� ��������:";
            cin >> column;
            Matrix User = LowerTriangularMatrix(line, column);
            cout << "���� ���������������� �������\n" << User;

            cout << "������� ����� ���������������� �������: \n" << User * User;

            cout << "������������ �������, ���������� �� ����� �������: \n" << DiagMatrix(User);
            break;
        }
        case 3:
        {
            int line, column;
            cout << "����������������� ������� \n\n";
            cout << "������� ���������� �����:";
            cin >> line;
            cout << "������� ���������� ��������:";
            cin >> column;
            Matrix Up = UpperTriangularMatrix(line, column);
            cout << "���� ���������������� �������\n" << Up;
            break;
        }
        case 4:
        {
            cout << "������������ ������� ������� 3*3\n\n";
            Matrix sym = SymMatrix(3, 3);
            cout << "���� �������: \n" << sym;
            break;
        }
        case 5:
        {
            int line, column;
            cout << "��������� �������\n";
            cout << "������� ���������� �����:";
            cin >> line;
            cout << "������� ���������� ��������:";
            cin >> column;
            UnitMatrix un(line, column);
            cout << un;
            cout << "������������ �������, ���������� ���������� ���������������� �� ���������� �������:\n";
            Matrix diag = 5 * un + 3 * un - 2 * un * un;
            cout << diag;
            
            break;
        }
        default:
            cout << "�������� ����\n";
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
