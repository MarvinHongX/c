// Bubble sort

// prob05.txt 파일에서 정수들을 입력받아 순서대로 배열에 저장한다. 그 후 오름차순으로 정렬하여 출력하라.

#include <stdio.h>
#define MAX 100

int main() {
    int data[MAX];
    int n = 0;

    FILE *filePtr = fopen("prob03.txt", "r");
    while(fscanf(filePtr, "%d", data+n) != EOF) {
        n++;
    }
    fclose(filePtr);

    for (int i = n - 1; i > 0; i--){
        for (int j = 0; j < i; j++){
            if (data[j] > data[j+1]){
                int tmp = data[j];
                data[j] = data[j+1];
                data[j+1] = tmp;
            }
        }
    }

    for (int k = 0; k < n; k++)
        printf("%d ",data[k]);
    printf("\n");
    return 0;
}