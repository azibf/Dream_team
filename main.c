#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#include "var6.h"
#include "var14.h"
#include "var15.h"
#include "var17.h"

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int main()
{
    setlocale(LC_ALL, "Rus");
    int q = 1;
    int a;
    while (q != 0)
    {
        printf("Type number of variant (6, 14, 15, 17 or other number to view all) ");
        scanf("%d", &a);
        switch(a)
        {
            case 6:
                {
                    printf("Author: Zakharova\n\n");
                    main6();
                    break;
                }
            case 14:
                {
                    printf("\n\nAuthor: Petrochenkov\n\n");
                    main14();
                    break;
                }
            case 15:
                {
                    printf("\n\nAuthor: Plestov\n\n");
                    main15();
                    break;
                }
            case 17:
                {
                    printf("\n\nAuthor: Suvorov\n\n");
                    main17();
                    break;
                }
            default:
                {
                    printf("Author: Zakharova\n\n");
                    main6();
                    printf("\n\nAuthor: Petrochenkov\n\n");
                    main14();
                    printf("\n\nAuthor: Plestov\n\n");
                    main15();
                    printf("\n\nAuthor: Suvorov\n\n");
                    main17();
                    break;
                }
        }
        printf("\n0 - exit, other number - continue ");
        scanf("%d", &q);
    }
    return 0;
}
