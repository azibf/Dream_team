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
			printf(" ");
			printf("%d", i);
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
				printf("Index of second zero:");
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
			if (a != N - 1)
			{
				printf("%d", arr[a]);
				printf("*");
			}
			else
			{
				printf("%d", arr[a]);
				printf("=");
			}
			c = c * arr[a];
			d = d + abs(arr[a]);
			if (arr[a] > 0)
			{
				e++;
			}
		}
		printf("Multiply:");
		printf("%d", c);
		printf("\n");
		printf("Sum:");
		printf("%d", d);
		printf("\n");
		printf("The number of positive elements:");
		printf("%d", e);
	}
	else
	{
		if (a > b)
		{
			for (b; b < a; b++)
			{
				if (b != a - 1)
				{
					printf("%d", arr[b]);
					printf("*");
				}
				else
				{
					printf("%d", arr[b]);
					printf("=");
				}
				c = c * arr[b];
				d = d + abs(arr[b]);
				if (arr[b] > 0)
				{
					e++;
				}
			}
			printf("\n");
			printf("Multiply: ");
			printf("%d", c);
			printf("\n");
			printf("Sum:");
			printf("%d", d);
			printf("\n");
			printf("The number of positive elements:");
			printf("%d", e);
		}
		else
		{
			for (a; a < b; a++)
			{
				printf("Multiply:");
				if (a != b - 1)
				{
					printf("%d", arr[a]);
					printf("*");
				}
				else
				{
					printf("%d", arr[a]);
					printf("=");
				}
				c = c * arr[a];
				d = d + abs(arr[a]);
				if (arr[a] > 0)
				{
					e++;
				}
			}
			printf("Multiply:");
			printf("%d", c);
			printf("\n");
			printf("Sum:");
			printf("%d", d);
			printf("\n");
			printf("The number of positive elements:");
			printf("%d", e);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
	printf("Reverse array:");
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
		if (p[j] != 0)
		{
			printf("%d", p[j]);
			printf(" ");
		}
	}
	j = 0;
	printf("\n");
	printf("Index of zero elements:");
	for (int i = N - 1; i > -1; i--)
	{
		if (arr[i] == 0)
		{
			p[j] = i;
			printf("%d", p[j]);
			printf(" ");
		}
	}

	return 0;
}
