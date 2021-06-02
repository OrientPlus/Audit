#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void main()
{
	setlocale(LC_ALL, "ru");
	int n, *mass;
	printf("Сколько простых чисел необходимо вывести?\n");
	scanf_s("%d", &n);
	mass = (int*)malloc(n * sizeof(int));
	printf("Какие простые числа необходимо отобразить?\n");
	for (int i = 0; i < n; i++)
	{
		printf("\n:");
		scanf_s("%d", &mass[i]);
		for (int j = 2; j < mass[i] + 1; j++)
		{
			for (int q = 2; q < i; q++)
			{
				if (j%q==0)
				{
					break;
				}
				else { printf("\n Просто число: %d\n", ); }
			}
		}
	}
}