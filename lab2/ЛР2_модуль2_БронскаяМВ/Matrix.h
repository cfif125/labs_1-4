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