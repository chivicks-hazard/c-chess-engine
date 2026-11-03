#include "defs.h"

const int KnightDirection[8] = {-8, -19, -21, -12, 8, 19, 21, 12};
const int RookDirection[4] = {-1, -10, 1, 10};
const int BishopDirection[4] = {-11, -9, 11, 9};
const int KingDirection[8] = {-1, -10, 1, 10, -11, -9, 11, 9};
 
int SqAttacked(const int sq, const int side, const S_BOARD *pos) {
    int piece, index, temp_sq, dir;

    // Check for pawns
    if (side == WHITE) {
        if (pos->pieces[sq - 11] == wP || pos->pieces[sq - 9] == wP) {
            return TRUE;
        }
    } else {
        if (pos->pieces[sq + 11] == bP || pos->pieces[sq + 9] == bP) {
            return TRUE;
        }
    }

    // Check for knights
    for (index = 0; index < 8; index++) {
        piece = pos->pieces[sq + KnightDirection[index]];

        if (IsKnight(piece) && PieceColour[piece] == side) {
            return TRUE;
        }
    }

    // Check for rooks and queens
    for (index = 0; index < 4; index++) {
        dir = RookDirection[index];
        temp_sq = sq + dir;
        piece = pos->pieces[temp_sq];

        while (piece != OFFBOARD) {
            if (piece != EMPTY) {
                if (IsRookQueen(piece) && PieceColour[piece] == side) {
                    return TRUE;
                }
                break;
            }

            temp_sq += dir;
            piece = pos->pieces[temp_sq];
        }
    }

    // Check for bishops and queens
    for (index = 0; index < 4; index++) {
        dir = BishopDirection[index];
        temp_sq = sq + dir;
        piece = pos->pieces[temp_sq];

        while (piece != OFFBOARD) {
            if (piece != EMPTY) {
                if (IsBishopQueen(piece) && PieceColour[piece] == side) {
                    return TRUE;
                }
                break;
            }

            temp_sq += dir;
            piece = pos->pieces[temp_sq];
        }
    }

    // Check for kings
    for (index = 0; index < 8; index++) {
        piece = pos->pieces[sq + KingDirection[index]];

        if (IsKing(piece) && PieceColour[piece] == side) {
            return TRUE;
        }
    }

    return FALSE;
}