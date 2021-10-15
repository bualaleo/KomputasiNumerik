#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x){
    return pow(x,2)-(2*x)-3;
}

double g(double x){
    return pow(2*x+3,1./2);
}

int main(){
    double p0=2.;
    double p, TOL = 1.e-6;
    int NO = 1000, i = 1;
    printf("------------------------------------------------\n");
    printf("n       p       f(p)        g(p)        error   \n");
    printf("________________________________________________\n");
    printf("%d %10.6lf %10.6lf %10.6lf\n", 0, p0, f(p0),g(p0));

    while (i<=NO){
        p=g(p0);
        printf("%d %10.6lf %10.6lf %10.6lf %10.6lf\n", i, p, f(p), g(p), fabs(p-p0));
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
