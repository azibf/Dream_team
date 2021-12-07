#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#define _CRT_SECURE_NO_WARNINGS
#define N 10


int main14()
{
	int k = 0, a, b, c = 1, d = 0, e = 0;
	int arr[N];
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 100 - 50;
		printf("%d", arr[i]);
		printf(" ");
	}
	printf("\n");
	for (int i = 0; i < N; i++)
	{
		if (arr[i] < 0)
		{
			printf("the first negative number: ");
			printf("%d", arr[i]);
			a = i;
			break;
		}
	}
	printf("\n");
	for (int i = 0; i < N; i++)
	{
		if (arr[i] == 0)
		{
			k++;
			if (k == 2)
			{
				printf("%d", i);
				b = i;
				break;
			}
		}
	}
	printf("\n");
	if (k < 2)
	{
		printf("Error");
		printf("\n");
		for (a; a < N; a++)
		{
			c = c * arr[a];
			d = d + abs(arr[a]);
			if (arr[a] > 0)
			{
				e++;
			}
		}
		printf("%d", c);
		printf("\n");
		printf("%d", d);
		printf("\n");
		printf("%d", e);
	}
	else
	{
		if (a > b)
		{
			for (b; b < a; b++)
			{
				c = c * arr[b];
				d = d + abs(arr[b]);
				if (arr[b] > 0)
				{
					e++;
				}
			}
			printf("%d", c);
			printf("\n");
			printf("%d", d);
			printf("\n");
			printf("%d", e);
		}
		if (a < b)
		{
			for (a; a < b; a++)
			{
				c = c * arr[a];
				d = d + abs(arr[a]);
				if (arr[a] > 0)
				{
					e++;
				}
			}
			printf("%d", c);
			printf("\n");
			printf("%d", d);
			printf("\n");
			printf("%d", e);
		}
		printf("\n");
	}
	printf("\n");
	int* p;
	int l = 0, j = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] != 0)
		{
			l++;
		}
	}
	p = (int*)malloc(l * sizeof(int));
	for (int i = N - 1; i > -1; i--)
	{
		p[j] = arr[i];
		j++;
	}
	for (int j = 0; j < N; j++)
	{
		printf("%d", p[j]);
		printf(" ");
	}
	j = 0;
	printf("\n");
	for (int i = 0; i < N; i++)
	{
		if (arr[i] != 0)
		{
			p[j] = i;
			printf("%d", p[j]);
			printf(" ");
		}
	}

	return 0;
}
