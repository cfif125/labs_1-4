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
        cout << "�������� ����� �����:" << endl;
        cout << "1. ���������� ������ ������� � �������� \n2. ���������� ������ � ���������\n3. ��������� ����� � ������� (����������)\n4. ��������� ������������ � ������������ ������� (����������)\n";
        cin >> n;

        switch (n) {
        case 1:
        {
            cout << "������� ����� ������� ������� 3" << endl;
            Matrix m(3, 3);
            cout << "\n���� �������:\n" << m << endl;
            cout << "����: " << Trace(m) << endl;
            cout << "������������: " << MethodGauss(m) << endl;
            cout << "����� ����������: " << NormFrobenius(m) << endl;
            break;
        }
        case 2:
        {
            cout << "������� 2 ����� �������" << endl;
            Matrix v1(1, 3), v2(1, 3);
            cout << "��������� ������������: " << ScalarMult(v1, v2) << endl;
            cout << "����� 1-�� �������: " << Norma(v1) << endl;
            cout << "������������ ����� 1-��: " << MaxNorma(v1) << endl;
            break;
        }
        case 3: 
        {
            cout << "\n������� �������:\n";
            Matrix m(2, 2);
            cout << "\n��������� ��������� ��������� �����...\n\n";
            cout << Norma(m) << endl;
            break;
        }
        case 4:
        {
            cout << "\n������� �������:\n";
            Matrix v(1, 3);
            cout << "\n��������� ������������ ������� ������...\n\n";
            cout << MethodGauss(v) << endl;
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
