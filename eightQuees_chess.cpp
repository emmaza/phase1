# include<stdio.h>
# include<stdlib.h>
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
	int row[8], col[8];
	int result[8][8];
	int count=0;
	//initialize the array
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			result[i][j]=0;
	//printArray(result); ----debug

	//start testing
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
				/*else  //if no conflict, save 
				{
					//row[count]=i;
					//col[count]=j;
					count++;
				}   
				*/
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
			//printArray(result);
			//i--;/////what i need: if one back-step is not enough, back one more step
		}
		//printArray(result);
		//printf("i=%d\n",i);

	}
	printArray(result);
	/*for(int k=3;k>-100;k--)
		printf("k=%d, row= %d\n", k,row[k]);*/  
		/*wrong index, random value assigned.
		this is related to the code "if(count>0)".
		without this restriction, count may become -1 and then random value will be assigned to row[count].*/
	int x=0;
	if(i==8)
		x++;
	
	printf("the number is %d.\n", x);

}
