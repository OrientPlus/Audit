#include <stdio.h>

int main()
{
	char smb = 0;
	int tmp = 0, point = 0, n = 0;
	int mass[200];
	while (smb != '\n')
	{
		smb = fgetc(stdin);
		if ((smb >= '0') && (smb <= '9'))
		{
			tmp = tmp * 10 + (smb - '0');
			point = 1;
		}
		else
		{
			if (point == 1)
			{
				mass[n] = tmp;
				n++;
				point = 0;
				tmp = 0;
			}
		}
	}
	if (point == 1)
	{
		mass[n] = tmp;
		n++;
	}
	for (int i = 0; i < n; i++) 
	{
		printf("%llu ", (unsigned long long)(mass[i] * mass[i]));
	}
	system("pause");
	return 0;
}