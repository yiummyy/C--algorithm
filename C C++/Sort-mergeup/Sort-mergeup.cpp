#include <iostream>
#include <malloc.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
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

void mergeArray(int* array, int lo, int mid, int hi)
{
	if(mid < lo || hi <= mid)
	{
		return;
	}
	
	int* ptmp = (int*)malloc((hi - lo +1) * sizeof(int));
	
	memcpy(ptmp, array + lo, (hi - lo +1) * sizeof(int));
	
	//i and j are ptmp's subscript ,the differ between ptmp's & array's subscript is lo
	int i = 0;
	int j = mid + 1 - lo; 
	
	//Actually k is the subscript between lo and hi in the array 
	for(int k = lo ; k <= hi; k++)
	{
		if(i + lo > mid)//The first child serie has fully used(zi xu lie)
		{
			*(array + k) = *(ptmp + j);
			j++;
		} 
		else if(j + lo > hi)
		{
			*(array + k) = *(ptmp + i);
			i++;
		}
		else if(*(ptmp + j) < *(ptmp + i))
		{
			*(array + k) = *(ptmp + j);
			j++;
		}
		else
		{
			*(array + k) = *(ptmp + i);
			i++;
		}
	}
	free (ptmp);
}

void sortArrayup2down(int* array, int lo, int hi)
{
	if(hi <= lo)
	{
		return;
	}
	int mid = lo +(hi + lo/2);
	
	sortArrayup2down(array, lo, mid);
	sortArrayup2down(array, mid + 1, hi);
	mergeArray(array, lo, mid, hi);
	return;
}

int main(int argc, char** argv)
{
	int array[] = {19,22,31,24,55,3,2,9,17,25,53};
	int len = sizeof(array)/sizeof(array[0]);
	
	printArray(0, array, len);
	sortArrayup2down(array, 0, len-1);
	printArray(1, array, len);
	return 0;
}
