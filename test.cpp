#include<stdio.h>
#define OUT 0
#define IN 1
//void swap(int a, int b){
//	int *x, *y, *z;
//	x=&a;
//	z=&b;
//	y=x;
//	x=z;
//	z=y;
//
//}	
void swap(int *a, int *b)
{
	int x;
	x=*a;
	*a=*b;
	*b=x;
}
int main(int argc, char const *argv[])
{
	char m=250,n=122;
	//swap(&m,&n);
	printf("sum=%d\n",m+n);
	return 0;
}
