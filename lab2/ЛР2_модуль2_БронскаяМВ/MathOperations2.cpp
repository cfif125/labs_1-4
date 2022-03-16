#include "MathOperations2.h"


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

//������������ ������ �2

//���������� ������������ ������� ������
double MethodGauss(const Matrix& matrix)
{
    //���� ���������� ����� ��� �������� = 0
   //�� ����������
   //������ ����������, ���� ������� �� ����������
    try
    {
        if (((matrix.countOfLines <= 0) || (matrix.countOfColumns <= 0)) || (matrix.countOfLines != matrix.countOfColumns))
            throw "�������� ���������� ����� � ��������\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    //��������� ������� = ������������ � ������� �������
    Matrix temp_matrix = matrix;
    //���������� ������������ = 1�
    double det = 1;
    //����� ������, ��� 1 �������
    //����� ������������ ��������
    int max_item_index;
    //�������� ������������� ��������
    double max_item;
    //��������� �����
    //double temp_buffer;
    //����������� ������������ (��� ����������� ����������� �������)
    double mult_coeff;
    //��� ���� ����� �������
    for (int line = 0; line < matrix.countOfLines; line++)
    {
        //������������ ������� = �������� �������� �� ������
        max_item = fabs(matrix.data[line][line]);
        //������������ ������ ������
        max_item_index = line;
        //����� ������������ ��������
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
    //���������� ������� � ��� ������� ����������� �������
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

    //������������ �������������� ��� ������������ ��������� �������,
    //������������� �� ���������
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
    //����������� ������� � ���������
    Matrix temp_matrix = matrix;
    //���� = 0
    double tr = 0;
    //��� ���� �����
    for (int line = 0; line < temp_matrix.countOfLines; line++)
    {
        //��� ���� ��������
        for (int column = 0; column < temp_matrix.countOfColumns; column++)
        {
            //������������ ��������� ����������� � �������
            if (line == column)
                tr += temp_matrix.data[line][column];
        }
    }
    //������� �������� ������� ����� ����������� �� ����������� �����
    return tr;
}


double ScalarMult(const Matrix& v1, const Matrix& v2)
{
    //����������.
   //���� ����� (������) �� ������ �� �������� ��������
   //�� ��������� ����������
    try
    {
        if (!((v1.countOfLines == 1) && (v1.countOfColumns >= 1)) && !((v1.countOfLines >= 1) && (v1.countOfColumns == 1)))
            throw "�� �������� �������� ���� �� (���) ����������(��)...\n";
        if (!((v2.countOfLines == 1) && (v2.countOfColumns >= 1)) && !((v2.countOfLines >= 1) && (v2.countOfColumns == 1)))
            throw "�� �������� �������� ���� �� (���) ����������(��)...\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    //��������� �������
    vector<double> temp_v1;
    vector<double> temp_v2;
    //�������� ������ ��������
    double abs_val[2];
    //��������� ������������ ��������
    double scalar_mult = 0;
    //��������� �������
    double temp[2];
    //���������� ��������-�������� � ������-�������
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
    try {
        if (temp_v1.size() != temp_v2.size())
            throw ("������� �������� �� ���������\n\n");
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    //��������� ������������ ��������
    for (int column = 0; column < temp_v2.size(); column++)
    {
        scalar_mult += temp_v1[column] * temp_v2[column];
    }


    return scalar_mult;
}

double Norma(const Matrix& v1)
{
    //����������.
    //���� ����� (������) �� ������ �� �������� ��������
    //�� ��������� ����������
    try
    {
        if (!((v1.countOfLines == 1) && (v1.countOfColumns >= 1)) && !((v1.countOfLines >= 1) && (v1.countOfColumns == 1)))
            throw "������ �� �������� ��������\n";
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
    //���������� ������ �� ����� ��������� ��������� (���������� �� ��� �����)
    abs_val = sqrt(summa);
    return abs_val;
}

double MaxNorma(const Matrix& v1)
{
    //����������.
    //���� ����� (������) �� ������ �� �������� ��������
    //�� ��������� ����������
    try
    {
        if (!((v1.countOfLines == 1) && (v1.countOfColumns >= 1)) && !((v1.countOfLines >= 1) && (v1.countOfColumns == 1)))
            throw "������ �� �������� ��������\n";
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


//����� ����������
double NormFrobenius(const Matrix& matrix)
{
    //����������� ������� � ���������
    Matrix temp_matrix = matrix;
    //������ ����������� � ������� ��������� = 0
    double acc = 0;
    //��� ���� �����
    for (int line = 0; line < temp_matrix.countOfLines; line++)
    {
        //��� ���� ��������
        for (int column = 0; column < temp_matrix.countOfColumns; column++)
        {
            //������������ ��������� ����������� � �������
            acc += temp_matrix.data[line][column] * temp_matrix.data[line][column];
        }
    }
    //������� �������� ������� ����� ����������� �� ����������� �����
    return sqrt(acc);
}
