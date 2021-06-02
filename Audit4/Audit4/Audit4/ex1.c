#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

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


void addRandomValue(list** ptr)
{
	srand(time(NULL));
	int n = rand() % 100;
	list* newValue = addValue(n);
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

void addBeforeValue(list** ptr, int value, int n)
{
	list* tmp = *ptr;
	while (tmp->next != NULL)
	{
		if (tmp->value == value)
		{
			list * newValue = addValue(n);
			newValue->next = tmp->next;
			tmp->next = newValue;
		}
		tmp = tmp->next;
	}
}

void outputList(list** ptr)
{
	list* tmp = *ptr;
	while (tmp->next != NULL)
	{
		printf("%d\n", tmp->value);
	}
}

void findFirstValue(list** ptr, int value)
{
	list* tmp = *ptr;
	int i = 0;
	while (tmp->next != NULL)
	{
		if (tmp->value == value)
		{
			printf("������ ��������� %d � ������ ��� %d ��������", value, i);
			break;
		}
		i++;
	}
}

void numberValue(list** ptr, int value)
{
	list* tmp = *ptr;
	int i = 0;
	while (tmp->next != NULL)
	{
		if (tmp->value == value)
		{
			i++;
		}
	}
	printf("����� ��������� %d � ������ = %d", value, i);
}

void main()
{
	setlocale(0, "ru");
	list* ptr = addValue(0);
	char choose = 0;
	int value = 0, n=0;
	printf("\n����:\n (1)�������� ��������� ����� � ������\n (2)������� ������\n (3)�������� ��������� ����� ����� ������ value � ������.\n (4)����� ������� ��������� value � ������.\n (5)������� ����� ��������� value � ������\n (6)���������� ������ � �������� �������\n");
	while (choose != '\n')
	{
		printf("\n�������� ����� ����:");
		scanf_s(" %d", &choose);
		switch (choose)
		{
		case 1:
			addRandomValue(&ptr);
			while (ptr != NULL)
			{
				printf("%d\n", ptr->value);
				ptr=ptr->next;
			}
			break;
		case 2:
			while (ptr != NULL)
			{
				printf("%d\n", ptr->value);
				ptr = ptr->next;
			}
			//outputList(&ptr);
			break;
		case 3:
			printf("����� ����� value ���������� �������� ��������� �����?\n");
			scanf_s(" %d\n", &value);
			n = rand() % 100;
			addBeforeValue(&ptr, value, n);
			break;
		case 4:
			printf("\n������� value:");
			scanf_s(" %d", &value);
			findFirstValue(&ptr, value);
			break;
		case 5:
			printf("\n������� value:");
			scanf_s(" %d", &value);
			numberValue(&ptr, value);
			break;
		}
	}
}
