#include <iostream>
#include <malloc.h>
#include <memory.h>

#define N1 53
#define HASHSIZE 41
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Node
{
	int key;
	int value;
	Node* pNext;
	Node(int k, Node* p, int v):
		key(k), pNext(p), value(v){}
};

int hashInt(int key)
{
	int iTemp = key * N1 % HASHSIZE;
	return iTemp;
}
int hashFloat(float f)
{
	int h = 0;
	char *s = (char*)&f;
	
	for(int i = 0;i < sizeof(f); i++)
	{
		h = (h * 31 +(unsigned int)* (s+i)) % HASHSIZE;
	}
	return h;
}
int hashString(char* s)
{
	int h = 0;
	for(; *s; s++)
	{
		h = (h * 31 +(unsigned int)* s) % HASHSIZE;
	}
	return h;
}

void putChaining(Node** hashTable, int key, int value)
{
	int index = hashInt(key);
	
	Node* p = NULL;//*(hashTable + index);
	
	if(*(hashTable + index) == NULL)
	{
		p = new Node(key, NULL, value);
		*(hashTable + index) = p;//pay attention
		printf("new Node(key=%d,value=&d), index=%d\n", key, value, index);
	}
	else
	{
		p = *(hashTable + index);
		while(p->key != key && p->pNext != NULL)
		{
			p = p->pNext;
		}
		if(p->value != key)
		{
			p->pNext = new Node(key, NULL, value);
			printf("new Node(key=%d,value=%d),index=%d\n", key, value, index);
			//printf("\n");
		}
		else
		{
			p->value = value;
			printf("duplicate key=%d, value is changed to %d\n", key, value);
		}
	}
}

int getChaining(Node** hashTable, int key)
{
	int index = hashInt(key);
	Node* p = *(hashTable + index);
	int value = -1;//if p is NULL, return -1 directly
	if(p != NULL)
	{
		while(p->key != key && p->pNext != NULL)
		{
			p = p->pNext;
		}
		if(p->key == key)
		{
			value = p->value;
		}
	}
	return value;
}
int main(int argc, char** argv) 
{
	Node** hashTable = NULL;
	hashTable = (Node**)malloc(HASHSIZE * sizeof(Node*));
	memset(hashTable, 0, HASHSIZE * sizeof(Node*));
	
	putChaining(hashTable, 22, 5);
	putChaining(hashTable, 23, 13);
	putChaining(hashTable, 25, 18);
	putChaining(hashTable, 29, 22);
	putChaining(hashTable, 31, 36);
	
	printf("%d\n", getChaining(hashTable, 25));
	return 0;
}
