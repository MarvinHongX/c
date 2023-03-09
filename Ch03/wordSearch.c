// Word Search Puzzle

// n x n의 2차원 문자 배열을 파일로부터 읽는다. 입력으로 하나의 단어(문자열)를 받고 배열의 행, 열 또는 대각선에서 그 단어를 찾는 프로그램을 작성하라.

#include <stdio.h>
#include <string.h>
#define MAX 100

char getChar(int row, int column, int direction, int distance);

char board[MAX][MAX];
char word[MAX];
int wordLen = 0;
int n = 0;

int main() {

    FILE *filePtr = fopen("wordSearch.txt", "r");
    if (filePtr == NULL){
        printf("Failed to open file.\n");
        return 1;
    }
    while(fscanf(filePtr, "%s", board[n]) != EOF)
        n++;
    fclose(filePtr);

    printf("Enter the word: ");
    scanf("%s", word);
    wordLen = (int) strlen(word);

    for (int row = 0; row < n; row++){
        for (int column = 0; column < n; column++){
            if (board[row][column] != word[0]){
                continue;
            }
            for (int direction = 0; direction < 8; direction++) {
                int distance = 1;
                for (; distance < wordLen; distance++){
                    char buffer = getChar(row, column, direction, distance);
                    if (buffer == '\0' || buffer != word[distance]){
                        break;
                    }
                }
                if (distance >= wordLen){
                    printf("Found!\nStart point: [%d, %d]\ndirection: %d\n\n", row, column, direction);
                }

            }
        }
    }

    return 0;
}

char getChar(int row, int column, int direction, int distance){
    char ch;
    switch(direction){
        case 0:
            ch = board[row - distance][column];
            break;
        case 1:
            ch = board[row - distance][column + distance];
            break;
        case 2:
            ch = board[row][column + distance];
            break;
        case 3:
            ch = board[row + distance][column + distance];
            break;
        case 4:
            ch = board[row + distance][column];
            break;
        case 5:
            ch = board[row + distance][column - distance];
            break;
        case 6:
            ch = board[row][column - distance];
            break;
        case 7:
            ch = board[row - distance][column - distance];
            break;
    }
    return ch;
}