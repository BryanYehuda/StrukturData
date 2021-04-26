#include <stdio.h>
#include <math.h>

int a; 
int b; 
int c; 
int d;
int array[1010];
int flag=0;
int x;
int y;

int main()
{
    scanf("%d %d",&a,&b);
    for(x=0;x<a;x++)
	{
        scanf("%d %d",&c,&d);
        for(y=c;y<=d;y++)
		{
            array[y]++;
            if(array[y]>b)
			{
                flag=1;
                break;
            }
        }
        if(flag==1)break;
    }
    if(flag==0) printf("Lancar\n");
    if(flag==1) printf("Macet\n");
    return 0;
}
