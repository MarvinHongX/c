// 삽입정렬(Insertion sort)

// 키보드로부터 정수를 연속으로 입력받는다. 정수가 하나씩 입력될 때마다 누적된 정수들을 오름차순으로 정렬하여 화면에 출력한다.
// 사용자가 -1을 입력하면 프로그램을 종료한다.

#include <stdio.h>
#define MAX 100

int main(){
    int data[MAX];
    int n = 0, val;

    while (1){
        scanf("%d", &val);
        if (val == -1)
            break;

        int i = n - 1;
        for ( ; i >= 0 && data[i] > val; i--)
            data[i+1] = data[i];

        data[i+1] = val;
        n++;

        for (int j = 0; j < n; j++)
            printf("%d ", data[j]);
        printf("\n");
    }


    return 0;
}