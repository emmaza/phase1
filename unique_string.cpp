#include<stdio.h>

int main(int argc, char const *argv[])
{
	int c,j;
	int a[255];
	char *input=(char *)argv[1];
	for(int i=0;i<256;i++) a[i]=0;
	for(j=0; *(input+j) != 0;j++){
		c=*(input+j); //input[1]
		if(a[c]==0)
			a[c]=1;
		else
		{
			printf("False\n");
			break;
		}
		//printf("%c\n", c);
	}
	//printf("==%c,j=%d\n", *(input+j),j);
	if(*(input+j) == 0) printf("True\n");
	//else printf("xyz\n");
	return 0;
}