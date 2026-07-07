#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

/* 
  * Each of the code blocks are for demonstration purposes.
  * Uncomment the code block you want to run and comment out the rest.
*/


#define FEN_1 "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1"
#define FEN_2 "rnbqkbnr/pp1ppppp/8/2p5/4P3/8/PPPP1PPP/RNBQKBNR w KQkq c6 0 2"
#define FEN_3 "rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2"

int main() {
    AllInit(); 

    // For board square mapping demonstration
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

    // For assert demonstration
    /* int num = 2;
    int nums = 4;

    ASSERT(num == nums); */

    // For bitboard demonstration
    /* U64 playBitBoard = 0ULL;

    printf("Start: \n\n");
    PrintBitBoard(playBitBoard);

    playBitBoard |= (1ULL << SQ64(D2));
    printf("D2 Added: \n\n");
    PrintBitBoard(playBitBoard);

    playBitBoard |= (1ULL << SQ64(G2));
    printf("G2 Added: \n\n");
    PrintBitBoard(playBitBoard); */

    // For pop demonstration
    /* U64 playBitBoard = 0ULL;

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
    printf("Count: %d\n", count); */

    /* int index = 0;
    U64 playBitBoard = 0ULL;

    for (index = 0;  index < 64; index++) {
        printf("Index: %d\n", index);
        PrintBitBoard(ClearMask[index]);
        printf("\n");
    } */

    /* SETBIT(playBitBoard, 61);
    PrintBitBoard(playBitBoard); */
    
    /* CLRBIT(playBitBoard, 61);
    PrintBitBoard(playBitBoard); */
    
    // For key demonstration
    /* int PieceOne = rand();
    int PieceTwo = rand();
    int PieceThree = rand();
    int PieceFour = rand();

    printf("Piece One: %X\n", PieceOne);
    printf("Piece Two: %X\n", PieceTwo);
    printf("Piece Three: %X\n", PieceThree);
    printf("Piece Four: %X\n", PieceFour);

    int key = PieceOne ^ PieceTwo ^ PieceThree ^ PieceFour;
    int tempKey = PieceOne;
    tempKey ^= PieceTwo;
    tempKey ^= PieceThree;
    tempKey ^= PieceFour;

    printf("Key: %X\n", key);
    printf("Temp Key: %X\n", tempKey); */

    // For FEN demonstration
    /* S_BOARD board[1];

    ParseFen(START_FEN, board);
    PrintBoard(board);

    ParseFen(FEN_1, board);
    PrintBoard(board);

    ParseFen(FEN_2, board);
    PrintBoard(board);

    ParseFen(FEN_3, board);
    PrintBoard(board);

    return 0; */
}