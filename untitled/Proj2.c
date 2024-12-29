//
// Created by Itay Segev on 22/12/2024.
//
#include "Proj2.h"
#include <stdio.h>
#include <string.h>

#define N 5
#define INF 10000000

int ex1() {
    int sum = 0;
    printf("Enter %d grades\n", N);
    int grades[N] = {0};
    for (int i = 0; i < N; i++) {
        int x = 0;
        scanf("%d", &grades[i]);
        printf("student %d grade %d\n", i + 1, grades[i]);
        sum += grades[i];
    }
    double avg = (double) sum / N;
    printf("Average grade %.2f\n", avg);
    for (int i = 0; i < N; i++) {
        if (grades[i] >= avg) {
            printf("student %d passed with grade of %d\n", i + 1, grades[i]);
        }
    }
    return 0;
}

int ex2(char *str) {
    int len=strlen(str);
    printf("len=%d\n",len);
    int i=0;
    int j=len-1;
    while (i<j) {
        if (str[i]!=str[j]) {
            printf("%s not palindrome\n",str);
            return -1;
        }
        i++;
        j--;
    }
    printf("%s palindrome\n",str);
    return 0;
}

int ex3(int n,int x[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int temp=x[i][j];
            x[i][j]=x[j][i];
            x[j][i]=temp;
        }
    }
    printf("transpose\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ",x[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int ex4(int n,int x[n][n]) {
    int cur=0;
    for (int i = 0; i < n; i++) {
        cur+=x[i][i];
    }
    int sum=cur;
    cur=0;
    for (int i = 0; i < n; i++) {
        cur+=x[i][n-i-1];
    }
    if (cur!=sum) {
        printf("not symmetric\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cur=0;
        for (int j = 0; j < n; j++) {
            cur+=x[i][j];
        }
        if (cur!=sum) {
            printf("not symmetric\n");
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        cur=0;
        for (int j = 0; j < n; j++) {
            cur+=x[j][i];
        }
        if (cur!=sum) {
            printf("not symmetric\n");
            return 0;
        }
    }
    printf("The given Matrix is a magic Matrix with sum of %d\n",sum);
    return 1;

}

int ex5(int n,int dist[n][n],int start,int end) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((dist[i][k] != INF) && (dist[k][j] != INF) && (dist[i][j] > dist[i][k] + dist[k][j])) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printf("The shortest path between %d and %d is %d\n",start,end,dist[start][end]);
    return 0;
}

int knapsack( int values[], int weights[], int sackSize, int isSelected[],int num) {
    int n=num;
    int knapsack[n+1][sackSize+1];
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=sackSize;j++) {
            if (i==0 || j==0) {
                knapsack[i][j]=0;
            }
            else if (weights[i-i]<=j) {
                if (values[i-1]+knapsack[i-1][j-weights[i-1]]>knapsack[i-1][j]) {
                    knapsack[i][j]=values[i-1]+knapsack[i-1][j-weights[i-1]];
                }
                else {
                    knapsack[i][j]=knapsack[i-1][j];
                }

            }
        }
    }
    printf("The maximum value that can be put in a knapsack of capacity %d is %d\n",sackSize,knapsack[n][sackSize]);
    int w = sackSize;
    for (int i = n; i > 0; i--) {
        if (knapsack[i][w] != knapsack[i - 1][w]) {
            isSelected[i - 1] = 1;
            w -= weights[i - 1];
        } else {
            isSelected[i - 1] = 0;
        }
    }
    printf("The items that are selected are :\n");
    for (int i = 0; i < n; i++) {
        if (isSelected[i] == 1) {
            printf("%d \n", i + 1);
        }
    }
    printf("\n");
    return 0;
}

int ex7(void *a,void *b, int size) {
    int x=0;
    if (a>b)
        x=a-b;
    else
        x=b-a;
    int dif=x/size;
    printf("The subarray size between the two given pointers is: %d\n",dif);
    return 0;
}

int ex8(int x[],int n,int num) {
    int i=0;
    int j=n-1;
    while (i<j) {
        if (x[i]+x[j]==num) {
            printf("there is two numbers that the sum of them is %d the numbers are %d , %d \n",num,x[i],x[j]);
            return 1;
        }
        if (x[i]+x[j]>num) {
            j--;
        }
        else {
            i++;
        }
    }
    printf("there is no two numbers that the sum of them is %d\n",num);
    return 0;
}

int ex9(int x[],int n) {
    int visited[n];
    for (int i = 0; i < n; i++) {
        int curval=i;
        for (int j = 0; j < n; j++) {
            visited[j] = 0;
        }
        curval=curval+x[curval];
        while (curval<n && visited[curval]==0) {
            visited[curval]=1;
            curval=curval+x[curval];
        }
        if (curval>=n) {
            printf("there is no circle found\n");
            return -1;
        }
        if (visited[curval]==1) {
            for (int j = 0; j < n; j++) {
                if (visited[j]==1) {
                    printf("there is a circle found start in %d\n",j);
                    return j;
                }
            }
        }
    }
    return -1;
}

int ex10(int A[],int B[],int alen,int blen,int *start,int *end) {
    *start=-1;
    *end=-1;
    for (int i = 0; i <= alen-blen; i++) {
        int f=1;
        for (int j = 0; j < blen; j++) {
            if (A[i+j]!=B[j]) {
                f=0;
                break;
            }
        }
        if (f==1) {
            *start=i;
            *end=i+blen-1;
            return 1;
        }
    }
    return -1;
}
