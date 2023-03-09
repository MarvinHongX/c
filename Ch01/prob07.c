// 2진수로 변환하기

#include<stdio.h>
int main(){
    int N = 0;
    int p = 1;
    
    scanf("%d", &N);

    // N보다 작은 2의 거듭제곱 중 가장 큰 수
    while (p*2 <= N)
        p *= 2;

    
    while (N > 0) {
        if (p <= N){
            printf("1");
            N = N - p;
        } else {
            printf("0");
        }
        p = p / 2;
    }
    printf("\n");
    return 0;
}