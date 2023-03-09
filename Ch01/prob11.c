// Divisors

// 1~N 사이의 정수들 중에서 서로 약수-배수 관계인 정수 쌍의 개수를 계산해 출력하라. 
// (a,b)와 (b,a)는 같은 쌍으로 간주하고 (a,a)는 세지 않는다.

#include<stdio.h>

int main() {
    int N;
    int count = 0;
    scanf("%d", &N);
    for (int a = 1; a <= N; a++){
        for (int b = 1; b <= a/2; b++){ // y=x 축 아래 (1사분면)
            if(a % b == 0)
                count++;
        }
    }

    printf("The count is %d\n", count);
    return 0;
}
