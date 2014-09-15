/* calculator*/

#include<stdio.h>
char input[] = "2+3";
int main(){
	int d;
	while (*input != EOF) {
		if(input[1]==43){
			d = input[0]+input[2];
			
		}
		else if(input[1]==45){
			d = input[0]-input[2];
		}
	printf("%d\n", d);

	}
}