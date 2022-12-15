#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INIT_CAPACITY 3    /* �迭 ���Ҵ��� �׽�Ʈ�ϱ� ���ؼ� �Ϻη� ���� ���� ������ */
#define BUFFER_SIZE 50

char** names;    // char * names[CAPACITY]; 
char** numbers;    // char * Ÿ��(������)�� �迭�� �̸�(�����͸� ������ ���� ������)�̹Ƿ� char ** Ÿ���� �����̴�.

int capacity = INIT_CAPACITY;    /* size of arrays */
int n = 0;                       /* number of people in phone directory */

/* function prototypes here */
void init_directory();
void reallocate();
int read_line(char str[], int limit);
void process_command();
void load(char* fileName);
void add(char* name, char* number);
void find(char* name);
void status();
void remove(char* name);
void save(char* fileName);
int search(char* name);

char delim[] = " ";

int main() {
    init_directory();
    process_command();
    return 0;
}

void init_directory()
{
    names = (char**)malloc(INIT_CAPACITY * sizeof(char*));
    numbers = (char**)malloc(INIT_CAPACITY * sizeof(char*));
}

void reallocate()
{
    int i;

    capacity *= 2;
    char** tmp1 = (char**)malloc(capacity * sizeof(char*));
    char** tmp2 = (char**)malloc(capacity * sizeof(char*));

    for (i = 0; i < n; i++) {
        tmp1[i] = names[i];
        tmp2[i] = numbers[i];
    }

    free(names);
    free(numbers);

    names = tmp1;
    numbers = tmp2;
}

int read_line(char str[], int limit)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')    // getchar() ��ȯ�� ���� Ÿ��, �ٹٲ� ���ڰ� ���� ������ �д´�. 
        if (i < limit - 1)              // �迭�� �뷮�� �ʰ����� ���� ���� �����Ѵ�. 
            str[i++] = ch;

    str[i] = '\0';

    return i;
}

void process_command()
{
    char command_line[BUFFER_SIZE];
    char* command, * argument1, * argument2;

    while (1) {
        char* context;
        printf("$ ");

        if (read_line(command_line, BUFFER_SIZE) <= 0)
            continue;

        command = strtok_s(command_line, delim, &context);
        if (command == NULL) continue;
        if (strcmp(command, "read") == 0) {
            argument1 = strtok_s(NULL, delim, &context);
            if (argument1 == NULL) {
                printf("File name required.\n");
                continue;
            }
            load(argument1);
        }
        else if (strcmp(command, "add") == 0) {
            argument1 = strtok_s(NULL, delim, &context);
            argument2 = strtok_s(NULL, delim, &context);
            if (argument1 == NULL || argument2 == NULL) {
                printf("Invalid arguments.\n");
                continue;
            }
            add(argument1, argument2);
            printf("%s was added successfully.\n", argument1);
        }
        else if (strcmp(command, "find") == 0) {
            argument1 = strtok_s(NULL, delim, &context);
            if (argument1 == NULL) {
                printf("Invalid arguments.\n");
                continue;
            }
            find(argument1);
        }
        else if (strcmp(command, "status") == 0)
            status();
        else if (strcmp(command, "delete") == 0) {
            argument1 = strtok_s(NULL, delim, &context);
            if (argument1 == NULL) {
                printf("Invalid arguments.\n");
                continue;
            }
            remove(argument1);
        }
        else if (strcmp(command, "save") == 0) {
            argument1 = strtok_s(NULL, delim, &context);
            argument2 = strtok_s(NULL, delim, &context);
            if (argument1 == NULL || strcmp("as", argument1) != 0 || argument2 == NULL) {
                printf("Invalid command format.\n");
                continue;
            }
            save(argument2);
        }
        else if (strcmp(command, "exit") == 0)
            break;
    }
}

void load(char* fileName) {
    char buf1[BUFFER_SIZE];
    char buf2[BUFFER_SIZE];

    FILE* fp = 0;
    fopen_s(&fp,fileName, "r");
    if (fp == NULL) {
        printf("Open failed.\n");
        return;
    }
    while ((fscanf_s(fp, "%s", buf1, BUFFER_SIZE) != EOF)) {
        fscanf_s(fp, "%s", buf2, BUFFER_SIZE);
        add(buf1, buf2);
    }
    fclose(fp);
}

void add(char* name, char* number) {
    if (n >= capacity)
        reallocate();

    int i = n - 1;
    while (i >= 0 && strcmp(names[i], name) > 0) {
        names[i + 1] = names[i];
        numbers[i + 1] = numbers[i];
        i--;
    }
    names[i + 1] = _strdup(name);    // add(argument1, argument2);�� �θ��� argumnet���� �� �Է°����� �����ϱ� ��� �����
    numbers[i + 1] = _strdup(number);
    n++;
}

void find(char* name) {
    int index = search(name);
    if (index == -1)
        printf("No person named '%s' exists.\n", name);
    else
        printf("%s\n", numbers[index]);
}

void status() {
    int i;
    for (i = 0; i < n; i++)
        printf("%s  %s\n", names[i], numbers[i]);
    printf("Total %d persons.\n", n);
}

void remove(char* name) {
    int i = search(name);
    if (i == -1) {
        printf("No person named '%s' exists.\n", name);
        return;
    }

    int j = i;
    for (; j < n - 1; j++) {
        names[j] = names[j + 1];
        numbers[j] = numbers[j + 1];
    }
    n--;
    printf("'%s' was deleted successfully.\n", name);
}

void save(char* fileName) {
    int i;
    FILE* fp = 0;
    fopen_s(&fp, fileName, "w");
    if (fp == NULL) {
        printf("Open failed.\n");
        return;
    }
    for (i = 0; i < n; i++) {
        fprintf(fp, "%s %s\n", names[i], numbers[i]);
    }
    fclose(fp);
}

int search(char* name) {
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(name, names[i]) == 0) {
            return i;
        }
    }
    return -1;
}