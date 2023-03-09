// prime

// n개의 음이 아닌 한 자리 정수들을 입력받아 배열에 순서대로 저장한다. 임의의 6자리 이내의 연속된 숫자를 하나의 정수로 환산했을 때
// 소수가 되는 모든 경우를 찾아서 소수 값을 출력하는 프로그램을 작성하라.

#include <stdio.h>
#define MAX 100
#define NUM_DIGIT 6

int arrayToInteger(int arr[], int from, int to);
int isPrime(int num);

int main(){
    int n = 0;
    int num;
    int digits[MAX];

    FILE *filePtr = fopen("prob06.txt", "r");
    if (filePtr == NULL) {
        printf("Error: cannot open file.");
        return 1;
    }
    while(fscanf(filePtr, "%d", &num) == 1){
        digits[n] = num;
        n++;
    }
    fclose(filePtr);

    for (int from = 0; from < n; from++){
        int convertedInt = 0;
        for (int distance = 0; (distance < NUM_DIGIT) && ((from + distance) < n); distance++){
            convertedInt = (convertedInt * 10) + digits[from + distance];
            if (isPrime(convertedInt) == 1){
                printf("%d: %d distance from index %d\n", convertedInt, distance, from);
            }
        }
    }
    return 0;
}

int isPrime(int num){
    if (num <= 1) return 0;  // 1 is not a prime
    for (int divisor = 2; divisor*divisor <= num; divisor++)
        if (num % divisor == 0) return  0; // is not prime
    return 1;
}