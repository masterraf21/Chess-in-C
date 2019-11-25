#include <stdlib.h>
#include "bidak.h"



/****HELPER FUNCTION******/
//check if the following b
boolean Enemy(BIDAK B, BOARD_TILE T){
    BOARD_TILE bk = B.id.type*B.warna;
    boolean retval = false; 
    retval = ((bk^T)<0);

    return retval;
}

boolean Friend(BIDAK B, BOARD_TILE T){
    BOARD_TILE bk = B.id.type*B.warna;
    boolean retval = false; 
    retval = ((bk^T)>0);

    return retval;
}

BIDAK InitBidak(PAWN_ID num,PAWN_TYPE Tipe, BOARD_INDEX Posisi, COLOR Warna)
{
    BIDAK B;
    B.id.number = num;
    B.posisi = Posisi;
    B.id.type = Tipe;
    B.warna = Warna;

    return B;
}

void InitListBidak(List_Bidak *L, COLOR Warna)
{
    CreateEmptyBidak(L);
    
    //Generate bidak satu satu sesuai warna
    //nanti bakal ada dua list, white or black
    if (Warna==WHITE){
        /* Generate yang putih dulu gan*/
        BIDAK PawnW1 = InitBidak(ONE, PAWN, A2, WHITE);
        BIDAK PawnW2 = InitBidak(TWO, PAWN, B2, WHITE);
        BIDAK PawnW3 = InitBidak(THREE, PAWN, C2, WHITE);
        BIDAK PawnW4 = InitBidak(FOUR, PAWN, D2, WHITE);
        BIDAK PawnW5 = InitBidak(FIVE, PAWN, E2, WHITE);
        BIDAK PawnW6 = InitBidak(SIX, PAWN, F2, WHITE);
        BIDAK PawnW7 = InitBidak(SEVEN, PAWN, G2, WHITE);
        BIDAK PawnW8 = InitBidak(EIGHT, PAWN, H2, WHITE);
        BIDAK RookW1 = InitBidak(ONE, ROOK, A1, WHITE);
        BIDAK RookW2 = InitBidak(TWO, ROOK, H1, WHITE);
        BIDAK KnightW1 = InitBidak(ONE, KNIGHT, B1, WHITE);
        BIDAK KnightW2 = InitBidak(TWO, KNIGHT, G1, WHITE);
        BIDAK BishopW1 = InitBidak(ONE, BISHOP, C1, WHITE);
        BIDAK BishopW2 = InitBidak(TWO, BISHOP, F1, WHITE);
        BIDAK KingW = InitBidak(ONE, KING, D1, WHITE);
        BIDAK QueenW = InitBidak(ONE, QUEEN, E1, WHITE);

        //Isi Linked list dengan bidak yang baru dibuat
        InsVFirst(L, PawnW1);InsVFirst(L, PawnW2);InsVFirst(L, PawnW3);InsVFirst(L, PawnW4);
        InsVFirst(L, PawnW5);InsVFirst(L, PawnW6);InsVFirst(L, PawnW7);InsVFirst(L, PawnW8);
        InsVFirst(L, RookW1);InsVFirst(L, RookW2);
        InsVFirst(L, KnightW1);InsVFirst(L, KnightW2);
        InsVFirst(L, BishopW1);InsVFirst(L, BishopW2);
        InsVFirst(L, QueenW);InsVFirst(L, KingW);
    }else{
        /* Generate yang hitam gan */
        BIDAK PawnB1 = InitBidak(ONE, PAWN, A2, BLACK);
        BIDAK PawnB2 = InitBidak(TWO, PAWN, B2, BLACK);
        BIDAK PawnB3 = InitBidak(THREE, PAWN, C2, BLACK);
        BIDAK PawnB4 = InitBidak(FOUR, PAWN, D2, BLACK);
        BIDAK PawnB5 = InitBidak(FIVE, PAWN, E2, BLACK);
        BIDAK PawnB6 = InitBidak(SIX, PAWN, F2, BLACK);
        BIDAK PawnB7 = InitBidak(SEVEN, PAWN, G2, BLACK);
        BIDAK PawnB8 = InitBidak(EIGHT, PAWN, H2, BLACK);
        BIDAK RookB1 = InitBidak(ONE, ROOK, A1, BLACK);
        BIDAK RookB2 = InitBidak(TWO, ROOK, H1, BLACK);
        BIDAK KnightB1 = InitBidak(ONE, KNIGHT, B1, BLACK);
        BIDAK KnightB2 = InitBidak(TWO, KNIGHT, G1, BLACK);
        BIDAK BishopB1 = InitBidak(ONE, BISHOP, C1, BLACK);
        BIDAK BishopB2 = InitBidak(TWO, BISHOP, F1, BLACK);
        BIDAK KingB = InitBidak(ONE, KING, D1, BLACK);
        BIDAK QueenB = InitBidak(ONE, QUEEN, E1, BLACK);

        //Isi Linked list dengan bidak yang baru dibuat
        InsVFirst(L, PawnB1);InsVFirst(L, PawnB2);InsVFirst(L, PawnB3);InsVFirst(L, PawnB4);
        InsVFirst(L, PawnB5);InsVFirst(L, PawnB6);InsVFirst(L, PawnB7);InsVFirst(L, PawnB8);
        InsVFirst(L, RookB1);InsVFirst(L, RookB2);
        InsVFirst(L, KnightB1);InsVFirst(L, KnightB2);
        InsVFirst(L, BishopB1);InsVFirst(L, BishopB2);
        InsVFirst(L, QueenB);InsVFirst(L, KingB);
    }


}