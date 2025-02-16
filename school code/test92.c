//重复元素
#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    long long a[1000];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld",a[i]);
    }
    int sum = 0;
    for (int i = 1; i < n; i++)
    { for (int j = 0; j < i; j++)
        {   if(a[i]==a[j]){
                sum++;
                break;
            }
        }   
    }
    printf("%d\n",sum);
    return 0;
}