// 소수(prime number) 
// ** 암호학 등 중요한 문제이고 효율적인 방법들이 많이 존재함.

// 1~100000 사이의 모든 소수들을 찾아서 출력하라.

#include<stdio.h>
#define MAX 100000

int main(){
    for (int i = 2; i <= MAX; i++){
        int isPrime = 1; //무죄추정의 원칙
        for (int j = 2; isPrime == 1 && j*j <= i; j++) { //항상 쌍이 존재하고 그 쌍 중에 작은 수는 루트 i 보다 작다.
            if (i % j == 0)
                isPrime = 0;
        }
        if (isPrime == 1)
            printf("%d\n", i); 
    }
    return 0;
}