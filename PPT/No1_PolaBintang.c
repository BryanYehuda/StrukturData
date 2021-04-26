#include <stdio.h>
void printStars(int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        printf("*");
    }
    printf("\n");
    if(i<=n)
    {
        printStars(n-1);
    }
    for(; i>0; i--)
    {
        printf("*");
        if(i<=0)
        {
            printStars(n+1);
        }
    }
    printf("\n");
}
int main()
{
    int n;
//int s;
    printf("Please Enter The Number of Lines:");
    scanf("%d", &n);
    printStars(n);
    return 0;
}//end main

