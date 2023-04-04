#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

//改造BF算法，使其可以实现从200乘1600的字符串中查找不大于3乘1600的子串。电子版，发给潘老师，后面会说怎么发。

int mate(char * src,char *dest){
    int i=0,j=0;
    while (i<strlen(src) && j<strlen(dest)) 
    {
        if (src[i]==dest[j]) {
            i++;
            j++;
        }
        else{
            i=i-j+1;
            j=0;
        }
    }
    if (j==strlen(dest)) {
        return i-strlen(dest)+1;
    }
    return 0;
}

int main()
{
    FILE* f1 = fopen("src.txt","rw+");
    FILE* f2 = fopen("dest.txt","rw+");

    char arr1[200 * 1600];
    char arr2[3 * 1600];

    char ch;
    printf("src string is :");

    int i = 0;
    int j = 0;
    while ((ch = fgetc(f1)) != EOF)
    {
        if(ch = '\n')
            continue;
        else
        {
            arr1[i++] = ch;
        }
    }

    while (ch = fgetc(f2) != EOF)
    {
        if(ch == '\n')
            continue;
        else
        {
            arr2[j++] = ch;
        }
    }

    fclose(f1);
    fclose(f2);

    if(mate(arr1,arr2) != 0)
    {
        printf("have sub string\n");
    }
    else
    {
        printf("sorry have not\n");
    }
 

}

