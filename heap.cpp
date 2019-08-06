#include <iostream>
#include <stdio.h>
int array[] = {0,19,22,31,24,55,3,2,9,17,25,53};
int len = sizeof(array)/sizeof(array[0])-1;

void printArray(int iLine, int* pArray, int len)
{
	
	printf("%d: array[] = {", iLine);
	
	for(int i = 1; i <= len; i++)
	{
		if(i != len)
		{
			printf("%d,", *(pArray+i));
			
		}
		else
		{
			printf("%d}\n", *(pArray+i));
		}
	}	
	return;
}

void printindent(int count)
{
	for(int i = 0; i < count ; i++)
	{
		printf(" ");
	}
}

void exchange(int* array ,int i ,int j)
{
	if(i != j)
	{
		int itmp = *(array + i);
		*(array + i) = *(array + j);
		*(array + j) = itmp;
	}
}

void sink(int* array, int k, int N)//begin counting from 1, so N is index or numbers
{
	while(2*k <= N)
	{
		int j = 2*k;
		if(2*k +1 < N)// right child tree exists
		{
			if(*(array + j) < *(array + j + 1))
			{
				j++;//if right subnode is greater than left subnode, then j points to right subnode
			}
			
			if(*(array + k) >= *(array + j))
			{
				break;
			}
			 
			exchange(array, k, j);
			
			k = j;//update k
		}
	}
}

int main(int arge, char** argv)
{
	printArray(0, array, len);
	
	for(int k = len/2; k>=1 ;k--)//found the whole heap 
	{
		sink(array, k, len);
		printArray(k, array, len);
	}
	
	int N = len;
	while(N > 1)// loop aimming to cut the greatest one(k) in each loop 
	{
		exchange(array, 1, N);
		N--;
		sink(array, 1, N);
	}
	return 0;
}
