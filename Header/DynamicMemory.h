#ifndef DYNAMIC_MEMORY_H
#define DYNAMIC_MEMORY_H

double** AllocateDoubleQuadraticMatrix(int size);
double* AllocateDoubleArray(int length);

void FreeDoubleQuadraticMatrix(double** matrix, int size);
void FreeDoubleArray(double** array);

#endif