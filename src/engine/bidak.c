#include <stdlib.h>
#include "bidak.h"

BIDAK InitBidak(PAWN_TYPE Tipe, BOARD_SQUARE Posisi, COLOR Warna)
{
    BIDAK B;
    B.posisi = Posisi;
    B.tipe = Tipe;
    B.warna = Warna;

    return
}

void InitGenerate(List_Bidak *L)
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
    RookW1 = InitBidak


}