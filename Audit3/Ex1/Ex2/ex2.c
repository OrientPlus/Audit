#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <locale.h>

int Play()
{
	int n = 0, * lengthWord, point = 0;
	char ch;
	printf("Из скольких слов будем играть?\n");
	scanf_s("%d\n", &n);

	char** word = (char**)malloc(n * sizeof(char*));
	for (int i = 0; i < n; ++i)
	{
		word[i] = (char*)malloc(15 * sizeof(char));
	}
	lengthWord = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		lengthWord[i] = 0;
		for (int j = 0; j < 30; j++)
		{
			ch = fgetc(stdin);
			if (ch != '\n')
			{
				word[i][j] = ch;
				lengthWord[i]++;
			}
			else
			{
				word[i] = (char*)realloc(word[i], (j + 1) * sizeof(char));
				word[i][0] = tolower(word[i][0]);
				break;
			}
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((word[i][lengthWord[i] - 1] == word[j][0] || word[i][0] == word[j][lengthWord[j] - 1]) & i != j)
			{
				point++;
			}
		}
	}
	if (point < n - 1)
	{
		printf("\n---> Нет\n");
	}
	else if (point == n - 1)
		printf("\n---> Да\n");
	free(lengthWord);
	printf("\nДля выхода нажмите '1'. Для продолжения любую клавишу.\n");
	ch = _getch();
	if (ch == '1')
		return 1;
	else
		return 0;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
	int choise = 0;
	while (choise != '1')
	{
		choise = Play();
		if (choise == 0)
			continue;
		else
			break;
	}
	system("pause");
	return 0;
}
