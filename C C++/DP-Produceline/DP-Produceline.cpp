#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

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
		for(int i = 0; i< LINE;i++)//three lines
		{
			for(int k = 0; k< LINE;k++)//
			{
				if(j == 0)
				{
					CostForIJ[k] = A[k][j];
				}
				else
				{
					CostForIJ[k] = A[k][j] + Cost[k][j-1];
				}
				CostForIJ[k] += calMoveCost(i,k);// j cost
			}
			
			int minValue = CostForIJ[0];
			int minIndex = 0;
			
			for(int k = 0; k< LINE; k++)
			{
				if(CostForIJ[k] < minValue)
				{
					minValue = CostForIJ[k];
					minIndex = k;
				}
			}
			Cost[i][j] = minValue;
			Route[i][j] = minIndex;
		}
	}
	
	printf("Cost:\n");
	printMatrix(Cost);
	
	printf("Route:\n");
	printMatrix(Route);
	//find the sm
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
