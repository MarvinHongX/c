// Sum of Two Cubes

// 10,000,000이하의 양의 정수들 중에서 적어도 두 가지 서로 다른 "세제곱의 합"으로
// 표현될 수 있는 모든 정수를 찾아서 출력하는 프로그램을 작성하라. 즉
// K=a^3+b^3=c^3+d^3이 되는 서로 다른 두 정수쌍 (a,b)와 (c,d)가 존재하는 모든 정수 K를 찾아서 출력한다.
// 여기서 a,b,c,d는 모두 양의 정수이다. (중복 출력되어도 상관없다.)

// 1) a < b, c < d
// 2) a < c
// 3) a < b < c < d 라면 a^3+b^3=c^3+d^3 가 될 수 없으므로 d < b여야 함.
// 1,2,3 을 종합하면 a < c < d < b 이다.
#include<stdio.h>
#define MAX 10000000

int main(){
    for (int a = 1; a*a*a <= MAX; a++){
        for (int c = a + 1; c*c*c <= MAX; c++){
            for (int d = c + 1; d*d*d <= MAX; d++){
                for (int b = d + 1; b*b*b <= MAX; b++){
                    if (a*a*a + b*b*b == c*c*c + d*d*d)
                        printf("%d: %d %d %d %d\n", a*a*a + b*b*b, a, b, c, d);
                }
            }
        }
    }
    return 0;
}