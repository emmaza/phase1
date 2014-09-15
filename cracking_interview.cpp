//string and array
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverseString(char *);
char *reverseSent(char *);
char *removeDup(char *);
void anagram(char * m, char * n);
int main(int argc, char const *argv[])
{
	char a[]="how are you doing sweetheart!"; 
	printf("%s\n", removeDup2(a));
	char b[]="how sweetheart are you doing!";
	//anagram(a,b);
	return 0;
}
void anagram(char * m, char * n){
	int a[256];
	int i,j;
	for(i=0; i<256; i++) a[i]=0;
	while(*m != '\0'){
		a[*m]++;
		m++;  //cf. for loop????????
	}
	while(*n != '\0'){
		a[*n]--;
		if(a[*n]<0){ 
			printf("%s\n", "not anagram");
			return; //if the value ever gets less than 0, function terminates.
		}			// don't need the for loop and if-else below.
		n++;
	}
	printf("%s\n", "anagram");
	//for(j=0; j<256, a[j] != 0; j++){   //j<256 -- warning: expression result unused
	/*for(j=0; j<256; j++){
		if(a[j] != 0){
			break;
		}
	}
	if(j==256)	printf("%s\n", "anagram");
	else		printf("%s\n", "not anagram");	*/
}

//cracking the coding interview 1.3
char *removeDup2(char *p){ //without using any additional buffer

}
char *removeDup(char *p){
	char a[256];
	int j, len, k;
	len=strlen(p);
	for(int i=0; i<256; i++) a[i]=0;
	for(j=0; j<len; j++){
		if(a[*(p+j)]==0){
			a[*(p+j)]=1;
		}
		else if(a[*(p+j)]==1){
			*(p+j)='\0';
		}
	}
	for(int i=0; i<len; i++){
		k=0;
		if(*(p+i)== '\0'){
			while(*(p+i+k) == '\0' && i+k<len){
				k++;
			}
			*(p+i)=*(p+i+k);
			*(p+i+k)='\0';
		}
	}
	return p;
}



//reverse "nice to meet you" to "you meet to nice"
char *reverseSent(char *sp){
	char *a;
	char *w; //word pointer, point to beginning of next word
	int i;
	a=reverseString(sp); //reverse the whole string. reverse each word back later in while loop.
	w=a;
	while(*a != '\0'){ //change spaces into \0 to use reverse to change order inside words back.
		if(*a==' '){
			*a='\0';
			reverseString(w);
			w=a+1; 
			*a=' '; //change \0 between words back to spaces
		}
		a++;
	}
	reverseString(w); //the last word does not have space after it. need independent reverse.
	return sp;
}

//cracking the coding interview 1.2
char *reverseString(char *p){
	char *end, *a;
	int b;
	int i,j;
	for(end=p; *end != '\0'; end++){}
	//end=p;
	//for(j=0; *end != '\0'; j++)
	//{	
	//	end++;
	//}
	for(i=0; p+i<=end-i-1; i++){
		b=*(p+i);  
		*(p+i)=*(end-i-1);
		*(end-i-1)=b;
	}
	return p;
	/*for(i=0; (p+i) <= (end-i); i++){ //Segmentation fault: 11  
		//because pointer is not initialized(?): char c; a=&c;
		*a=*(p+i);
		*(p+i)=*(end-i-1);
		*(end-i-1)=*a;
		printf("i=%d\n", i);
	}
	printf("i2=%d\n", i);
	*/	
}

char *reverse(char *p){
	int i,j,len;
	char *pp;
	for(i=0;*(p+i) != '\0';i++);
	len=i;
	//printf("%d\n", len);
	char *x=(char *)malloc(sizeof(char)*len); //cf. char x[len]; don't use this. storage may not be assigned.
	//for(int i=0;i<len;i++)x[i]=0;
	//for(j=0,i=len-1;j<len;j++,i--){
	for(j=0;j<len;j++){
		x[j]=*(p+len-j-1);
		//printf("%c,j=%d\n", x[j],j);
	}
	//printf("%d\n", j);
	x[len]='\0';
	pp=x;
	//printf(".......\n");
	return pp; //"return x" can work but not recommended. 
}