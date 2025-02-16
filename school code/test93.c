#include<stdio.h>
#include<math.h>
int main(){
    int n;
    double result;
    FILE* file = fopen("rr.dat","w");
    for (int i = 1; i <=n; i++)
    {
        result = sqrt(i);
        fprintf(file,"%.6lf\n",result);
    }
    fclose(file);
    file = fopen("rr.dat","r");
    while (fscanf(file,"%lf",&result)==1)
    {
        printf("%.6lf",result);
    }
    fclose(file);
    
    return 0;
}
