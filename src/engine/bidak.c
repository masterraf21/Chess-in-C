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

void InitListBidak(List_Bidak *L, COLOR Warna)
{
    CreateEmpty(L);
    
    //Generate bidak satu satu sesuai warna
    //nanti bakal ada dua list, white or black
    if (Warna==WHITE){
        /* Generate yang putih dulu gan*/
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

        //Isi Linked list dengan bidak yang baru dibuat
        InsVLast(L, PawnW1);InsVLast(L, PawnW2);InsVLast(L, PawnW3);InsVLast(L, PawnW4);
        InsVLast(L, PawnW5);InsVLast(L, PawnW6);InsVLast(L, PawnW7);InsVLast(L, PawnW8);
        InsVLast(L, RookW1);InsVLast(L, RookW2);
        InsVLast(L, KnightW1);InsVLast(L, KnightW2);
        InsVLast(L, BishopW1);InsVLast(L, BishopW2);
        InsVLast(L, KingW);InsVLast(L, QueenW);
    }else{
        /* Generate yang hitam gan */
        PawnB1 = InitBidak(PAWN, A7, BLACK);
        PawnB2 = InitBidak(PAWN, B7, BLACK);
        PawnB3 = InitBidak(PAWN, C7, BLACK);
        PawnB4 = InitBidak(PAWN, D7, BLACK);
        PawnB5 = InitBidak(PAWN, E7, BLACK);
        PawnB6 = InitBidak(PAWN, F7, BLACK);
        PawnB7 = InitBidak(PAWN, G7, BLACK);
        PawnB8 = InitBidak(PAWN, H7, BLACK);
        RookB1 = InitBidak(ROOK, A8, BLACK);
        RookB2 = InitBidak(ROOK, H8, BLACK);
        KnightB1 = InitBidak(KNIGHT, B8, BLACK);
        KnightB2 = InitBidak(KNIGHT, G8, BLACK);
        BishopB1 = InitBidak(BISHOP, C8, BLACK);
        BishopB2 = InitBidak(BISHOP, F8, BLACK);
        KingB = InitBidak(KING, D8, BLACK);
        QueenB = InitBidak(KING, E8, BLACK);

        //Isi Linked list dengan bidak yang baru dibuat
        InsVLast(L, PawnB1);InsVLast(L, PawnB2);InsVLast(L, PawnB3);InsVLast(L, PawnB4);
        InsVLast(L, PawnB5);InsVLast(L, PawnB6);InsVLast(L, PawnB7);InsVLast(L, PawnB8);
        InsVLast(L, RookB1);InsVLast(L, RookB2);
        InsVLast(L, KnightB1);InsVLast(L, KnightB2);
        InsVLast(L, BishopB1);InsVLast(L, BishopB2);
        InsVLast(L, KingB);InsVLast(L, QueenB);
    }
    
    
    



}