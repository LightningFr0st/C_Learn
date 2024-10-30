#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void z24() {
	int n, ans = 0;
    scanf("%d",&n);
	int* arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d",arr + i);
		if (*(arr + i) > 7) {
			*(arr + i) = 7;
			ans++;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ",*(arr + i));
	}
	free(arr);
	printf("\nAmount - %d",ans);
}

void z26() {
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= (int)(floor(sqrt(n))); i++) {
		if (!(n % i)) {
			if (i == (int)(floor(sqrt(n))))
                printf("%d ",i);
			else
                printf("%d %d ",i,n/i);
		}
	}
}

int fact(int n) {
	if (n == 0 || n == 1)
		return 1;
	return n * fact(n - 1);
}

void z28() {
	int n, m;
	scanf("%d %d",&n,&m);
	printf("%f",(fact(n) + fact(m)) / (double)fact(m + n));
}


void z30() {
	int n;
	scanf("%d",&n);
	float min = 9e10f, max = 0.0f;
	for (int i = 0; i < n; i++) {
		float temp;
		scanf("%f",&temp);
		if (temp < min) {
			min = temp;
		}
		if (temp > max) {
			max = temp;
		}
	}
	printf("%f",max - min);
}

int main() {
    z30();
    return 0;
}
