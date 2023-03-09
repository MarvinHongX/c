// 소수(prime number) 

// 1~100000 사이의 모든 소수들을 찾아서 출력하라.

#include<stdio.h>
#define MAX 100000

int main(){
    for (int i = 2; i <= MAX; i++){
        int j = 2;
        while (j*j <= i && i%j!=0){
            j++;
        }
        if (j*j>i)
            printf("%d\n", i); 
    }

    return 0;
}