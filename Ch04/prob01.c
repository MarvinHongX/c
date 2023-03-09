// 프로그램을 실행하면 화면에 프롬프트($)와 한 칸의 공백문자를 출력하고 사용자의 입력을 기다린다.
// 사용자가 문장을 입력하고 Enter키를 치면, 입력한 문장과 그 길이를 출력하라.
// 단 문장의 앞 뒤에 붙은 공백까지 그대로 출력해야 하며, 길이를 셀 때는 공백문자를 포함한다.

#include <stdio.h>
#include <string.h>

#define MAX 10

int readLine(char *str, int n);

int main(){
    char buffer[MAX];
    while (1){
        printf("$ ");
        int len = readLine(buffer, MAX);
        printf("%s: %d\n", buffer, len);
    }

    return 0;
}

int readLine(char *str, int limit){
    int ch, i = 0;
    while((ch = getchar()) != '\n')
        if (i < limit - 1)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}