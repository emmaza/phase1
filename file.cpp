#include<stdio.h>

int main(int argc, char const *argv[])
{
	FILE *fp;
	char c;
	for(int i=1;i<argc;i++){
		fp=fopen(argv[i],"r");
		while((c=fgetc(fp)) != EOF){
			putchar(c);
		}
	}
		//printf("arg%d = %s\n", i, argv[i]);
	return 0;
}