//算行列式值
//小规模 余子式法
/*#include<stdio.h>
#include<stdlib.h>

int determinant(int **matrix,int n);
void getminor(int **matrix,int **minor,int n,int row,int col);
int main()
{
    int n;
    scanf("%d",&n);
    int **matrix = (int**)malloc(n*sizeof(int*));
    for(int j=0;j<n;j++){
        matrix[j]=(int*)malloc(n*sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {   for (int j = 0; j < n; j++)
        {scanf("%d",&matrix[i][j]);}
    }
    printf("%d\n",determinant(matrix,n));

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
int determinant(int **matrix,int n)
{
    if(n==1)return matrix[0][0];
    if(n==2)return matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0];
    int det = 0;
    int sign = 1;
    int **minor = (int **)malloc(n-1*sizeof(int *));
    for(int i=0;i<n-1;i++){
        minor[i] = (int *)malloc(n-1*sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {   getminor(matrix,minor,n,0,i);
        det += sign*matrix[0][i]*determinant(minor,n-1);
        sign = -sign;
    }
    for (int i = 0; i < n-1; i++)
    {   free(minor[i]);}
    free(minor);

    return det;
}
void getminor(int **matrix,int **minor,int n,int row,int col)
{   int mrow=0;
    for (int i = 0; i < n; i++)
    {   
        if(n==row)continue;
        int mcol=0;
        for(int j=0;j<n;j++){
            if(j==col)continue;
            minor[mrow][mcol]=matrix[i][j];
            mcol++;
        }
        mrow++;
    }    
}*/
/*
//逆序数对法
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

long long determinant;
int countInversions(int *permutation,int len);
void calculatedeterminant(int **matrix,int curRow,int *permutation,bool *usedcol,int pro,int);

int main()
{   
    int n;
    scanf("%d",&n);
    int **matrix = (int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++){
        matrix[i] = (int *)malloc(n*sizeof(int));
    }
     for (int i = 0; i < n; i++)
    {   for (int j = 0; j < n; j++)
        {scanf("%d",&matrix[i][j]);}
    }
    bool *usedcol = (bool *)malloc(n*sizeof(bool));
    int *permutation = (int *)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        permutation[i] = false;
    }
    calculatedeterminant(matrix,0,permutation,usedcol,1,n);
    printf("%lld\n",determinant);

    free(permutation);
    free(usedcol);
    for (int i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    
    return 0;
}
int countInversions(int *permutation,int len)
{   int inversions = 0;
    for (int i = 0; i < len; i++)
    {    for (int j = i+1; j < len; j++)
        {     if (permutation[i]>permutation[j]){
              inversions++;
            }   
        }   
    }
    return inversions;
}

void calculatedeterminant(int **matrix,int curRow,int *permutation,bool *usedcol,int pro,int n)
{
    if (curRow==n)
    {   int inversions = countInversions(permutation,n);
        int sign = (inversions%2 == 0)?1:-1;
        determinant += sign*pro;
        return;
    }
    for (int col = 0; col < n; col++)
    {    if(!usedcol[col]){
         usedcol[col] = true;
        permutation[curRow] = col; 
        calculatedeterminant(matrix,curRow+1,permutation,usedcol,pro*matrix[curRow][col],n);
        usedcol[col] = false;
        }
    }
}
*/
//LU(高斯消元法)
#include <stdio.h>
#include <stdlib.h>

double determinant(double **matrix,int n);

int main()
{
    int n;
    scanf("%d", &n);

    double **matrix = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double *)malloc(n * sizeof(double));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    double result = determinant(matrix, n);
    printf("%.2f\n", result);
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
double determinant(double **matrix,int n)
{
    int i,j,k;
    double det = 1;
    for ( i = 0; i < n; i++)
    {   int maxrow = i;
        for ( j = i+1; j < n; j++)
        {   
            if(matrix[j][i]>matrix[maxrow][i])
            {
                maxrow = j;
            }   
        }
        if(maxrow!=i){
            for ( k = 0; k < n; k++)
            {
                double temp = matrix[maxrow][k];
                matrix[maxrow][k] = matrix[i][k];
                matrix[i][k] = temp;
            }
            det = -det;
        }
        if (matrix[maxrow][i] == 0) {
            return 0;
        }
        for ( j = i+1; j < n; j++)
        {    double factor = matrix[j][i]/matrix[i][i];
             for ( k = i; k < n; k++)
             {
                matrix[j][k] -= matrix[i][k]*factor; 
             }
        }
        
    }
    for ( i = 0; i < n; i++)
    {
        det *= matrix[i][i];
    }
    
    return det;
}


