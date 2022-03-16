#pragma once

#include <vector>
#include <iostream>

using namespace std;

class Matrix
{
public:
    Matrix(int countLines, int countCol);
    Matrix();
    friend std::ostream& operator<< (std::ostream& out, const Matrix& matrix);
    //���������� ����� �������
    int countOfLines;
    //���������� �������� �������
    int countOfColumns;
    //����������, �������� �������� �������
    vector<vector<double>> data;

    void Allocate(int countLines, int countCol)
    {
        this->countOfLines = countLines;
        this->countOfColumns = countCol;
        Matrix temp_matrix;
        vector<double> temp_vector;
        for (int r = 0; r < countLines; r++)
        {
            for (int c = 0; c < countCol; c++)
            {
                temp_vector.push_back(0);
            }
            temp_matrix.data.push_back(temp_vector);
            temp_vector.clear();

        }
    }

    /*void Deallocate()
    {
        for (int r = 0; r < Rows; r++)
            delete[] data[r];
        delete[] data;
    }*/
};

//��������� �������
class UnitMatrix : public Matrix
{
public:
    //����������� ��� �������� ��.������� �� ������ ������ �������
    UnitMatrix(const Matrix& pMatrix);
    //���������� ��� �������� ����� ��������� �������
    UnitMatrix(int countLin, int countCol);
};

// ������������ �������
class DiagMatrix : public Matrix
{
public:
    //������������ ������� �� ������ �������
    DiagMatrix(const Matrix& pMatrix);
    //����� ������������ ������� �� ������ ���������� ����� � ��������
    DiagMatrix(int countLin, int countCol);
    DiagMatrix();
};

//������� ����������� �������
class UpperTriangularMatrix : public Matrix
{
public:
    //����������� ������� �� ������ ������� (� ������ ������������ ������� �������������� ����)
    UpperTriangularMatrix(const Matrix& pMatrix);
    //����� ����������� �������
    UpperTriangularMatrix(int countLin, int countCol);
    UpperTriangularMatrix();
};

//������ ����������� �������
class LowerTriangularMatrix : public Matrix
{
public:
    //�������� �� ������ ������� (��������� "�������� ������������")
    LowerTriangularMatrix(const Matrix& pMatrix);
    //�������� ����� �������
    LowerTriangularMatrix(int countLin, int countCol);
    LowerTriangularMatrix();
};

//������������ �������
class SymMatrix : public Matrix
{
public:
    //�������� ����� ������������ �������
    SymMatrix(int countLin, int countCol);
};
