#include<stdio.h>
#include<string.h>
int main(){
    char str1[10],str2[10];
    int sum = 0;
    scanf("%s %s",str1,str2);
    for (int i = 0; i < 6; i++)
    {
        if (i<=1)
        {
            sum+=(str1[i]>str2[i])?26-(str1[i]-str2[i]):(str2[i]-str1[i]);
        }else
        {
            sum+=(str1[i]>str2[i])?10-(str1[i]-str2[i]):(str2[i]-str1[i]);
        }
    }
    printf("%d\n",sum);
    return 0;
}