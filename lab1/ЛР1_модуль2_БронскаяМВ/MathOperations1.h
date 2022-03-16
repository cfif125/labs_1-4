#pragma once


#include "Matrix.h"
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <iostream>

 //ЛР№1
//Перегрузка операции суммы
Matrix operator+(const Matrix& A, const Matrix& B);
//Перегрузка операции вычитания
Matrix operator-(const Matrix& A, const Matrix& B);
//Перегрузка операции произведения
Matrix operator*(const Matrix& A, const Matrix& B);
//Перегрузка операции произведения числа на матрицу
Matrix operator*(const double& d, const Matrix& B);
//Произведение Адамара
Matrix MultOfAdamard(const Matrix& A, const Matrix& B);





