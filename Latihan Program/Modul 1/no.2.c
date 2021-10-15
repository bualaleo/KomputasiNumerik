#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f (double x){
    return pow(x,3)+(4*x*x)-10;
}

int main(){
    double a = 1.;
    double b = 2.;
    double FA,FP,p, TOL = 1.e-5;
    int NO = 1000;
    int i = 1;
    FA = f(a);

    printf("-------------------------------------------------------------------------------\n");
    printf("n\t     a\t     \tb     \tp     \tf(a)      f(b)      f(p)      error\n");
    printf("_______________________________________________________________________________\n");

    while (i<=NO){
        p  = (a+b)/2;
        FP = f(p);

    printf("%d\t%10.6lf%10.6lf%10.6lf%10.6lf%10.6lf%10.6lf%10.6lf\n",i,a,b,p,f(a),f(b),f(p),(b-a)/2);

    if (FP == 0 | (b-a)/2 < TOL){
        printf("______________________________________________________________________________\n");
        printf("akarnya adalah = %10.6lf\n", p);
        return 0;
    }
    i++;
    if (FA * FP > 0){
        a = p;
        FA = FP;
    } else
        b = p;
    }
    getchar();
    return 0;
    }
