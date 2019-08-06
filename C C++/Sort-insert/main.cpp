#include <iostream>
#include <stdio.h> 
int main(int argc, char** argv) {
	
	int array[11] = {19,22,1,24,55,3,2,9,17,25,53};
	int a = 0;
	int Len = sizeof(array)/sizeof(array[0]);
	
	for(int i = 0 ; i < Len ; i++)
	{
		for(int j = i; j > 0; j--)
		{
			if(array[j-1]>array[j])
			{
				a = array[j];
				array[j] = array[j-1];
				array[j-1] = a;
			}
			else
			{
				break;
			}
		}
	}
	for(int t = 0 ; t<=Len-1 ; t++)
	{
		if(t == Len-1)
		{
			printf("%d",array[t]);
		}
		else
		{
			printf("%d,",array[t]);
		}
	}
	return 0;
}
