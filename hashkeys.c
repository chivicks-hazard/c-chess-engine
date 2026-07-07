#include "defs.h"

U64 GeneratePosKey(const S_BOARD *pos) {
    int sq = 0;
    U64 finalKey = 0;
    int piece = EMPTY;

    // pieces
    for (sq = 0; sq < BOARD_SQ_NUMBER; sq++) {
        piece = pos->pieces[sq];

        if (piece != NO_SQ && piece != EMPTY && piece != OFFBOARD) {
            ASSERT(piece >= wP && piece <= bK);
            finalKey ^= PieceKeys[piece][sq];
        }
    }

    if (pos->side == WHITE) {
        finalKey ^= SideKey;
    }

    if (pos->enPassant != NO_SQ) {
        ASSERT(pos->enPassant >= 0 && pos->enPassant < BOARD_SQ_NUMBER);
        finalKey ^= PieceKeys[EMPTY][pos->enPassant];
    }

    ASSERT(pos->castlePerm >= 0 && pos->castlePerm <= 15);
    finalKey ^= CastleKeys[pos->castlePerm];
    
    return finalKey;
}