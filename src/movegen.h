#ifndef _MOVEGEN_H
#define _MOVEGEN_H

#include <stdint.h>

#include "types.h"
#include "magics.h"

void genAllMoves(Board * board, uint16_t * moves, int * size);
void genAllNonQuiet(Board * board, uint16_t * moves, int * size);
int isNotInCheck(Board * board, int turn);
int squareIsAttacked(Board * board, int turn, int sq);

#define __MDB MoveDatabaseBishop
#define __MDR MoveDatabaseRook
#define __OMB OccupancyMaskBishop
#define __OMR OccupancyMaskRook
#define __MNB MagicNumberBishop
#define __MNR MagicNumberRook
#define __MSB MagicShiftsBishop
#define __MSR MagicShiftsRook

#define KnightAttacks(sq, tg)       (KnightMap[(sq)] & (tg))
#define BishopAttacks(sq, ne, tg)   (__MDB[(sq)][(((ne) & __OMB[(sq)]) * __MNB[(sq)]) >> __MSB[(sq)]] & (tg))
#define RookAttacks(sq, ne, tg)     (__MDR[(sq)][(((ne) & __OMR[(sq)]) * __MNR[(sq)]) >> __MSR[(sq)]] & (tg))
#define KingAttacks(sq, tg)         (KingMap[(sq)] & (tg))

#endif