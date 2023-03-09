//최대공약수(GCD)

//Euclid 알고리즘: 두 정수 x, y중에 크거나 같은 쪽을 x라 하자. 만약 x가 y로 나누어 떨어지면 GCD는 y이다. 
//               그렇지 않다면 x와 y의 GCD는 x%y와 y의 GCD와 같다.

#include<stdio.h>

int main(){
    int x, y;
    scanf("%d %d", &x, &y);

    // x, y 순서 정렬
    if (y > x) {
        int tmp = x;
        x = y;
        y = tmp;
    }
    printf("x = %d, y = %d\n", x, y);

    int GCD;
    while (1){
        int remainder = x % y;
        if (remainder == 0){
            GCD = y;
            break;
        }
        x = y;
        y = remainder;
    }
    printf("GCD is %d\n", GCD);
    return 0;
}