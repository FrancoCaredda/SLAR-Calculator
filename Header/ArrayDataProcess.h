#ifndef ARRAY_DATA_PROCESS_H
#define ARRAY_DATA_PROCESS_H

void PrintDoubleMatrix(double** matrix, int rows, int columns);
void EnterDataToDoubleMatrix(double** matrix, int rows, int columns);
void CopyDoubleMatrix(double** destination, double** source, int rows, int columns);
void EnterDataToDoubleArray(double* array, int size);
void PrintDoubleArray(double* array, int size);
void UpdateMatrixColumnFromArray(double** matrix, double* array, int column, int size);
void CopyDoubleMatrixDataWithoutRowAndColumn(double** destination, double** source, int row, int column, int size);

#endif