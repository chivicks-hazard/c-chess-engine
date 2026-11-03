#include <stdio.h>
#include "defs.h"

char *PrintSq(const int sq) {
    static char SqString[3];

    int file = FilesBoard[sq];
    int rank = RanksBoard[sq];

    sprintf(SqString, "%c%c", ('a' + file), ('1' + rank));

    return SqString;
}

char *PrintMove(const int move) {
    static char MoveString[6];

    int ff = FilesBoard[FROMSQ(move)];
    int rf = RanksBoard[FROMSQ(move)];
    int ft = FilesBoard[TOSQ(move)];
    int rt = RanksBoard[TOSQ(move)];

    int promoted = PROMOTED(move);

    if (promoted) {
        char promotedChar = 'q';

        if (IsKnight(promoted)) {
            promotedChar = 'n';
        } else if (IsRookQueen(promoted) && !IsBishopQueen(promoted)) {
            promotedChar = 'r';
        } else if (!IsRookQueen(promoted) && IsBishopQueen(promoted)){
            promotedChar = 'b';
        }

        sprintf(MoveString, "%c%c%c%c%c", ('a' + ff), ('1' + rf), ('a' + ft), ('1' + rt), promotedChar);
    } else {
        sprintf(MoveString, "%c%c%c%c", ('a' + ff), ('1' + rf), ('a' + ft), ('1' + rt));
    }

    return MoveString;
}