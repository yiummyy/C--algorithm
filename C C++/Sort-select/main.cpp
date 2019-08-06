#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
struct Node
{
	int iData;
	Node* pNext;

	Node(int i, Node* p):
		iData(i), pNext(p)
	{
	}
};

void printLink(int iLine, Node* p)
{
	printf("%d array:{", iLine);
	//Node* ptmp = p;
	while (p != NULL)
	{
		printf("%d", p->iData);
		if (p->pNext != NULL)
		{
			printf(",");
		}
		else
		{
			printf("}\n");
		}
		p = p->pNext;
	}
	
	return;//pay attention
}

int main(int argc , char** argv)
{
	Node* p = new Node(53, NULL);
	p = new Node(25, p);
	p = new Node(17, p);
	p = new Node(9, p);
	p = new Node(2, p);
	p = new Node(3, p);
	p = new Node(55, p);
	p = new Node(24, p);
	p = new Node(31, p);
	p = new Node(22, p);
	p = new Node(19, p);

	Node* pHead = p;

	printLink(111, pHead);
	
	return 0;
}

