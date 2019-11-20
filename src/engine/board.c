#include "board.h"
#include <stdlib.h>

// Init board kita kondisikan
// agar dia seperti kondisi awal chess
void init_board(BOARD *B)
{
    //Yang belum fix special case
    //sementara boolean aja
    (*B).is_castling = false;
    (*B).is_checkmate = false;
    (*B).is_en_passant = false;
    (*B).is_promosi = false;

    //Buat dulu ListW dan List B nya
    List_Bidak ListW;InitListBidak(&ListW, WHITE);
    List_Bidak ListB;InitListBidak(&ListB, BLACK);
    //Assign ke structnya
    LPutih(*B) = ListW;
    LHitam(*B) = ListB;

    //Assign Array dengan kondisi awal chess
    InitTab(B);
    /*Bidak*/
    //Pawn dulu 
    for (BOARD_INDEX i = A2; i <= H2; i++)
        Tab(*B).TI[i] = WHITE*PAWN;
    for (BOARD_INDEX i = A7; i <= H7; i++)
        Tab(*B).TI[i] = BLACK*PAWN;
    //Rook
    Tab(*B).TI[A1]=WHITE*ROOK;Tab(*B).TI[H1]=WHITE*ROOK;
    Tab(*B).TI[A8]=BLACK*ROOK;Tab(*B).TI[H8]=BLACK*ROOK;
    //Knight
    Tab(*B).TI[B1]=WHITE*KNIGHT;Tab(*B).TI[G1]=WHITE*KNIGHT;
    Tab(*B).TI[B8]=BLACK*KNIGHT;Tab(*B).TI[G8]=BLACK*KNIGHT;
    //Bishop
    Tab(*B).TI[C1]=WHITE*BISHOP;Tab(*B).TI[F1]=WHITE*BISHOP;
    Tab(*B).TI[C8]=BLACK*BISHOP;Tab(*B).TI[F8]=BLACK*BISHOP;
    //King
    Tab(*B).TI[D1]=WHITE*KING;Tab(*B).TI[D8]=BLACK*KING;
    //Queen
    Tab(*B).TI[E1]=WHITE*QUEEN;Tab(*B).TI[E8]=BLACK*QUEEN;
   
    /* Empty Squares */
    for (BOARD_INDEX i = A3; i <= H3; i++)
        Tab(*B).TI[i] = EMPTY_SQUARE;
    for (BOARD_INDEX i = A4; i <= H4; i++)
        Tab(*B).TI[i] = EMPTY_SQUARE;
    for (BOARD_INDEX i = A5; i <= H5; i++)
        Tab(*B).TI[i] = EMPTY_SQUARE;
    for (BOARD_INDEX i = A6; i <= H6; i++)
        Tab(*B).TI[i] = EMPTY_SQUARE;

    /* Off-Board */
    for (BAD_INDEX i = 0; i <= 19; i++)
        Tab(*B).TI[i] = BAD_SQUARE;
    for (BAD_INDEX i = 100; i <= 119; i++)
        Tab(*B).TI[i] = BAD_SQUARE;
    for (BAD_INDEX i = 20; i <= 90; i+=10)
        Tab(*B).TI[i] = BAD_SQUARE;
    for (BAD_INDEX i = 29; i <= 99; i += 10)
        Tab(*B).TI[i] = BAD_SQUARE;
}
// Update
void update_board(BOARD *B, List_Bidak L);
// Draw procedure
void draw_board(BOARD B)
{
    
};
// Checkmate check
boolean is_check(BOARD B);
// En passant check
boolean is_enpassant(BOARD B);