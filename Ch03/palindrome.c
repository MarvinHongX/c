// palindrome

// palindrome은 level 처럼 거꾸로 읽어도 같은 단어를 의미한다. 입력으로 하나의 단어를 받아서 palindrome인지 검사하는 프로그램을 작성하라.

#include <stdio.h>
#include <string.h>
#define MAX 50
int isPalindrome(char word[]);

int main(){
    char word[MAX];
    scanf("%s", word);
    
    if (isPalindrome(word))
        printf("Palindrome.\n");

    return 0;
}

int isPalindrome(char str[]){
    int len = strlen(str);
    for (int i = 0; i < len/2; i++){
        if (str[i] != str[len-1-i]){
            return 0;
        }
    }
    return 1;
}
