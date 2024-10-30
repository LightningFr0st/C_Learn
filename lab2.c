#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

void z1(){
    srand(time(NULL));
    int m,n;
    scanf("%d",&n);
    scanf("%d",&m);

    int** arr = (int**)malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++){
        arr[i] = (int*)malloc(m*sizeof(int));
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            arr[i][j] = rand() % 100;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d\t",arr[i][j]);
       }
       printf("\n");
    }
    printf("\n");
    int mn=0,mx=0;
    for (int i = 0; i < m; i++){
        mn = mx = 0;
        for (int j = 1; j < n; j++){
            if(arr[j][i]>arr[mx][i])
                mx = j;
            if(arr[j][i]<arr[mn][i])
                mn = j;
        }
        arr[mx][i]^=arr[mn][i]^=arr[mx][i]^=arr[mn][i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d\t",arr[i][j]);
       }
       printf("\n");
    }
    for (int i = 0; i < n; ++i)
    {
        free(arr[i]);
    }
    free(arr);
}

void z2(){
    srand(time(NULL));
    int m,n;
    scanf("%d",&n);
    scanf("%d",&m);
    int** arr = (int**)malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++){
        arr[i] = (int*)malloc(m*sizeof(int));
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            arr[i][j] = rand() % 100;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d\t",arr[i][j]);
       }
       printf("\n");
    }
    printf("\n");

    for(int i = 0; i < n/2; i++){
        for(int j = 0; j < m; j++){
            arr[i][j]^=arr[n/2+i][j]^=arr[i][j]^=arr[n/2+i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d\t",arr[i][j]);
       }
       printf("\n");
    }
    for (int i = 0; i < n; ++i)
    {
        free(arr[i]);
    }
    free(arr);
}

void z3(){
    srand(time(NULL));
    int** arr = (int**)malloc(6*sizeof(int*));
    for (int i = 0; i < 6; i++){
        arr[i] = (int*)malloc(6*sizeof(int));
    }
    int* check = (int*)malloc(101*sizeof(int));
    memset(check, 0, sizeof(int)*101);
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            arr[i][j] = 2 + rand() % 15;
            printf("%d\t",arr[i][j]);
            check[arr[i][j]]++;
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            if (check[arr[i][j]] > 1)
                arr[i][j] = 1;
            else
                arr[i][j] = 0;
        }
    }

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            printf("%d\t",arr[i][j]);
       }
       printf("\n");
    }
    for (int i = 0; i < 6; ++i)
    {
        free(arr[i]);
    }
    free(arr);
}

int main() {
    z2();
    return 0;
}
