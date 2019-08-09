#include <iostream>
struct stack
{
	tNode **array;
	int index;
	
	stack()
	{
		array = new tNode*[100];
		index = 0;//index pointing to next position which you are going to wright
	}
	~stack()
	{
		delete[] array;
	}
	void push(tNode* node)
	{
		if(index < 100)
		{
			*(array + index) = node;
			index++;
		}
	}
	tNode* pop()
	{
		if(index > 0)
		{
			index--;
			return *(array+index);
		}
		else
		{
			return NULL;
		}
	}
	int getLength()
	{
		return index;
	}
	tNode* get(int i)
	{
		tNode* p = NULL;
		if(i > 0 && i < index)//0~index-1
		{
			p = *(array + i);
		}
		return p;
	}
};

