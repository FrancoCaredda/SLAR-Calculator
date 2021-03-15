#include "../Header/MatricesOperations.h"
#include "../Header/ArrayDataProcess.h"
#include "../Header/DynamicMemory.h"

#include <stdio.h>
#include <math.h>

double CalculateDeterminant(double** matrix, int size)
{
    double** temp =  AllocateDoubleQuadraticMatrix(size);

    if (temp == NULL)
        return;

    CopyDoubleMatrix(temp, matrix, size, size);

    double f = 0;

    for (int k = 0; k < size; k++)
    {
        for (int i = k + 1; i < size; i++)
        {
            f = temp[i][k] / temp[k][k];

            for (int j = k + 1; j < size; j++)
            {
                temp[i][j] -= temp[k][j] * f;
            }
            
            temp[i][k] = 0;
        }
    }

    double determinant = 1;

    for (int i = 0; i < size; i++)
        determinant *= temp[i][i];

    FreeDoubleQuadraticMatrix(temp, size);
    temp = NULL;

    return determinant;
}
double* CramerMethod(double** coeficient, double* freeCoeficient, int size)
{
    double mainDeterminant = CalculateDeterminant(coeficient, size);
    printf("\ndet(mainMatrix) = %lf\n", mainDeterminant);

    if (mainDeterminant == 0.0)
        return NULL;

    double** temp = AllocateDoubleQuadraticMatrix(size);

    if (temp == NULL)
    {
        printf("Memory wasn\'t allocated!!!!!!!");
        return NULL;
    }
    
    double* result = AllocateDoubleArray(size);
    
    if (result == NULL)
    {
        printf("Memory wasn\t allocated!!!!!!!");
        return NULL;
    }

    for (int i = 0; i < size; i++)
    {
        CopyDoubleMatrix(temp, coeficient, size, size);
        UpdateMatrixColumnFromArray(temp, freeCoeficient, i, size);

        printf("\nMatrix%d\n", i + 1);
        PrintDoubleMatrix(temp, size, size);
        

        result[i] = CalculateDeterminant(temp, size);
        printf("det(Matrix%d) = %lf\n", i + 1, result[i]);
    }
    
    for (int i = 0; i < size; i++) 
        result[i] = result[i] / mainDeterminant;

    FreeDoubleQuadraticMatrix(temp, size);
    temp = NULL;
    return result;
}
double CalculateAlgebraicAddition(double** matrix, int row, int column, int size)
{
    double** minor = AllocateDoubleQuadraticMatrix(size - 1);
    
    if (minor == NULL)
    {
        printf("ERROR: Cannot allocate memory!!!\n");
        return;
    }

    CopyDoubleMatrixDataWithoutRowAndColumn(minor, matrix, row, column, size);

    printf("Minor: \n");
    PrintDoubleMatrix(minor, size - 1, size - 1);
    printf("\n");

    double minorDeterminant = CalculateDeterminant(minor, size - 1);

    printf("Minor determinant: %lf\n\n", minorDeterminant);

    double addition = pow((-1), row + column) * minorDeterminant;

    FreeDoubleQuadraticMatrix(minor, size-1);
    return addition;
}
void TransposeMatrix(double** matrix, int size)
{
    double temp;

    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    
}
void MultiplyMatrixOnScalar(double** matrix, double scalar, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            matrix[i][j] *= scalar;
    } 
}
double** InvertedMatrix(double** matrix, int size)
{
    double determinant = CalculateDeterminant(matrix, size);

    if (determinant == 0.0)
        return NULL;

    double** invertedMatrix = AllocateDoubleQuadraticMatrix(size);

    if (invertedMatrix == NULL)
        return NULL;

    double addition;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            addition = CalculateAlgebraicAddition(matrix, i, j, size);
            invertedMatrix[i][j] = addition;
        }
    }

    printf("Matrix of additions: \n");
    PrintDoubleMatrix(invertedMatrix, size, size);
    printf("\n\n");

    TransposeMatrix(invertedMatrix, size);

    printf("Transposed matrix of additions: \n");
    PrintDoubleMatrix(invertedMatrix, size, size);
    printf("\n\n");

    MultiplyMatrixOnScalar(invertedMatrix, 1.0 / determinant, size);
    
    return invertedMatrix;
}
double* MultiplyMatrices(double** matrix, double* vector, int size)
{
    double* resultMatrix = AllocateDoubleArray(size);

    if (resultMatrix == NULL)
        return NULL;

    double c = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            for (int k = 0; k < size; k++)
            {
                c += matrix[i][k]*vector[k];
            }

            resultMatrix[i] = c;
        }

        c = 0;
    }
    
    return resultMatrix;
}