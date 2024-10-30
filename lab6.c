#include <stdio.h>
#include <string.h>

struct student {
	char sur[32];
	char plc[32];
	float sr;
};

void lab6() {
	int n, j = 0;
	printf("Size: ");
	scanf("%d", &n);
	struct student* arr = calloc(n, sizeof(struct student));
	for (int i = 0; i < n; i++) {
		char temp[32];
		printf("Student's surname: ");
		scanf("%s", arr[i].sur);
		printf("Student's location: ");
		scanf("%s", arr[i].plc);
		printf("Student's score: ");
		scanf("%f", &arr[i].sr);
		printf("\n");

		if (strcmp(arr[i].plc,"Minsk") == 0) {
			j++;
		}
	}
	printf("Students from Minsk: %d", j);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (strcmp(arr[j].sur, arr[j + 1].sur) > 0) {
				struct student temp;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	printf("\nStudents: ");
	for (int i = 0; i < n; i++) {
		if (strcmp(arr[i].plc, "Minsk") == 0) {
			printf("%s ", arr[i].sur);
		}
	}
}

int main() {
	lab6();
	return 0;
}

/*
3

TYTY
Minsk
7.2

TUI
qwjeo
8.1

ATTA
Minsk
9.0
*/