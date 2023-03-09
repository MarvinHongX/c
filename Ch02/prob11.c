// Minesweeper

// 입력으로 아래 왼쪽과 같은 모양의 N*N 크기의 minesweeper 게임의 모양을 받는다.
// 폭탄은 *로 표시되고 폭탄이 아닌 자리는 .로 표시된다. 오른쪽 그림과 같이 인접한 폭탄의 개수를 세어서 출력하는 프로그램을 작성하라.
// * * . .       * * 1 0
// . . . .       3 3 2 0
// . * . .       2 * 3 2
// * . * *       * 3 * *

#include <stdio.h>
#define MAX 100

int main(){
    int n;
    char mat[MAX][MAX];

    FILE *filePtr = fopen("prob11.txt", "r");
    fscanf(filePtr, "%d ", &n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            fscanf(filePtr, "%c ", &mat[i][j]); // white space 를 모두 건너뛴다.
        }
    }
    fclose(filePtr);

    int offset[][2] = {{-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}};
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (mat[i][j] == '*'){
                printf("* ");
            } else {
                int count = 0;
                for (int dir = 0; dir < 8; dir++){
                    int row = i + offset[dir][0];
                    int column = j + offset[dir][1];
                    if (row >= 0 && row < n && column >= 0 && column < n && mat[row][column] == '*')
                        count++;
                }
                printf("%d ", count);
            }
        }
        printf("\n");
    }
    return 0;
}