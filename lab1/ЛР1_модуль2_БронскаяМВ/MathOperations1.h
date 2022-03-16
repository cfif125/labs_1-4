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





