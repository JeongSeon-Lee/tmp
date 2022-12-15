#include <stdio.h>
#include <string.h>

int main(void)
{
	char ary1[21], ary2[21];
	char input;
	int i, j, count = 0, dif= 0;

	scanf_s("%c", &input, 21);
	ary1[0] = input;

    while (1) {
        scanf_s("%c", &input, 21);
        if (input == '\n')
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

    scanf_s("%s", ary2, 21);

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

    return 0;
}