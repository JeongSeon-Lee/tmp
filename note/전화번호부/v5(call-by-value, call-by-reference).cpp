#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INIT_CAPACITY 100
#define BUFFER_LENGTH 100

typedef struct person {
    char* name;
    char* number;
    char* email;
    char* group;
} Person;

Person** directory;    // 고정되지 않게
int n = 0;
int capacity = INIT_CAPACITY;

// main, save, search, print_person, status, find, handle_add 수정하시오.
void init();
int read_line(FILE* fp, char str[], int n);
void load(char* fileName);
void add(char* name, char* number, char* email, char* group);
void reallocate();
int compose_name(char str[], int limit);
void handle_add(char* name);
void find(char* name);
int search(char* name);
void print_person(Person p);
void status();
void remove(char* name);
void release_person(Person* p);
void save(char* fileName);

int main() {
    char command_line[BUFFER_LENGTH];
    char* command, * argument;
    char name_str[BUFFER_LENGTH];

    while (1) {
        printf("$ ");
        if (read_line(stdin, command_line, BUFFER_LENGTH) <= 0)
            continue;

        command = strtok(command_line, " ");

        if (strcmp(command, "read") == 0) {
            argument = strtok(NULL, " ");
            if (argument == NULL) {
                printf("Invalid arguments.\n");
                continue;
            }
            load(argument);
        }
        else if (strcmp(command, "add") == 0) {
            if (compose_name(name_str, BUFFER_LENGTH) <= 0) {
                printf("Name required.\n");
                continue;
            }
            handle_add(name_str);
        }
        else if (strcmp(command, "find") == 0) {
            if (compose_name(name_str, BUFFER_LENGTH) <= 0) {
                printf("Name required.\n");
                continue;
            }
            find(name_str);
        }
        else if (strcmp(command, "status") == 0) {
            status();
        }
        else if (strcmp(command, "delete") == 0) {
            if (compose_name(name_str, BUFFER_LENGTH) <= 0) {
                printf("Invalid arguments.\n");
                continue;
            }
            remove(name_str);
        }
        else if (strcmp(command, "save") == 0) {
            argument = strtok(NULL, " ");
            if (strcmp(argument, "as") != 0) {
                printf("Invalid arguments.\n");
                continue;
            }
            argument = strtok(NULL, " ");
            if (argument == NULL) {
                printf("Invalid arguments.\n");
                continue;
            }
            save(argument);
        }
        else if (strcmp(command, "exit") == 0)
            break;
    }
    return 0;
}

void init() {
    directory = (Person**)malloc(INIT_CAPACITY * sizeof(Person*));
    capacity = INIT_CAPACITY;
    n = 0;
}

int read_line(FILE* fp, char str[], int n) {
    int ch, i = 0;
    while ((ch = fgetc(fp)) != '\n' && ch != EOF)   //
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}

void load(char* fileName) {
    char buffer[BUFFER_LENGTH];
    char* name, * number, * email, * group* token;

    FILE* fp = fopen(fileName, "r");
    if (fp = NULL) {
        printf("Open failed.\n");
        return;
    }

    while (1) {
        if (read_line(fp, buffer, BUFFER_LENGTH) <= 0)  //
            break;
        name = strtok(buffer, "#");
        token = strtok(NULL, "#");
        if (strcmp(token, " ") == 0)    // v4 편법 해결
            number = NULL;
        else
            number = strdup(token);
        token = strtok(NULL, "#");
        if (strcmp(token, " ") == 0)
            email = NULL;
        else
            email = strdup(token);
        token = strtok(NULL, "#");
        if (strcmp(token, " ") == 0)
            group = NULL;
        else
            group = strdup(token);
        add(strdup(name), number, email, group);    //
    }
    fclose(fp);
}

