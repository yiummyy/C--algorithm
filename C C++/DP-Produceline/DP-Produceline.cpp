#include <iostream>
#define LINE 3
#define STEPS 4
#define MOVECOST 3

int A[LINE][STEPS] = {{9,7,9,3},{9,11,5,2},{3,12,7,5}};

void printMatrix(int (&m)[LINE][STEPS])
{
	for(int i = 0; i < LINE; i++)
	{
		for(int j = 0; j < STEPS; j++)
		{
			
			if(j == 0)
			{
				printf("(%d",m[i][j]);
			}
			else
			{
				printf(",%d",m[i][j]);
			}
		}
		printf(")\n");
	}
}
int calMoveCost(int l1, int l2)
{
	int gap = l2 - l1;
	if(gap < 0)
	{
		gap = -gap;
	}
	
	return gap * MOVECOST;
}
int main(int argc, char** argv)
{
	int Cost[LINE][STEPS];//0.1.2.3 : b-a,c-b,d-,out-d
	int Route[LINE][STEPS];//which line(pre-progress)
	int CostForIJ[LINE];
	printf("A:\n");
	printMatrix(A);
	
	for(int j = 0; j < STEPS; j++)//each step
	{
		for(int i = 0; i< LINE;i++)//each line
		{
			for(int k = 0; k< LINE;k++)//in each line there are possiblitis that you may change your road to another line 
			{
				if(j == 0)//if at the beginning, so b-a.
				{
					CostForIJ[k] = A[k][j];
				}
				else//if at c or d oy out
				{
					CostForIJ[k] = A[k][j] + Cost[k][j-1];
				}
				CostForIJ[k] += calMoveCost(i,k);//change road cost
			}
			
			int minValue = CostForIJ[0];//set the initial value  (here is the first row)
			int minIndex = 0;//set the initial index(change road)  (here is the first line)
			//find the minimum that is also the smallest cost
			for(int k = 0; k< LINE; k++)
			{
				if(CostForIJ[k] < minValue)
				{
					minValue = CostForIJ[k];
					minIndex = k;
				}
			}
			Cost[i][j] = minValue;//From the beginning 
			Route[i][j] = minIndex;//From the beginning ,shows the 
		}
	}
	
	printf("Cost:\n");
	printMatrix(Cost);
	
	printf("Route:\n");
	printMatrix(Route);
	//find the minimum cost(which is the answer)
	int minValue = Cost[0][STEPS-1];
	int minIndex = 0;
	for(int k = 0; k < LINE; k++)
	{
		if(Cost[k][STEPS-1] < minValue)
		{
			minValue = Cost[k][STEPS-1];
			minIndex = k;
		}
	}
	printf("\nmin Cost: %d\n", minValue);
	//draw the road
	int r[STEPS];
	for(int k = STEPS-1; k >= 0; k--)
	{
		r[k] = Route[minIndex][k];
		minIndex = Route[minIndex][k-1];
	}
	
	for(int k = 0; k<STEPS; k++)
	{
		printf("%d->",r[k]);
	}
	return 0;
}
