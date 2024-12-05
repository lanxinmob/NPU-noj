//蒙特卡罗方法求积分，用上了刚学的函数指针数组
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double func1(double x) {
    return pow(x, 4) * exp(-x);
}
 
double func2(double x) {
    return x * x + 1;
}
 
double func3(double x) {
    return cos(x);
}
 
double func4(double x) {
    return sqrt(x) * (x - 2);
}
 
double func5(double x) {
    return 2 * sin(x) - 5 * cos(x);
}

double (*str[5])(double)={func1,func2,func3,func4,func5};
double mtk(int m,double a,double b,int N)
{ 
    srand(RAND_MAX);
    double len = b - a,sum = 0;
    for(int i=1;i<N;i++){
        double x=((double)rand() / RAND_MAX) * len + a;
        sum += len*(str[m-1](x));
    }
    return sum/N;
}

int main()
{   
    int m,N;
    double a,b;
    scanf("%d%lf%lf%d",&m,&a,&b,&N);
    printf("%.6lf",mtk(m,a,b,N));
    return 0;
}