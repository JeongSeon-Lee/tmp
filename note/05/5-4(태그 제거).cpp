/* 4. sample.html 파일을 읽어서 파일에 등장하는 모든 HTML 태그(tag)들을 제거한 후 sample.txt라
는 이름의 파일로 저장하는 프로그램을 작성하라. HTML 태그란 ‘<‘와 ‘>’ 문자로 둘러싸진 부분을
의미한다. 단, HTML 파일에서 태그를 제거하는 것 말고 다른 부분은 그대로 유지되어야 한다. 즉, 출
력 파일 sample.txt는 correct_answer.txt 파일과 완벽하게 동일해야 한다. */

#include <stdio.h>
#include <string.h>

int main()
{
    FILE* fp = 0;
    fopen_s(&fp, "sample.html", "r");
    FILE* of = 0;
    fopen_s(&of, "sample.txt", "w");
    int c;
    bool inside_tag = false;
    while ((c = fgetc(fp)) != EOF) {
        if (c == '<')
            inside_tag = true;
        else if (c == '>')
            inside_tag = false;
        else if (!inside_tag)
            fputc(c, of);
    }
    fclose(fp);
    fclose(of);

    return 0;
}

//while (fscanf_s(fp, "%c", &tag) != EOF) {
//    if (tag == '<') {
//        while (tag != '>')
//            fscanf_s(fp, "%c", &tag);
//    }
//    else {
//        fprintf(op, "%c", tag);
//    }
//}