#ifndef MATRICES_OPERATIONS_H
#define MATRICES_OPERATIONS_H

double CalculateDeterminant(double** matrix, int size);
double* CramerMethod(double** coeficient, double* freeCoeficient, int size);
double CalculateAlgebraicAddition(double** matrix, int row, int column, int size);
void TransposeMatrix(double** matrix, int size);
void MultiplyMatrixOnScalar(double** matrix, double scalar, int size);
double** InvertedMatrix(double** matrix, int size);
double* MultiplyMatrices(double** matrix, double* vertor, int size);

#endif