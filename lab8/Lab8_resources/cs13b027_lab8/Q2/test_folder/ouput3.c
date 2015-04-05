#include <stdlib.h>
#include <stdio.h>
 
void fn()
{
	int* x = malloc(10 * sizeof(int));
	printf("%d",*x);
	x[10] = 0;
	int i,j,k,l,m;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			for(k=0;k<10;k++)
			{
				for(l=0;l<10;l++)
				{
					for(m=0;m<10;m++)
					{
						printf("Hello %d\n",n);
					}
				}
			}
		}
	}
}
int main()
{
	fn();
	return 0;
}
