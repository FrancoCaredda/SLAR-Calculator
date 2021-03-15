#include "../Header/DynamicMemory.h"
#include "../Header/ArrayDataProcess.h"
#include "../Header/MatricesOperations.h"

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int size;

    printf("Enter the dimension of the system of equations: ");
    scanf("%d", &size);

    double** coeficientMatrix = AllocateDoubleQuadraticMatrix(size);

    if (coeficientMatrix == NULL)
    {
        printf("ERROR: coeficient matrix wasn\'t allocated!!!");
        return -1;
    }

    printf("Enter coeficiencs of the system of equations\n");
    EnterDataToDoubleMatrix(coeficientMatrix, size, size);


    double* freeCoeficientVector = AllocateDoubleArray(size);
    
    if (freeCoeficientVector == NULL)
    {
        printf("ERROR: free coeficient vector wasn\'t allocated!!!");
        return -1;   
    }

    printf("\nEnter the free terms of the system of equations: ");
    EnterDataToDoubleArray(freeCoeficientVector, size);

    //Cramer

    printf("Cramer\n");
    double* cramerVector = CramerMethod(coeficientMatrix, freeCoeficientVector, size);

    if (cramerVector == NULL)
    {
        printf("ERROR: memory for equision wasn\'t allocated!!!");
        return -1;
    }

    printf("\nResult: \n");
    PrintDoubleArray(cramerVector, size);
    printf("\n");

    FreeDoubleArray(&cramerVector);

    //MatrMethod

    printf("MatrMethod\n\n");

    double** invertedMatrix = InvertedMatrix(coeficientMatrix, size);

    printf("Inverted coeficient matrix: \n");
    PrintDoubleMatrix(invertedMatrix, size, size);
    printf("\n\n");

    if (invertedMatrix == NULL)
        return -1;

    double* result = MultiplyMatrices(invertedMatrix, freeCoeficientVector, size);

    if (result == NULL)
        return -1;


    printf("Result: \n");
    PrintDoubleArray(result, size);

    printf("\n\n");

    FreeDoubleQuadraticMatrix(coeficientMatrix, size);
    FreeDoubleArray(&freeCoeficientVector);
    FreeDoubleArray(&result);
    FreeDoubleQuadraticMatrix(invertedMatrix, size);

    coeficientMatrix = NULL;

    printf("\n");
    system("pause");

    return 0;
}