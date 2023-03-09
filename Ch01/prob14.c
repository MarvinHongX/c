// Gambler's Ruin Simulation

// 동전을 던져서 앞면이 나오면 $1을 따고 뒷면이 나오면 $1을 잃는다.
// 초기자본(stake)와 목표액(goal)이 주어진다.
// 목표액에 도달하면 이기고, 돈을 모두 잃으면 진다.
// 게임에 이길 확률을 계산하기 위해서 시뮬레이션을 수행한다. 즉, 게임을 T번 반복하여 승률을 출력한다.
// T와 초기자본, 목표액은 입력으로 주어진다.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int init_stake, stake, goal, T;
    int win = 0;
    printf("stake: ");
    scanf("%d", &init_stake);

    printf("goal: ");
    scanf("%d", &goal);

    printf("T: ");
    scanf("%d", &T);

    srand((unsigned int) time(NULL));
    for (int i = 0; i < T; i++){
        int stake = init_stake;
        while(stake < goal && stake > 0){
            int coin = rand() % 2; // 0 or 1
            if (coin == 0) 
                stake++;
            else
                stake--;
        }
        if (stake > 0)
            win++;
    }

    printf("The win is %f\n", (double) win * 100 / T);
    return 0;
}