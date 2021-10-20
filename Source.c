#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <malloc.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	double min, max, drob, d, sum1 = 0;
	int k, g, n;
	printf("Ââåäèòå êîëè÷åñòâî: ");
	scanf_s("%d", &n);
	if (n <= 0)
	{
		printf("Error, n <= 0");
		return 0;
	}
	printf("Ââåäèòå ìèíèìóì: ");
	scanf_s("%lf", &min);
	printf("Ââåäèòå ìàêñèìóì: ");
	scanf_s("%lf", &max);
	if (min > max)
	{
		printf("Error, min > max");
		return 0;
	}
	double* mas = NULL;
	int* mas1 = NULL;
	mas = ((double*)malloc(n * sizeof(double) + 1));
	mas1 = ((int*)malloc(n * sizeof(double) + 1));
	for (k = 0; k < n; k++)
	{
		mas[k] = (((double)rand()) / RAND_MAX * (max - min) + min);
		drob = modf(mas[k], &d);
		mas1[k] = (int)ceil(drob * 1000000);
		sum1 += mas[k];
	}
	for (k = 0; k < n; k++)
	{
		for (g = 0; g < n; g++)
		{
			if (k == mas1[g])
			{
				sum1 -= 2 * mas[g];
			}
		}
	}
	printf("Ñóììà ðàâíà: %lf\n", sum1);
	free(mas);
	free(mas1);
	return 0;
}
