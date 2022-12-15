/* 4. sample.html ������ �о ���Ͽ� �����ϴ� ��� HTML �±�(tag)���� ������ �� sample.txt��
�� �̸��� ���Ϸ� �����ϴ� ���α׷��� �ۼ��϶�. HTML �±׶� ��<���� ��>�� ���ڷ� �ѷ����� �κ���
�ǹ��Ѵ�. ��, HTML ���Ͽ��� �±׸� �����ϴ� �� ���� �ٸ� �κ��� �״�� �����Ǿ�� �Ѵ�. ��, ��
�� ���� sample.txt�� correct_answer.txt ���ϰ� �Ϻ��ϰ� �����ؾ� �Ѵ�. */

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