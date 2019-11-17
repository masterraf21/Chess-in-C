#ifndef BOARD_H
#define BOARD_H

#include "chess.h"

// Konstruktor
void init_board(BOARD *B);
// Update
void update_board(BOARD *B, List_Bidak L);
// Draw procedure
void draw_board(BOARD B);
// Checkmate check
boolean is_check(BOARD B);
// En passant check
boolean is_enpassant(BOARD B);
// Testing illegal board (ini gajelas buat apa sebenernya)
//boolean is_illegal(ElType T);

#endif
