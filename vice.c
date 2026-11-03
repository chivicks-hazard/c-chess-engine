#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

/* 
  * Each of the code blocks are for demonstration purposes.
  * Uncomment the code block you want to run and comment out the rest.
*/


// #define FEN_1 "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1"
// #define FEN_1 "8/3q4/8/8/4Q3/8/8/8 w - - 0 1"
#define FEN_1 "8/3q1p2/8/5P2/4Q3/8/8/8 w - - 0 1"
#define FEN_2 "rnbqkbnr/pp1ppppp/8/2p5/4P3/8/PPPP1PPP/RNBQKBNR w KQkq c6 0 2"
#define FEN_3 "rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2"
#define FEN_4 "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1"

// For attack square demonstration
void ShowSQAttackedBySide(const int side, const S_BOARD *pos) {
    int rank = 0;
    int file = 0;
    int sq = 0;

    printf("\n\nSquares attacked by: %c\n", SideChar[side]);
    
    for (rank = RANK_8; rank >= RANK_1; --rank) {
        for (file = FILE_A; file <= FILE_H; file++) {
            sq = FR2SQ(file, rank);

            if (SqAttacked(sq, side, pos) == TRUE) {
                printf("X");
            } else {
                printf("-");
            }
        }

        printf("\n");
    }

    printf("\n\n");
}

void PrintBin(int move) {
    int index = 0;
    printf("As binary: \n");

    for (index = 27; index >= 0; index--) {
        if ((1 << index) & move) {
            printf("1");
        } else {
            printf("0");
        }

        if (index != 28 && index % 4 == 0) {
            printf(" ");
        }
    }

    printf("\n");
}

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

    int count = COUNT(playBitBoard);

    printf("Count: %d\n", count);

    int index = POP(&playBitBoard);

    printf("Index: %d\n", index);
    PrintBitBoard(playBitBoard);
    count = COUNT(playBitBoard);
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
    PrintBoard(board); */
    

    // S_BOARD board[1];

    // ParseFen(FEN_4, board);

    // PrintBoard(board);

    /* printf("\nWhite Pawns: \n");
    PrintBitBoard(board->pawns[WHITE]);
    printf("\nBlack Pawns: \n");
    PrintBitBoard(board->pawns[BLACK]);
    printf("\nBoth Pawns: \n");
    PrintBitBoard(board->pawns[BOTH]); */

    // ASSERT(CheckBoard(board)); 
    // board->pieceNum[wP]--;
    // ASSERT(CheckBoard(board));

    // For attack square demonstration
    /* S_BOARD board[1];

    ParseFen(FEN_1, board);

    PrintBoard(board);

    printf("\nSquares attacked by White:\n");
    ShowSQAttackedBySide(WHITE, board);

    printf("\nSquares attacked by Black:\n");
    ShowSQAttackedBySide(BLACK, board); */

    // Storing moves in binary
    /* int move = 0;
    int from = 6;
    int to = 12;
    int captured = wR;
    int promoted = bR;

    move = (from) | (to << 7) | (captured << 14) | (promoted << 20);

    printf("\nDecimal: %d, Hexadecimal: %X\n", move, move);
    PrintBin(move);

    printf("\n");
    
    printf(
        "From: %d, To: %d, Captured: %d, Promoted: %d",
        FROMSQ(move), TOSQ(move), CAPTURED(move), PROMOTED(move)
    ); */

    int move = 0;
    int from = A2;
    int to = H7;
    int captured = wR;
    int promoted = bN;

    move = ((from) | (to << 7) | (captured << 14) | (promoted << 20));

    printf("\nDecimal: %d, Hexadecimal: %X\n", move, move);
    PrintBin(move);

    printf("\n");
    
    printf(
        "From: %d, To: %d, Captured: %d, Promoted: %d\n\n",
        FROMSQ(move), TOSQ(move), CAPTURED(move), PROMOTED(move)
    );

    printf("Algebraic from: %s\n", PrintSq(from));
    printf("Algebraic to: %s\n", PrintSq(to));
    printf("Algebraic move: %s\n", PrintMove(move));

    return 0;
}