void add(char* name, char* number, char* email, char* group) {
    if (n >= capacity)
        reallocate();
    int i = n - 1;
    while (i >= 0 && strcmp(directory[i]->name, name) > 0) {
        directory[i + 1] = directory[i];    // 구조체 이런 식으로 저장 가능
        i--;
    }
    directory[i + 1] = (Person*)malloc(sizeof(Person));

    directory[i + 1]->name = name;
    directory[i + 1]->number = number;
    directory[i + 1]->email = email;
    directory[i + 1]->group = group;

    n++;
}

void reallocate() {
    capacity *= 2;
    Person** tmp = (Person**)malloc(INIT_CAPACITY * sizeof(Person*));
    for (int i = 0; i < n; i++) {
        tmp[i] = directory[i];
        free(directory);
        directory = tmp;
    }
}

int compose_name(char str[], int limit) {
    char* ptr;
    int length = 0;

    ptr = strtok(NULL, " ");    // add 뒤 이름 인자 토큰 나누기
    if (ptr == NULL)
        return 0;
    strcpy(str, ptr);
    length += strlen(ptr);

    while ((ptr = strtok(NULL, " ")) != NULL) {
        if (length + strlen(ptr) + 1 < limit) { // 공백이 있는 이름 합칠 때 오버플로우 방지
            str[length++] = ' '; // strcpy로 \0이 붙여져 있음
            str[length] = '\0'; // 그 뒤에 널문자 다시 붙여줌
            strcat(str, ptr);
            length += strlen(ptr);
        }
    }
    return length;
}

void handle_add(char* name) {
    char number[BUFFER_LENGTH], email[BUFFER_LENGTH], group[BUFFER_LENGTH];
    char empty[] = " ";

    printf("  Phone: ");
    read_line(stdin, number, BUFFER_LENGTH);
    printf("  Email: ");
    read_line(stdin, email, BUFFER_LENGTH);
    printf("  Group: ");
    read_line(stdin, group, BUFFER_LENGTH);

    add(name, (char*)(strlen(number) > 0 ? number : empty),
        (char*)(strlen(email) > 0 ? email : empty),
        (char*)(strlen(group) > 0 ? group : empty));
}

void find(char* name) {
    int index = search(name);
    if (index == -1)
        printf("No person named '%s' exists.\n", name);
    else
        print_person(directory[index]);
}

int search(char* name) {
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(name, directory[i].name) == 0)
            return i;
    }
    return -1;
}

void print_person(Person p) {
    printf("%s:\n", p.name);
    printf("   Phone: %s\n", p.number);
    printf("   Email: %s\n", p.email);
    printf("   Group: %s\n", p.group);
}

void status() {
    int i;
    for (i = 0; i < n; i++)
        print_person(directory[i]);
    printf("Total %d persons.\n", n);
}

void remove(char* name) {
    int i = search(name);
    if (i == -1) {
        printf("No person named '%s' exists.\n", name);
        return;
    }

    Person* p = directory[i];   //
    for (int j = i; j < n - 1; j++) {
        directory[j] = directory[j + 1];
    }
    n--;
    release_person(p);  // malloc으로 할당되었으니까, free(p)를 하지 않는 이유는 구조체 안 애들도 strdup로 할당받았기 때문
    printf("'%s' was deleted successfully.\n", name);
}

void release_person(Person* p) {
    free(p->name);
    if (p->number != NULL) free(p->number);     // NULL인 경우에는 굳이 할 필요 없으니까
    if (p->email != NULL) free(p->email);
    if (p->group != NULL) free(p->group);
    free(p);
}

void save(char* fileName) {
    int i;
    FILE* fp = fopen(fileName, "w");
    if (fp == NULL) {
        printf("Open failed.\n");
        return;
    }
    for (i = 0; i < n; i++) {
        fprintf(fp, "%s#", directory[i].name);
        fprintf(fp, "%s#", directory[i].number);
        fprintf(fp, "%s#", directory[i].email);
        fprintf(fp, "%s#", directory[i].group);
    }
    fclose(fp);
}