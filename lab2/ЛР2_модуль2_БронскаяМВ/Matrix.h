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
    //Количество строк матрицы
    int countOfLines;
    //Количество столбцов матрицы
    int countOfColumns;
    //Переменная, хранящая элементы матрицы
    vector<vector<double>> data;
};

//Единичная матрица
class UnitMatrix : public Matrix
{
public:
    //Конструктор для создания ед.матрицы на основе другой матрицы
    UnitMatrix(const Matrix& pMatrix);
    //Конструтор для создания новой единичной матрицы
    UnitMatrix(int countLin, int countCol);
};

// Диагональная матрица
class DiagMatrix : public Matrix
{
public:
    //Диагональная матрица на основе матрицы
    DiagMatrix(const Matrix& pMatrix);
    //Новая диагональная матрица на основе количества строк и столбцов
    DiagMatrix(int countLin, int countCol);
    DiagMatrix();
};

//Верхняя треугольная матрица
class UpperTriangularMatrix : public Matrix
{
public:
    //Треугольная матрица на основе матрицы (в нижнем треугольнике матрицы устнавливаются нули)
    UpperTriangularMatrix(const Matrix& pMatrix);
    //Новая треугольная матрица
    UpperTriangularMatrix(int countLin, int countCol);
    UpperTriangularMatrix();
};

//Нижняя треугольная матрица
class LowerTriangularMatrix : public Matrix
{
public:
    //Создание на основе матрицы (отсечение "верхнего треугольника")
    LowerTriangularMatrix(const Matrix& pMatrix);
    //Создание новой матрицы
    LowerTriangularMatrix(int countLin, int countCol);
    LowerTriangularMatrix();
};

//Симметричная матрица
class SymMatrix : public Matrix
{
public:
    //Создание новой симметричной матрицы
    SymMatrix(int countLin, int countCol);
};