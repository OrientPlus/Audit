#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct NODE
{
	int value;
	struct NODE* next;
}list;

list *addValue(int set_value)
{
	list* node = (list*)malloc(sizeof(list));
	node->value = set_value;
	node->next = NULL;
	return node;
}


void addBefore(list** ptr, int set_value)
{
	list* newValue = addValue(set_value);
	newValue->next = *ptr;
	*ptr = newValue;
}

void addAfter(list** ptr, int set_value)
{
	list* newValue = addValue(set_value);
	list* tmp = *ptr;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = newValue;
}

void addAfterValue(list** ptr, int set_value, int insert)
{
	list* tmp = *ptr;
	while (tmp->next != NULL)
	{
		if (tmp->value == insert)
		{
			list * newValue = addValue(set_value);
			newValue->next = tmp->next;
			tmp->next = newValue;
		}
		tmp = tmp->next;
	}
}

void outputValue()
{
	list* ptr;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->value);
		ptr = ptr->next;
	}
}

void main()
{
	list* ptr=addValue(0);
	srand(time(NULL));
	int insert = rand() % 100;
	addAfter(&ptr, insert);
	outputValue();
}
