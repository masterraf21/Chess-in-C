#ifndef BOARD_H
#define BOARD_H

#include "chess.h"
#include "bidak.h"

/****** MACRO *******/

#define Tab(L) (L).Tab
#define LPutih(L) (L).LPutih
#define LHitam(L) (L).LHitam




/******* KONSTRUKTOR ******/

// Init
void init_board(BOARD *B);
// Update
void update_board(BOARD *B, List_Bidak L);
// Draw procedure
void draw_board(BOARD B);
// Checkmate check
boolean is_check(BOARD B);
// En passant check
boolean is_enpassant(BOARD B);

#endif
