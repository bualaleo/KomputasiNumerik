#include <stdio.h>

int main(){
    int i, j, k, n;
    float A[20][20],c,x[10],sum=0.0;
    printf("\nInput elemen matriks N : ");
    scanf("%d",&n);
    printf("\nInput Matriks : \n\n");
    for (i=1;i<=n;i++){
        for(j=1;j<=(n+1);j++){
            printf("A[i][j] : ");
            scanf("%d%d\n",&i,&j);
        }
    }
}
