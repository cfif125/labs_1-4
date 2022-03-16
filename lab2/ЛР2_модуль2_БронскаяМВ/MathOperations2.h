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


//ЛР№2
//След
double Trace(const Matrix& matrix);
//Вычисление определителя методом Гаусса
double MethodGauss(const Matrix& matrix);
//Скалярное произведение векторов
double ScalarMult(const Matrix& v1, const Matrix& v2);
//Евклиова норма
double Norma(const Matrix& v1);
//Максимальная норма
double MaxNorma(const Matrix& v1);
//Норма Фробениуса
double NormFrobenius(const Matrix& matrix);