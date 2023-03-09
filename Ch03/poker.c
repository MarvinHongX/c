// poker 

// 5장의 카드를 읽고 어떤 패인지 출력하는 프로그램을 작성하라.
// rank는 1(Ace), 2, 3, ..., 10, 11(J), 12(Q), 13(K) 이다.
// suit는 c(club),d(diamond),h(heart),s(space) 이다.
// 패는 다음과 같다.

// straight flush (straight 이면서 flush)
// four cards (4장 모두 동일한 rank)
// full house (triple 이면서 pair)
// flush (5장 모두 동일한 suit)
// straight (5장 모두 연속된 rank)
// triple (3장 모두 연속된 rank)
// two pairs (pair가 두 개)
// pair (2장이 동일한 rank)
// high card(위의 어떠한 경우도 해당하지 않음)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CARD_NUM 5
#define CARD_DIGIT 3

int isStraightFlush(int ranks[], char suits[]);
int isFourCards(int ranks[]);
int isFullHouse(int ranks[]);
int isFlush(char suits[]);
int isStraight(int ranks[]);
int isTriple(int ranks[]);
int isTwoPairs(int ranks[]);
int isPair(int ranks[]);
void bubbleSort(int arr[], int n);

int main() {
    int ranks[CARD_NUM];
    char suits[CARD_NUM];
    int sortedRanks[CARD_NUM];

    FILE *filePtr = fopen("poker.txt", "r");
    if (filePtr == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    for (int i = 0; i < CARD_NUM; i++) {
        char card[CARD_DIGIT+1];
        fscanf(filePtr, " %s", card);

        // 문자열을 숫자와 문자로 분리해서 저장
        ranks[i] = strtol(card, NULL, 10);
        char *token = strtok(card, "0123456789");
        if (token != NULL) {
            suits[i] = token[0];
        }
    }

    fclose(filePtr);

    for (int i = 0; i < CARD_NUM; i++)
        printf("%d%c ", ranks[i], suits[i]);

    printf("\n");

    
    memcpy(sortedRanks, ranks, CARD_NUM * sizeof(int));
    bubbleSort(sortedRanks, CARD_NUM);


    if (isStraightFlush(sortedRanks, suits) == 1) {
        printf("Straight Flush\n");
    } else if(isFourCards(sortedRanks) == 1) {
        printf("Four Cards\n");
    } else if(isFullHouse(sortedRanks) == 1) {
        printf("Full House\n");
    } else if(isFlush(suits) == 1) {
        printf("Flush\n");
    } else if(isStraight(sortedRanks) == 1) {
        printf("Straight\n");
    } else if(isTriple(sortedRanks) == 1) {
        printf("Triple\n");
    } else if(isTwoPairs(sortedRanks) == 1) {
        printf("Two Pair\n");
    } else if(isPair(sortedRanks) == 1) {
        printf("Pair\n");
    } else {
        printf("High card\n");
    }

    return 0;
}

int isStraightFlush(int sortedRanks[], char suits[]){
    return (isStraight(sortedRanks) && isFlush(suits));
}

int isStraight(int sortedRanks[]){
    for (int i = 0; i < CARD_NUM - 1; i++){
        if ((sortedRanks[i+1] - sortedRanks[i]) != 1) return 0;
    }
    return 1;
}

int isFlush(char suits[]){
    for (int i = 1; i < CARD_NUM; i++){
        if (suits[i] != suits[0]) return 0;
    }
    return 1;
}

int isFourCards(int sortedRanks[]){
    return ((sortedRanks[0] == sortedRanks[1] && sortedRanks[1] == sortedRanks[2] && sortedRanks[2] == sortedRanks[3]) ||
            (sortedRanks[1] == sortedRanks[2] && sortedRanks[2] == sortedRanks[3] && sortedRanks[3] == sortedRanks[4])); 
}

int isFullHouse(int sortedRanks[]){
    return ((sortedRanks[0] == sortedRanks[1] && sortedRanks[1] == sortedRanks[2] && sortedRanks[3] == sortedRanks[4]) ||
            (sortedRanks[0] == sortedRanks[1] && sortedRanks[2] == sortedRanks[3] && sortedRanks[3] == sortedRanks[4])); 
}

int isTriple(int sortedRanks[]){
    return ((sortedRanks[0] == sortedRanks[1] && sortedRanks[1] == sortedRanks[2]) ||
            (sortedRanks[1] == sortedRanks[2] && sortedRanks[2] == sortedRanks[3]) ||
            (sortedRanks[2] == sortedRanks[3] && sortedRanks[3] == sortedRanks[4]));
}

int isTwoPairs(int sortedRanks[]){
    int pair_count = 0;
    for (int i = 0; i < CARD_NUM - 1; i++) {
        if (sortedRanks[i] == sortedRanks[i+1]) {
            pair_count++;
            i++;
        }
    }
    return pair_count == 2;
}

int isPair(int sortedRanks[]){
    for (int i = 0; i < CARD_NUM - 1; i++) {
        if (sortedRanks[i] == sortedRanks[i+1]) {
            return 1;
        }
    }
    return 0;
}

void bubbleSort(int arr[], int n){
    for (int endPos = n - 1; endPos > 0; endPos--){
        for (int startPos = 0; startPos < endPos; startPos++){
            if (arr[startPos] > arr[startPos+1]){
                int tmp = arr[startPos];
                arr[startPos] = arr[startPos+1];
                arr[startPos+1] = tmp;
            }
        }
    }
}   