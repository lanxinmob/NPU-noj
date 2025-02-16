//归并排序法
#include<stdio.h>

int Reversepairs(int *nums,int n,int left,int right);
int main()
{   int n;
    scanf("%d",&n);
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&nums[i]);
    }
    int result = Reversepairs(nums,n,0,n-1);
    printf("%d",result);
    
    return 0;
}

int Reversepairs(int *nums,int n,int left,int right)
{   int res = 0;
    if(left>=right){
        return 0;
    }
    int mid = left + (right-left)/2;
    int r = Reversepairs(nums,n,left,mid);
    int l = Reversepairs(nums,n,mid+1,right);
    res = r+l;
    int temp[n];
    for (int i = left; i <= right; i++)
    {
        temp[i] = nums[i];
    }
    int left1 = left,left2 = mid+1;
    for (int i = left; i <= right; i++)
    { 
        if(left1>mid){
         nums[i] = temp[left2++];      
        }else if(left2>right){
         nums[i] = temp[left1++];
        }else if(temp[left1]<=temp[left2]){
         nums[i] = temp[left1++]; 
        }else{
         res += mid- left1 +1;//当temp[left1]>temp[left2]时，mid到left1之间的数均与temp[left2]形成逆序数对
         nums[i] = temp[left2++];
        }  
    }
    return res;
} 