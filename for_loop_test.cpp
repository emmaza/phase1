# include<stdio.h>

int main()
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			printf("i=%d, j=%d\n", i,j);
			i=0;
		}
}

/* the output is 
i=0, j=0
i=0, j=1
i=0, j=2
i=1, j=0
i=0, j=1
i=0, j=2
i=1, j=0
i=0, j=1
i=0, j=2
*/