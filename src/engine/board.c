#include "board.h"
#include <stdlib.h>

// Init board kita kondisikan
// agar dia seperti kondisi awal chess
void init_board(BOARD *B)
{
    //Buat dulu ListW dan List B nya
    List_Bidak ListW;InitListBidak(&ListW, WHITE);
    List_Bidak ListB;InitListBidak(&ListB, BLACK);
    //Assign ke structnya
    LPutih(*B) = ListW;
    LHitam(*B) = ListB;

    //Assign Array dengan kondisi awal chess
    MakeEmpty((Tab(B));
    


}
// Update
void update_board(BOARD *B, List_Bidak L);
// Draw procedure
void draw_board(BOARD B);
// Checkmate check
boolean is_check(BOARD B);
// En passant check
boolean is_enpassant(BOARD B);