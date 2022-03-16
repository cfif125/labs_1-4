#include "Matrix.h"

Matrix::Matrix()
{

}

//���������� ������������ ������ �������, � �������������� ����������
//���� ���������� ����������� ��� ����������, �� ���������, ���
//���������� ����� � �������� = 0
Matrix::Matrix(int countLines, int countCol) : countOfLines(countLines), countOfColumns(countCol)
{
    //���� ���������� ����� ��� �������� = 0
    //�� ����������
    try
    {
        if ((countOfLines <= 0) || (countOfColumns <= 0))
            throw "�������� ���������� � ����� � ��������...\n";
    }
    catch (const char* msg)
    {
        cout << msg << endl;
        throw - 1;
    }
    //��������� ���������� ��� �������� ��������
    double item_data;
    //��������� ������
    vector<double> temp_vector;
    //���������� ������� ����������
    for (int line = 0; line < countOfLines; line++)
    {
        for (int column = 0; column < countOfColumns; column++)
        {
            //������ ����� �������� ��� �������� �������
            printf("�������[%d][%d] = ", line, column);
            cin >> item_data;
            //���������� � ��������� ������
            temp_vector.push_back(item_data);
        }
        //���������� ������ � �������
        data.push_back(temp_vector);
        //������� ��������� ������
        temp_vector.clear();
    }
}



