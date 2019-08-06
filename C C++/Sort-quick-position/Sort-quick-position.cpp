#include <iostream>
#include <malloc.h>
/* run this progr,am using the console pauser or add your own getch, system("pause") or input loop */
int array[] = {19,22,31,24,55,3,2,9,17,25,53};
int len = sizeof(array)/sizeof(array[0]);
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

void sort(int* array, int lo, int hi)
{
	printf("sort(array,lo=%d, hi=%d )\n", lo , hi);
	printArray(lo*1000 + hi,array, len);
	if(hi <= lo)
	{
		return;
	}
	
	int i =  lo;
	int j =  hi;
	
	int pivot = *(array + lo);
	
    while(1)
    {
    	while(pivot < *(array + j) && i < j)
    	{
    		j--;
		}
		*(array + i) = *(array + j);
		
		while(*(array + i) < pivot && i < j)
    	{
    		i++;
		}
		*(array + j) = *(array + i);
		
		if(i >= j)
		{
			break;
		}
	}
	*(array + i) = pivot;
	
	printArray(lo*1000 + hi,array, len);
	
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
