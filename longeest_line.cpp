//a program that reads a set of text lines and prints the longest. from the book, c programming language

//while (there's another line)
//	if (it's longer than the previous longest)
//		(save it)
//		(save its length) 
//print longest line

#include<stdio.h>
#define MAXLINE 1000

int getline(int maxline, char line[]); //cf. the book p30--order of arguments is flexible
void copy(char to[], char from[]);

int main()
{
	int len;
	char line[MAXLINE], longest[MAXLINE];

	int max=0;
	while((len=getline(MAXLINE, line))>0)
	{
		if(len>max)
		{
			max=len;
			copy(longest,line);
		}
	}
	printf("%s\n", longest);
}

int getline(int lim, char line[])
{
	//char line[]; //error: redefinition of 'line' with a different type: 'char []' vs 'char *'
	int i;
	char c;
	for(i=0;i<lim-1; i++)
		if((c=getchar())!=EOF)
		{
			if(c!='\n')
			{
				line[i]=c;
			}
		
		}
		else
		{
			break;
			i++; //????????????? do i need this. and the order with break--why does it matter?

		}
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i]='\0';

	return i;
}

void copy(char to[], char from[])
{
	int i=0;
	while((to[i]=from[i])!=0)
		i++;
}
