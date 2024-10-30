#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// format: surname;year;number 

FILE* file;

void find() {
    printf("Surname: ");
    char surname[32] = { 0 };
    scanf("%s", surname);
    char temp[96] = { 0 };
    fseek(file, 0, SEEK_SET);
    while (1) {
        fscanf(file, "%s", temp);
        char* t_sur = strtok(temp, ";");
        if (!strcmp(surname, t_sur)) {
            t_sur = strtok(NULL, ";");
            t_sur = strtok(NULL, ";");
            printf("Number : %s\n", t_sur);
            break;
        }
        if (feof(file)) {
            printf("Surname not found\n");
            break;
        }
    }
}

void number() {
    printf("Year: ");
    int year;
    scanf("%d", &year);
    char temp[96] = { 0 };
    int ans = 0;
    fseek(file, 0, SEEK_SET);
    while (1) {
        fscanf(file, "%s", temp);
        char* sy = strtok(temp, ";");
        sy = strtok(NULL, ";");
        int ty = atoi(sy);

        if (ty >= year)
            ans++;

        if (feof(file))
            break;
    }
    printf("Number of installed phones since %d = %d\n", year, ans);
}

void modify() {
    printf("Surname: ");
    char surname[32] = { 0 };
    scanf("%s", surname);
    char temp[96] = { 0 };
    fseek(file, 0, SEEK_SET);
    while (1) {
        fscanf(file, "%s", temp);
        int offset = strlen(temp);
        char* namepos = strchr(temp, ';');
        int name_count = namepos - temp;
        char t_sur[32] = { 0 };
        strncpy(t_sur, temp, name_count);

        if (!strcmp(surname, t_sur)) {
            printf("Change\n 1 - year\n 2 - number\n");
            int req;
            scanf("%d", &req);
            if (req == 1) {
                printf("Year:");
                char year[16];
                scanf("%s", &year);
                int i = 0;
                namepos++;
                while (*namepos != ';') {
                    *namepos++ = year[i++];
                }
                fseek(file, -offset, SEEK_CUR);
                fputs(temp, file);
            }
            else {
                printf("Number:");
                char number[16];
                scanf("%s", &number);
                int i = 0;
                namepos += 6;
                while (number[i]) {
                    *namepos++ = number[i++];
                }
                fseek(file, -offset, SEEK_CUR);
                fputs(temp, file);
                fseek(file, -(temp + offset - namepos), SEEK_CUR);
                for (int i = temp + offset - namepos; i > 0; i--) {
                    fputc(0, file);
                }
            }
            break;
        }
        if (feof(file)) {
            printf("Surname not found\n");
            break;
        }
    }
}

void add() {
    printf("Enter new data:\n");
    char data[96];
    scanf("%s", data);
    fseek(file, 0, SEEK_END);
    fprintf(file, "\n%s", data);
}

int main() {
    file = fopen("./files/l8.txt", "r+");
    int isRunning = 1;
    printf("Requests:\n 1 - Find phone number by surname\n 2 - Number of installed phones since XXXX year \n");
    printf(" 3 - Change data \n 4 - Add Data\n 5 - End \n");
    while (isRunning) {
        int req;
        printf("Your request: ");
        scanf("%d", &req);
        switch (req)
        {
        case 1:
            find();
            break;
        case 2:
            number();
            break;
        case 3:
            modify();
            break;
        case 4:
            add();
            break;
        default:
            isRunning = 0;
            break;
        }
    }
    fclose(file);
    return 0;
}
//temper;2000;321
//sunwell;1999;333