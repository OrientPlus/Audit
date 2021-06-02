#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

typedef struct NODE
{
	int value;
	struct NODE* next;
}spisok;

spisok* AddValue(int data)
{
	spisok* tmp = (spisok*)malloc(sizeof(spisok));
	tmp->value = data;
	tmp->next = NULL;
	return (tmp);
}

spisok* addBefore(spisok* head)
{
	int data;
	spisok* tmp = (spisok*)malloc(sizeof(spisok));
	srand(time(NULL));
	data = rand() % 10;
	tmp->value = data;
	tmp->next = head;
	return (tmp);
}

spisok* addBeforeValue(spisok* head, int n)
{
	spisok* p = head;
	while (p->next != NULL)
	{
		if (p->value == n)
		{

		}
	}
}

void main()
{

}