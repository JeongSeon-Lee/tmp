#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INIT_CAPACITY 3    /* 배열 재할당을 테스트하기 위해서 일부러 아주 작은 값으로 */
#define BUFFER_SIZE 50

char ** names;    // char * names[CAPACITY]; 
char ** numbers;    // char * 타입(포인터)의 배열의 이름(포인터를 값으로 갖는 포인터)이므로 char ** 타입의 변수이다.

int capacity = INIT_CAPACITY;    /* size of arrays */
int n = 0;                       /* number of people in phone directory */

/* function prototypes here */
void init_directory();
void reallocate();
int read_line(char str[], int limit);
void process_command();
void load(char *fileName);
void add(char * name, char * number);
void find(char *name);
void status();
void remove(char *name);
void save(char *fileName);
int search(char *name);

char delim[] = " ";

int main() {
    init_directory();
    process_command();
    return 0;
}

void init_directory() {
    names = (char **)malloc(INIT_CAPACITY * sizeof(char *));    // char * : 한 칸의 크기
    numbers = (char **)malloc(INIT_CAPACITY * sizeof(char *));
}

void reallocate() {
    int i;

    capacity *= 2;    // 일반적으로 두 배
    char **tmp1 = (char **)malloc(capacity * sizeof(char *));
    char **tmp2 = (char **)malloc(capacity * sizeof(char *));

    for (i = 0; i < n; i++) {
        tmp1[i] = names[i];
        tmp2[i] = numbers[i];
    }

    free(names);
    free(numbers);

    names = tmp1;
    numbers = tmp2;
}

int read_line(char str[], int limit) {
    int ch, i = 0;

    while ((ch = getchar()) != '\n')    // getchar() 반환값 정수 타입, 줄바꿈 문자가 나올 때까지 읽는다. 
        if (i < limit - 1)              // 배열의 용량을 초과하지 않을 때만 저장한다. 
            str[i++] = ch;

    str[i] = '\0';
    
    return i;
}

void process_command() {
    char command_line[BUFFER_SIZE];
    char *command, *argument1, *argument2;

    while (1) {
        printf("$ ");

        if (read_line(command_line, BUFFER_SIZE) <= 0)    // 아무것도 입력하지 않은 경우
            continue;

        command = strtok(command_line, delim);
        if (command == NULL) continue;    // 앞에서 처리했기 때문에 이런 경우는 없음
        if (strcmp(command, "read") == 0) {
            argument1 = strtok(NULL, delim);
            if (argument1 == NULL) {
                printf("File name required.\n");
                continue;
            }
            load(argument1);
        }
        else if (strcmp(command, "add") == 0) {
            argument1 = strtok(NULL, delim);
            argument2 = strtok(NULL, delim);
            if (argument1 == NULL || argument2 == NULL) {
                printf("Invalid arguments.\n");
                continue;
            }
            add(argument1, argument2);
            printf("%s was added successfully.\n", argument1);
        }
        else if (strcmp(command, "find") == 0) {
            argument1 = strtok(NULL, delim);
            if (argument1 == NULL) {
                printf("Invalid arguments.\n");
                continue;
            }
            find(argument1);
        }
        else if (strcmp(command, "status") == 0)
            status();
        else if (strcmp(command, "delete") == 0) {
            argument1 = strtok(NULL, delim);
            if (argument1 == NULL) {
                printf("Invalid arguments.\n");
                continue;
            }
            remove(argument1);
        }
        else if (strcmp(command, "save") == 0) {
            argument1 = strtok(NULL, delim);
            argument2 = strtok(NULL, delim);
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

void load(char *fileName) {
    char buf1[BUFFER_SIZE];
    char buf2[BUFFER_SIZE];

    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Open failed.\n");
        return;
    }
    while ((fscanf(fp, "%s", buf1) != EOF)) {
        fscanf(fp, "%s", buf2);
        add(buf1, buf2);
    }
    fclose(fp);
}

void add(char * name, char * number) {
    if (n >= capacity)
        reallocate();

    int i = n - 1;
    while (i >= 0 && strcmp(names[i], name) > 0) {
        names[i + 1] = names[i];
        numbers[i + 1] = numbers[i];
        i--;
    }
    names[i + 1] = strdup(name);    // add(argument1, argument2);로 부르고 argumnet들은 또 입력값으로 받으니까 계속 변경됨
    numbers[i + 1] = strdup(number);
    n++;
}

void find(char *name) {
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

void remove(char *name) {
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

void save(char *fileName) {
    int i;
    FILE *fp = fopen(fileName, "w");
    if (fp == NULL) {
        printf("Open failed.\n");
        return;
    }
    for (i = 0; i < n; i++) {
        fprintf(fp, "%s %s\n", names[i], numbers[i]);
    }
    fclose(fp);
}

int search(char *name) {
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(name, names[i]) == 0) {
            return i;
        }
    }
    return -1;
}