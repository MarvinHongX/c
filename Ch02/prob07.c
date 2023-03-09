// 최대 부분합 구하기

// 입력으로 n개의 정수가 주어진다. 1개 이상의 연속된 정수들을 더하여 구할 수 있는 최대값을 찾아라.

#include <stdio.h>
#define MAX 100

int main(){
    int data[MAX];
    int n = 0;
    
    FILE *filePtr = fopen("prob03.txt", "r");
    while(fscanf(filePtr, "%d", data+n) != EOF) {
        n++;
    }
    fclose(filePtr);    

    int max_sum = data[0];

    for (int begin = 0; begin < n; begin++){
        int sum = 0;
        for (int end = begin; end < n; end++){
            sum += data[end];
            if (max_sum < sum)
                max_sum = sum;       
        }
    }
    
    printf("The max sum is %d\n", max_sum);

    return 0;
}