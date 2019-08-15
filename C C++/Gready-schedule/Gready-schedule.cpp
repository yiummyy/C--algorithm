#include <iostream>
#include <memory.h>
#include <malloc.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int N = 7;
int d[N] = {4,2,4,3,1,4,6};
int w[N] = {70,60,50,40,30,20,10};

int taskDelay[N];
int taskId[N];
int taskCount = 0; 
int taskDelay2[N];
int taskId2[N];
int taskCount2 = 0;

int rank(int* array, int key, int low, int high )
{
	int lo = low;
	int hi = high;
	while(lo <= hi)
	{
		int mid = lo + (hi - lo)/2;
		if(key < *(array+mid))
		{
			hi = mid - 1;
		}
		else if(key > *(array+mid))
		{
			lo = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return lo;
}

void insertInt(int* pTmp, int tmpLength, int insertPoint, int value)
{
	if(taskCount-insertPoint > 0)
	{
		int* pTmp2 = (int*)malloc(sizeof(int)*(tmpLength-insertPoint));
		memcpy(pTmp2, pTmp+insertPoint, sizeof(int)*(tmpLength-insertPoint));
		*(pTmp+insertPoint) = value;
		memcpy(pTmp+insertPoint+1, pTmp2, sizeof(int)*(tmpLength-insertPoint));
		
		free(pTmp2);
	}
	else
	{
		*(pTmp+insertPoint) = value;
	}
}
void checkAddingTask(int t)
{
	int* pTmp = (int*)malloc(sizeof(int)*(taskCount + 1));
	if(taskCount != 0)
	{
		memcpy(pTmp, &taskDelay, sizeof(int)*taskCount);
	}
	int insertPoint = rank(pTmp, d[t], 0, taskCount-1);
	insertInt(pTmp, taskCount, insertPoint, d[t]);
	
	int taskCountTmp = taskCount + 1;
	int result = 1;
	for(int i = 0; i < taskCountTmp; i++)
	{
		if(i+1 > *(pTmp+i))//if your finish-time > whole-time
		{
			result = -1;
			break;
		}
	}
	if(result > 0)//you can arrange
	{
		insertInt((int*)taskDelay, taskCount, insertPoint, d[t]);//d[t] = time value
		insertInt((int*)taskId, taskCount, insertPoint, t);//d[t]'s subscript
		taskCount++;
	}
	else
	{
		taskDelay2[taskCount2] = d[t];
		taskId2[taskCount2] = t;
		taskCount2++;
	}
}
int main(int argc, char** argv) 
{
	memset(taskDelay, 0, sizeof(int)*N);
	memset(taskId, 0, sizeof(int)*N);
	
	memset(taskDelay2, 0, sizeof(int)*N);
	memset(taskId2, 0, sizeof(int)*N);
	for(int t = 0; t <N; t++)
	{
		checkAddingTask(t);	
	} 
	for(int i = 0; i < taskCount; i++)
	{
		printf("%d ", taskId[i]+1);
	}
	printf(" |  ");
	for(int i = 0; i < taskCount2; i++)
	{
		printf("%d ", taskId2[i]+1);
	}
	return 0;
}
