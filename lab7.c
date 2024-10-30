#include<stdio.h>
#include<string.h>

void z1() {

	int req = 0;
	scanf("%d", &req);
	FILE* input, * output;
	input = fopen("D:/kpo/files/l6_input1.txt", "r");
	output = fopen("D:/kpo/files/l6_output1.txt", "w");
	char name[64] = { 0 };
	char firm[64] = { 0 };
	char sal[64] = { 0 };
	int isal = 0;
	while (1) {
		fscanf(input, "%s", name);
		if (feof(input)) {
			break;
		}
		fscanf(input, "%s", firm);
		fscanf(input, "%s", sal);
		isal = atoi(sal);

		if (isal < req) {
			fprintf(output, "%s", name);
			fprintf(output, " %s", firm);
			fprintf(output, " %d\n", isal);
		}
	}
	fclose(input);
	fclose(output);
}

void z2() {
	FILE* input, * output;
	input = fopen("D:/kpo/files/l6_input2.txt", "r");
	output = fopen("D:/kpo/files/l6_output2.txt", "w");
	char cur;
	while ((cur = fgetc(input)) != EOF) {
		if (cur >= 65 && cur <= 90) {
			cur += 32;
		}
		fputc(cur, output);
	}
	fclose(input);
	fclose(output);
}

int main() {
	//z1();
	z2();
}