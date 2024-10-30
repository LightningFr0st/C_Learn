#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) < (Y)) ? (Y) : (X))

int z1(int** arr, int n){
    int mn = 101;
    for (int i = 0; i < n; i++){
        for (int j = MIN(i+1,n - i - 1); j < MAX(i+1,n - i - 1); j++){
            if(arr[i][j]<mn){
                mn = arr[i][j];
            }
        }
    }
    return mn;
}

int z2(int** arr, int n){
    int mn = 101;
    for (int i = 0; i < n/2; i++){
        for (int j = i+1; j < n-i-1; j++){
            if(arr[j][i]<mn){
                mn = arr[j][i];
            }
        }
    }
    return mn;
}
void swap(int* a, int* b) {
    int t;
    t = *b;
    *b = *a;
    *a = t;
}
void z3(int** arr, int n) {

    for (int i = 0; i < n; i++) {
        int csum = 0;
        for (int j = 0; j < n; j++) {
            csum += arr[j][i];
        }
        arr[n][i] = csum;
        printf("%d\t", arr[n][i]);
    }
    printf("\n\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[n][j + 1] > arr[n][j]) {
                for (int k = 0; k <= n; k++) {
                    swap(*(arr + k) +j, *(arr + k) + j + 1);
                }
            }
        }
    }
}
int main() {
    srand(time(NULL));
    int n;
    scanf("%d", &n);
    printf("N = %d\n",n);
    int** arr = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        arr[i] = (int*)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = rand() % 100;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    //printf("1)MIN = %d\n",z1(arr,n));
    //printf("2)MIN = %d\n",z2(arr,n));

    z3(arr, n);

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i <= n; ++i)
    {
        free(arr[i]);
    }
    free(arr);
    return 0;
}
