# include<stdio.h>
# include<stdlib.h>

//based on eightQuees_chess.cpp, which finds only one solution
//How to exhaust the solutions? changes to be made are marked by **

void printArray(int result[][8])
{
	int i,j;
	printf("-------------------------------\n");
	for(i=0;i<8;i++){
		for(j=0;j<8;j++)
		{
			printf("%d ",result[i][j]);
			if(j==7)
				printf("\n");
		}
	}
	printf("-------------------------------\n");
}

int main()
{
	int i,j,k;
	int a,b,y,x,LINE;
	int row[8], col[8];
	int result[8][8];
	int count;
	
	for(a=0;a<8;a++)
		for(b=0;b<8;b++)
			result[a][b]=0;		
		
		count=0;
		LINE=0;
		for(i=LINE;i<8;i++) //**instead of 0, i should start at the line to be retested (LINE). so, maybe i=count.
		{	
			for(int m=0;m<=x;m++) //**x is the previous chosen point. change all preceding points to 2.
				result[LINE][m]=2; //**instead of 0 row, this change should start at the line to be retested (LINE).
			//**i=LINE. change all points after LINE to 0.
			for(int a=LINE+1;a<8;a++)
				for(int b=0;b<8;b++)
					result[a][b]=0;

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
				for(int k=0;k<8;k++){result[row[count]][k]=0;}
				
				if(count>0)count--; 
				result[row[count]][col[count]]=2;
				i=row[count]-1;
				//printf("~~~~~~~~ intermediate\n");
				//printArray(result);
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

}
