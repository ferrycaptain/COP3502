#include<stdio.h>
#include<conio.h>
#include<math.h>
int a=0;
int main()
{
    char bin[8];
    int i=0,len=0,r=0,w;
    printf("Enter a Binary Number :: ");
    scanf("%s",bin);
    printf("\n");
    len = strlen(bin);
    for(i=0;i<len;i++)
    {
            w=pow(2,i);
            r+=bin[i]*w;
    }
    printf("Decimal is :: %d\n\n",r);
    scanf("%d",&a);
    getch();
    return 0;
}
