#include <stdio.h>
#include "Proj2.h"

int main(void) {
    // ex1();
    //
    // ex2("abba");
    //
    //  int x[5][5]={{5,5,5,5,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
    //  ex3(5,x);
    //
    //  int y[3][3]={{2,7,6},{9,5,1},{4,3,8}};
    //  ex4(3,y);
    //
    //  int dist [3][3]={{0,3,5},{3,0,1},{5,1,0}};
    //  ex5(3,dist,0,2);
    //
    //  int values[]={4,8,7,1,2,10};
    //  int weights[]={9,6,3,4,5,2};
    //  int sackSize=15;
    //  int isSelected[6]={0};
    //  knapsack(values,weights,sackSize,isSelected,6);
    //
    //  int x1[25]={0};
    //  ex7(&x1[5],&x1[19],sizeof(x1[0]));
    //
    //  int x2[10]={1,3,5,7,10,11,14,24,34,67};
    //  ex8(x2,10,24);

    // int x3[5]={3,2,0,1,-3};
    // ex9(x3,5);

    int A[10]={1,2,3,4,5,6,7,8,9,10};
    int B[5]={3,4,5,6,7};
    int C[4]={1,2,4,5};
    int D[4]={1,2,3,4};
    int E[4]={7,8,9,10};
    int start=0;
    int end=0;
    int ans=ex10(A,B,10,5,&start,&end);
    if (ans==1)
        printf("start=%d,end=%d\n",start,end);
    else
        printf("there is nothing found\n");
    start=0;
    end=0;
    ans=ex10(A,C,10,4,&start,&end);
    if (ans==1)
        printf("start=%d,end=%d\n",start,end);
    else
        printf("there is nothing found\n");
    start=0;
    end=0;
    ans=ex10(A,D,10,4,&start,&end);
    if (ans==1)
        printf("start=%d,end=%d\n",start,end);
    else
        printf("there is nothing found\n");
    start=0;
    end=0;
    ans=ex10(A,E,10,4,&start,&end);
    if (ans==1)
        printf("start=%d,end=%d\n",start,end);
    else
        printf("there is nothing found\n");

    return 0;
}