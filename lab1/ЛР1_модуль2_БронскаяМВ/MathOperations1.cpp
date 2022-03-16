#include "MathOperations1.h"


//���������� �������� �����
Matrix operator+(const Matrix& A, const Matrix& B)
{
    //����������
    //������������� ����� ������ ������� ����������� �������
    // ����� ��������� ����������
    try
    {
        if ((A.countOfLines != B.countOfLines) || (A.countOfColumns != B.countOfColumns))
            throw "������������ ����������, ������� ����� ������ �����������\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    //��������� �������
    Matrix temp_matrix;

    //����������� ������������
    temp_matrix.countOfLines = A.countOfLines;
    temp_matrix.countOfColumns = A.countOfColumns;

    //��������� ������ �������
    vector<double> temp_vector;
    //��� ���� �����
    for (int line = 0; line < temp_matrix.countOfLines; line++)
    {
        //��� ���� ��������
        for (int column = 0; column < temp_matrix.countOfColumns; column++)
        {
            //��������� ��������� ������ ������� ������ ��������������� ���������
            temp_vector.push_back(A.data[line][column] + B.data[line][column]);
        }
        //�������� � ������� ������ �� ������
        temp_matrix.data.push_back(temp_vector);
        temp_vector.clear();
    }
    //���������� �������
    return temp_matrix;
}

//���������� �������� ���������
Matrix operator-(const Matrix& A, const Matrix& B)
{
    //�������� ����������� ������ ��� �������������� ������,
    //����� ��������� ����������
    try
    {
        if ((A.countOfLines != B.countOfLines) || (A.countOfColumns != B.countOfColumns))
            throw "��������� ����������, ������� ����� ������ �����������\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    //��������� �������
    Matrix temp_matrix;

    //����������� �����������
    temp_matrix.countOfLines = A.countOfLines;
    temp_matrix.countOfColumns = A.countOfColumns;
    //��������� ������ �������
    vector<double> temp_vector;
    //���������� ���������
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

//���������� �������� ������������
Matrix operator*(const Matrix& A, const Matrix& B)
{
    //����������
    //����� �������� � ������ �����������
    //������ ��������� ����� ����� �� ������,
    //����� ��������� ����������
    try
    {
        if (A.countOfColumns != B.countOfLines)
            throw "������������ ����������, ������� ����� ������������ �����������\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    //��������� �������
    Matrix temp_matrix;

    //�����������
    temp_matrix.countOfLines = A.countOfLines;
    temp_matrix.countOfColumns = B.countOfColumns;
    //����� ��� �������� ��������
    double temp_data = 0;
    //��������� ������
    vector<double> temp_vector;
    //���������� �������� ��������� (������ ������ ������� � ���������� ��
    // ������� ������ ������� B)
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

//���������� �������� ������������ ����� �� �������
Matrix operator*(const double& d, const Matrix& B)
{
    //��������� �������
    Matrix temp_matrix;

    //����������� ������������
    temp_matrix.countOfLines = B.countOfLines;
    temp_matrix.countOfColumns = B.countOfColumns;
    //����� ��� �������� ���������
    double temp_data = 0;
    //��������� ������ �������
    vector<double> temp_vector;
    //���������� ��������� �������� �� �������
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

//������������ �������
Matrix MultOfAdamard(const Matrix& A, const Matrix& B)
{
  
    try
    {
        if ((A.countOfLines != B.countOfLines) || (A.countOfColumns != B.countOfColumns))
            throw "������������ ������� ����������, ������� ����� ������ �����������\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    //��������� �������
    Matrix temp_matrix;
    //��������� ������ �������
    vector<double> temp_vector;
    //����������� ������������
    temp_matrix.countOfLines = A.countOfLines;
    temp_matrix.countOfColumns = A.countOfColumns;

    //���������� ��������� ������������ ������� (������������ ���������)
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