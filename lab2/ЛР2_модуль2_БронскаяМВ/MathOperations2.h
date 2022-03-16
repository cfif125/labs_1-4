#pragma once


#include "Matrix.h"
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <iostream>

//�й1
//���������� �������� �����
Matrix operator+(const Matrix& A, const Matrix& B);
//���������� �������� ���������
Matrix operator-(const Matrix& A, const Matrix& B);
//���������� �������� ������������
Matrix operator*(const Matrix& A, const Matrix& B);
//���������� �������� ������������ ����� �� �������
Matrix operator*(const double& d, const Matrix& B);
//������������ �������
Matrix MultOfAdamard(const Matrix& A, const Matrix& B);


//�й2
//����
double Trace(const Matrix& matrix);
//���������� ������������ ������� ������
double MethodGauss(const Matrix& matrix);
//��������� ������������ ��������
double ScalarMult(const Matrix& v1, const Matrix& v2);
//�������� �����
double Norma(const Matrix& v1);
//������������ �����
double MaxNorma(const Matrix& v1);
//����� ����������
double NormFrobenius(const Matrix& matrix);