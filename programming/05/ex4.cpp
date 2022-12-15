#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp = fopen("sample.html", "r");
    FILE *of = fopen("sample.txt", "w");
    int c;
    bool inside_tag = false;
    while ((c=fgetc(fp)) != EOF) {
        if (c=='<')
            inside_tag = true;
        else if (c=='>')
            inside_tag = false;
        else if (!inside_tag)
            fputc(c, of);
    }
    fclose(fp);
    fclose(of);

    return 0;
}