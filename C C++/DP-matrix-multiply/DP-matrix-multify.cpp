#include <iostream>
#include <mpmery.h>
#define N 6
int p[N+1] = {30,35,15,5,10,20,25};

//A0~An-1 matrixs , Aj`s wei ,p[j] * p[j+1]

//the i raw,j conlum, from Aj to Aj+i ,totally i+1 matrixs
//Rj�������� 
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
int getI1(int i, int j, int Rj)// after cut ��һ��cost�е�i�Ƕ��٣��кţ� 
{
	return getL1(i, j, Rj) - 1;
}
int getJ1(int i, int j, int Rj)//�о���j 
{
	return j;
}
int getI2(int i, int j, int Rj)// �зֺ� �ڶ�������cost�е��к� 
{
	return getL2(i, j, Rj) - 1;
}
int getJ2(int i, int j, int Rj)// �зֺ� �ڶ�������cost�е��к�
{
	return j + getL1(i, j, Rj);//Rj + 1 
}
int getMatrixLines(int j)
{
	return p[j];
}
int getMatrixColums(int j)
{
	return p[j+1];
}
int getLastCost(int i, int j, int Rj)
{
	int p1,p2,p3;
	//i�� j�� ��> [Aj ~ A(Rj)] *[A(Rj+1) ~ A(j+i)]
	p1 = getMatrixLines(j);
	p2 = getMatrixColums(Rj);
	p3 = getMatrixColums(j+1);
	
	return p1*p2*p3;
}
int getCost1(inti, int j, int Rj)
{
	return Cost[getI1(i, j, Rj)][getJ1(i, j, Rj)]
}
int getCost2(inti, int j, int Rj)
{
	return Cost[getI2(i, j, Rj)][getJ2(i, j, Rj)]
}
int getCost(inti, int j, int Rj)
{
	return getCost(i,j,Rj) + getCost(i,j,Rj) + getLastCost(i,j,Rj);
}
void printTriangle(int (&m)[N][N])
{
	printf("%s\n")
}
int main(int argc, char** argv)
{
	//�����У�����һ����������COSTΪ0 
	for(int j=0; j<N; j++)
	{
		Cost[0][j] = 0;
		Route[0][j] = j;		
	}
	//��һ�У�������������Aj*A(j+1)�����ǹ̶��ľ�����˵Ĵ��ۣ��п�Ϊj 
	for(int j; j<N-1; j++)
	{
		Cost[1][j] = getLastCost(i,j,j);
		Route[1][j] = j;
	}
	
	int CostTmp[N];
	for(int i = 2; i < N-1; i++)
	{
		for(in j = 0; j < N - i; j++)
		{
			for(int Rj = j; Rj < j + i; Rj++)
			{
				CostTmp[Rj] = getCost(i,j,Rj);				
			}
			
			int minValue = CostTmp[j];
			int minRj = Rj;
			
			for(Rj = j; Rj < j; Rj++)
			{
				if(CostTmp[Rj]< minValue)
				{
					minValue = CostTmp[Rj];
					minRj = Rj;
				}
			}
			
			Cost[i][j] = minValue;
			Route[i][j] = minRj; 
		}
	}
	printTriangle("Cost")
	printTriangle("Cost")
	return 0;
}
