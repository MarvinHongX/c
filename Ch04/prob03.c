// strdup(문자열 복사함수)

// 여러개의 단어들을 입력받아 포인터를 이용하여 저장하라

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
#define MAXLEN 100

char * strdupMimic(char *s);

int main(){
    char * words[MAX];
    int n = 0;
    char buffer[MAXLEN];
    while (n < 4 && scanf("%s", buffer) != EOF){
        words[n] = strdupMimic(buffer);  // strcpy(toStr, fromStr)
        n++;
    }
    
    for (int i = 0; i < 4; i++)
        printf("%s\n", words[i]);

    return 0;
}


char * strdupMimic(char *s){
    char *p;
    p = (char *)malloc(strlen(s)+1);
    if (p != NULL)
        strcpy(p, s);
    return p;
}
