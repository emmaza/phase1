#include<stdio.h>

int main () {
	int f=0;
	float c=0;
	//scanf("%lf",&i); //address of i
	for(f=0; f<101; ++f){
		c=(5.0/9.0)*(f-32);
		printf("%d %.1f\n", f, c);
	}
}