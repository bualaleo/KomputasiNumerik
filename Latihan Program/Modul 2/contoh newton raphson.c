#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x){
    return pow(x,3)-(2*x*x)-5;
}

double turunan_f(double x){
    return (3*x*x)-(4*x);
}

int main(){
    double p0=2.;
    double p;
    double TOL = 1.e-5;
    int NO=1000;
    printf("------------------------------------------------\n");
    printf("n       p       f(p)        f'(p)        error   \n");
    printf("________________________________________________\n");
    printf("%d %10.6lf %10.6lf %10.6lf\n", 0, p0, f(p0),turunan_f(p0));

    int i=1;
    while (i<=NO){
        p=p0-f(p0)/turunan_f(p0);
        printf("%d %10.6lf %10.6lf %10.6lf %10.6lf\n", i, p, f(p),turunan_f(p), fabs(p-p0));

        if(fabs(p-p0)<TOL){
            printf("akarnya adalah = %10.6lf\n", p);
            return 0;
        }
        i++;
        p0=p;
    }
    getchar();
    return 0;
}
