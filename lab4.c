#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

void z1() {
	char str[40];
	scanf("%[^\n]", str);
	int min = 100000;
	int i = 0;
	int cur = 0;
	while (str[i] != '\0') {
		if (str[i] != ' ') {
			cur++;
		}
		else {
			if (str[i - 1] != ' ') {
				min = MIN(cur, min);
				cur = 0;
			}
		}
		i++;
	}
	printf("Min Length = %d", min);
}

void z2() {
	char str[40];
	scanf("%[^\n]", str);
	int ans = 0, word = 1, i = 0;
	while (str[i] != '\0') {
		if (word && str[i] == 'A') {
			ans++;
			word = 0;
		}
		else if (str[i] == ' ') {
			word = 1;
		}
		i++;
	}
	printf("Amount = %d", ans);
}

void z3() {
	char str[50];
	scanf("%[^\n]", str);

	int i = 0, j = 0;
	char** matr = calloc(10, sizeof(char));
	i = 0;
	char* token = strtok(str, " ");
	while (token != NULL) {
		matr[i] = malloc(sizeof(char) * 10);
		strcpy(matr[i], token);
		i++;
		token = strtok(NULL, " ");
	}
	int size = i;
	i = 0;
	char* temp;
	for (i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (strcmp(matr[j], matr[j+1]) > 0) {
				temp = matr[j];
				matr[j] = matr[j + 1];
				matr[j + 1] = temp;
			}
		}
	}
	
	for (int i = 0; i < size; i++) {
		printf("%s ", matr[i]);
	}
}

int main() {
	//z1();
	//z2();
	//z3();
	return 0;
}