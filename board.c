#include <stdio.h>
#include "defs.h"

int CheckBoard(const S_BOARD *pos) {
    int temp_pieceNum[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int temp_bigPieces[2] = {0, 0};
    int temp_majorPieces[2] = {0, 0};
    int temp_minorPieces[2] = {0, 0};
    int temp_material[2] = {0, 0};

    int sq64, temp_piece, temp_piece_num, sq120, colour, piece_count;

    U64 temp_pawns[3] = {0ULL, 0ULL, 0ULL};

    temp_pawns[WHITE] = pos->pawns[WHITE];
    temp_pawns[BLACK] = pos->pawns[BLACK];
    temp_pawns[BOTH] = pos->pawns[BOTH];

    // check piece lists
    for (temp_piece = wP; temp_piece <= bK; temp_piece++) {
        for (temp_piece_num = 0; temp_piece_num < pos->pieceNum[temp_piece]; temp_piece_num++) {
            sq120 = pos->pieceList[temp_piece][temp_piece_num];
            ASSERT(pos->pieces[sq120] == temp_piece);
        }
    }

    // check piece counts and other counters
    for (sq64 = 0; sq64 < 64; sq64++) {
        sq120 = SQ120(sq64);
        temp_piece = pos->pieces[sq120];
        temp_pieceNum[temp_piece]++;
        colour = PieceColour[temp_piece];

        if (PieceBig[temp_piece] == TRUE) {
            temp_bigPieces[colour]++;
        }
        
        if (PieceMinor[temp_piece] == TRUE) {
            temp_minorPieces[colour]++;
        }
        
        if (PieceMajor[temp_piece] == TRUE) {
            temp_majorPieces[colour]++;
        }

        temp_material[colour] += PieceValue[temp_piece];
    }

    for (temp_piece = wP; temp_piece <= bK; temp_piece++) {
        ASSERT(temp_pieceNum[temp_piece] == pos->pieceNum[temp_piece]);
    }

    // check bitboards count
    piece_count = COUNT(temp_pawns[WHITE]);
    ASSERT(piece_count == pos->pieceNum[wP]);
    piece_count = COUNT(temp_pawns[BLACK]);
    ASSERT(piece_count == pos->pieceNum[bP]);
    piece_count = COUNT(temp_pawns[BOTH]);
    ASSERT(piece_count == pos->pieceNum[bP] + pos->pieceNum[wP]);

    // check bitboards squares
    while (temp_pawns[WHITE]) {
        sq64 = POP(&temp_pawns[WHITE]);
        ASSERT(pos->pieces[SQ120(sq64)] == wP);
    }

    while (temp_pawns[BLACK]) {
        sq64 = POP(&temp_pawns[BLACK]);
        ASSERT(pos->pieces[SQ120(sq64)] == bP);
    }

    while (temp_pawns[BOTH]) {
        sq64 = POP(&temp_pawns[BOTH]);
        ASSERT(pos->pieces[SQ120(sq64)] == wP || pos->pieces[SQ120(sq64)] == bP);
    }

    // sanity checks
    ASSERT(temp_material[WHITE] == pos->material[WHITE] && temp_material[BLACK] == pos->material[BLACK]);
    ASSERT(temp_bigPieces[WHITE] == pos->bigPieces[WHITE] && temp_bigPieces[BLACK] == pos->bigPieces[BLACK]);
    ASSERT(temp_majorPieces[WHITE] == pos->majorPieces[WHITE] && temp_majorPieces[BLACK] == pos->majorPieces[BLACK]);
    ASSERT(temp_minorPieces[WHITE] == pos->minorPieces[WHITE] && temp_minorPieces[BLACK] == pos->minorPieces[BLACK]);

    ASSERT(pos->side == WHITE || pos->side == BLACK);
    ASSERT(GeneratePosKey(pos) == pos->posKey);

    ASSERT(pos->enPassant == NO_SQ || (RanksBoard[pos->enPassant] == RANK_6 && pos->side == WHITE) || (RanksBoard[pos->enPassant] == RANK_3 && pos->side == BLACK));

    ASSERT(pos->pieces[pos->KingSquare[WHITE]] == wK);
    ASSERT(pos->pieces[pos->KingSquare[BLACK]] == bK);

    return TRUE;
}

void UpdateListsMaterial(S_BOARD *pos) {
     int piece, sq, index, colour;

     for (index = 0; index < BOARD_SQ_NUMBER; index++) {
        sq = index;
        piece = pos->pieces[index];
        
        if (piece != OFFBOARD && piece != EMPTY) {
            colour = PieceColour[piece];

            if (PieceBig[piece] == TRUE) {
                pos->bigPieces[colour]++;
            }
            if (PieceMajor[piece] == TRUE) {
                pos->majorPieces[colour]++;
            }
            if (PieceMinor[piece] == TRUE) {
                pos->minorPieces[colour]++;
            }

            pos->material[colour] += PieceValue[piece];

            pos->pieceList[piece][pos->pieceNum[piece]] = sq;
            pos->pieceNum[piece]++;

            if (piece == wK) {
                pos->KingSquare[WHITE] = sq;
            }
            
            if (piece == bK) {
                pos->KingSquare[BLACK] = sq;
            }

            if (piece == wP) {
                SETBIT(pos->pawns[WHITE], SQ64(sq));
                SETBIT(pos->pawns[BOTH], SQ64(sq));
            } else if (piece == bP) {
                SETBIT(pos->pawns[BLACK], SQ64(sq));
                SETBIT(pos->pawns[BOTH], SQ64(sq));
            }
        }
     }
}

int ParseFen(char *fen, S_BOARD *pos) {
    ASSERT(fen != NULL);
    ASSERT(pos != NULL);

    int rank = RANK_8;
    int file = FILE_A;
    int piece = 0;
    int count = 0;
    int i = 0;
    int sq64 = 0;
    int sq120 = 0;

    ResetBoard(pos);

    while ((rank >= RANK_1) && *fen) {
        count = 1;

        switch (*fen) {
            case 'p': 
                piece = bP; 
                break;

            case 'r': 
                piece = bR; 
                break;

            case 'n': 
                piece = bN; 
                break;

            case 'b': 
                piece = bB; 
                break;

            case 'k': 
                piece = bK; 
                break;

            case 'q': 
                piece = bQ; 
                break;

            case 'P': 
                piece = wP; 
                break;

            case 'R': 
                piece = wR; 
                break;

            case 'N': 
                piece = wN; 
                break;

            case 'B': 
                piece = wB; 
                break;

            case 'K': 
                piece = wK; 
                break;

            case 'Q': 
                piece = wQ; 
                break;

            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
                piece = EMPTY;
                count = *fen - '0';
                break;

            case '/':
            case ' ':
                rank--;
                file = FILE_A;
                fen++;
                continue;

            default:
                printf("FEN error \n");
                return -1;
        }

        for (i = 0; i < count; i++) {
            sq64 = rank * 8 + file;
            sq120 = SQ120(sq64);

            if (piece != EMPTY) {
                pos->pieces[sq120] = piece;
            }

            file++;
        }

        fen++;
    }

    ASSERT(*fen == 'w' || *fen == 'b');

    pos -> side = (*fen == 'w') ? WHITE : BLACK;
    fen += 2;

    // * Check castling permissions
    for (i = 0; i < 4; i++) {
        if (*fen == ' ') {
            break;
        }

        switch (*fen) {
            case 'K':
                pos -> castlePerm |= WKCA;
                break;


            case 'Q':
                pos -> castlePerm |= WQCA;
                break;


            case 'k':
                pos -> castlePerm |= BKCA;
                break;


            case 'q':
                pos -> castlePerm |= BQCA;
                break;

            default:
                break;
        }

        fen++;
    }

    fen++;

    ASSERT(pos -> castlePerm >= 0 && pos -> castlePerm <= 15);

    // * Check enPassant squares
    if (*fen != '-') {
        file = fen[0] - 'a';
        rank = fen[1] - '1';

        ASSERT(file >= FILE_A && file <= FILE_H);
        ASSERT(rank >= RANK_1 && rank <= RANK_8);

        pos -> enPassant = FR2SQ(file, rank);
    }

    pos -> posKey = GeneratePosKey(pos);
}

void ResetBoard(S_BOARD *pos) {
    int index = 0;

    for (index = 0; index < BOARD_SQ_NUMBER; index++) {
        pos->pieces[index] = OFFBOARD;
    }

    for (index = 0; index < 64; ++index) {
        pos->pieces[SQ120(index)] = EMPTY;
    }

    for (index = 0; index < 2; ++index) {
        pos->bigPieces[index] = 0;
        pos->majorPieces[index] = 0;
        pos->minorPieces[index] = 0;
        pos->material[index] = 0;
    }

    for (index = 0; index < 3; ++index) {
        pos->pawns[index] = 0ULL;
    }

    for (index = 0; index < 13; ++index) {
        pos->pieceNum[index] = 0;
    }

    pos->KingSquare[WHITE] = pos->KingSquare[BLACK] = NO_SQ;

    pos->side = BOTH;
    pos->enPassant = NO_SQ;
    pos->fiftyMove = 0;

    pos->ply = 0;
    pos->hisPly = 0;

    pos->castlePerm = 0;
    pos->posKey = 0ULL;
}

void PrintBoard(const S_BOARD *pos) {
    int sq, rank, file, piece;

    printf("\n Game Board: \n\n");

    for (rank = RANK_8; rank >= RANK_1; rank--) {
        printf("%d ", rank + 1);

        for (file = FILE_A; file <= FILE_H; file++) {
            sq = FR2SQ(file, rank);
            piece = pos -> pieces[sq];
            printf("%3c", PieceChar[piece]);
        }

        printf("\n");
    }

    printf("\n   ");
    for (file = FILE_A; file <= FILE_H; file++) {
        printf("%3c", 'a' + file);
    }
    printf("\n");

    printf("side: %c\n", SideChar[pos -> side]);
    printf("enPassant: %d\n", pos -> enPassant);

    printf("Castling Permissions: %c%c%c%c\n", 
        pos -> castlePerm & WKCA ? 'K' : '-',
        pos -> castlePerm & WQCA ? 'Q' : '-',
        pos -> castlePerm & BKCA ? 'k' : '-',
        pos -> castlePerm & BQCA ? 'q' : '-'
    );

    printf("Position Key: %llX\n", pos -> posKey);
}