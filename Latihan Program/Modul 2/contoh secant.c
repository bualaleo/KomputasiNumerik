#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x){
    return pow(x,3)-(2*x*x)-5;
}

int main(){
    double p0=2.;
    double p1=4.;
    double p,q0,q1,TOL=1.e-7;
    int NO=1000;
    printf("------------------------------------\n");
    printf("n       p       f(p)        error   \n");
    printf("____________________________________\n");
    printf("%d %10.6lf %10.6lf \n", 0, p0, f(p0));
    printf("%d %10.6lf %10.6lf \n", 1, p1, f(p1));

    int i = 2;
    q0=f(p0);
    q1=f(p1);

    while (i<=NO){
        p=p1-(q1*(p1-p0)/(q1-q0));
        printf("%d %10.6lf %10.6lf %10.6lf\n", i, p, f(p), fabs(p-p1));

        if(fabs(p-p1)<TOL){
            printf("akarnya adalah = %10.6lf\n", p);
            return 0;
        }
        i++;
        p0=p1;
        q0=q1;
        p1=p;
        q1=f(p1);
    }
}
