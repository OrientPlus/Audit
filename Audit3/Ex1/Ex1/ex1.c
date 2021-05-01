#include <stdio.h>
#include <stdlib.h>



int main()
{
    int n = 0, input, tmp;
    printf("Enter N:");
    scanf_s("%d", &n);
    int* mass;
    mass = (int*)malloc(n * sizeof(int));
    printf("Enter element:");
    for (int i = 0; i < n; i++)
    {
        scanf_s("%d", &mass[i]);
    }
    for (int i = 0; i < n - 1; i++) //Сортировка пузырьком
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (mass[j] > mass[j + 1])
            {
                tmp = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < n; i++) //вывод считанного массива
    {
        printf("  %d ", mass[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) //Вывод уникальных элементов в квадрате
    {
        if (mass[i] != mass[i + 1])
        {
            //input = mass[i] * mass[i];
            printf("  UNIQ ELEMENT = %d \n", mass[i]);
        }
    }
    free(mass);
    printf("\n");
	system("pause");
	return 0;
}