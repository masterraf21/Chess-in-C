#include <stdlib.h>
#include "bidak.h"

BIDAK InitBidak(PAWN_TYPE Tipe, BOARD_SQUARE Posisi, COLOR Warna)
{
    BIDAK B;
    B.posisi = Posisi;
    B.tipe = Tipe;
    B.warna = Warna;

    return B;
}

void InitListBidak(List_Bidak *L)
{
    CreateEmpty(*L);
    /* Generate yang putih dulu gan*/
    //Generate bidak satu satu
    PawnW1 = InitBidak(PAWN, A2, WHITE);
    PawnW2 = InitBidak(PAWN, B2, WHITE);
    PawnW3 = InitBidak(PAWN, C2, WHITE);
    PawnW4 = InitBidak(PAWN, D2, WHITE);
    PawnW5 = InitBidak(PAWN, E2, WHITE);
    PawnW6 = InitBidak(PAWN, F2, WHITE);
    PawnW7 = InitBidak(PAWN, G2, WHITE);
    PawnW8 = InitBidak(PAWN, H2, WHITE);
    RookW1 = InitBidak(ROOK, A1, WHITE);
    RookW2 = InitBidak(ROOK, H1, WHITE);
    KnightW1 = InitBidak(KNIGHT, B1, WHITE);
    KnightW2 = InitBidak(KNIGHT, G1, WHITE);
    BishopW1 = InitBidak(BISHOP, C1, WHITE);
    BishopW2 = InitBidak(BISHOP, F1, WHITE);
    KingW = InitBidak(KING, D1, WHITE);
    QueenW = InitBidak(QUEEN, E1, WHITE);
    
    /* Generate yang hitam gan */
    



}