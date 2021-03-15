#include "../Header/DynamicMemory.h"

#include <stdlib.h>

double** AllocateDoubleQuadraticMatrix(int size)
{
    double** matrix = (double**)malloc(size * sizeof(double*));

    if (matrix == NULL)
        return NULL;

    for (int i = 0; i < size; i++)
    {
        matrix[i] = (double*)malloc(size * sizeof(double));

        if (matrix[i] == NULL)
        {
            for (int j = 0; j < i; j++)
                free(matrix[i]);
            
            return NULL;
        }
    }

    return matrix;
}
double* AllocateDoubleArray(int length)
{
    double* array = (double*)malloc(length * sizeof(double));
    
    if (array == NULL)
        return NULL;
    
    return array;
}

void FreeDoubleQuadraticMatrix(double** matrix, int size)
{
    for (int i = 0; i < size; i++)
        free(matrix[i]);
    
    free(matrix);
}
void FreeDoubleArray(double** array)
{
    free(*array);
    array = NULL;
}