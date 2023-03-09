// 임의의 정수들을 읽고 정렬하는 프로그램을 작성하라. bubble sort 알고리즘을 하나의 함수로 구현하라.

#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *arr, int len);

int main(){
    int *data = NULL;
    int num;
    int n = 0; // length of "data" array

    FILE *filePtr = fopen("prob04.txt","r");
    if (filePtr == NULL) {
        printf("File open error\n");
        return 1;
    }

    while(fscanf(filePtr, "%d", &num) == 1){
        data = realloc(data, sizeof(int) * (n + 1)); 
        data[n] = num;
        n++;
    }
    fclose(filePtr);

    bubble_sort(data, n);

    printf("length of array is %d\n", n);
    for (int i = 0; i < n; i++)
        printf("%d ", data[i]);

    free(data); //free memory allocated by realloc

    return 0;
}

void bubble_sort(int *arr, int len){
    for (int i = 0; i < len - 1; i++){
        for (int j = 0; j < len - i - 1; j++){
            if (arr[j] > arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}