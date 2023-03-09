// 행렬곱셈

// prob10.txt 파일로부터 두 행렬을 받은 후 두 행렬의 곱을 계산하여 출력하는 프로그램을 작성하라.

#include <stdio.h>
#define MAX 100
int main(){
    int p, q, q2, r;
    int A[MAX][MAX] = {0}, B[MAX][MAX] = {0}, C[MAX][MAX] = {0};

    FILE *filePtr = fopen("prob10.txt","r");
    fscanf(filePtr,"%d", &p);
    fscanf(filePtr,"%d", &q);
    for (int row = 0; row < p; row++){
        for (int column = 0; column < q; column++)
            fscanf(filePtr, "%d", &A[row][column]);
    }

    fscanf(filePtr,"%d", &q2);
    fscanf(filePtr,"%d", &r);

    for (int row = 0; row < q2; row++){
        for (int column = 0; column < r; column++)
            fscanf(filePtr, "%d", &B[row][column]);
    }

    fclose(filePtr);

    if (q != q2){
        printf("Matrix size is wrong\n");
        return 0;
    }

    for (int row = 0; row < p; row++){
        for (int column = 0; column < r; column++){
            int sum = 0;
            for (int common = 0; common < p; common++){
                sum+= A[row][common] * B[common][column];
            }
            C[row][column] = sum;
            printf("%d ", sum);
        }        
        printf("\n");
    }

    return 0;
}