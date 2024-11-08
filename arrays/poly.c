#include<stdio.h>
#include<stdlib.h>
int* add_poly(int *A,int *B,int N, int M)
{
    int *c;
    if (N>M)
    {
        c=(int*)malloc((N+1)*sizeof(int));
        for (int i = 0; i < N+1; i++)
        {
            c[i]=A[i];
        }
        for (int i = 0; i < M+1; i++)
        {
            c[i]+=B[i];
        }
    }
    else
    {
        c=(int*)malloc((M+1)*sizeof(int));
        for (int i = 0; i < M+1; i++)
        {
            c[i]=B[i];
        }
        for (int i = 0; i < N+1; i++)
        {
            c[i]+=A[i];
        }
    }
    return c;
}
int* multi_poly(int *A,int *B, int N, int M)
{
    int *C = (int*)calloc(N+M+1, sizeof(int));
    for (int i = 0; i < N+1; i++)
    {
        for(int j = 0; j < M+1; j++)
        C[i+j]+=A[i]+B[j];
    }
    return C;
}
int main()
{
    return 0;
}