#include <iostream>
#include <mpmery.h>
#define N 6
int p[N+1] = {30,35,15,5,10,20,25};

//A0~An-1 matrixs , Aj`s wei ,p[j] * p[j+1]

//the i raw,j conlum, from Aj to Aj+i ,totally i+1 matrixs

int Cost[N][N];
int Route[N][N];
int getL1(int i, int j, int Rj)//length
{
	return Rj - j + 1;
}
int getL2(int i, int j, int Rj)
{
	return i + 1 - getL1(i, j, Rj);
}
int getI1(int i, int j, int Rj)// 
{
	return getL1(i, j, Rj) - 1;
}
int getJ1(int i, int j, int Rj)
{
	return j;
}
int getI2(int i, int j, int Rj)// 
{
	return getL2(i, j, Rj) - 1;
}
int getJ2(int i, int j, int Rj)
{
	return j + getL1(i, j, Rj);//Rj + 1 
}
int getMatrixLines(int j)
{
	return p[j];
}
int getMatrixLines(int j)
{
	return p[j+1];
}
int main(int argc, char** argv)
{
	return 0;
}
