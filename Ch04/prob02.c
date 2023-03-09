// compress while reading

// 프로그램을 실행하면 화면에 프롬프트($)와 한 칸의 공백문자를 출력하고 사용자의 입력을 기다린다.
// 사용자가 문장을 입력하고 Enter키를 치면, 입력한 문장과 그 길이를 출력하라.
// 단 문장의 앞 뒤에 붙은 공백은 제거하고, 단어 사이의 연속된 공백문자들은 하나의 공백 문자로 대체한다. 
// 길이를 셀 때는 공백문자를 포함한다.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

int readLineWithCompression(char *str, int n);

int main(){
    char buffer[MAX];
    while (1){
        printf("$ ");
        int len = readLineWithCompression(buffer, MAX);
        printf("%s: %d\n", buffer, len);
    }

    return 0;
}

int readLineWithCompression(char *str, int limit){
    int ch, i = 0;
    while((ch = getchar()) != '\n'){
        if (i < limit-1 && (!isspace(ch) || i > 0 && !isspace(str[i-1])))
            str[i++] = ch;
    }
    if (i > 0 && isspace(str[i-1])) //마지막 문자가 공백이면
        i--;
    str[i] = '\0';
    return i;
}