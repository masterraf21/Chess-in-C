#include <stdlib.h>
#include "bidak.h"



/****HELPER FUNCTION******/
//check if the following b
boolean Enemy(BIDAK B, BOARD_TILE T){
    BOARD_TILE bk = B.tipe*B.warna;
    boolean retval = false; 
    retval = ((bk^T)<0);

    return retval;
}

boolean Friend(BIDAK B, BOARD_TILE T){
    BOARD_TILE bk = B.tipe*B.warna;
    boolean retval = false; 
    retval = ((bk^T)>0);

    return retval;
}

BIDAK InitBidak(LIST_ID Id, PAWN_TYPE Tipe, BOARD_INDEX Posisi, COLOR Warna)
{
    BIDAK B;
    B.id = Id;
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
        PawnW1 = InitBidak(PAWN1, PAWN, A2, WHITE);
        PawnW2 = InitBidak(PAWN2, PAWN, B2, WHITE);
        PawnW3 = InitBidak(PAWN3, PAWN, C2, WHITE);
        PawnW4 = InitBidak(PAWN4, PAWN, D2, WHITE);
        PawnW5 = InitBidak(PAWN5, PAWN, E2, WHITE);
        PawnW6 = InitBidak(PAWN6, PAWN, F2, WHITE);
        PawnW7 = InitBidak(PAWN7, PAWN, G2, WHITE);
        PawnW8 = InitBidak(PAWN8, PAWN, H2, WHITE);
        RookW1 = InitBidak(ROOK1, ROOK, A1, WHITE);
        RookW2 = InitBidak(ROOK2, ROOK, H1, WHITE);
        KnightW1 = InitBidak(KNIGHT1, KNIGHT, B1, WHITE);
        KnightW2 = InitBidak(KNIGHT2, KNIGHT, G1, WHITE);
        BishopW1 = InitBidak(BISHOP1, C1, WHITE);
        BishopW2 = InitBidak(BISHOP2, F1, WHITE);
        KingW = InitBidak(KINGX, KING, D1, WHITE);
        QueenW = InitBidak(QUEENX, QUEEN, E1, WHITE);

        //Isi Linked list dengan bidak yang baru dibuat
        InsVLast(L, PawnW1);InsVLast(L, PawnW2);InsVLast(L, PawnW3);InsVLast(L, PawnW4);
        InsVLast(L, PawnW5);InsVLast(L, PawnW6);InsVLast(L, PawnW7);InsVLast(L, PawnW8);
        InsVLast(L, RookW1);InsVLast(L, RookW2);
        InsVLast(L, KnightW1);InsVLast(L, KnightW2);
        InsVLast(L, BishopW1);InsVLast(L, BishopW2);
        InsVLast(L, QueenW);InsVLast(L, KingW);
    }else{
        /* Generate yang hitam gan */
        PawnB1 = InitBidak(PAWN1, PAWN, A7, BLACK);
        PawnB2 = InitBidak(PAWN2, PAWN, B7, BLACK);
        PawnB3 = InitBidak(PAWN3, PAWN, C7, BLACK);
        PawnB4 = InitBidak(PAWN4, PAWN, D7, BLACK);
        PawnB5 = InitBidak(PAWN5, PAWN, E7, BLACK);
        PawnB6 = InitBidak(PAWN6, PAWN, F7, BLACK);
        PawnB7 = InitBidak(PAWN7, PAWN, G7, BLACK);
        PawnB8 = InitBidak(PAWN8, PAWN, H7, BLACK);
        RookB1 = InitBidak(ROOK1 ROOK, A8, BLACK);
        RookB2 = InitBidak(ROOK2, ROOK, H8, BLACK);
        KnightB1 = InitBidak(KNIGHT1, KNIGHT, B8, BLACK);
        KnightB2 = InitBidak(KNIGHT2, KNIGHT, G8, BLACK);
        BishopB1 = InitBidak(BISHOP1, BISHOP, C8, BLACK);
        BishopB2 = InitBidak(BISHOP2, BISHOP, F8, BLACK);
        KingB = InitBidak(KINGX, KING, D8, BLACK);
        QueenB = InitBidak(QUEENX, QUEEN, E8, BLACK);

        //Isi Linked list dengan bidak yang baru dibuat
        InsVLast(L, PawnB1);InsVLast(L, PawnB2);InsVLast(L, PawnB3);InsVLast(L, PawnB4);
        InsVLast(L, PawnB5);InsVLast(L, PawnB6);InsVLast(L, PawnB7);InsVLast(L, PawnB8);
        InsVLast(L, RookB1);InsVLast(L, RookB2);
        InsVLast(L, KnightB1);InsVLast(L, KnightB2);
        InsVLast(L, BishopB1);InsVLast(L, BishopB2);
        InsVLast(L, QueenB);InsVLast(L, KingB);
    }


}