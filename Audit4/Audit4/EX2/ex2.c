#include <stdlib.h>
#include <stdio.h>
#include <math.h>


void main()
{
	double R=0, side=0, d=0, x, s, Q;
	double result, pi = 3.1415926535;
	printf("Enter the length of the side of the vegetable garden:");
	scanf_s(" %lf\n", &side);
	printf("Enter the length of the goat rope:");
	scanf_s(" %lf\n", &R);
	d = side / 2;
	if (R <= d) { result = pi * pow(R, 2); }
	else {
		Q = acos ( (pi / 2) - atan((d / R) / sqrt(1 - (d / R) * (d / R))));
		x = 2 *Q;
		s = 4 * (0.5 * pow(R, 2) * (x - sin(x)));
		result = pi * pow(R, 2) - s;
	}
	printf("Goat-eaten area: %.4lf", result);

	system("pause");
}