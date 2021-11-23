#include <stdio.h>
#include <math.h>

double x1, x2;

int eval_sqr(double a, double b, double c, double *x1, double *x2)
{
    if (a == 0)
    {
        return(-1);
    }
    
    double d = b*b - 4*a*c;
    
    if(d<0)
    {
        return(0);
    } 
    else if (d==0)
    {
        *x1 = (-1*b) / (2*a);
        *x2 = *x1;
        return(1);
    }
    else
    {
        *x1 = (-1*b + sqrt(d))/ (2*a);
        *x2 = (-1*b - sqrt(d))/ (2*a);
        return(2);
    }
}

int main()
{
    double a, b, c;
    printf("Input coefficients:\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    int r = eval_sqr(a, b, c, &x1, &x2);
    if(r > 0)
    {
        printf("The result is:\n%.2f %.2f", x1, x2);
    }
    else if(r == 0)
    {
        printf("No solutions!\n");
    }
    else
    {
        printf("Inappropriate input");
    }
    return(0);
}