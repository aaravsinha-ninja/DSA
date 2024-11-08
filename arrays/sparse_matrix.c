#include<stdio.h>
#include<stdlib.h>
int **normal_to_3tuple(int** mat,int r,int c)
{
    int **mat2 = (int**)malloc(((r*c)+1)*sizeof(int*));
    for (int i = 0; i <= (r*c); i++)
    {
        mat2[i]=(int*)malloc(3*sizeof(int));
    }
    int k=1;
    mat2[0][0]=r;
    mat2[0][1]=c;
    mat2[0][2]=k;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (mat[i][j]!=0)
            {
                mat2[k][0]=i;
                mat2[k][1]=j;
                mat2[k][2]=mat[i][j];
                k++;
            }
        }
    }
    mat2[0][2]=k-1;
    mat2 = (int**)realloc(mat2, k * sizeof(int*));
    return mat2;
}
int main()
{
    return 0;
}