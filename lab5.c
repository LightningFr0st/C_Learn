#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

void z1() {
	char str[256];
	char seek[40];
	char chng[40];
	char str_res[512];
	memset(str_res, 0, sizeof(str_res));
	printf("Enter source string: ");
	scanf("%s", str);
	printf("What string is replace: ");
	scanf("%s", seek);
	printf("Replacement string: ");
	scanf("%s", chng);
	
	int i = 0, j = 0, k = 0;
	char cnt[2];
	cnt[0] = 49;
	cnt[1] = 0;

	while (str[i]) {
		if (str[i] == seek[k]) {
			j = i;
			while (str[j] == seek[k]) { 
				j++; 
				k++;
				if (!str[j]) break;
			}
			if(!seek[k]){
				i += k - 1;
				strcat(str_res, chng);
				strcat(str_res, cnt);
				cnt[0]++;
			}
			k = 0;
		}
		else {
			char temp[2];
			temp[0] = str[i];
			temp[1] = '\0';
			strcat(str_res, temp);
		}
		i++;
	}
	printf("Result string : %s", str_res);
}

int main() {
	//setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	z1();
	return 0;
}
//ПОЛИЛИ_ЛИЛИЮ_ЛИЛИЛИ
//ЛИ
//СТО