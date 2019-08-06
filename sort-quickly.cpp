#include <iostream>
#include <malloc.h>
/* run this progr,am using the console pauser or add your own getch, system("pause") or input loop */
//int array[] = {19,22,31,24,55,3,2,9,17,25,53};

void printArray(int iLine, int* pArray, int len)
{
	printf("%d: array[] = {", iLine);
	
	for(int i = 0; i < len; i++)
	{
		if(i != len - 1)
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

int partition(int* array ,int lo , int hi)
{
	int i = lo;
	int j = hi + 1;
	while(1)
	{
		do
		{
			i++;
			if(i == hi)
			{
				break; 
			}
		}while(*(array + i) < *(array + lo));
		
		do
		{
			j--;
			if(j == lo)
			{
				break;
			}
		}while(*(array + lo) < *(array + j));
		
		if(i >= j)
		{
			break;
		}
		exchange(array, i, j);
	}
    exchange(array, lo, j);
    return j;
}

void sort(int* array, int lo, int hi)
{
	if(hi <= lo)
	{
		return;
	}
	
	int j = partition(array , lo , hi);
	
	sort(array, lo, j-1);
	sort(array, j+1, hi);
}
int main(int argc, char** argv) 
{
	int array[] = {19,22,31,24,55,3,2,9,17,25,53};
	int len = sizeof(array)/sizeof(array[0]);
    //int indent = 0;
	sort(array, 0, len-1);
	printArray(0, array, len);
	return 0;
}
