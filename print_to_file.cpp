//print a triangle in a txt file

#include<stdio.h>

void pr_multi(int n, char x);

int main()
{
	pr_multi(50,'*');
	return 0;
}
/*
void triangle(int n)
{
	int i,j;
	for(i=n-1;i>=0;i--){
		printf("~");
		for(j=1;j<=;j++)
		printf("\n");
	}
	for(j=1;)
}
*/
void pr_multi(int n, char x)
{
	int m;
	for(m=1;m<=n;m++)
	{
		for(int i=(n-m);i>=0;i--)
			printf("%c",' ');	
		for(int i=1;i<=2*m-1;i++)
			printf("%c",x);	
		printf("\n");
	}
	
}

//first attempt, tried to use array.
/*void triangle(int r, int c){
	int i, j;
	char a[r][c];  //cf. a[i][j]. what's the difference?
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			a[i][j]=0;	

	//for(i=0;((c/2-i)>=0) && (i<r) && ((c/2+i)<c) ;i++)
	for(i=0;i<r;i++)
	{
		//printf("i1=%d\n", i);
		for(j=0;j<c;j++)
		{
			
			//printf("i2=%d\n", i);
			//printf("j=%d\n", j);
			if((j>=(c/2-i)) && (j<=(c/2+i)))
				a[i][j]=1;
			else
				a[i][j]=0;
			//printf("~");
		}
	}

		//a[i][(c/2-i):(c/2+i+1)]=1; why this doesn't work?
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++){
			if(a[i][j]==1)
			{
				printf("*");

			}
			else
				printf(" ");
		}
		if(j==c)
			printf("\n");
	}
}

int main(){
	triangle(100,100);
}
*/

