#include "../Header/ArrayDataProcess.h"

#include <stdio.h>

void PrintDoubleMatrix(double** matrix, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("% -5lf ", matrix[i][j]);
        }
        printf("\n");
    } 
}
void EnterDataToDoubleMatrix(double** matrix, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        printf("Enter row No%d: ", i + 1);

        for (int j = 0; j < columns; j++)
        {
            scanf("%lf", &matrix[i][j]);
        }
    }
}
void EnterDataToDoubleArray(double* array, int size)
{
    for (int i = 0; i < size; i++)
        scanf("%lf", &array[i]);
}
void PrintDoubleArray(double* array, int size)
{
    for (int i = 0; i < size; i++)
        printf("% -5lf ", array[i]); 
}
void CopyDoubleMatrix(double** destination, double** source, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            destination[i][j] = source[i][j];
    }
}
void UpdateMatrixColumnFromArray(double** matrix, double* array, int column, int size)
{
    for (int i = 0; i < size; i++)
        matrix[i][column] = array[i];    
}
void CopyDoubleMatrixDataWithoutRowAndColumn(double** destination, double** source, int row, int column, int size)
{
    int a = 0, b = 0;

    for (int i = 0; i < size; i++)
    {
        if (i != row)
        {
            for (int j = 0; j < size; j++)
            {
                if (j != column)
                {
                    destination[a][b] = source[i][j];
                    b++;
                }
            }
            a++;
            b = 0;
        }
    }
}