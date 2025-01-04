//和字符串
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

long long strtonum(char *str,int begin,int len){
    long long sum=0;
    for (int  i = 0; i < len; i++)
    {
        sum = sum*10+str[begin+i]-'0';
    }
    return sum;
}
long long getlen(int n){
    int i=0;
    while (n)
    {
        n/=10;
        i++;
    }
    return i;     

}
bool backtrack(char *str,int l,int begin,int len1,int len2){
    if (begin+len1+len2>=l)return true;
    long long num1=strtonum(str,begin,len1);
    long long num2=strtonum(str,begin + len1,len2);
    long long num3=strtonum(str,begin + len1+len2,getlen(num1+num2));
    if (num1+num2==num3)return backtrack(str,l,begin+getlen(num1),getlen(num2),getlen(num3));
    return false;
}
void partion(char *str){
int l = strlen(str);
    for (int i = 1; i <=l/2 ; i++)
    {
     if (backtrack(str,l,0,i,i));
     {
       printf("True\n");
       return;
     }      
    }
    printf("False\n");
}
int main()
{
    char str[]="";
    scanf("%s",str);
    partion(str);
    return 0;
}