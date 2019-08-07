#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int rank(int*array, int key, int low, int high)
{
	int lo = low;
	int hi = high;
	
	while(lo <= hi)
	{
		int mid = lo + (hi - lo)/2;
		
		if(key < *(array + mid))
		{
			hi = mid - 1;
		}
		else if(key > *(array + mid))
		{
			lo = mid +1;
		}
		else
		{
			return mid;
		}
	}
	return hi;//
}

int main(int argc, char** argv) 
{
	int array[] = {2,3,9,17,19,22,24,25,31,53,55};
	int len = sizeof(array)/sizeof(array[0]);
	printf("3:%d\n",rank (array,3,0,10));
	printf("9:%d\n",rank (array,9,0,10));
	printf("24:%d\n",rank (array,24,0,10));
	printf("53:%d\n",rank (array,53,0,10));
	printf("55:%d\n",rank (array,55,0,10));
	return 0;
}
