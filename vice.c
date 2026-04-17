#include <stdio.h>
#include "defs.h"

int main() {
    AllInit(); 

    /* int index = 0;

    for (index = 0; index < BOARD_SQ_NUMBER; ++index) {
        if (index % 10 == 0) {
            printf("\n");
        }

        printf("%5d", Sq120ToSq64[index]);
    }

    printf("\n\n");

    for (index = 0; index < 64; ++index) {
        if (index % 8 == 0) {
            printf("\n");
        }

        printf("%5d", Sq64ToSq120[index]);
    } */

    /* int num = 2;
    int nums = 4;

    ASSERT(num == nums); */

    /* U64 playBitBoard = 0ULL;

    printf("Start: \n\n");
    PrintBitBoard(playBitBoard);

    playBitBoard |= (1ULL << SQ64(D2));
    printf("D2 Added: \n\n");
    PrintBitBoard(playBitBoard);

    playBitBoard |= (1ULL << SQ64(G2));
    printf("G2 Added: \n\n");
    PrintBitBoard(playBitBoard); */

    U64 playBitBoard = 0ULL;

    playBitBoard |= (1ULL << SQ64(D2));
    playBitBoard |= (1ULL << SQ64(D3));
    playBitBoard |= (1ULL << SQ64(D4));

    PrintBitBoard(playBitBoard);

    int count = CNT(playBitBoard);

    printf("Count: %d\n", count);

    int index = POP(&playBitBoard);

    printf("Index: %d\n", index);
    PrintBitBoard(playBitBoard);
    count = CNT(playBitBoard);
    printf("Count: %d\n", count);

    return 0;
}