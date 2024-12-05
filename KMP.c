#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define pattern_size 100
#define text_size 100

void Prefix(char* pattern, int* prefix, int len);
int kmpsearch(char*,char*);
int main()
{
    char *text = (char*)malloc(text_size*sizeof(char));
    char *pattern = (char*)malloc(pattern_size*sizeof(char));
    fgets(text,text_size,stdin);
    fgets(pattern,pattern_size,stdin);
    
    kmpsearch(text,pattern);
    free(text);
    free(pattern);
    return 0;
}
void Prefix(char* pattern, int* prefix, int len)
{
    int length = 0;
    prefix[0] = 0;
    int i= 1;
    while(i<len){
        if(pattern[i]==pattern[length]){
            length++;
            prefix[i] = length;
            i++;
        }else{
            if (length!=0)
            {   
                length = prefix[length-1];
            }else{
                prefix[i] = 0;
                i++;
            }
        }
    }
}
int kmpsearch(char*text,char*pattern)
{ 
    int len = strlen(pattern);
    int wid = strlen(text);
    int prefix[len];
    Prefix(pattern,prefix,len);
    int i=0,j=0;

    while (i < wid)
    {
        if(pattern[j]==text[i]){
            i++;
            j++;
        }
        if(j==len){
           printf("%d\n",i-j);
           j = prefix[j-1];
        }else if(i<wid&&pattern[j]!=text[i]){
           if(j!=0){
            j = prefix[j-1];
           }else{
            i++;
           }
        }
    }
    return 0;
}