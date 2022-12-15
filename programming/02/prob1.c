/* 통과완료 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char ary1[21], ary2[21];
	char input;
	int i, j, count = 0;

	scanf("%c", &input);    // scanf_s("%c", &input, 21);
	ary1[0] = input;

    while (1) {
        scanf("%c", &input);
        if (isspace(input))
            break;
        count++;
        for (i = 0; i < count; i++) {
            if (ary1[i] == input) {
                count--;
                break;
            }
            if (i == count - 1)
                ary1[count] = input;
        }
    }

    count++;

    scanf("%s", ary2);

    for (i = 0; i < strlen(ary2); i++) {
        for (j = 0; j < count; j++) {
            if (ary2[i] == ary1[j]) {
                break;
            }
        }
        if (j == count) {
            printf("no");
            break;
        }
    }

    if (i == strlen(ary2))
        printf("yes");

    for (i = 0; i < count; i++) {
        printf("%c", ary1[i]);
    }

    return 0;
}