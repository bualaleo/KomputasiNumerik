#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f (double x){
    return exp(-x) - x;
}

int main(){
    double p0 = 0.;
    double p1 = 1.;
    double q0,q1,p,q, TOL = 1.e-5;
    int NO = 1000;
    int i = 2;
    q0 = f(p0);
    q1 = f(p1);

    printf("_______________________________________________________\n");
    printf("n           p                 f(p)                error\n");
    printf("_______________________________________________________\n");

    printf("%d      %10.6lf         %10.6lf\n", 0, p0, f(p0));
    printf("%d      %10.6lf         %10.6lf\n", 1, p1, f(p1));

    while (i <= NO){
        p = p1-(q1*(p1-p0)/(q1-q0));
        printf("%d      %10.6lf         %10.6lf         %10.6lf\n", i, p, f(p), fabs(p-p1));

        if (fabs(p-p1) < TOL) {
            printf("_______________________________________________________\n");
            printf("akar nya adalah = %10.6lf\n", p);
         return 0;
        }
    i++;
    q = f(p);
    if(q * q1 < 0) {
        p0=p1;
        q0=q1;
    }
    p1 = p;
    q1 = q;
    }
    getchar();
    return 0;
}
