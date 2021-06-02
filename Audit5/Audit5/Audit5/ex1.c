#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void gotoxy(int x, int y);

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int x[4], y[4];
	system("color 04");
	while (1)
	{
		system("cls");
		for (int i = 0; i < 3; i++)
		{
			Sleep(1200);
			srand(time(NULL));
			x[i] = 2 + rand() % 50;
			y[i] = 2 + rand() % 35;

			gotoxy(x[i], y[i]);
			printf("*");

			x[i]--; y[i]--;
			gotoxy(x[i], y[i]);
			printf("***");

			x[i]++; y[i]--;
			gotoxy(x[i], y[i]);
			printf("*");
		}
	}
	gotoxy(x + 5, y + 5);
	printf("\n");
	system("pause");
	return 0;
}


void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}