#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int age;
	char name[350];
}Person;

int main()
{
	int n, max=0, maxj=0, a=0;
	int* length;
	char tab;
	FILE* in;
	fopen_s(&in, "input.txt", "r");
	fscanf_s(in, "%d", &n);
	Person *pers = (Person*)malloc(n * sizeof(Person));
	length = (int*)malloc(n * sizeof(int));
	fseek(in, 3, SEEK_SET);
	length[a] = 1;
	while (!feof(in))
	{
		fscanf_s(in, "%c", &tab, 1);
		length[a]++;
		if ((tab == '\n'))
		{
			a++;
			length[a] = 1;
		}
	}
	fseek(in, 2, SEEK_SET);
	for (int i = 0; i < n; i++)
	{
		fscanf_s(in, "%d", &pers[i].age);
		if (pers[i].age > max)
		{
			max = pers[i].age;
			maxj = i;
		}
		printf("%d  ", pers[i].age);
		fgets(pers[i].name, length[i], in);
		printf("%s\n", pers[i].name);
	}
	printf("\n\n");
	printf("The oldest: %d years %s\n", pers[maxj].age, pers[maxj].name);
	fclose(in);
	free(length);
	free(pers);
	system("pause");
	return 0;
}