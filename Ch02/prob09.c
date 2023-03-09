// Coupon collector

// 0~5 사이의 정수들을 키보드로부터 연속해서 입력받는다. 중복된 값들이 입력될 수 있다. 0~5까지의 모든 정수들이 각각 적어도 한 번 이상 입력되면 그때까지 입력된 정수의 개수를 출력하고 종료한다. 
// 예를 들어서 다음과같이 입력되면 12를 출력하고 종료한다.
// 5 5 2 2 1 0 0 2 5 2 3 4

#include <stdio.h>
#define INT_COUNT 6

int main(){
    int visited = 0; //bit가 1이면 입력된 적이 있음
    int val;
    int count = 0;
    while(visited < ((1<<INT_COUNT) - 1)){ //bit가 모두 1일 때까지
        scanf("%d", &val);
        if (val >= 0 && val < INT_COUNT){
            visited = (visited | (1<<val));
        }
        count++;
    }

    printf("The count is %d\n", count);
    return 0;
}