UnitMatrix::UnitMatrix(int countLin, int countCol) :Matrix()
{
    //���� ���������� ����� ��� �������� = 0
    //�� ����������
    //������ ����������, ���� ������� �� ����������
    try
    {
        if ((countLin <= 0) || (countCol <= 0))
            throw "�������� ���������� � ����� � ��������...\n";
        if (((countLin <= 0) || (countCol <= 0)) || (countLin != countCol))
            throw "\n�������� ���������� ����� �/��� ��������. ������� ������ ���� ����������. \n\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    //����������� �������
    countOfLines = countLin;
    countOfColumns = countCol;
    //��������� ������ ������� (������ ��������)
    vector<double> temp_vector;
    for (int line = 0; line < countOfLines; line++)
    {
        for (int column = 0; column < countOfColumns; column++)
        {
            //���� ������� ���������
            if (line == column)
            {
                //�� ���������� 1
                temp_vector.push_back(1);
            }
            else
            {
                //�� ���� ��������� ��������� 0
                temp_vector.push_back(0);
            }
        }
        //�������� ������ � �������
        data.push_back(temp_vector);
        //������� ��������� ������
        temp_vector.clear();
    }
}

//��������� ������� �� ������ ��������� �������
UnitMatrix::UnitMatrix(const Matrix& pMatrix)
{
    //����������� ������������
    countOfLines = pMatrix.countOfLines;
    countOfColumns = pMatrix.countOfColumns;

    //���� ���������� ����� ��� �������� = 0
    //�� ����������
    //������ ����������, ���� ������� �� ����������
    try
    {
        if ((countOfLines <= 0) || (countOfColumns <= 0))
            throw "�������� ���������� � ����� � ��������. \n";
        if (countOfLines != countOfColumns)
            throw "\n�������� ���������� ����� �/��� ��������. ������� ������ ���� ����������. \n\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    //�������� ������ �������
    vector<double> temp_vector;
    //��������� ������ �� ���������, �� ��������� ����
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
    //��������� ������������
    countOfLines = countLin;
    countOfColumns = countCol;

    //���� ���������� ����� ��� �������� = 0
   //�� ����������
   //������ ����������, ���� ������� �� ����������
    try
    {
        if ((countOfLines <= 0) || (countOfColumns <= 0))
            throw "�������� ���������� � ����� � ��������. \n";
        if (countOfLines != countOfColumns)
            throw "\n�������� ���������� ����� �/��� ��������. ������� ������ ���� ����������. \n\n";
    }
    catch (const char* msg)
    {
        cout << msg << endl;
        throw - 1;
    }
    //��������� ����� ��� ��������
    double item_data;
    //��������� ������ �������
    vector<double> temp_vector;
    //���������� ������� ���������� (��������� �� ���������)
    for (int line = 0; line < countOfLines; line++)
    {
        for (int column = 0; column < countOfColumns; column++)
        {
            if (line == column)
            {
                printf("�������[%d][%d] = ", line, column);
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
    //�����������
    countOfLines = pMatrix.countOfLines;
    countOfColumns = pMatrix.countOfColumns;

    //���� ���������� ����� ��� �������� = 0
    //�� ����������
    //������ ����������, ���� ������� �� ����������
    try
    {
        if ((countOfLines <= 0) || (countOfColumns <= 0))
            throw "�������� ���������� � ����� � ��������. \n";
        if (countOfLines != countOfColumns)
            throw "\n�������� ���������� ����� �/��� ��������. ������� ������ ���� ����������. \n\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    //��������� ������ �������
    vector<double> temp_vector;
    //���������� ���������� ������������ ��������� �������
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
    //�����������
    countOfLines = pMatrix.countOfLines;
    countOfColumns = pMatrix.countOfColumns;

    //���� ���������� ����� ��� �������� = 0
   //�� ����������
   //������ ����������, ���� ������� �� ����������
    try
    {
        if ((countOfLines <= 0) || (countOfColumns <= 0))
            throw "�������� ���������� � ����� � ��������. \n";
        if (countOfLines != countOfColumns)
            throw "\n�������� ���������� ����� �/��� ��������. ������� ������ ���� ����������. \n\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    //��������� ������ �������
    vector<double> temp_vector;
    //���������� ������� ����������� �������
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


//����������� ��� �������� ����� ������� ����������� �������
UpperTriangularMatrix::UpperTriangularMatrix(int countLin = 0, int countCol = 0)
{
    //�����������
    countOfLines = countLin;
    countOfColumns = countCol;

    //���� ���������� ����� ��� �������� = 0
    //�� ����������
    //������ ����������, ���� ������� �� ����������
    try
    {
        if ((countOfLines <= 0) || (countOfColumns <= 0))
            throw "�������� ���������� � ����� � ��������. \n";
        if (countOfLines != countOfColumns)
            throw "\n�������� ���������� ����� �/��� ��������. ������� ������ ���� ����������. \n\n";
    }
    catch (const char* msg)
    {
        cout << msg << endl;
        throw - 1;
    }

    //����� ��� �������� ��������
    double item_data;
    //��������� ������ �������
    vector<double> temp_vector;
    //���������� ������� ����������� �������
    for (int line = 0; line < countOfLines; line++)
    {
        for (int column = 0; column < countOfColumns; column++)
        {
            if (line == column)
            {
                printf("�������[%d][%d] = ", line, column);
                cin >> item_data;
                temp_vector.push_back(item_data);
            }
            else
                if (column > line)
                {
                    printf("�������[%d][%d] = ", line, column);
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

//����������� ��� �������� ������� �� ������ ������������ �������
LowerTriangularMatrix::LowerTriangularMatrix(const Matrix& pMatrix)
{
    //�����������
    countOfLines = pMatrix.countOfLines;
    countOfColumns = pMatrix.countOfColumns;

    //���� ���������� ����� ��� �������� = 0
    //�� ����������
    //������ ����������, ���� ������� �� ����������
    try
    {
        if ((countOfLines <= 0) || (countOfColumns <= 0))
            throw "�������� ���������� � ����� � ��������. \n";
        if (countOfLines != countOfColumns)
            throw "\n�������� ���������� ����� �/��� ��������. ������� ������ ���� ����������. \n\n";
    }
    catch (const char* msg)
    {
        cout << msg << endl;
        throw - 1;
    }
    //��������� ������ �������
    vector<double> temp_vector;
    //���������� ������ ����������� �������
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

//����������� ��� �������� ������� �� ������ ���������� ������ � �������
LowerTriangularMatrix::LowerTriangularMatrix(int countLin = 0, int countCol = 0)
{
    //�����������
    countOfLines = countLin;
    countOfColumns = countCol;

    //���� ���������� ����� ��� �������� = 0
   //�� ����������
   //������ ����������, ���� ������� �� ����������
    try
    {
        if ((countOfLines <= 0) || (countOfColumns <= 0))
            throw "�������� ���������� � ����� � ��������. \n";
        if (countOfLines != countOfColumns)
            throw "\n�������� ���������� ����� �/��� ��������. ������� ������ ���� ����������. \n\n";

    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }

    //����� ��� �������� �������� �������� �������
    double item_data;
    //��������� ������ �������
    vector<double> temp_vector;
    //���������� ������ ����������� �������
    for (int line = 0; line < countOfLines; line++)
    {
        for (int column = 0; column < countOfColumns; column++)
        {
            if (line == column)
            {
                printf("�������[%d][%d] = ", line, column);
                scanf_s("%lf", &item_data);
                temp_vector.push_back(item_data);
            }
            else
                if (column < line)
                {
                    printf("�������[%d][%d] = ", line, column);
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

//����������� ��� �������� ����� ������������ ������� (���������� �� ��������� = 0)
SymMatrix::SymMatrix(int countLin = 0, int countCol = 0)
{
    countOfLines = countLin;
    countOfColumns = countCol;

    //���� ���������� ����� ��� �������� = 0
   //�� ����������
   //������ ����������, ���� ������� �� ����������
    try
    {
        if ((countOfLines <= 0) || (countOfColumns <= 0))
            throw "�������� ���������� � ����� � ��������. \n";
        if (countOfLines != countOfColumns)
            throw "\n�������� ���������� ����� �/��� ��������. ������� ������ ���� ����������. \n\n";
    }
    catch (const char* msg)
    {
        cout << msg << endl;
        throw - 1;
    }

    //������ ��� �������� ��������
    double item_data;

    //��������� ������ �������
    vector<double> temp_vector;
    cout << "������� ������� �����������: " << endl;
    //���������� ������������ ������� ����������. ������� ����������� ������� ����������� �������
    for (int line = 0; line < countOfLines; line++)
    {
        for (int column = 0; column < countOfColumns; column++)
        {
            if (line == column)
            {
                printf("�������[%d][%d] = ", line, column);
                cin >> item_data;
                temp_vector.push_back(item_data);
            }
            else
                if (column > line)
                {
                    printf("�������[%d][%d] � �������[%d][%d] = ", line, column, column, line);
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
    //���������� ����������� �������� "������������" �� ������ "�����������"
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


//���������� ��������� �������
std::ostream& operator<< (std::ostream& out, const Matrix& matrix)
{
    //��������� ������ �������
    vector<double> temp;

    //��� ���� ����� �������
    for (int line = 0; line < matrix.countOfLines; line++)
    {
        //����������� � ����� ������ �������
        temp = matrix.data[line];
        //��� ���� �������� �������
        for (int column = 0; column < matrix.countOfColumns; column++)
        {
            //����� ���� ��������� ������
            cout << temp[column] << "\t";
        }
        //�����
        cout << "\n";
    }
    //������� ������
    return out;
}