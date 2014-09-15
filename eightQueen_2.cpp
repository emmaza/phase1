# include<stdio.h>
# include<stdlib.h>

//based on eightQuees_chess.cpp, which finds only one solution
//this one can find 8 solutions, one for each starting position (a different column in the first row).
//the problem is, there can be more than one solution with each starting position. How to exhaust the solutions?

void printArray(int result[][8]){
int i,j;
printf("-------------------------------\n");
for(i=0;i<8;i++){
	for(j=0;j<8;j++)
	{
		//printf("%d\n", result[i][j]);	
		printf("%d ",result[i][j]);
		//if(result[i][j]>2)exit(-1);
		if(j==7)
			printf("\n");
	}
}
printf("-------------------------------\n");
}

int main()
{
	int i,j,k;
	int a,b,y;
	int row[8], col[8];
	int result[8][8];
	int count;
	//initialize the array
	
	//start testing
	for(int x=0;x<8;x++)
	{
		for(a=0;a<8;a++)
			for(b=0;b<8;b++)
				result[a][b]=0;
		if(x>0) 
			for(int m=0;m<x;m++)
				result[0][m]=2;
		printArray(result);
		count=0;

		for(i=0;i<8;i++)
		{	
			for(j=0;j<8;j++)
			{
				//store the points being tested.
				if(result[i][j]==2) continue;
				row[count]=i;
				col[count]=j;
				//compare testing points with previously chosen ones
				for(k=0;k<count;k++)
				{
					if(i==row[k]||
						j==col[k]||
						i+j==row[k]+col[k]||
						i-j==row[k]-col[k])
						break;  //if conflict, move on to next point in the same row
				}
	
				if(k==count) 
				{
					result[i][j]=1;
					count++;
					break; //point found. move on to next row
				}
			}
				//if no point found, go back to previus row, reinitialize and choose a different point.
			if(j==8)
			{
				//count--;  //if j==8, then count has not incremented. (??)
				for(int k=0;k<8;k++){result[row[count]][k]=0;}
				
				if(count>0)count--; 
				result[row[count]][col[count]]=2;
				i=row[count]-1;
				//printf("~~~~~~~~ intermediate\n");
				//printArray(result);
				//i--;/////what i need: if one back-step is not enough, back one more step
			}
			//printf("i=%d\n",i);
			if(i==7)
			{
				y++;
				/*i=-1;
				for(int n=(col[0]+1);n<8;n++)
					result[0][n]=0;
				for(int n=0;n<= col[0];n++)
					result[0][n]=2;
				printArray(result);
	
			}*/
			printf("the number is %d.\n", y);

			}
		}
	printf("***final\n");
	printArray(result);
	}
	
	/* this is a finding from debugging.
	for(int k=3;k>-100;k--)
		printf("k=%d, row= %d\n", k,row[k]);*/  
		/*wrong index, random value assigned.
		this is related to the code "if(count>0)".
		without this restriction, count may become -1 and then random value will be assigned to row[count].*/
	
	

}
