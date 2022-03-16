#include "MathOperations3.h"


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
        //����� ������������� ��������
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
    //���� ����� ����� ������ ������ � ���������� ������
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
            //������������ ���������, ������������� �� ���������
            if (line == column)
                tr += temp_matrix.data[line][column];
        }
    }
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
    /*try {
        if (temp_v1.size() != temp_v2.size())
            throw ("������� �������� �� ���������\n\n");
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }*/

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
        if (v1.countOfLines <= 0 || v1.countOfColumns <= 0)
            throw "������������ ������ ������� \n";
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


//����� ���������� - ������ �� ����� ��������� ���� ���������
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

double AngleBetVectors(const Matrix& v1, const Matrix& v2)
{

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
    double scalar = ScalarMult(v1, v2);

    //���������
    temp[0] = 0;
    temp[1] = 0;
    //����� ��������� ��������� ��������
    for (int column = 0; column < temp_v2.size(); column++)
    {
        temp[0] += temp_v1[column] * temp_v1[column];
        temp[1] += temp_v2[column] * temp_v2[column];
    }
    //���������� ������ �� ����� ��������� ��������� (���������� �� ��� �����)
    abs_val[0] = sqrt(temp[0]);
    abs_val[1] = sqrt(temp[1]);


    return (scalar / (abs_val[0] * abs_val[1]));
}

//���� ������� (� ������� ��������� ������);
int GaussMatrixRank(const Matrix& matrix)
{
    //��������� ������� = ������� ���������
    Matrix temp_matrix = matrix;
    //������ ������ � ������������ ���������
    //int max_item_index;
    //����������� ��������
    //double max_item;
    //��������� ������
    double temp_buffer;
    //����������� ���������
    double mult_coeff;
    //���������� ������� � ����������� ���
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
    //������� ��������� �����
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
    //������� ���� �������
    return count_rank;
}

//��������������� ������� ��������� ������ �������
Matrix GetMinorElementsMatrix(const Matrix& matrix, int line, int column)
{
    //��������� �������
    Matrix temp_matrix;
    //��������� ������ �������
    vector<double> temp_vector;
    //��� ������ ������ i1 ������������
    for (int i = 0; i < matrix.countOfLines; i++)
    {
        //��� ������� ������� j1 ������������
        for (int j = 0; j < matrix.countOfColumns; j++)
        {
            //����� �������� ������, � ���������� �� ��������� ������
            if (!((i == line) && (j == column)) && !((i == line) && (j != column)) && !((i != line) && (j == column)))
            {
                temp_vector.push_back(matrix.data[i][j]);
                
            }
            //����� �����
        }
        //���� ��������� ������ �� �����, �������� � ������� ������
        if (temp_vector.size() != 0)
        {
            temp_matrix.data.push_back(temp_vector);
            temp_vector.clear();
        }
        //����� �����
    }
    //������� ������������ ij
    //����������� ������������
    temp_matrix.countOfLines = temp_matrix.data.size();
    temp_matrix.countOfColumns = temp_matrix.data.size();
    //������� ����� 
    return temp_matrix;
   
}

//���������������� �������
Matrix TransposeMatrix(const Matrix& matrix)
{
    //��������� �������
    Matrix temp_matrix;
    //��������� ������ �������
    vector<double> temp_vector;
    //����������� ������������
    temp_matrix.countOfLines = matrix.countOfColumns;
    temp_matrix.countOfColumns = matrix.countOfLines;

    //������� ����� (����������� � �������)
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

//���������� �������� �������
Matrix InverseMatrix(const Matrix& matrix)
{

    try {
        if (MethodGauss(matrix) == 0)
            throw ("�������� ������� �� ����������\n");
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    //������� �������������� ����������
    Matrix algMatrix;
    //����������������� ������� �������������� ����������
    Matrix transAlgMatrix;
    //�������� �������
    Matrix reverseMatrix;
    //��������� ������ �������
    vector<double> temp_vector;
    //������������ �������
    double detMatrix = MethodGauss(matrix);
    //����� ������� ������ �������, ������� � ������� ������,
    // ����� �������, ������ ����
    for (int line = 0; line < matrix.countOfLines; line++)
    {
        for (int column = 0; column < matrix.countOfColumns; column++)
        {
            //���������� ��������������� ���������� ��� ������� �������� �������
            double temp = pow(-1, line + column) * MethodGauss(GetMinorElementsMatrix(matrix, line, column));
            if (temp == 0)
                temp = fabs(temp);
            temp_vector.push_back(temp);
        }
        //���������� ��������� ������ � �������
        algMatrix.data.push_back(temp_vector);
        temp_vector.clear();
    }
    //����������� ������������
    algMatrix.countOfLines = matrix.countOfLines;
    algMatrix.countOfColumns = matrix.countOfColumns;
    //���������� ����������������� �������
    transAlgMatrix = TransposeMatrix(algMatrix);
    //���������� �������� �������
    reverseMatrix = 1 / detMatrix * transAlgMatrix;
    //������� ���������
    return reverseMatrix;
}